#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


int anagramKontrol(char *str, char *str2){

    int *frekansDizisi,*frekansDizisi2;
    char *ptr=str,*ptr2=str2;
    int i;

    if(strlen(str)!=strlen(str2)){
        return 0;//anagram degildir.
    }

    frekansDizisi=(int*)calloc(26,sizeof(int));
    frekansDizisi2=(int*)calloc(26,sizeof(int));

    while(*ptr!='\0'&& *ptr2!='\0'){
        int indeks=*ptr-'a';
        frekansDizisi[indeks]+=1;
        indeks=*ptr2-'a';
        frekansDizisi2[indeks]+=1;
        ptr++;
        ptr2++;
    }
    for(i=0;i<26;i++){
        printf("%d ",frekansDizisi[i]);
    }
    printf("\n");
    for(i=0;i<26;i++){
        printf("%d ",frekansDizisi2[i]);
    }

    for(i=0;i<26;i++){
        if(frekansDizisi[i]!=frekansDizisi2[i]){
            return 0;//anagram degillerdir.
        }
    }
    return 1;//anagramdir.
}

int main(){

    if(anagramKontrol("eczane","cenaze")){
        puts("\nGirdiginiz iki string birbirinin anagramidir.");
    }
    else{
        puts("\nGirdiginiz iki string birbirinin anagrami degildir.");
    }
    return 0;
}
