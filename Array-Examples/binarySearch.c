#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    
    //Select Sort Algorithm
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
//Binary Search
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

    return 0;
}
