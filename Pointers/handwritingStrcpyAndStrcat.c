#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void myStrCat(char *str,char *str2){

    //int karakterSayisi=strlen(str);
    //char *p1=str+karakterSayisi;
    char *p1=str;
    while(*p1){//*p1!='\0'
        p1++;
    }
    char *p2=str2;
    while(*p2){
        *p1=*p2;
        p1++;
        p2++;
    }
    *p1='\0';
}
void myStrCpy(char *str,char *str2){
    char *p1=str;
    char *p2=str2;
    while(*p2){
        *p1++=*p2++;
    }
    *p1='\0';//İkinci string kısa oldugunda birinci stringteki uzun alanlar siliniyor
}

int main(){
    char kullaniciGirisi[]="ilkerrrrrrr";
    char kullaniciGirisi2[]="karaca";
    myStrCat(kullaniciGirisi,kullaniciGirisi2);
    puts(kullaniciGirisi);
    myStrCpy(kullaniciGirisi,kullaniciGirisi2);
    puts(kullaniciGirisi);

    return 0;
}
