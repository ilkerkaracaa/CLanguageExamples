#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    //Selective Sort Algorithm
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
  return 0;
}
