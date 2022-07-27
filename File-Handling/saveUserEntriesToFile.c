#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int i;
    char *filmListesi[5];
    char film[20];
    FILE *filmDosyasi;
    if((filmDosyasi=fopen("filmDosyasi.txt","w"))==NULL){
        fprintf(stderr,"Dosya acilirken bir hata meydana geldi.");
        exit(0);
    }
    for(i=0;i<5;i++){
        puts("Lutfen istediginiz dizi-film adini girin:");
        fgets(film,20,stdin);
        filmListesi[i]=(char*)malloc(sizeof(char)*strlen(film)+1);
        strcpy(filmListesi[i],film);
    }
    for(i=0;i<5;i++){
        fprintf(filmDosyasi,"Film-Dizi Adi:%s\n",filmListesi[i]);
    }
    fclose(filmDosyasi);

    return 0;
}
