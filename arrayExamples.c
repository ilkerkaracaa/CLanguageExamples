#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;
int main() {

}
    /*
    //Seçerek Sıralama Algoritması
    srand(time(NULL));
    int arr[10];
    for (int i = 0; i < 10; ++i) {
        arr[i]=rand()%20;
    }
    printf("Dizi:\n");
    for (int i = 0; i < 10; ++i) {
        printf("%d ",arr[i]);
    }
    int tutucu;
    for (int i = 0; i < 10; ++i) {
        for (int j = i+1; j < 10; ++j) {
            if (arr[i]>arr[j]){
                tutucu = arr[i];
                arr[i] = arr[j];
                arr[j] = tutucu;
            }
        }
    }
    printf("\nSıralanmış Hali:\n");
    for (int i = 0; i < 10; ++i) {
        printf("%d ",arr[i]);
    }
    //İkili Arama
    int ortanca,sol,sag,sayi,bulunduMu=0;
    printf("\nlütfen aramak istediğiniz sayıyı girin:");
    scanf("%d",&sayi);
    sol = 0;//indexler
    sag = 9;
    while (sol<=sag){
        ortanca = (sol+sag)/2;
        if (sayi==arr[ortanca]){
            bulunduMu = 1;
            break;
        }
        else if(sayi>arr[ortanca]){
            sol = ortanca+1;
        }
        else{
            sag = ortanca-1;
        }
    }
    if (bulunduMu){
        printf("%d sayısı dizide var",sayi);
    }
    else{
        printf("%d sayısı dizide yok",sayi);
    }
}
    /*
    //Matrisin simetrik olduğunu tespit ediyor.
    int arr[3][3]={{1,2,4,},{2,0,5,},{4,5,8}};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    int sayac=0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i==j){
                continue;
            }
            if (arr[i][j]==arr[j][i]){
                sayac++;
            }
        }
    }
    if (sayac==6){
        printf("Matris simetrik");
    }else{
        printf("Matris simetrik değil");
    }
}
    /*
    srand(time(NULL));
    int arr[10];
    for (int i = 0; i < 10; ++i) {
        arr[i] = rand()%30+1;
    }
    for (int i = 0; i < 10; ++i) {
        printf("%d ",arr[i]);
    }
    printf("\n-----------------------\n");
    int satır,sutun;
    printf("Lütfen satır ve sütun sayısını giriniz:");
    scanf("%d%d",&satır,&sutun);
    int sayac=0;
    for (int i = 0; i < satır; ++i) {
        for (int j = 0; j < sutun; ++j) {
            printf("%d \t",arr[sayac]);
            sayac++;
        }
        printf("\n");
    }
}
    */
    /*
    int arr[3][3];
    int arr2[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            arr[i][j]=rand()%10+1;
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            arr2[i][j]=rand()%10+1;
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    printf("------------------------------------------\n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d\t",arr2[i][j]);
        }
        printf("\n");
    }
    int carpim;
    int carpimDizi[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            carpim = 0;
            for (int k = 0; k < 3; ++k) {
                carpim += arr[i][k] * arr2[k][j];
            }
            carpimDizi[i][j] = carpim;
        }
    }
    printf("----------CARPIM MATRİS ------------\n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d\t",carpimDizi[i][j]);
        }
        printf("\n");
    }
     */

