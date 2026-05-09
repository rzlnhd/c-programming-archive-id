/*
  NIM     : I0714031
  Nama    : Rizal Nurhidayat
  Website : https://tiraini.blogspot.com/
  Program : Konverter dari desimal ke biner
*/
#include <stdio.h>
#include <stdlib.h>
void caribiner(short int x)
{
    short int j, hasil, i = 12, bin[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    while (x > 0)
    {
        hasil = x % 2;
        x = (x - hasil) / 2;
        i--;
        bin[i] = hasil;
    }
    printf("Nilai Biner dari %d Adalah \t\t%s", x, "= ");
    for (j = 0; j <= 11; j++)
    {
        printf("%d", bin[j]);
        if ((j + 1) % 4 == 0)
        {
            printf(" ");
        }
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    short int x;
    int lg;
    printf("===============================================================================\n");
    printf("|                  Program Converter Desimal ke Biner 12 bit                  |\n");
    printf("|                  Dibuat Oleh : Rizal Nurhidayat | I0714031                  |\n");
    printf("|                   Website : https://tiraini.blogspot.com/                   |");
    printf("\n===============================================================================\n");
ulang:
    printf("\nMasukkan Nilai Desimal x Dibawah 4096\t%s", "= ");
    scanf("%d", &x);
    if (x < 0)
    {
        printf("\n-------------------------------------------------------------------------------\n");
        printf("|                               Critical Error!                               |\n");
        printf("|        Bilangan Desimal Negatif Tidak Bisa Dikonversi di Program Ini        |\n");
        printf("|                    Mohon Masukkan Nilai Desimal Kembali!                    |\n");
        printf("-------------------------------------------------------------------------------\n");
        goto ulang;
    }
    if (x > 4095)
    {
        printf("\n-------------------------------------------------------------------------------\n");
        printf("| Critical Error!! Program Tidak Bisa Mengkonversi Bilangan Desimal Tersebut! |\n");
        printf("|        Program Hanya Bisa Mengkonversi Bilangan Desimal Dibawah 4096        |\n");
        printf("|                    Mohon Masukkan Nilai Desimal Kembali!                    |\n");
        printf("-------------------------------------------------------------------------------\n");
        goto ulang;
    }
    caribiner(x);
    printf("\nMau mengulang program ini? (Y/N)   : ");
    while ((lg = getchar()) != "N")
    {
        switch (lg)
        {
        case 'Y':
        case 'y':
            goto ulang;
            break;

        case 'N':
        case 'n':
            return (0);
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
