/* Program untuk tumpukan */
#include <stdio.h>
#define MAKS 10 /* The maximum size of the tumpukan */
#include <stdlib.h>

void tempatkanpadaTumpukan(int tumpukan[], int *atas, int nilai)
{
   if (*atas < MAKS)
   {
      *atas = *atas + 1;
      tumpukan[*atas] = nilai;
   }
   else
   {
      printf("Tumpukan penuh, tidak bisa menempatkan nilai pada tumpukan\n");
      exit(0);
   }
}

void ambilDariTumpukan(int tumpukan[], int *atas, int *nilai)
{
   if (*atas >= 0)
   {
      *nilai = tumpukan[*atas];
      *atas = *atas - 1;
   }
   else
   {
      printf("Tumpukan kosong, tidak bisa mengambil nilai dari tumpukan\n");
      exit(0);
   }
}

void main()
{
   int tumpukan[MAKS];
   int atas = -1;
   int n, nilai;
   do
   {
      do
      {
         printf("Masukkan elemen pada tumpukan:\n");
         scanf("%d", &nilai);
         tempatkanpadaTumpukan(tumpukan, &atas, nilai);
         printf("Masukkan 1 untuk lanjut\n");
         scanf("%d", &n);
      } while (n == 1);

      printf("Masukkan 1 untuk mengambil elemen dari tumpukan\n");
      scanf("%d", &n);
      while (n == 1)
      {
         ambilDariTumpukan(tumpukan, &atas, &nilai);
         printf("Nilai yang diambil dari tumpukan adalah %d\n", nilai);
         printf("Masukkan 1 untuk mengambil elemen dari tumpukan\n");
         scanf("%d", &n);
      }
      printf("Masukkan 1 untuk lanjut\n");
      scanf("%d", &n);
   } while (n == 1);
}
