# Sound-cloud-implimentation-in-Cpp


This repository contains an implementation of a Soundcloud system in C++. The system consists of various databases for managing music metadata, author metadata, albums, and discography. The implementation utilizes linked lists and provides functionalities for searching and updating records in each database.

## Music Metadata Database (MMD)
The Music Metadata Database stores records of all music tracks. Each track is identified by a unique MBID (4-digit number) and contains information such as the song name, writer, and length. The database features include maintaining the data structure with strong connections between nodes, maintaining the list in ascending order based on MBID, and locating and updating records based on MBID.

## Author Metadata Database (AMD)
The Author Metadata Database stores records of all authors. Each author is identified by a unique AID (4-digit number) and contains information such as the name, band, gender, date of birth, career start date, and genre. The database features include maintaining the data structure with strong connections between nodes, accessing the last node and head of the list, maintaining the list in ascending order based on AID, and locating and updating records based on AID.

## Album Database (AD)
The Album Database maintains data related to music tracks of each album. Each record contains information such as the ABID (4-digit unique number), album name, AID (author ID), publisher, number of tracks, total duration, and tracks. The "Tracks" field represents a singly linked list, where each node contains information related to a specific music track of the album. The database features include maintaining the data structure with connections between nodes, maintaining the list in ascending order based on ABID, and locating and updating records based on ABID. The AD database is connected to the MMD and AMD databases via MBID and AID, respectively.

## Author Discography Playlist (ADP)
The Author Discography Playlist database serves as the centralized database, connecting MMD, AMD, and AD. It keeps records of all music tracks released by an author with respect to albums. Each record contains information such as the DID (4-digit unique number), AID (author ID), and albums. The "Albums" field represents a singly linked list, where each node contains information related to a specific album. The database features include maintaining the data structure with connections between nodes, maintaining the list in ascending order based on DID, and locating and updating records based on DID. The ADP database is connected to the AMD and AD databases via AID and ABID, respectively.

## General Functionalities
The implementation includes the following general functionalities:

1.Upon running the program, it reads data for each database from related data files and stores it in a linked-list-based queue, following the FIFO (First-In-First-Out) rule.
2.After loading all data into the queue, the program populates each database with the related queue data following the FIFO rule.
3.Searching music by MBID in MMD and displaying all records from MMD.
4.Searching authors by AID in AMD and displaying all records from AMD.
5.Searching albums by ABID in AD and displaying all records from AD.
6.Searching discographies by DID in ADP and displaying all records from ADP.
7.Searching music by albums, given ABID, and displaying all track details from MMD of all tracks.
8.Searching music by author, given DID, and displaying all track names from MMD of all tracks released by the author.
## Usage
Clone the repository:

Compile the C++ source files using a C++ compiler.

Run the compiled executable to interact with the Soundcloud system.
