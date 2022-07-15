#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int toplama(int sayi1,int sayi2){
    return sayi1+sayi2;
}
int carpma(int sayi1,int sayi2){
    return sayi1*sayi2;
}
int bolme(int sayi1,int sayi2){
    return sayi1/sayi2;
}
int cikarma(int sayi1,int sayi2){
    return sayi1-sayi2;
}
int hesapla(int(*ptr[4])(int,int),int sayi1,int sayi2,int islem){

    if(islem==1){
        (*ptr[0])(sayi1,sayi2);
    }
    else if(islem==2){
        (*ptr[1])(sayi1,sayi2);
    }
    else if(islem==3){
        (*ptr[2])(sayi1,sayi2);
    }
    else if(islem==4){
        (*ptr[3])(sayi1,sayi2);
    } else{
        printf("Yanlış giriş yaptınız!");
    }

}
int main(){
    int sayi1,sayi2;
    int islem;
    int(*ptr[4])(int,int);
    ptr[0]=toplama;
    ptr[1]=cikarma;
    ptr[2]=carpma;
    ptr[3]=bolme;
    printf("Lutfen iki adet sayi giriniz:");
    scanf("%d",&sayi1);
    scanf("%d",&sayi2);
    printf("Lutfen yapmak istediginiz islemi seciniz (Toplama icin 1, Cikarma icin 2, Carpma icin 3, Bolme icin 4):");
    scanf("%d",&islem);
    printf("Sonuc:%d",hesapla(ptr,sayi1,sayi2,islem));
    return 0;
}
