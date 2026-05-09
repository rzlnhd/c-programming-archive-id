/* Program untuk mensimulasikan antrian sirkular */
#include <stdio.h>
#define MAKS 10 /* Ukuran maksimum dari antrian */
#include <stdlib.h>

void sisip(int antrian[], int *belakang, int depan, int nilai)
{
   *belakang = (*belakang + 1) % MAKS;
   if (*belakang == depan)
   {
      printf("Antrian penuh, nilai tidak bisa disisipkan\n");
      exit(0);
   }
   antrian[*belakang] = nilai;
}

void hapus(int antrian[], int *depan, int belakang, int *nilai)
{
   if (*depan == belakang)
   {
      printf("Antrian kosong, nilai tidak bisa dihapus\n");
      exit(0);
   }
   *depan = (*depan + 1) % MAKS;
   *nilai = antrian[*depan];
}

void main()
{
   int antrian[MAKS];
   int depan, belakang;
   int n, nilai;
   depan = 0;
   belakang = 0;
   do
   {
      do
      {
         printf("Masukkan elemen yang akan disisipkan\n");
         scanf("%d", &nilai);
         sisip(antrian, &belakang, depan, nilai);
         printf("Masukkan 1 untuk lanjut\n");
         scanf("%d", &n);
      } while (n == 1);

      printf("Masukkan 1 untuk menghapus suatu elemen\n");
      scanf("%d", &n);
      while (n == 1)
      {
         hapus(antrian, &depan, belakang, &nilai);
         printf("Nilai yang dihapus adalah %d\n", nilai);
         printf("Masukkan 1 untuk menghapus suatu elemen\n");
         scanf("%d", &n);
      }
      printf("Masukkan 1 untuk lanjut\n");
      scanf("%d", &n);
   } while (n == 1);
}
