/*
  NIM     : I0714031
  Nama    : Rizal Nurhidayat
  Program : Program Menghitung f(x)= sin(x) + cos(x)
*/
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
  double hasil;
  double derajat;
  double radian;
  double sinus;
  double cosinus;
  int kounter = 1;
  int start;
  int menit, detik, lg;

  printf("===============================================================================\n");
  printf("|               Program Penghitung Nilai f(x) = sin(x) + cos(x)               |\n");
  printf("|                  Dibuat Oleh : Rizal Nurhidayat | I0714031                  |\n");
  printf("===============================================================================\n\n");
lagi:
  printf("Masukkan NIM : I 07 14 0");
  scanf("%d", &start);

  menit = start / 60;
  detik = start / 3600;
  derajat = start + menit + detik;

  radian = derajat * (M_PI / 180);
  sinus = sin(radian);
  cosinus = cos(radian);
  hasil = sin(radian) + cos(radian);

  printf("\nSudut : %d D, %d M, %d S", start, start, start);
  printf("\nSudut : %lf rad\n", radian);
  printf("===============================================================================\n");
  printf("%s\t\t %s\t\t %s\t\t  %s", "Iterasi", "sin(x)", "cos(x)", "f(x)= sin(x)+cos(x)"
                                                                    "\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("   %d\t", kounter);
  printf("\t%f", sinus);
  printf("\t%f", cosinus);
  printf("\t\t%f\n", hasil);
  printf("===============================================================================\n");
  system("pause");
  return (0);
}
