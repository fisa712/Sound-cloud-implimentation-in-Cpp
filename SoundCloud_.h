#include <iostream>//nowwwwwwww
#include<fstream>
#include <string>


using namespace std;
template<class I1, class S1, class F1>
class MMD;
template<class I1, class S1 >
class AMD;
template <class I, class S, class F>
class Tracks;
template<class I1, class S1, class F1>
class AD;
template <class I, class S, class F>
class ADP;


//MMD<int, string, float>* GlobMMDHead = new MMD<int, string, float>;



//Music Metadata DataBase (A doubly linked list)
template<class I1, class S1, class F1>
class MMD
{
public:

	//data members....MBID,SONG NAME,WRITER,Length
	I1 mbid;
	S1 s_name;
	S1 wrtr;
	F1 len;
	AD<int , string , float>* album;

	//connections
	MMD* next;
	MMD* previous;
};
MMD<int, string, float>* GlobMMDHead = new MMD<int, string, float>;

//Author Metadata DataBase (A circular linked list)
template<class I1, class S1 >
class AMD
{
public:
	//data members
	I1 aid;
	S1 A_name;
	S1 Band;
	S1 Gendr;
	I1 DOB;
	I1 Date;
	S1 Genre;
	AD < int , string , float >* albums;
	ADP < int, string, float >* adp;

	//connections
	AMD* next;
};

//Tracks (A singly linked list)
template <class I, class S, class F>
class Tracks
{
public:
	//data members
	int trackNumber;
	MMD<int, string, float>* trackRef;

	//connections
	Tracks* next;
};

//Album DataBase (A circular linked list)
template<class I1, class S1, class F1>//NUMBER OF TRACKS,TOTAL DURATION,TRACK NUMBER,TRACK MBID
class AD
{
public:
	//data members
	I1 abid;
	S1 albm;
	I1 A_Id;
	S1 publ;
	I1 N_of_Tracks;
	F1 Tot_Dur;
	I1 Trk_Num;
	I1 MbId;

	AMD <int , string >* author;
	Tracks <int, string, float>* tracks;
	ADP <int, string, float>* adp;

	//connections
	AD* next;
};

AD<int, string, float>* GlobADHead = new AD<int, string, float>;


//Albums (A singly linked list)
template <class I, class S, class F>
class Albums
{
public:
	//data members
	int year;
	AD<int , string , float>* albumRef;

	//connections
	Albums* next;
};

//Author Discography Playlist (A circular linked list)
template <class I, class S, class F>
class ADP
{
public:
	//data members
	int did;
	AMD <int , string >* author;
	Albums<int , string , float>* albums;

	//connections
	ADP* next;
};

//Functions Prototypes
template<class I, class S, class F>
MMD<int, string, float>* Create_MMD(string path); //should return head of the MMD linkedlist
template<class I1, class S1, class F1>
AMD<int, string> * Create_AMD(string path); //should return head of the AMD linkedlist
AD<int , string , float>* Create_AD(string path); //should return head of the AD linkedlist
ADP<int, string, float>* Create_ADP(string path); //should return head of the ADP linkedlist
//MMD<int, string, float>* Search_Music(int MBID); //should return pointer to track having mbid = MBID
//AMD* Search_Author(int AID); //should return pointer to author having aid = AID
AD<int, string, float>* Search_Album(int ABID); //should return pointer to album having abid = ABID
//ADP* Search_Discography(int DID); //should return pointer to discography having did = DID
//Tracks* Search_Music_By_Album(int ABID); //should return singly linklist of "Tracks" in given album
//Albums* Search_Music_By_Author(int DID); //should return singly linklist of "Albums" in given discography
//
//---------------------------------------------------------------------------------------------------------------------------------------------//
//
//MMD<int, string, float>* Head = new MMD<int, string, float>;
//MMD<int, string, float>* N_Node = new MMD<int, string, float>;
//MMD<int, string, float>* Tail_Node = new MMD<int, string, float>;
//Head = NULL;
//N_Node = Head;
//Tail_Node = Head;

AD<int, string, float>* CreateAlbumsAMD2AD()
{
	int static  c = 0;
	AD<int, string, float>* N_Node = new AD<int, string, float>;
	N_Node->abid = c++;
	N_Node->next = NULL;
	//cout << c << endl;
	return N_Node;
}

AMD<int , string>* CreateAuthors()
{
	static int cnt = 0;
	AMD <int, string>* N_Node = new AMD<int, string>;
	N_Node->aid = cnt++;
	//N_Node->next = NULL;
	return N_Node;
}

