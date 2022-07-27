#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


int kelimeArama(FILE *file, char *aranacakKelime){
    char kelime[30];
    int kelimeSayisi=0;
    while (!feof(file)){
        fscanf(file,"%s",&kelime);
        kelimeSayisi++;
        if (strcmp(kelime,aranacakKelime)==0){
            return kelimeSayisi;
        }
    }
    return -1;
}

int main(){
    char aranacakKelime[30];
    FILE *file = fopen("deneme.txt","r");
    if (file==NULL){
        fprintf(stderr,"Hata!");
        exit(0);
    }
    puts("Aranacak kelimeyi girin:");
    scanf("%s",&aranacakKelime);
    int index = kelimeArama(file,aranacakKelime);
    if (index != -1){
        printf("%s kelimesi dosyanin %d.kelimesi",aranacakKelime,index);
    }else{
        printf("%s kelimesi dosyada bulunamadı.",aranacakKelime);
    }
    fclose(file);
    return 0;
}
