#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
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

    return 0;
}
