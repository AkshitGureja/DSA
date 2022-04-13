#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "musicplayer.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

ptr current_ptr;
int num_songs_main;

ptr New_song(char song[], char YT_vid[])
{
    ptr P = (ptr)(malloc(sizeof(Song)));
    assert(P!=NULL);

    strcpy(P->song_name, song);
    strcpy(P->youtube_video, YT_vid);
    P->current_status = 0;

    P->Prev = NULL;
    P->Next = NULL;
    return P;
}

ptr Empty_Lib()
{
    char song[3] = "lib";
    char YT_vid[6] = "no_vid";
    ptr lib = New_song(song, YT_vid);
    lib->index = 0;
    return lib;
}

void play()
{
    current_ptr->current_status = 1;
    printf("Now playing %s\n", current_ptr->song_name);
    printf("For video, go to %s\n", current_ptr->youtube_video);

}

void pause()
{
    current_ptr->current_status = 0;
    printf("Stopped playing %s\n", current_ptr->song_name);
    printf("To resume playing, write play\n");
}

void Next()
{
    current_ptr->current_status = 0;
    current_ptr = current_ptr->Next;
    //current_ptr->current_status = 1;
    play();
}

void Prev()
{
    current_ptr->current_status = 0;
    current_ptr = current_ptr->Prev;
    play();
}

void shuffle(ptr Lib, int r)
{
    ptr P = Lib;

    while(P->Next->index != r)
    {
        P = P->Next;
    }
    current_ptr = P;
    play();
}

void rename_songs_by_index(ptr Lib, int index)
{
    ptr P = Lib;
    while(P->Next->index != index)
    {
        P = P->Next;
    }
    printf("New Name of the song: ");
    scanf("%s", P->Next->song_name);

    printf("\nNew video link of the song: ");
    scanf("%s", P->Next->youtube_video);

    printf("Done\n");
}

void rename_songs_by_name(ptr Lib, char S[])
{
    ptr P = Lib;
    for(int i = 0; i < num_songs_main;i++)
    {
        if(strcmp(P->Next->song_name, S) == 0)
        {
            break;
        }
        P = P->Next;
    }

    printf("New Name of the song: ");
    scanf("%s", P->Next->song_name);
    
    printf("\nNew video link of the song :");
    scanf("%s", P->Next->youtube_video);

    printf("Done\n");
}

void print_all_songs(ptr Lib)
{
    ptr P = Lib->Next;
    if(P == NULL)
    {
        printf("No songs in this library");
    }

    for(int i = 0; i <Lib->index;i++)
    {
        printf("%d %s\n", P->index, P->song_name);
        P = P->Next;
    }

    printf("Done\n");
}

void Delete_song(ptr Lib, char song_name[])
{
    ptr P = Lib->Next;
    ptr T = P;
    int found = 0;
    
    for(int i = 0; i <num_songs_main;i++)
    {
        if(strcmp(P->song_name, song_name) == 0)
        {
            found = 1;
            break;
        }

        P = P->Next;
    }

    if(found == 0)
    {
        printf("Song doesnt exist\n");
    }
    else
    {
        ptr C = P->Next;
        ptr K = P;
        free(K);
        P = C;
        num_songs_main--;
        printf("Done\n");
    }

}

void add_song_to_lib(ptr Lib, char song_name[], char youtube_video[])
{
    ptr T = New_song(song_name, youtube_video);
    ptr P = Lib;

    if(P->Next == NULL)
    {
        P->Next = T;
        T->Next = NULL;
        T->Prev = P;
        current_ptr = T;
        T->index = (Lib->index)+1;
        num_songs_main++;
    }
    else
    {
        for(int i = 0; i < num_songs_main;i++)
        {
            P = P->Next;
        }
        P->Next = T;
        T->Next = Lib->Next;
        T->Prev = P;
        T->index = (Lib->index)+1;
        Lib->Next->Prev = T;
        num_songs_main++;
    }
    Lib->index++;
    printf("Done\n");
}

void Delete_lib(ptr P)
{   
    ptr Z = P;

    for(int i = 0; i <num_songs_main;i++)
    {
        Z = Z->Next;
        free(P);
        P = Z;
    }
    free(P);

    printf("Done\n");
    
    P = NULL;
}   