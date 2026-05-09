/* Membalikkan isi array */
#include <stdio.h>
#include <conio.h>
void main()
{
   void baca(int *, int);
   void dis(int *, int);
   void balik(int *, int *, int);
   int a[5], b[5];
   baca(a, 5);
   dis(a, 5);
   balik(a, b, 5);
   dis(b, 5);
   getch();
}

void baca(int c[], int i)
{
   int j;
   printf("Masukkan array \n");
   for (j = 0; j < i; j++)
      scanf("%d", &c[j]);
   fflush(stdin);
}
void dis(int d[], int i)
{
   int j;
   printf("Array adalah \n");
   for (j = 0; j < i; j++)
      printf("%d ", d[j]);
   printf("\n");
}
void balik(int a[], int balik_b[], int j)
{
   int i, k;
   k = j - 1;
   for (i = 0; i < j; i++)
   {
      balik_b[i] = a[k];
      k--;
   }
}
