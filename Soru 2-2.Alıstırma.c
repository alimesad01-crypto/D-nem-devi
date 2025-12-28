#include <stdio.h>

int main() {

    int satirSayi;
    int mevcutSatir;
    int mevcutSayi=1;
    int sutun;

    printf("Olusturmak istediginiz ucgen satirini giriniz:");
    scanf("%d",&satirSayi);

    for(mevcutSatir=1;mevcutSatir<=satirSayi;mevcutSatir++){
        for(sutun=1;sutun<=mevcutSatir;sutun++){
            printf("%d ",mevcutSayi);
            mevcutSayi++;
        }
        printf("\n");
    }
    return 0;
}
