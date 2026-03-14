#include <stdio.h>
#include <stdlib.h>

int main() {
    int jumlahData;
    int *stokBarang;
    int kategoriTarget;
    int totalStokKategori = 0;

    if (scanf("%d", &jumlahData) != 1) {
        return 0;
    }

    stokBarang = (int *)malloc(jumlahData * sizeof(int));
    if (stokBarang == NULL) {
        return 1;
    }

    for (int i = 0; i < jumlahData; i++) {
        scanf("%d", &stokBarang[i]);
    }

    scanf("%d", &kategoriTarget);

    /* Berdasarkan pola rak gudang (umumnya pemisahan kelompok/kategori 
       ditentukan oleh indeks atau nilai tertentu), program ini menjumlahkan 
       stok yang sesuai dengan kategori yang diinputkan.
    */
    for (int i = 0; i < jumlahData; i++) {
        if (stokBarang[i] == kategoriTarget) {
            totalStokKategori += stokBarang[i];
        } else if (i + 1 == kategoriTarget) {
            /* Alternatif jika kategori merujuk pada urutan/posisi rak */
            totalStokKategori = stokBarang[i];
            break;
        }
    }

    printf("%d\n", totalStokKategori);

    free(stokBarang);
    return 0;
}