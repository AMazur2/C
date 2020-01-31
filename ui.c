#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "song.h"
#include "ui.h"

void show_song ( Song_l *item ) {
    if(item==NULL)
        printf("List is empty!\n");
    else{
        printf("Title: %s\nAblum title: %s\nArtist: %s\nGenre: %s\nYear of release: %4d\nGrade: %s\n\n",
                item->title, item->album_title, item->artist, item->genre, item->year_of_release, item->grade);
    }
}

void show_playlist( Song_l *item ){

    if(item==NULL){
        printf("List is empty!\n");
        return;
    }

    Song_l* iter = item;

    do{
        show_song(iter);
        iter=next_song(iter);
    }while(iter != item);
}

Song_l* put_song (Song_l* item){
    item = new_song (item, "", "", "","", 0, "");
    edit_song(item);

    return item;
}

void edit_song (Song_l *item) {

    if(item==NULL){
        printf("There is no song to be edited\n");
        return;
    };

    buf_clean();

    do{
        printf("Please enter a title\n");
        scanf("%40[0-9a-zA-Z '/-,]", item->title);
        buf_clean();
    } while(strlen(item->title)==0);

    do{
        printf("Please enter an album title\n");
        scanf("%40[0-9a-zA-Z '-/,]", item->album_title);
        buf_clean();
    } while(strlen(item->album_title)==0);

    do{
        printf("Please enter an artist\n");
        scanf("%40[0-9a-zA-Z .,'/-]", item->artist);
        buf_clean();
    } while (strlen(item->artist)==0);

    do{
        printf("Please enter a genre\n");
        scanf("%40[a-zA-Z /-]", item->genre);
        buf_clean();
    } while (strlen(item->genre)==0);

    int year;
    do{
        do{
            printf("Please enter a year of release of this song\n");
            year = scanf("%d", &item->year_of_release);
            buf_clean();
        }while (year<1);

        if(item->year_of_release>2019)
            printf("Music cannot be produced in the future\n");
    } while(item->year_of_release>2019);

    do{
        printf("Please enter a grade using ' * ' (maximum 5 stars [*])\n");
        scanf("%5[*]s", item->grade);
        buf_clean();
    } while(strlen(item->grade)==0);

    printf("Song was successfully edited/added!\n");
    }
