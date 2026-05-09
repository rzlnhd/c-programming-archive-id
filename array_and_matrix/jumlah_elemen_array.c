/* Penjumlahan elemen-elemen array */
#include <stdio.h>
#include <conio.h>
void main()
{
   void baca(int *, int);
   void dis(int *, int);
   int a[5], i, jum = 0;

   printf("Masukkan elemen-elemen ke dalam daftar \n");
   baca(a, 5); /*baca the list*/
   printf("Elemen-elemen di dalam daftar adalah \n");
   dis(a, 5);
   for (i = 0; i < 5; i++)
   {
      jum += a[i];
   }
   printf("Jumlah elemen-elemen di dalam daftar adalah %d\n", jum);
   getch();
}

void baca(int c[], int i)
{
   int j;
   for (j = 0; j < i; j++)
      scanf("%d", &c[j]);
   fflush(stdin);
}

void dis(int d[], int i)
{
   int j;
   for (j = 0; j < i; j++)
      printf("%d ", d[j]);
   printf("\n");
}
