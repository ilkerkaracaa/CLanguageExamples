#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//Function Signatures
void diziyiDoldur(int [][5] ,int ,int );
void diziyiYazdir(int [][5] ,int ,int );
int diagonalCarpimi(int [][5] ,int ,int );
int sagdanDiagonalCarpimi(int [][5] ,int ,int );
void satirSutunToplami(int [][5] ,int ,int );

int main(){
    int satirSayisi=5,sutunSayisi=5;
    int dizi[satirSayisi][sutunSayisi];
    diziyiDoldur(dizi,satirSayisi,sutunSayisi);
    diziyiYazdir(dizi,satirSayisi,sutunSayisi);
    printf("Diagonel çarpımları:%d\n", diagonalCarpimi(dizi,satirSayisi,sutunSayisi));
    int sonuc = sagdanDiagonalCarpimi(dizi,satirSayisi,sutunSayisi);
    if (sonuc){
        printf("\nSağdan ve soldan diagonal carpımı eşittir.");
    }
    else{
        printf("\nSağdan ve soldan diagonal carpımı eşit değildir.");
    }
    satirSutunToplami(dizi,satirSayisi,sutunSayisi);
}
void diziyiDoldur(int fonkDizi[][5],int satirSayisi,int sutunSayisi){
    int i,j;
    srand(time(NULL));
    for(i=0;i<satirSayisi;i++){
        for(j=0;j<sutunSayisi;j++){
            fonkDizi[i][j]=rand()%5+1;
        }
    }
}
void diziyiYazdir(int fonkDizi[][5],int satirSayisi,int sutunSayisi){
    int i,j;
    for(i=0;i<satirSayisi;i++){
        for(j=0;j<sutunSayisi;j++){
            printf("%d ",fonkDizi[i][j]);
        }
        printf("\n");
    }
}
int diagonalCarpimi(int fonkDizi[][5],int satirSayisi,int sutunSayisi){
    int i,j;
    int carpimSonucu=1;
    for(i=0;i<satirSayisi;i++){
        for(j=0;j<sutunSayisi;j++){
            if(i==j){
                carpimSonucu*=fonkDizi[i][j];
            }
        }
    }
    return carpimSonucu;
}
int sagdanDiagonalCarpimi(int fonkDizi[][5],int satirSayisi,int sutunSayisi){
    int i,j;
    int carpimSonucu=1;
    for(i=0;i<satirSayisi;i++){
        for(j=0;j<sutunSayisi;j++){
            if(i+j==satirSayisi-1){
                carpimSonucu*=fonkDizi[i][j];
            }
        }
    }
    printf("Sagdan diagonal carpimi:%d",carpimSonucu);
    if(carpimSonucu==diagonalCarpimi(fonkDizi,satirSayisi,sutunSayisi)){
        return 1;
    }
    else{
        return 0;
    }
}
void satirSutunToplami(int fonkDizi[][5],int satirSayisi,int sutunSayisi){
    int i,j;
    for(i=0;i<satirSayisi;i++){
        int satirToplam=0;
        int sutunToplam=0;
        for(j=0;j<sutunSayisi;j++){
            satirToplam+=fonkDizi[i][j];
            sutunToplam+=fonkDizi[j][i];//sutun toplamina eristik.
        }
        printf("\n%d.satirin toplami:%d",i+1,satirToplam);
        printf("\n%d.sutunun toplami:%d",i+1,sutunToplam);
    }
}
