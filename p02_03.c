#include <stdio.h>
#include <string.h>

int main() {
    int jumlahBarang;
    
    printf("Masukkan jumlah data barang: ");
    scanf("%d", &jumlahBarang);

    char nama[100][50];
    char kategori[100][50];
    int stok[100];

    int i;

    for(i = 0; i < jumlahBarang; i++) {
        printf("Nama barang ke-%d: ", i + 1);
        scanf("%s", nama[i]);

        printf("Kategori barang ke-%d: ", i + 1);
        scanf("%s", kategori[i]);

        printf("Stok barang ke-%d: ", i + 1);
        scanf("%d", &stok[i]);
    }

    char kategoriDicari[50];
    int totalStok = 0;

    printf("Masukkan kategori yang ingin dihitung total stoknya: ");
    scanf("%s", kategoriDicari);

    for(i = 0; i < jumlahBarang; i++) {
        if(strcmp(kategori[i], kategoriDicari) == 0) {
            totalStok += stok[i];
        }
    }

    printf("Total stok untuk kategori %s adalah %d\n", kategoriDicari, totalStok);

    return 0;
}