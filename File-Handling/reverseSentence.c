#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void tersAktar(FILE *file1, FILE *file2){
    int karakterSayisi;
    fseek(file1,0,SEEK_END);//Dosya sonu
    karakterSayisi= ftell(file1);//Karakter sayisi
    printf("Karakter sayisi:%d\n",karakterSayisi);
    fseek(file1,-1,SEEK_END);//Son harfe geldik
    for (int i = 2; i <= karakterSayisi+1; ++i) {
        int karakter=fgetc(file1);
        printf("%c ",karakter);
        fputc(karakter,file2);
        fseek(file1,-(i),SEEK_END);
    }
    printf("\nBaşarıyla aktarıldı");
}

int main(){
    FILE *firstFile= fopen("deneme.txt","r");
    FILE *secondFile= fopen("deneme2.txt","w");
    if(firstFile==NULL || secondFile==NULL){
        fprintf(stderr,"Dosyalar açılırken bir hata meydana geldi.");
        exit(0);
    }
    tersAktar(firstFile,secondFile);
    fclose(firstFile);
    fclose(secondFile);
    return 0;
}
