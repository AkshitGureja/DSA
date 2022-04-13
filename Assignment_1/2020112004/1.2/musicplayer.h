#ifndef __MUSIC_H
#define __MUSIC_H

typedef struct song_info* ptr;
typedef struct song_info Song;

typedef struct All_lib* ptr_lib;

struct song_info
{
    int index;
    char song_name[30];
    char youtube_video[80];
    int current_status; // 1 for play, 0 for stop;

    ptr Prev;
    ptr Next;
};

// we can make a linked list of the libraraies, each library has a linked list of the songs in it;

//by deafult add to main library of all songs
//the user can add to other libraries by using the add_to_lib function
ptr New_song(char song_name[], char youtube_video[]);

//by default provide one main library, user can create more
ptr Empty_Lib(); 

//print song name of song to which the current pointer points, chnage song status
void play(); 

//change the status of the song
void pause(); 

//if not paused, pause the first one and then play the next
void Next(); 

// if not paused, pause first and then play the prev;
void Prev(); 

//delete song from particular library
void Delete_song(ptr lib, char song_name[]); 

// print song names in a Lib;
void print_all_songs(ptr Lib); 

//copy song info to the other libraries linked list
// right now it is hardcoded to add to main_lib
void add_song_to_lib(ptr Lib, char song_name[], char youtube_video[]); 

// use rand function to play the song
void shuffle(ptr Lib, int r); 

void rename_songs_by_index(ptr Lib, int index);
void rename_songs_by_name(ptr Lib, char song_name[]);
void Delete_lib(ptr Lib);

// I wanted to implement this, but couldnt be done due to some time constraints and 
// highly hectic schedule that week 

struct All_lib
{
    char lib_name[30];
    ptr First_node; // will be the pointer to the dummy node of the library

    ptr_lib Next;
};

//create a new library
ptr_lib new_lib(char lib_name[]);

//similar to the way we have done for the songs
ptr_lib Empty_list_lib();



#endif