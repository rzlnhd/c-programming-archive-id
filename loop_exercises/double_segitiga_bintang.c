/*
  NIM     : I0714031
  Nama    : Rizal Nurhidayat
  Website : http://clever-society.blogspot.com/
  Program : Gambar Segitiga Bintang
*/
#include <stdio.h>

void main()
{
    int tinggi, kountery, kounterx, lg, alas, luas;
    printf("===============================================================================\n");
    printf("|                   Program Pembuat Double Segitiga Bintang                   |\n");
    printf("|                  Dibuat Oleh : Rizal Nurhidayat | I0714031                  |\n");
    printf("|                Website : http://clever-society.blogspot.com/                |");
    printf("\n===============================================================================\n");
lagi:
    printf("\nMasukkan Nilai Tinggi Segitiga %6s", "= ");
    scanf("%d", &tinggi);
    for (kountery = 1; kountery <= tinggi; kountery++)
    {
        for (kounterx = 1; kounterx <= kountery; kounterx++)
        {
            printf("*");
        }
        printf("\n");
    }
    for (kountery = tinggi; kountery >= 1; kountery--)
    {
        for (kounterx = 1; kounterx < kountery; kounterx++)
        {
            printf("*");
        }
        printf("\n");
    }

    printf("\n<!ATAU----------------------------------------------->\n\n");
    for (kountery = tinggi; kountery >= 1; kountery--)
    {
        for (kounterx = 1; kounterx <= kountery; kounterx++)
        {
            printf("*");
        }
        printf("\n");
    }
    for (kountery = 2; kountery <= tinggi; kountery++)
    {
        for (kounterx = 1; kounterx <= kountery; kounterx++)
        {
            printf("*");
        }
        printf("\n");
    }

    alas = (2 * tinggi - 1);
    luas = (tinggi * alas) - ((alas * tinggi) / 2);

    printf("\nNilai Alas Kedua Segitiga Diatas Adalah %3s%2d Satuan Panjang", "= ", alas);
    printf("\nNilai Luas Kedua Segitiga Diatas Adalah %3s%d Satuan Luas", "= ", luas);
    printf("\n\nMau mengulang program ini? (Y/N)   : ");
    while ((lg = getchar()) != "N")
    {
        switch (lg)
        {
        case 'Y':
        case 'y':
            goto lagi;
            break;

        case 'N':
        case 'n':
            return;
            break;

        case '\n':
        case '\t':
        case ' ':
            break;

        default:
            printf("Huruf yang dimasukkan salah.\n");
            printf("Masukkan opsi huruf baru! (Y/N) %5s", ": ");
            break;
        }
    }
}