AD <int, string, float>* Create_Music(int Mbid )
{
	AD<int, string, float>* N_Node = new AD<int, string, float>;
	N_Node->abid = Mbid;
	N_Node->next = NULL;
	
	return N_Node;

}
MMD<int, string, float>* CreateTrackRef(int Mbid)//------------------------OWN
{
	//MMD<int, string, float>* Head = new MMD<int, string, float>;
	//MMD<int, string, float>* temp = new MMD<int, string, float>;
	MMD<int, string, float>* N_Node = new MMD<int, string, float>;
	N_Node->mbid = Mbid;
	N_Node->next = NULL;
	N_Node->previous = NULL;

	return N_Node;
}


Tracks<int, string, float>* CreateAlbums( ifstream& input,int size , int TrackNumber , int trkMbid)//---------------------OWN_Function
{
	static int count = 0;
	int i = 1 , previous;
	string track_numbr;
	string noftracks;
	string trk_mbid;
	string NoUse;
	Tracks<int, string, float >* Head = new Tracks <int, string, float >;
	Head = NULL;
	Tracks<int, string, float >* temp = new Tracks <int, string, float >;
	while (i != size + 1 )
	{
		Tracks<int, string, float >* N_Node = new Tracks <int, string, float >;
		N_Node->trackNumber = TrackNumber;
		//cout << trkMbid<< endl;
		//N_Node->trackRef->mbid = trkMbid;
		N_Node->trackRef = CreateTrackRef(trkMbid);
		N_Node->next = NULL;
		if (Head == NULL)
		{
			Head = N_Node;
			temp = N_Node;
		}
		else
		{
			temp->next = N_Node;
			temp = N_Node;
		}
		//previous = TrackNumber;
		i++;
		//cout << ++count << endl;
		if (i > size)
		{
			break;
		}
			
		//if (TrackNumber < previous)
		//cout << "-----------------------------------------" << TrackNumber << "---------------------" << endl;

		getline(input, NoUse, ',');
		getline(input, NoUse, ',');
		getline(input, NoUse, ',');
		getline(input, NoUse, ',');
		getline(input, noftracks, ',');
		getline(input, NoUse, ',');
		getline(input, track_numbr, ',');
		getline(input, trk_mbid, '\n');

		//AbId = stoi(ab_ID);
		//A_id = stoi(aid);
		//size = stoi(noftracks);
		//tot_dur = stof(tot_duration);
		if (track_numbr != "")
		{
			TrackNumber = stoi(track_numbr);
			trkMbid = stoi(trk_mbid);
		}
		//trk_mbid = stoi(track_mbid);
		//cout<<"------------------------String-------------------------------------"<< track_numbr <<"---------------------"<<endl;
		
	}
	/*Tracks<int, string, float >* aaa = new Tracks <int, string, float >;
	aaa = Head;
	while (aaa != NULL)
	{
		cout<<"aaa: "<<aaa->trackNumber<<endl;
		aaa = aaa->next;
	}*/
	return Head;
}
template<class I, class S , class F>
MMD<int, string, float>* Create_MMD(string path)
{
	I Mb_Id;
	F Len;
	S t_ID;
	S song_name = "";
	S writer = "";
	S t_len = "";
	S t = "";
	
	//-------------------------// 	   
	
	//MMD<int, string, float>* N_Node = new MMD<int, string, float>;
	MMD<int, string, float>* Head = new MMD<int, string, float>;
	/*MMD<int, string, float>* N_Node = new MMD<int, string, float>;*/
	MMD<int, string, float>* Tail_Node = new MMD<int, string, float>;

	Head = NULL;
	//Tail_Node = Head;
	//temp_Node = Head;
	//-----------------------//
	ifstream input;
	input.open(path, ios::in);
	
	getline(input, t);
	
	//cout << t;
	for (int i = 1; i < 13; i++)
	{
		MMD<int, string, float>* N_Node = new MMD<int, string, float>;
		getline(input, t_ID, ',');
		getline(input, song_name, ',');
		getline(input, writer, ',');
		getline(input, t_len, '\n');

		//cout << "MBID: " << t_ID << endl;
		/*cout << "Sname: " << song_name << endl;
		cout << "WRTER: " << writer << endl;
		cout << "Len: " << t_len << endl;*/
		Mb_Id = stoi(t_ID);
		Len = stof(t_len);
		//cout << "\nMb_Id" <<Mb_Id<< endl;
		//cout << "Len" << Len << endl;
		//---------------------------------//
		//cout << "*******************"<<endl;
		//----------------//
		N_Node->mbid = Mb_Id;
		N_Node->s_name = song_name;
		N_Node->wrtr = writer;
		N_Node->len = Len;
		N_Node->album = Create_Music(Mb_Id - 1);//-------------???????????????????????????????????????????????

		//cout<<"Out:"<<N_Node->album->abid << endl;


		N_Node->next = NULL;///--------tick
		Tail_Node = Head;//------------------------------------<<Commented>>
		if (Head == NULL)
		{
			N_Node->previous = NULL;
			Head = N_Node;
			GlobMMDHead = Head;
			//Tail_Node = Head;
		}
		else
		{
			while (Tail_Node->next != NULL)
			{
				Tail_Node =  Tail_Node->next;
			}

			Tail_Node->next = N_Node;
			N_Node->previous = Tail_Node;
		}
		
	}
	int n = 0;
	/*while (Head->next != NULL && n < 14)
	{
		cout<<"MBID-->"<<Head->mbid<<endl;
		Head = Head->next;
		n++;
	}*/
	
	return Head;
}

