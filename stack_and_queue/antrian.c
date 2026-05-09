#include <stdio.h>
/* Program untuk mensimulasikan antrian */
#define MAKS 10 /* Ukuran maksimum antrian */
#include <stdlib.h>

void sisip(int antrian[], int *belakang, int nilai)
{
   if (*belakang < MAKS - 1)
   {
      *belakang = *belakang + 1;
      antrian[*belakang] = nilai;
   }
   else
   {
      printf("Antrian penuh, tidak bisa menyisipkan suatu nilai\n");
      exit(0);
   }
}

void hapus(int antrian[], int *depan, int belakang, int *nilai)
{
   if (*depan == belakang)
   {
      printf("Antrian kosong, tidak bisa menghapus suatu nilai\n");
      exit(0);
   }
   *depan = *depan + 1;
   *nilai = antrian[*depan];
}

void main()
{
   int antrian[MAKS];
   int depan, belakang;
   int n, nilai;
   depan = belakang = (-1);
   do
   {
      do
      {
         printf("Masukkan elemen yang akan disisipkan\n");
         scanf("%d", &nilai);
         sisip(antrian, &belakang, nilai);
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
