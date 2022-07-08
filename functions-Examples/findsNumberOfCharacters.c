#include <stdio.h>
//Function Signature
int diziKarakterSay(char []);
int main(){
    int ozelKarakterler=diziKarakterSay("ilkerkaraca");
    printf("Gonderdiginiz string %d adet ozel karakter icermektedir.",ozelKarakterler);
    return 0;
}
int diziKarakterSay(char kullaniciGirisi[]){
    char karakterler[26];// max kullanabilecek karakterleri.
    int i,j;//i ilk döngüm(kullaniciGirisi),j ikinci döngüm (karakterler icin)
    for(i=0;i<26;i++){
        karakterler[i]='$';// bos mu degil mi bunu sorgulamak icin.
    }
    i=0;//0a çektik.
    while(kullaniciGirisi[i]!='\0'){
        j=0;//ikinci.
        while(1){
            if(karakterler[j]=='$'){
                karakterler[j]=kullaniciGirisi[i];
                break;
            }
            else if(karakterler[j]==kullaniciGirisi[i]){
                break;
            }
            j++;
        }
        i++;
    }
    for(i=0;i<26;i++){
        if(karakterler[i]=='$'){
            break;
        }
    }
    return i;
}
