#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 10

void diziyiDoldur(int *dizi){
    srand(time(NULL));
    int *ptr;
    for(ptr=dizi;ptr<dizi+N;ptr++){
        *ptr=rand()%100;
    }
}
void diziyiYazdir(int *dizi){
    printf("Dizi:");
    int *ptr;
    for(ptr=dizi;ptr<=dizi+N-1;ptr++){
        printf("%d ",*ptr);
    }
}
void diziyiTerstenYazdir(int *dizi){
    printf("\nDizinin tersten hali:");
    int *ptr=dizi+N-1;
    for(;ptr>=dizi;ptr--){
        printf("%d ",*ptr);
    }

}
int main() {
    int arr[N];
    diziyiDoldur(arr);
    diziyiYazdir(arr);
    diziyiTerstenYazdir(arr);
    return 0;
}
