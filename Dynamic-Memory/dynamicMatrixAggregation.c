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
    int **matris=(int **) calloc(satir,sizeof (int *));
    int **matris2=(int **) calloc(satir,sizeof (int *));
    int **cikarma=(int **) calloc(satir,sizeof (int *));
    for (int i = 0; i < satir; ++i) {
        matris[i]=(int *) calloc(sutun,sizeof (int ));
        matris2[i]=(int *) calloc(sutun,sizeof (int ));
        cikarma[i]=(int *) calloc(sutun,sizeof (int ));
    }
    for (int i = 0; i < satir; ++i) {
        for (int j = 0; j < sutun; ++j) {
            matris[i][j]=rand()%10;
            matris2[i][j]=rand()%10;
        }
    }
    for (int i = 0; i < satir; ++i) {
        for (int j = 0; j < sutun; ++j) {
            printf("%d ",matris[i][j]);
        }
        printf("\n");
    }
    printf("--------------\n");
    for (int i = 0; i < satir; ++i) {
        for (int j = 0; j < sutun; ++j) {
            printf("%d ",matris2[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < satir; ++i) {
        for (int j = 0; j < sutun; ++j) {
            matris2[i][j]*=-1;
        }
    }
    for (int i = 0; i < satir; ++i) {
        for (int j = 0; j < sutun; ++j) {
            cikarma[i][j]=matris[i][j]+matris2[i][j];
        }
    }
    printf("Toplama\n");
    for (int i = 0; i < satir; ++i) {
        for (int j = 0; j < sutun; ++j) {
            printf("%d ",cikarma[i][j]);
        }
        printf("\n");
    }
}
