#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    int saat;
    int dakika;
    double saniye;
}saatBilgileri;

saatBilgileri farkiBul(saatBilgileri ilkSaat,saatBilgileri ikinciSaat){
    saatBilgileri saatFarki;//sonuc bunda tutulacak.

    double ilkSaatDouble=ilkSaat.saat*3600+ilkSaat.dakika*60+ilkSaat.saniye;
    double ikinciSaatDouble=ikinciSaat.saat*3600+ikinciSaat.dakika*60+ikinciSaat.saniye;

    if(ilkSaatDouble>=ikinciSaatDouble){
        if(ilkSaat.saniye<ikinciSaat.saniye){
            ilkSaat.saniye+=60;
            ilkSaat.dakika-=1;
        }
        if(ilkSaat.dakika<ikinciSaat.dakika){
            ilkSaat.dakika+=60;
            ilkSaat.saat-=1;
        }
        saatFarki.saat=ilkSaat.saat-ikinciSaat.saat;
        saatFarki.dakika=ilkSaat.dakika-ikinciSaat.dakika;
        saatFarki.saniye=ilkSaat.saniye-ikinciSaat.saniye;
    }
    else{
        if(ilkSaat.saniye>ikinciSaat.saniye){
            ikinciSaat.saniye+=60;
            ikinciSaat.dakika-=1;
        }
        if(ilkSaat.dakika>ikinciSaat.dakika){
            ikinciSaat.dakika+=60;
            ikinciSaat.saat-=1;
        }
        saatFarki.saat=ikinciSaat.saat-ilkSaat.saat;
        saatFarki.dakika=ikinciSaat.dakika-ilkSaat.dakika;
        saatFarki.saniye=ikinciSaat.saniye-ilkSaat.saniye;

    }
    return saatFarki;

}


int main(){
    saatBilgileri kullaniciSaati,kullaniciSaati2;
    saatBilgileri saatFarki;

    printf("Lutfen ilk saat bilgisini saat:dakika:saniye seklinde giriniz:");
    scanf("%d:%d:%lf",&kullaniciSaati.saat,&kullaniciSaati.dakika,&kullaniciSaati.saniye);

    printf("Lutfen ikinci saat bilgisini saat:dakika:saniye seklinde giriniz:");
    scanf("%d:%d:%lf",&kullaniciSaati2.saat,&kullaniciSaati2.dakika,&kullaniciSaati2.saniye);

    saatFarki=farkiBul(kullaniciSaati,kullaniciSaati2);
    printf("%d:%d:%.2lf",saatFarki.saat,saatFarki.dakika,saatFarki.saniye);

    return 0;
}