//-----------------------------------------------------AUTHJOR Meta DATa database---------------------------------------//
template<class I , class S>
AMD<int, string>* Create_AMD(string path)//a circular linked list 
{
	I a_Id;
	I Dob;
	I date;
	S t;
	S t_ID;
	S auth_name = "";
	S band = "";
	S gendr = "";
	S t_DOB = "";
	S t_date = "";
	S genre = "";
	
	
	//-------------------------// 	   
	AMD<int, string>* Head = new AMD<int, string>;
	AMD<int, string>* t_Node = new AMD<int, string>;
	AMD<int, string>* curr_Node = new AMD<int, string>;

	Head = NULL;
	//t_Node = Head;
	
	//-----------------------//
	ifstream input;
	input.open(path, ios::in);

	getline(input, t);

	//cout << t;
	for (int i = 1; i < 6; i++)
	{
		AMD<int, string>* N_Node = new AMD<int, string>;
		
		getline(input, t_ID, ',');
		getline(input, auth_name, ',');
		getline(input, band, ',');
		getline(input, gendr, ',');
		getline(input, t_DOB, ',');
		getline(input, t_date, ',');
		getline(input, genre, '\n');
		/*cout<<"\n In for..."<<endl;
		cout << "MBID: " << t_ID << endl;
		cout << "Sname: " << auth_name << endl;
		cout << "WRTER: " << band << endl;
		cout << "Len: " << t_DOB << endl;
		cout << "Len: " << t_date << endl;
		cout << "Len: " << genre << endl;*/
		
		a_Id = stoi(t_ID);
		Dob = stoi(t_DOB);
		date = stoi(t_date);
		/*cout << "\nMb_Id" << a_Id << endl;
		cout << "Len" << date << endl;*/
		//---------------------------------//
		//----------------//
		N_Node->aid = a_Id;
		N_Node->A_name = auth_name;
		N_Node->Band = band;
		N_Node->Gendr = gendr;
		N_Node->DOB = Dob;
		N_Node->Date = date;
		N_Node->Genre = genre;
		N_Node->albums = CreateAlbumsAMD2AD();
		//t_Node = Head;
		
		if (Head == NULL)
		{
			Head = N_Node;
			N_Node->next = Head;
			t_Node = Head;
		}
		else
		{
			t_Node->next = N_Node;
			N_Node->next = Head;
			t_Node = N_Node;
		}
		
		//cout << "-------------------" << endl;

	}
	/*int n = 0;
	while (Head->next != NULL && n < 5)
	{
		cout<<"MBID-->"<<Head->aid<<endl;
		Head = Head->next;
		n++;
	}*/
	return Head;
}
template<class I ,class  S , class  F >
AD<int, string, float>* Create_AD(string path) //should return head of the AD linkedlist//---ABID,ALBUM NAME,AID,PUBLISHER,NUMBER OF TRACKS,TOTAL DURATION,TRACK NUMBER,TRACK MBID
{
	 I AbId;
	I A_id;
	I num_of_tracks;
	F tot_dur;
	I trk_numb;
	I trk_mbid;
	S t;
	S ab_ID;
	S  albm_name = "";
	S aid = "";
	S publisher = "";
	S NOFTraks = "";
	S tot_duration = "";
	S track_numbr = "";
	S track_mbid = "";

	

	//-------------------------// 	   
	AD<int, string , float >* Head = new AD<int, string, float >;
	AD<int, string, float >* t_Node = new AD<int, string, float >;

	Head = NULL;
	//t_Node = Head;

	//-----------------------//
	
	ifstream input;
	input.open(path, ios::in);

	getline(input, t);

	//cout << t;
	for (int i = 1; i < 14; i++)//ABID,ALBUM NAME,AID,PUBLISHER,NUMBER OF TRACKS,TOTAL DURATION,TRACK NUMBER,TRACK MBID
	{
		AD<int, string, float >* N_Node = new AD<int, string, float >;

		getline(input, ab_ID, ',');
		getline(input, albm_name, ',');
		getline(input, aid, ',');
		getline(input, publisher, ',');
		getline(input, NOFTraks, ',');
		getline(input, tot_duration, ',');
		getline(input, track_numbr, ',');
		getline(input, track_mbid, '\n');

		AbId = stoi(ab_ID);
		A_id = stoi(aid);
		num_of_tracks = stoi(NOFTraks);
		tot_dur = stof(tot_duration);
		trk_numb = stoi(track_numbr);
		trk_mbid = stoi(track_mbid);
		//---------------------------------//
		//cout<<"\n In for..."<<endl;
		/*cout << "MBID: " << ab_ID << endl;
		cout << "Sname: " << albm_name << endl;
		cout << "WRTER: " << aid << endl;
		*///cout << "Len: " << publisher << endl;
		//-------------------//
		
		//----------------//
		N_Node->abid = AbId;
		N_Node->albm = albm_name;
		N_Node->A_Id = A_id;
		N_Node->publ = publisher;
		N_Node->N_of_Tracks = num_of_tracks;
		N_Node->Tot_Dur = tot_dur;
		N_Node->Trk_Num = trk_numb;
		N_Node->MbId = trk_mbid;

		N_Node->tracks = CreateAlbums (input, num_of_tracks, trk_numb , trk_mbid);// logic is worong
		N_Node->author = CreateAuthors();
		if (Head == NULL)
		{

			//cout << "Once??" << endl;

			Head = N_Node;
			GlobADHead = Head;
			N_Node->next = Head;
		//	cout<<" in head N_Node->next :"<< N_Node->abid <<endl;
			t_Node = Head;
		}
		else
		{
			//cout<<"Now what??"<<endl;
			t_Node->next = N_Node;
			N_Node->next = Head;
			t_Node = N_Node;
			//cout << "in Else N_Node->next :" << N_Node->abid << endl;

		}
		

		//cout << "-------------------" << endl;

	}
	return Head;

}
//---------------------------------------------------------//

