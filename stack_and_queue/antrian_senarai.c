/* Program untuk mensimulasikan antrian menggunakan senarai berantai */
#include <stdio.h>
#include <stdlib.h>
struct simpul
{
   int data;
   struct simpul *link;
};

void sisip(struct simpul **depan, struct simpul **belakang, int nilai)
{
   struct simpul *temp;
   temp = (struct simpul *)malloc(sizeof(struct simpul));
   /* menciptakan simpul baru
      menggunakan nilai
      yang dilewatkan sebagai parameter */
   if (temp == NULL)
   {
      printf("Memori tidak tersedia\n");
      exit(0);
   }
   temp->data = nilai;
   temp->link = NULL;
   if (*belakang == NULL)
   {
      *belakang = temp;
      *depan = *belakang;
   }
   else
   {
      (*belakang)->link = temp;
      *belakang = temp;
   }
}

void hapus(struct simpul **depan, struct simpul **belakang, int *nilai)
{
   struct simpul *temp;
   if ((*depan == *belakang) && (*belakang == NULL))
   {
      printf(" Antrian kosong, tidak bisa menghapus nilai\n");
      exit(0);
   }
   *nilai = (*depan)->data;
   temp = *depan;
   *depan = (*depan)->link;
   if (*belakang == temp)
      *belakang = (*belakang)->link;
   free(temp);
}

void main()
{
   struct simpul *depan = NULL, *belakang = NULL;
   int n, nilai;
   do
   {
      do
      {
         printf("Masukkan elemen yang akan disisipkan\n");
         scanf("%d", &nilai);
         sisip(&depan, &belakang, nilai);
         printf("Masukkan 1 untuk lanjut\n");
         scanf("%d", &n);
      } while (n == 1);

      printf("Masukkan 1 untuk menghapus suatu elemen\n");
      scanf("%d", &n);
      while (n == 1)
      {
         hapus(&depan, &belakang, &nilai);
         printf("Nilai yang dihapus adalah %d\n", nilai);
         printf("Masukkan 1 untuk menghapus sebuah elemen\n");
         scanf("%d", &n);
      }
      printf("Masukkan 1 untuk lanjut\n");
      scanf("%d", &n);
   } while (n == 1);
}
