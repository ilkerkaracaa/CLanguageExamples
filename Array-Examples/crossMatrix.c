#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
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
//Çarpım Matrisi
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
  return 0;
}
