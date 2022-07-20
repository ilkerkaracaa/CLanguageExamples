#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void diziyiDoldur(int *dizi,int elemanSayisi){
    int *ptr;//baslangic adresinden sona kadar gidecek.
    srand(time(NULL));
    for(ptr=dizi;ptr<dizi+elemanSayisi;ptr++){
        *ptr=rand()%100;
    }
}
void diziyiYazdir(int *dizi,int elemanSayisi){
    int *ptr;//baslangic adresinden sona kadar gidecek.
    for(ptr=dizi;ptr<dizi+elemanSayisi;ptr++){
        printf("%d ",*ptr);
    }
    printf("\n");
}
void arayaSokma(int *dizi,int elemanSayisi){

    int *ptr,*ptr2,arayaSokulacakEleman;
    for(ptr=dizi+1;ptr<dizi+elemanSayisi;ptr++){
        arayaSokulacakEleman=*ptr;
        for(ptr2=ptr-1;ptr2>=dizi && arayaSokulacakEleman <=*ptr2;ptr2--){
            *(ptr2+1)=*ptr2;
        }
        *(ptr2+1)=arayaSokulacakEleman;
    }
}
int ardisilArama(int *dizi,int elemanSayisi,int arananSayi){
    int *ptr;
    for(ptr=dizi;ptr<dizi+elemanSayisi;ptr++){
        if(*ptr==arananSayi){
            return 1;
        }
    }
    return 0;
}
int main(){
    int elemanSayisi;
    int arananSayi;
    printf("Lutfen dizinin eleman sayisini giriniz:");
    scanf("%d",&elemanSayisi);
    int *dizi=(int*)malloc(sizeof(int)*elemanSayisi);//DİNAMİK TEK BOYUTLU DİZİ OLUŞTURMA.
    printf("Sirasiz Hali:");
    diziyiDoldur(dizi,elemanSayisi);
    diziyiYazdir(dizi,elemanSayisi);
    arayaSokma(dizi,elemanSayisi);
    printf("Sirali Hali:");
    diziyiYazdir(dizi,elemanSayisi);
    printf("Aramak istediginiz degeri giriniz:");
    scanf("%d",&arananSayi);
    if(ardisilArama(dizi,elemanSayisi,arananSayi)){
        printf("%d degeri dizide bulundu.",arananSayi);
    }
    else{
        printf("%d degeri dizide bulunamadı.",arananSayi);
    }

    free(dizi);//serbest biraktik

    return 0;
}
