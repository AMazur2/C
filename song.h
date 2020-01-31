typedef struct Song Song_l;
struct Song{
    char title[41];
    char album_title[41];
    char artist[41];
    char genre[41];
    int year_of_release;
    char grade[6];
    Song_l* prev;
    Song_l* next;
    };



Song_l* new_song (Song_l *item, char *title, char *album_title, char *artist,
                   char *genre, int year_of_release, char *grade);

Song_l* new_song_from_song (Song_l *item, Song_l* src_item);

Song_l* next_song (Song_l *item);

Song_l* prev_song (Song_l* item);

Song_l* delete_song (Song_l *item);

void buf_clean ( );

void save_list(Song_l* item, char* file_name);

Song_l* load_list (Song_l* item, char* file_name);
