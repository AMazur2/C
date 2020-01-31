#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "song.h"

Song_l* new_song (Song_l *item, char *title, char *album_title, char *artist,
                   char *genre, int year_of_release, char *grade) {

    Song_l* new_item;
    Song_l* next_item;
    Song_l* prev_item;

    new_item = malloc( sizeof( Song_l ));
    if ( !new_item )
        printf("Unexpected error has occured. Cannot alocate memory correctly!\n");
    else {
        if(item == NULL){
            next_item = new_item;
            prev_item = new_item;
        } else {
            next_item = item->next;
            prev_item = item;
            item->next->prev = new_item;
            item->next = new_item;
        }

        strncpy(new_item->title, title, 41);
        strncpy(new_item->album_title, album_title, 41);
        strncpy(new_item->artist, artist, 41);
        strncpy(new_item->genre, genre, 41);
        new_item->year_of_release = year_of_release;
        strncpy(new_item->grade, grade, 6);
        new_item->next = next_item;
        new_item->prev = prev_item;

    }

    return new_item;
}

Song_l* new_song_from_song (Song_l *item, Song_l* src_item) {

    Song_l* new_item;
    Song_l* next_item;
    Song_l* prev_item;

    new_item = malloc( sizeof( Song_l ));
    if ( !new_item )
        printf("Unexpected error has occured. Cannot alocate memory correctly!\n");
    else {
        if(item == NULL){
            next_item = new_item;
            prev_item = new_item;
        } else {
            next_item = item->next;
            prev_item = item;
            item->next->prev = new_item;
            item->next = new_item;
        }

        memcpy(new_item, src_item, sizeof(*src_item) );
        new_item->next = next_item;
        new_item->prev = prev_item;

    }

    return new_item;
}

Song_l* next_song (Song_l* item) {
    if (item!=NULL)
        return item->next;
    else
        return NULL;
}

Song_l* prev_song (Song_l* item) {
    if (item!=NULL)
        return item->prev;
    else
        return NULL;
}


Song_l* delete_song (Song_l* item) {

    if(item==NULL)
        return item;

    if(item==item->next)
        return NULL;

    item->prev->next = item->next;
    item->next->prev = item->prev;
    Song_l* tmp = item->prev;
    free(item);

    return tmp;
}

void buf_clean ( void ) {
    char c ;
    do
        c=getchar();
    while ( c!='\n' && c!=EOF );
}

void save_list(Song_l* item, char* file_name) {
    FILE *f = fopen(file_name, "wb");

    if(item==NULL)
        return;

    Song_l* iter = item;

    do{
        fwrite(iter, sizeof(*iter), 1, f);
        iter=next_song(iter);
    }while(iter != item);

    fclose(f);
}

Song_l* load_list (Song_l* item, char* file_name){
    FILE *f = fopen(file_name, "rb");

    Song_l tmp;
    Song_l* iter = item;

    fread(&tmp, sizeof(tmp), 1, f);
    while(!feof(f)){
        iter = new_song_from_song (iter, &tmp);
        fread(&tmp, sizeof(tmp), 1, f);
        //printf(iter->artist);
    };

    return iter;
}
