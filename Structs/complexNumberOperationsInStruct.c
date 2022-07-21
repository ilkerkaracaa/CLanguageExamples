#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float gercek;
    float sanal;
}karmasikSayi;

karmasikSayi sayiTopla(karmasikSayi sayi1, karmasikSayi sayi2){
    karmasikSayi sonuc;
    sonuc.gercek=sayi1.gercek+sayi2.gercek;
    sonuc.sanal=sayi1.sanal+sayi2.sanal;
    return sonuc;
}
int main(){
    karmasikSayi sayi1,sayi2,sonuc;
    printf("Lütfen gercek ve sanal sayıları girin:");
    scanf("%f",&sayi1.gercek);
    scanf("%f",&sayi1.sanal);
    printf("Lütfen gercek ve sanal sayıları girin:");
    scanf("%f",&sayi2.gercek);
    scanf("%f",&sayi2.sanal);
    sonuc=sayiTopla(sayi1,sayi2);
    printf("Sonuc:%.1f+%1.fi",sonuc.gercek,sonuc.sanal);
    return 0;
}
