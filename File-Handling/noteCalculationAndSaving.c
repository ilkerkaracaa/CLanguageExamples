#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char adSoyad[20],harfNotu;
    int vizeNotu,finalNotu;
    double ortalama;
}ogrenciBilgileri;
double ortalamaHesapla(int vizeNotu,int finalNotu){
    return vizeNotu*0.35+finalNotu*0.65;
}
char harfNotuHesapla(double ortalama){
    if(ortalama>=90){
        return 'A';
    }
    else if(ortalama>=80 && ortalama<90){
        return 'B';
    }
    else if(ortalama>=65 && ortalama<80){
        return 'C';
    }
    else if(ortalama>=50 && ortalama<65){
        return 'D';
    }
    else{
        return 'F';
    }
}
void sonDurumHesapla(FILE *ilkDosya,FILE *ikinciDosya){
    while(!feof(ilkDosya)){
        ogrenciBilgileri ogrenci;
        fscanf(ilkDosya,"%s %d %d",&ogrenci.adSoyad,&ogrenci.vizeNotu,&ogrenci.finalNotu);
        ogrenci.ortalama=ortalamaHesapla(ogrenci.vizeNotu,ogrenci.finalNotu);
        ogrenci.harfNotu=harfNotuHesapla(ogrenci.ortalama);
        if(ogrenci.harfNotu!='F'){
            fprintf(ikinciDosya,"%s\t\t%d\t\t%d\t\t%lf\t\t%c\t\t%s\n",ogrenci.adSoyad,ogrenci.vizeNotu,ogrenci.finalNotu,ogrenci.ortalama,ogrenci.harfNotu,"Gectiniz.");
        }
        else{
            fprintf(ikinciDosya,"%s\t\t%d\t\t%d\t\t%lf\t\t%c\t\t%s\n",ogrenci.adSoyad,ogrenci.vizeNotu,ogrenci.finalNotu,ogrenci.ortalama,ogrenci.harfNotu,"Kaldiniz.");
        }
    }

}

int main(void){

    FILE *ilkDosya=fopen("deneme.txt","r");
    FILE *ikinciDosya=fopen("deneme2.txt","w");
    if(ilkDosya==NULL || ikinciDosya==NULL){
        fprintf(stderr,"Dosyalar acilirken hata meydana geldi.");
        exit(0);
    }
    sonDurumHesapla(ilkDosya,ikinciDosya);
    printf("Hesaplama tamamlandi..");
    fclose(ilkDosya);
    fclose(ikinciDosya);
    return 0;
}
