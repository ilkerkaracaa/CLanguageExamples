#include <stdio.h>

//Recursive Functions
int obebiBul(int , int);
int okekiBul(int , int);
int main(){
    printf("Obebi ve Okeki bulunacak iki sayıyı girin:");
    int a,b;
    scanf("%d%d",&a,&b);
    printf("Obebi:%d\n", obebiBul(a,b));
    printf("Okeki:%d", okekiBul(a,b));
    return 0;
}

int obebiBul(int a, int b){
    if(b==0){
        return a;
    }
    return obebiBul(b,a%b);
}
int okekiBul(int a, int b){
    return a*b/ obebiBul(a,b);
}
