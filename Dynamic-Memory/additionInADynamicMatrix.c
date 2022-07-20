#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


void matrisOlustur(int **matris,int satir,int sutun){
    for (int i = 0; i < satir ; ++i) {
        matris[i]= (int *)malloc(sutun*sizeof (int));
    }
    for (int i = 0; i < satir; ++i) {
        for (int j = 0; j < sutun; ++j) {
            matris[i][j] = rand()%2;
        }
    }
}
void matrisYazdir(int **matris,int satir,int sutun){
    for (int i = 0; i < satir; ++i) {
        for (int j = 0; j < sutun; ++j) {
            printf("%d ",matris[i][j]);
        }
        printf("\n");

    }
}
void matrisTopla(int **matris1, int **matris2,int **sonuc,int satir,int sutun){
    for (int i = 0; i < satir; ++i) {
        for (int j = 0; j < sutun; ++j) {
            sonuc[i][j] = matris1[i][j] + matris2[i][j];
        }
    }
}
int main(){
    srand(time(NULL));
    int satir,sutun;
    printf("Satır sayısını gir:");
    scanf("%d",&satir);
    printf("\nSutun sayisi:");
    scanf("%d",&sutun);
    int **matris =(int **) malloc(satir*sizeof (int *));
    int **matris2 =(int **) malloc(satir*sizeof (int *));
    int **toplam =(int **) calloc(satir,sizeof (int *));

    matrisOlustur(matris,satir,sutun);
    matrisOlustur(matris2,satir,sutun);
    matrisOlustur(toplam,satir,sutun);
    printf("İlk Matris:\n");
    matrisYazdir(matris,satir,sutun);
    printf("İkinci Matris:\n");
    matrisYazdir(matris2,satir,sutun);
    printf("Toplam Matris:\n");
    matrisTopla(matris,matris2,toplam,satir,sutun);
    matrisYazdir(toplam,satir,sutun);
    return 0;
}
