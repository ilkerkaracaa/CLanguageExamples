
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int satir,sutun;
    printf("Satır sayisini girin:");
    scanf("%d",&satir);
    printf("Sutun sayisini girin:");
    scanf("%d",&sutun);
    int **matris=(int**) calloc(satir,sizeof (int *));
    for (int i = 0; i < satir; ++i) {
        matris[i]=(int *) calloc(sutun,sizeof (int ));
    }
    for (int i = 0; i < satir; ++i) {
        for (int j = 0; j < sutun; ++j) {
            printf("Matris elemanlarını girin:");
            int sayi;
            scanf("%d",&sayi);
            matris[i][j]=sayi;
        }
    }
    for (int i = 0; i < satir; ++i) {
        for (int j = 0; j < sutun; ++j) {
            printf("%d ",matris[i][j]);
        }
        printf("\n");
    }
    int simetrikMi=1;
    for (int i = 0; i < satir; ++i) {
        for (int j = 0; j < sutun; ++j) {
            if (matris[i][j]!=matris[j][i]){
                simetrikMi = 0;
            }
        }
    }
    if (simetrikMi){
        printf("Simetrik");
    }else
    {
        printf("Simetrik Değil");
    }
    return 0;
}
