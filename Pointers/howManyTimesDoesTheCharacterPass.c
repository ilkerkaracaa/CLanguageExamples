#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int karakterSorgula(char *arr, char karakter){
    int sayac=0;
    char *ptr;
    ptr = arr;
    while (*ptr){//pointer içindeki veri '\0' array sonuna gelirse döngüden çıkar
        if (*ptr == karakter){
            sayac++;
        }
        ptr++;
    }
    return sayac;
}
int main(){
    printf("Bir string girin:\n");
    char arr[30];
    fgets(arr,30,stdin);
    printf("Sorgulanacak karakteri girin:");
    char karakter;
    scanf("%c",&karakter);
    printf("String içinde %c karakteri %d defa geçiyor!",karakter,karakterSorgula(arr,karakter));

}
