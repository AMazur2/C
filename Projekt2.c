#include <stdio.h>
#include <string.h>

int main(){

    int row;
    char *name;
    char *surname;
    char data[50][2][60];
    char buffer[121];
    char data2[50][2][60];
    char buffer2[121];

    row = 0;
    do{
        name = data[row][0];

        surname = data[row][1];

        puts("Podaj imie i nazwisko");

        while(gets(buffer), (sscanf(buffer, "%[a-zA-Z]%*[ \t\n]%[a-zA-Z]", name, surname) < 2) && (strcmp(buffer,"  ")!=0)){
                printf("Wprowadzono niewlasciwa dana\n");
        }
        if(strcmp(buffer,"  ")==0)
            break;

        row++;
    } while((row<50));

    int a,b;
    for(a=0; a<row; a++){
        for(b=0; b<2; b++){
            strncpy(data2[a][b], data[a][b], 121);
        }
    }

   int i,j,col;
   for(i=0; i<row-1; i++) {
        for(j=i+1; j<row; j++){
            if(strcmp(data[i][1], data[j][1]) >0) {
                for(col=0; col<2; col++){
                strncpy(buffer, data[i][col], 60);
                strncpy(data[i][col], data[j][col], 60);
                strncpy(data[j][col], buffer, 60);
                }
            }

            else if((strcmp(data[i][1], data[j][1]) ==0) && (strcmp(data[i][0], data[j][0]) >0)) {
               for(col=0; col<2; col++){
                strncpy(buffer, data[i][col], 60);
                strncpy(data[i][col], data[j][col], 60);
                strncpy(data[j][col], buffer, 60);
                }
            }
        }
   }
   int row2;
   row2=row;

   int k,l,col1;
   for(k=0; k<row2-1; k++) {
        for(l=k+1; l<row2; l++){
            if(strcmp(data2[k][0], data2[l][0]) <0) {
                for(col1=0; col1<2; col1++){
                strncpy(buffer2, data2[k][col1], 60);
                strncpy(data2[k][col1], data2[l][col1], 60);
                strncpy(data2[l][col], buffer2, 60);
                }
            }

            else if((strcmp(data2[k][0], data2[l][0]) ==0) && (strcmp(data2[k][1], data2[l][1]) <0)) {
               for(col1=0; col1<2; col1++){
                strncpy(buffer2, data2[k][col1], 60);
                strncpy(data2[k][col1], data2[l][col1], 60);
                strncpy(data2[l][col], buffer2, 60);
                }
            }
        }
   }
   printf("Uporzadkowana lista imion i nazwisk:\n");
    for(i=0; i<row; i++) {
        printf("%d. %s %s\n",i+1, data[i][0], data[i][1]);
    }
     printf("Uporzadkowana lista imion i nazwisk nr.2:\n");
    for(k=0; k<row; k++) {
        printf("%d. %s %s\n",k+1, data2[k][0], data2[k][1]);
    }
    return 0;
}
