/* Transposisi Matriks */
#include <stdio.h>
#include <conio.h>
#define BARIS 3
#define KOLOM 3

void main()
{
   void baca(int a[][KOLOM], int, int);
   void dis(int a[][KOLOM], int, int);
   void trans(int a[][KOLOM], int, int);
   int a[3][3];

   baca(a, BARIS, KOLOM);
   printf("\nMatriks adalah \n");
   dis(a, BARIS, KOLOM);
   trans(a, BARIS, KOLOM);
   printf("Transposisi atas matriks adalah\n");
   dis(a, BARIS, KOLOM);
   getch();
}

void baca(int c[3][3], int i, int k)
{
   int j, l;
   printf("Masukkan array \n");
   for (j = 0; j < i; j++)
      for (l = 0; l < k; l++)
         scanf("%d", &c[j][l]);
   fflush(stdin);
}

void dis(int d[3][3], int i, int k)
{
   int j, l;
   for (j = 0; j < i; j++)
   {
      for (l = 0; l < k; l++)
         printf("%d ", d[j][l]);
      printf("\n");
   }
}

void trans(int mat[][3], int k, int l)
{
   int i, j, temp;
   for (i = 0; i < k; i++)
   {
      for (j = i + 1; j < l; j++)
      {
         temp = mat[i][j];
         mat[i][j] = mat[j][i];
         mat[j][i] = temp;
      }
   }
}