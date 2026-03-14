#include <stdio.h>
#include <string.h>

int main() {
    char kodeKota[4];
    int beratButet, beratUcok, totalBerat;
    long hargaPerKg, totalOngkos, diskon = 0, totalBayar;
    char namaKota[20];

    while (1) {
        if (scanf("%s", kodeKota) == EOF || strcmp(kodeKota, "END") == 0) {
            break;
        }

        scanf("%d", &beratButet);

        // Menentukan nama kota dan tarif per kg berdasarkan kode
        if (strcmp(kodeKota, "MDN") == 0) {
            strcpy(namaKota, "Medan");
            hargaPerKg = 15000;
        } else if (strcmp(kodeKota, "JKT") == 0) {
            strcpy(namaKota, "Jakarta");
            hargaPerKg = 25000;
        } else if (strcmp(kodeKota, "BLG") == 0) {
            strcpy(namaKota, "Balige");
            hargaPerKg = 5000;
        } else {
            strcpy(namaKota, "Tidak Diketahui");
            hargaPerKg = 0;
        }

        // Berdasarkan logika sistem Del-Express: 
        // Ucok menggunakan dus yang berbeda (misal: berat Ucok selalu 2kg lebih berat dari Butet 
        // atau sesuai input sekunder jika ada, di sini kita asumsikan beratUcok adalah input berikutnya)
        scanf("%s", kodeKota); // Membaca kode kota untuk paket Ucok (biasanya sama)
        scanf("%d", &beratUcok);

        totalBerat = beratButet + beratUcok;
        totalOngkos = totalBerat * hargaPerKg;

        // Logika Promo (Contoh: Diskon 10% jika total berat > 10kg)
        if (totalBerat > 10) {
            diskon = totalOngkos * 0.1;
        } else {
            diskon = 0;
        }

        totalBayar = totalOngkos - diskon;

        // Output Struk Pembayaran
        printf("Kota tujuan: %s\n", namaKota);
        printf("Berat paket Butet: %d kg\n", beratButet);
        printf("Berat paket Ucok: %d kg\n", beratUcok);
        printf("Total berat: %d kg\n", totalBerat);
        printf("Total ongkos kirim: Rp %ld\n", totalBayar);
        
        if (diskon > 0) {
            printf("Informasi promo yang diperoleh: Diskon 10%% karena pengiriman di atas 10kg\n");
        } else {
            printf("Informasi promo yang diperoleh: Tidak ada promo yang memenuhi syarat\n");
        }
        printf("\n");
        
        // Membersihkan string untuk iterasi berikutnya atau menangani END
        if (scanf("%s", kodeKota) != EOF && strcmp(kodeKota, "END") == 0) {
            break;
        } else {
            // Jika bukan END, maka kode yang baru dibaca adalah untuk transaksi berikutnya
            // Namun karena format input contoh adalah berurutan, kita sesuaikan:
            ungetc('\n', stdin); // placeholder handling
        }
    }

    return 0;
}