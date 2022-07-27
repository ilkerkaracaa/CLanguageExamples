#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int kelimeSayisi(FILE *file){
    int kelimeSayisi=0,karakter;
    do {
        karakter= fgetc(file);
        if (karakter==' ' || karakter=='.'){
            kelimeSayisi++;
        }
    } while (karakter!=EOF);
    return kelimeSayisi;
}

int main(){
    FILE *file= fopen("deneme.txt","r");
    if(file==NULL){
        fprintf(stderr,"Dosya acilirken bir hata meydana geldi.");
        exit(0);
    }
    int sayac=kelimeSayisi(file);
    printf("Dosyada %d tane kelime var.",sayac);
    fclose(file);
    return 0;
}
