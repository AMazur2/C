#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "song.h"
#include "ui.h"
#include "enterp.h"

int main(int argc, char* argv[]){

    Song_l* curr = NULL;
    if(argc<2){
        printf("Please enter file name\n\
               Additionally - available parameters:\n \
                [/S]- sorting playlist from file,\n\
                [/W]- to view playlist immediately after starting the program.");
        exit(0);
    }
    curr = load_list(curr, argv[1]);

    printf("%s\n%s\n\n", argv[0], argv[1]);
    int i;
     for(i=2;i<argc;i++)
        if(argv[i][0]=='/')
            switch(argv[i][1]) {
                case 's':
                case 'S':
                    sort_playlist_by_artist(curr);
                    break;
                case 'w':
                case 'W':
                    show_playlist(curr);
                    break;
            }

    printf("Hello, please choose:\n");

    int num;

    do{
        printf("[1] if you want to see the whole playlist, \n\
[2] to see a current song,\n\
[3] to see a next song, \n\
[4] to see a previous one, \n\
[5] to add new element,\n\
[6] to delete current element, \n\
[7] to edit current element, \n\
[8] to save a list, \n\
[0] to exit the program.\n");


        while(1!=scanf("%d",&num)){
            buf_clean();
            printf("Please enter a correct number (0-8)\n");
        }
        switch (num) {
        case 1:
            show_playlist(curr);
            break;
        case 2:
            show_song(curr);
            break;
        case 3:
            curr = next_song(curr);
            show_song(curr);
            break;
        case 4:
            curr = prev_song(curr);
            show_song(curr);
            break;
        case 5:
            put_song(curr);
            break;
        case 6:
            curr = delete_song(curr);
            show_song(curr);
            break;
        case 7:
            edit_song(curr);
            show_song(curr);
            break;
        case 8:
            save_list(curr, "Playlist.dat");
            break;
        case 0:
            printf("Thanks! Goodbye");
            save_list(curr, "Playlist.dat");
            break;
       default:
            printf("Please enter a correct number (0-8)\n");
            break;
        }
    } while(num!=0);

    return 0;
}