AMD<int ,string >* Create_Auth_DID(ifstream& input, int limit )
{
	int previous = limit + 1;
	
	string lim;
	string NoUse;
	AMD<int, string >* Head = new AMD <int, string>;
	Head = NULL;
	AMD<int, string >* temp = new AMD <int, string>;
	while (limit == previous)
	{
		AMD<int, string >* N_Node = new AMD <int, string>;
		N_Node->aid;
		N_Node->next = NULL;
		if (Head == NULL)
		{
			Head = N_Node;
			temp = N_Node;
		}
		else
		{
			temp->next = N_Node;
			temp = N_Node;
		}
		/*if (limit != previous+1)
		{
			continue;
		}*/
		getline(input,lim , ',');
		getline(input, NoUse, ',');
		getline(input, NoUse, ',');
		getline(input, NoUse, '\n');		

		//AbId = stoi(ab_ID);
		limit = stoi(lim);
		cout << limit << endl;
		
		cout<<"------------------------String-------------------------------------"<< limit<<"---------------------"<<endl;

	}
	
	return Head;

}




template<class I, class S, class F>
ADP<int, string, float>* Create_ADP(string path)
{
	int DID;
	int AID;
	int album_ABID;
	int YEAR;
		S d_id;
		S a_id;
		S alb_abid;
		S year;
		S t;

		ADP<int, string, float >* Head = new ADP<int, string, float >;
		ADP<int, string, float >* temp = new ADP<int, string, float >;



		ifstream input;
		input.open(path, ios::in);

		getline(input, t);
		cout << t << endl;
		for (int i = 1; i < 6; i++)
		{
			ADP<int, string, float >* N_Node = new ADP<int, string, float >;

			getline(input, d_id, ',');
			getline(input, a_id, ',');
			getline(input, alb_abid, ',');
			getline(input, year, '\n');

			DID = stoi(d_id);
			cout<<DID<<endl;
			AID = stoi(a_id);
			album_ABID = stoi(alb_abid);
			YEAR = stoi(year);

			N_Node->did = DID;
			N_Node->author = Create_Auth_DID(input ,DID );
			if (Head == NULL)
			{

				//cout << "Once??" << endl;

				Head = N_Node;
				N_Node->next = Head;
				//	cout<<" in head N_Node->next :"<< N_Node->abid <<endl;
				temp = Head;
			}
			else
			{
				//cout<<"Now what??"<<endl;
				temp->next = N_Node;
				N_Node->next = Head;
				temp = N_Node;
				//cout << "in Else N_Node->next :" << N_Node->abid << endl;

			}
		}
		return Head;
}

AD<int , string , float>* Search_Album(int ABID)
{
	return GlobADHead;
}
