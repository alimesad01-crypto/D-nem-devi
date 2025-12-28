#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int ciro[12];
    int ay;
    int enYuksekCiro=0;
    int yildiz;

    srand(time(NULL));
    for(ay=0;ay<12;ay++){
        ciro[ay]=rand()%10+1;
    }

    for(ay=0;ay<12;ay++){
        if(enYuksekCiro<ciro[ay]){
            enYuksekCiro=ciro[ay];
        }
    }

    printf("YATAY BAR GRAFIGI: Max ciro= %d\n",enYuksekCiro);

    for(ay=0;ay<12;ay++){
        printf("Ay %2d:",ay+1);
        for(yildiz=0;yildiz<ciro[ay];yildiz++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
