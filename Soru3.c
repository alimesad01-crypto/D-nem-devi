#include <stdio.h>

int asalMi(int sayi);
int unluMu(char harf);

int main() {
    char harf1,harf2,harf3;
    int asciiToplam;
    int sayac=0;

    for(harf1='a';harf1<='z';harf1++){
        for(harf2='a';harf2<='z';harf2++){
        for(harf3='a';harf3<='z';harf3++){
            if(harf1==harf3){
                if(
                    unluMu(harf1)&& !unluMu(harf2)&& unluMu(harf3)||
                    !unluMu(harf1)&& unluMu(harf2)&& !unluMu(harf3)
                    ){
                        asciiToplam=harf1+harf2+harf3;

                        if(asalMi(asciiToplam)){
                            printf("%c%c%c\n",harf1,harf2,harf3);
                            sayac++;
                        }
                    }
            }

        }}}
    printf("toplam gecerli isim sayisi=%d",sayac);

    return 0;
}
int asalMi(int sayi){
    int i;

    if (sayi < 2) {
        return 0;
    }

    for (i = 2; i <= sayi / 2; i++) {
        if (sayi % i == 0) {
            return 0;
        }
    }

    return 1;
}

int unluMu(char harf){
    if(harf=='a'||harf=='e'||harf=='i'||harf=='u'||harf=='o'){
        return 1;
    }
    return 0;
}
