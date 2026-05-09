/* Penjumlahan dua array */
#include <stdio.h>
#include <conio.h>
void main()
{
  void baca(int *, int);
  void dis(int *, int);
  void tambah(int *, int *, int *, int);
  int a[5], b[5], c[5], i;

  printf("Masukkan elemen-elemen ke daftar pertama \n");
  baca(a, 5); /*membaca daftar pertama*/
  printf("Elemen-elemen array pertama adalah \n");
  dis(a, 5); /*Menampilkan array pertama*/
  printf("Masukkan elemen-elemen ke daftar kedua \n");
  baca(b, 5); /*membaca array kedua*/
  printf("Elemen-elemen array kedua adalah \n");
  dis(b, 5); /*Menampilkan array kedua*/
  tambah(a, b, c, i);
  printf("Array hasil perjumlahan adalah \n");
  dis(c, 5);
  getch();
}

void tambah(int a[], int b[], int c[], int i)
{
  for (i = 0; i < 5; i++)
  {
    c[i] = a[i] + b[i];
  }
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
