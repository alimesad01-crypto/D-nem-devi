#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int ciro[12];
    int ay;
    int seviye;
    int enYuksekCiro = 0;

    srand(time(NULL));

    for (ay = 0; ay < 12; ay++) {
        ciro[ay] = rand() % 10 + 1;
    }

    for (ay = 0; ay < 12; ay++) {
        if (ciro[ay] > enYuksekCiro) {
            enYuksekCiro = ciro[ay];
        }
    }

    printf("DIKEY BAR GRAFIGI (Max: %dK)\n\n", enYuksekCiro);

    for (seviye = enYuksekCiro; seviye >= 1; seviye--) {

        for (ay = 0; ay < 12; ay++) {
            if (ciro[ay] >= seviye) {
                printf(" * ");
            } else {
                printf("   ");
            }
        }

        printf("\n");
    }

    for (ay = 0; ay < 12; ay++) {
        printf("---");
    }
    printf("\n");

    for (ay = 0; ay < 12; ay++) {
        printf("%2d ", ay + 1);
    }

    printf("\n");

    return 0;
}
