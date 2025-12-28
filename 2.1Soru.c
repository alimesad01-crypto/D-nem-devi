#include <stdio.h>

int ucgenSayiHesapla(int siraNo);

int main() {

    int istenenAdet;
    int mevcutSira;

    printf("kac tane ucgen sayi yazdirilsin: ");
    scanf("%d",&istenenAdet);

    for(mevcutSira=1;mevcutSira<=istenenAdet;mevcutSira++){
        printf("%d ", ucgenSayiHesapla(mevcutSira));
    }

    return 0;
}

int ucgenSayiHesapla(int siraNo){
    if(siraNo==1){
        return 1;
    }
    return ucgenSayiHesapla(siraNo-1)+siraNo;
}
