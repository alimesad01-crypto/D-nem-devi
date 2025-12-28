#include <stdio.h>


void sifrelemeYap(char metin[], int anahtar);
void cozmeYap(char metin[], int anahtar);

int main() {
    char mesaj[100];
    int kaydirmaSayisi;
    int i;

    // --- SIFRELEME KISMI ---
    printf("Sifrelemek istediginiz mesaji girin: ");
    // Bosluklu cumle alabilmek icin fgets kullandim
    fgets(mesaj, 100, stdin);

    // fgets enter tusunu da aliyor, onu silmek icin dongu kurdum
    for(i = 0; i < 100; i++) {
        if(mesaj[i] == '\n') {
            mesaj[i] = '\0'; // Satir sonunu bitir
            break;
        }
    }

    printf("Anahtar degeri girin: ");
    scanf("%d", &kaydirmaSayisi);

    // Klavyedeki enter tusunu bosa cikarmak icin
    getchar();

    sifrelemeYap(mesaj, kaydirmaSayisi);
    printf("Sifrelenmis Mesaj: %s\n", mesaj);

    // --- COZME KISMI ---
    printf("\nCozmek istediginiz mesaji girin: ");
    fgets(mesaj, 100, stdin);

    // Yine enter karakterini temizleme islemi
    for(i = 0; i < 100; i++) {
        if(mesaj[i] == '\n') {
            mesaj[i] = '\0';
            break;
        }
    }

    printf("Anahtar degeri girin: ");
    scanf("%d", &kaydirmaSayisi);

    cozmeYap(mesaj, kaydirmaSayisi);
    printf("Cozulmus Mesaj: %s\n", mesaj);

    return 0;
}

void sifrelemeYap(char metin[], int anahtar) {
    int i;
    // Metnin sonuna gelene kadar tek tek bak
    for(i = 0; metin[i] != '\0'; i++) {

        // Kucuk harf ise
        if(metin[i] >= 'a' && metin[i] <= 'z') {
            metin[i] = (metin[i] - 'a' + anahtar) % 26 + 'a';
        }
        // Buyuk harf ise
        else if(metin[i] >= 'A' && metin[i] <= 'Z') {
            metin[i] = (metin[i] - 'A' + anahtar) % 26 + 'A';
        }
    }
}

void cozmeYap(char metin[], int anahtar) {
    int i;
    int gercekAnahtar = anahtar % 26; // 26 harf oldugu icin modu alinir

    for(i = 0; metin[i] != '\0'; i++) {
        // Kucuk harf cozumu
        if(metin[i] >= 'a' && metin[i] <= 'z') {
            // Geriye dogru sayma islemi
            metin[i] = (metin[i] - 'a' - gercekAnahtar + 26) % 26 + 'a';
        }
        // Buyuk harf cozumu
        else if(metin[i] >= 'A' && metin[i] <= 'Z') {
            metin[i] = (metin[i] - 'A' - gercekAnahtar + 26) % 26 + 'A';
        }
    }
}
