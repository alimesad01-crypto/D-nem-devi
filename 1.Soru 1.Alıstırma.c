#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    int ciro[12],ay;
    for(ay=0;ay<12;ay++){
        ciro[ay]=rand()%10+1;
    }
    printf("AYLIK CIRO VERILERI:\n");
    for(ay=0;ay<12;ay++){
        printf("Ay %d: %d \n",ay+1,ciro[ay]);
    }
    return 0;
}
