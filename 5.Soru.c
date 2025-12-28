#include <stdio.h>

#define BOYUT 5

// Prototipler
int yolBul(int harita[BOYUT][BOYUT], int satir, int sutun, int sonuc[BOYUT][BOYUT]);
void matrisiYazdir(int dizi[BOYUT][BOYUT]);

int main() {
    // 1: Yol, 0: Duvar
    int labirent[BOYUT][BOYUT] = {
        {1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 1, 1, 1},
        {1, 1, 1, 0, 1}
    };

    // Cozum yolunu tutacak bos dizi (basta hepsi 0)
    int cozum[BOYUT][BOYUT] = {0};

    // Fonksiyonu (0,0) noktasindan baslatiyoruz
    if (yolBul(labirent, 0, 0, cozum) == 1) {
        printf("Cikis yolu bulundu:\n");
        matrisiYazdir(cozum);
    } else {
        printf("Maalesef cikis yolu bulunamadi.\n");
    }

    return 0;
}

// Recursive (Ozyinelemeli) Fonksiyon
int yolBul(int harita[BOYUT][BOYUT], int satir, int sutun, int sonuc[BOYUT][BOYUT]) {

    // Cikis noktasina (4,4) geldik mi?
    if (satir == 4 && sutun == 4) {
        sonuc[satir][sutun] = 1;
        return 1; // Basarili
    }

    // Sinirlarin icinde miyiz? Duvar degil mi? Daha once gectik mi?
    if (satir >= 0 && satir < 5 && sutun >= 0 && sutun < 5 && harita[satir][sutun] == 1 && sonuc[satir][sutun] == 0) {

        // Burayi yol olarak isaretle
        sonuc[satir][sutun] = 1;

        // Sirayla yonleri deniyoruz

        // 1. Asagi gitmeyi dene
        if (yolBul(harita, satir + 1, sutun, sonuc) == 1) return 1;

        // 2. Saga gitmeyi dene
        if (yolBul(harita, satir, sutun + 1, sonuc) == 1) return 1;

        // 3. Yukari gitmeyi dene
        if (yolBul(harita, satir - 1, sutun, sonuc) == 1) return 1;

        // 4. Sola gitmeyi dene
        if (yolBul(harita, satir, sutun - 1, sonuc) == 1) return 1;

        // Hicbir yere gidilemiyorsa burayi iptal et (Geri izleme)
        sonuc[satir][sutun] = 0;
        return 0;
    }

    return 0;
}

void matrisiYazdir(int dizi[BOYUT][BOYUT]) {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d", dizi[i][j]);
        }
        printf("\n");
    }
}
