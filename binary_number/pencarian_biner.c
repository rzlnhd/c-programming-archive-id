/* Pencarian Biner */
#include <stdio.h>
#define MAKS 10

void pencarianBiner(int list[], int n, int elemen)
{
   int l, u, m, flag = 0;
   l = 0;
   u = n - 1;
   while (l <= u)
   {
      m = (l + u) / 2;
      if (list[m] == elemen)
      {
         printf(" Elemen dengan nilai %d ada pada posisi %d \n", elemen, m);
         flag = 1;
         break;
      }
      else if (list[m] < elemen)
         l = m + 1;
      else
         u = m - 1;
   }
   if (flag == 0)
      printf("Elemen dengan nilai %d tidak ada\n", elemen);
}

void bacaList(int list[], int n)
{
   int i;
   printf("Masukkan elemen-elemen\n");
   for (i = 0; i < n; i++)
      scanf("%d", &list[i]);
}

void tampilList(int list[], int n)
{
   int i;
   printf("Elemen-elemen di dalam list adalah: \n");
   for (i = 0; i < n; i++)
      printf("%d\t", list[i]);
}

void main()
{
   int list[MAKS], n, elemen;
   printf("Jumlah elemen di dalam list, maks = 10\n");
   scanf("%d", &n);
   bacaList(list, n);
   printf("\nList sebelum pengurutan adalah:\n");
   tampilList(list, n);
   printf("\nMasukkan elemen yang akan dicari\n");
   scanf("%d", &elemen);
   pencarianBiner(list, n, elemen);
}
