#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "song.h"
#include "enterp.h"

void sort_playlist_by_artist (Song_l* item){

    if(item==NULL){
        printf("An empty list cannot be sorted!\n");
        return;
     }

    struct Song *iter_i = item;
    struct Song *iter_j;
    char buffer[41];
    int tmp;

    while(iter_i != item->prev) {
        iter_j = iter_i->next;
        while(iter_j != item) {
            if(strcmp(iter_i->artist, iter_j->artist) >0) {

                strncpy(buffer, iter_i->title, 40);
                strncpy(iter_i->title, iter_j->title, 40);
                strncpy(iter_j->title, buffer, 40);

                strncpy(buffer, iter_i->album_title, 40);
                strncpy(iter_i->album_title, iter_j->album_title, 40);
                strncpy(iter_j->album_title, buffer, 40);

                strncpy(buffer, iter_i->artist, 40);
                strncpy(iter_i->artist, iter_j->artist, 40);
                strncpy(iter_j->artist, buffer, 40);

                strncpy(buffer, iter_i->genre, 40);
                strncpy(iter_i->genre, iter_j->genre, 40);
                strncpy(iter_j->genre, buffer, 40);

                tmp = iter_i->year_of_release;
                iter_i->year_of_release = iter_j->year_of_release;
                iter_j->year_of_release = tmp;

                strncpy(buffer, iter_i->grade, 5);
                strncpy(iter_i->grade, iter_j->grade, 5);
                strncpy(iter_j->grade, buffer, 5);

            }
            iter_j=iter_j->next;
        }
        iter_i=iter_i->next;
    }
}
