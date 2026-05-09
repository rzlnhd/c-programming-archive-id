/* Program menghapus simpul senarai berantai */
#include <stdio.h>
#include <stdlib.h>
struct simpul *hapus(struct simpul *, int);
int panjang(struct simpul *);

struct simpul
{
   int data;
   struct simpul *link;
};

struct simpul *sisip(struct simpul *p, int n)
{
   struct simpul *temp;
   if (p == NULL)
   {
      p = (struct simpul *)malloc(sizeof(struct simpul));
      if (p == NULL)
      {
         printf("Error\n");
         exit(0);
      }
      p->data = n;
      p->link = NULL;
   }
   else
   {
      temp = p;
      while (temp->link != NULL)
         temp = temp->link;
      temp->link = (struct simpul *)malloc(sizeof(struct simpul));
      if (temp->link == NULL)
      {
         printf("Error\n");
         exit(0);
      }
      temp = temp->link;
      temp->data = n;
      temp->link = NULL;
   }
   return (p);
}

void tampilList(struct simpul *p)
{
   printf("Nilai-nilai data di dalam list adalah\n");
   while (p != NULL)
   {
      printf("%d\t", p->data);
      p = p->link;
   }
}

void main()
{
   int n;
   int x;
   struct simpul *awal = NULL;
   printf("Masukkan jumlah simpul yang akan diciptakan \n");
   scanf("%d", &n);
   while (n-- > 0)
   {
      printf("Masukkan nilai-nilai data yang akan ditempatkan pada simpul\n");
      scanf("%d", &x);
      awal = sisip(awal, x);
   }
   printf(" List sebelum penghapusan adalah\n");
   tampilList(awal);
   printf("% \n Masukkan nomor simpul\n");
   scanf(" %d", &n);
   awal = hapus(awal, n);
   printf(" List setelah penghapusan adalah\n");
   tampilList(awal);
}

/* fungsi untuk menghapus simpul tertentu*/
struct simpul *hapus(struct simpul *p, int simpul_no)
{

   struct simpul *prev, *curr;
   int i;

   if (p == NULL)
   {
      printf("Tidak ada simpul yang akan dihapus \n");
   }
   else
   {
      if (simpul_no > panjang(p))
      {
         printf("Error\n");
      }
      else
      {
         prev = NULL;
         curr = p;
         i = 1;
         while (i < simpul_no)
         {
            prev = curr;
            curr = curr->link;
            i = i + 1;
         }
         if (prev == NULL)
         {
            p = curr->link;
            free(curr);
         }
         else
         {
            prev->link = curr->link;
            free(curr);
         }
      }
   }
   return (p);
}

/* fungsi untuk menghitung panjang senarai berantai */
int panjang(struct simpul *p)
{
   int count = 0;
   while (p != NULL)
   {
      count++;
      p = p->link;
   }
   return (count);
}
