#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <assert.h>
#include "musicplayer.h"
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SONG_NUM 100

int main()
{
    ptr main_lib = Empty_Lib();

    //songs by default
    
    add_song_to_lib(main_lib, "Pungi", "https://www.youtube.com/watch?v=xLJNnlsLQa8" );
    add_song_to_lib(main_lib, "Song_performance", "https://www.youtube.com/watch?v=8vZs7YGrFLk" );
    add_song_to_lib(main_lib, "Dance_performance_1", "https://www.youtube.com/watch?v=tXI7LW594j0" );
    add_song_to_lib(main_lib, "Dance_performance_2", "https://www.youtube.com/watch?v=pcA4muNRfHo" );
    add_song_to_lib(main_lib, "Jagruti", "https://www.youtube.com/watch?v=WgimqesOXD4" );

    char function[20];
    char new_line, space;
    char song[30];
    char youtube[80];
    int index;    

    srand((unsigned)time(NULL));

    printf("Welcome user, use the functions below with the correct format to run the programme\n");
    printf("This is just my take on the music player with the songs being the felicity events. Please dont grade me on the basis of the implementation\n");
    printf("The user can add more songs if he/she wants\n\n");
    printf("1. add_song_to_lib song_name youtube_link\n");
    printf("2. play\n");
    printf("3. pause\n");
    printf("4. next\n");
    printf("5. prev\n");
    printf("6. print_all_songs\n");
    printf("7. shuffle\n");
    printf("8. rename_song_by_index index\n");
    printf("9. rename_song_by_name song_name\n");
    printf("10. Delete_song song_name\n\n");

    printf("The user has the following songs by default\n");
    print_all_songs(main_lib);
    printf("\n");

    while(1==1)
    {

        int rand_num = rand() % MAX_SONG_NUM;
        rand_num = rand_num % ((main_lib->index)+1);
        //printf("rand_num: %d\n", rand_num);

        scanf("%s", function);
        //printf("%s", function);

        if(strcmp(function, "pause")==0)
        {
            assert(main_lib->Next != NULL);
            scanf("%c", &space);
            pause();
        }
        else if(strcmp(function, "next") == 0)
        {
            assert(main_lib->Next != NULL);
            scanf("%c", &space);
            Next();
        }
        else if(strcmp(function, "play") == 0)
        {
            assert(main_lib->Next != NULL);
            scanf("%c", &space);
            play();
        }
        else if(strcmp(function, "prev") == 0)
        {
            assert(main_lib->Next != NULL);
            scanf("%c", &space);
            Prev();
        }
        else if(strcmp(function, "print_all_songs")==0)
        {
            scanf("%c", &space);
            print_all_songs(main_lib);
        }
        else if(strcmp(function, "shuffle")==0)
        {
            scanf("%c", &space);
            if(rand_num == 1)
                rand_num++;

            shuffle(main_lib, rand_num);
        }
        else if(strcmp(function, "rename_song_by_index")==0)
        {
            scanf(" %d", &index);
            rename_songs_by_index(main_lib, index);
        }
        else if(strcmp(function, "rename_song_by_name")==0)
        {
            scanf(" %s", song);
            rename_songs_by_name(main_lib, song);
        }
        else if(strcmp(function, "add_song_to_lib")==0)
        {
            scanf(" %[^ ]s", song);
            scanf(" %s", youtube);
            add_song_to_lib(main_lib, song, youtube);
        }
        else if(strcmp(function, "Delete_song") == 0)
        {
            scanf(" %s", song);
            Delete_song(main_lib, song);
            //printf("Done\n");
        }
        else
        {
            char yes_or_no;
            printf("Invalid function input, try again\n");
            printf("Do you want to exit (Y/N): ");
            scanf("%c", &yes_or_no);

            if(toupper(yes_or_no) == 'N')
            {
                continue;
            }
            Delete_lib(main_lib);
            break;
        }

        //scanf("%c", &new_line);        
    }
    return 0;
}