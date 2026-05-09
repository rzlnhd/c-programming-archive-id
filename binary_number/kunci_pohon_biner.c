/* Program untuk mencari kunci pada pohon pencarian biner */
#include <stdio.h>
#include <stdlib.h>
struct tsimpul
{
   int data;
   struct tsimpul *L_anak, *R_anak;
};

/* Fungsi untuk mencari kunci di dalam pohon biner */
struct tsimpul *cari(struct tsimpul *p, int kunci)
{
   struct tsimpul *temp;
   temp = p;
   while (temp != NULL)
   {
      if (temp->data == kunci)
         return (temp);
      else if (temp->data > kunci)
         temp = temp->L_anak;
      else
         temp = temp->R_anak;
   }

   return (NULL);
}

/*fungsi iteratif untuk menata pohon biner*/
void inorder1(struct tsimpul *p)
{
   struct tsimpul *tumpukan[100];
   int atas;
   atas = -1;
   if (p != NULL)
   {
      atas++;
      tumpukan[atas] = p;
      p = p->L_anak;
      while (atas >= 0)
      {
         while (p != NULL) /* menempatkann anak kiri pada tumpukan */
         {
            atas++;
            tumpukan[atas] = p;
            p = p->L_anak;
         }
         p = tumpukan[atas];
         atas--;
         printf("%d\t", p->data);
         p = p->R_anak;

         if (p != NULL) /* menempatkan anak kanan pada tumpukan */
         {
            atas++;
            tumpukan[atas] = p;
            p = p->L_anak;
         }
      }
   }
}

/* Fungsi untuk menyisipkan simpul baru di dalam pohon biner
   untuk menghasilkan pohon biner */
struct tsimpul *sisip(struct tsimpul *p, int nilai)
{
   struct tsimpul *temp1, *temp2;
   if (p == NULL)
   {
      p = (struct tsimpul *)malloc(sizeof(struct tsimpul)); /* menyisipkan simpul baru sebagai simpul akar */
      if (p == NULL)
      {
         printf("Tidak bisa dialokasikan\n");
         exit(0);
      }
      p->data = nilai;
      p->L_anak = p->R_anak = NULL;
   }
   else
   {
      temp1 = p;
      /* menjelajah pohon untuk menghasilkan pointer ke simpul dengan anak yang baru diciptakan */
      while (temp1 != NULL)
      {
         temp2 = temp1;
         if (temp1->data > nilai)
            temp1 = temp1->L_anak;
         else
            temp1 = temp1->R_anak;
      }
      if (temp2->data > nilai)
      {
         temp2->L_anak = (struct tsimpul *)malloc(sizeof(struct tsimpul)); /*menyisipkan simpul yang baru tercipta sebagai anak kiri */
         temp2 = temp2->L_anak;
         if (temp2 == NULL)
         {
            printf("Tidak bisa dialokasikan\n");
            exit(0);
         }
         temp2->data = nilai;
         temp2->L_anak = temp2->R_anak = NULL;
      }
      else
      {
         temp2->R_anak = (struct tsimpul *)malloc(sizeof(struct tsimpul)); /*menyisipkan simpul yang baru tercipta sebagai anak kiri*/
         temp2 = temp2->R_anak;
         if (temp2 == NULL)
         {
            printf("Tidak bisa dialokasikan\n");
            exit(0);
         }
         temp2->data = nilai;
         temp2->L_anak = temp2->R_anak = NULL;
      }
   }
   return (p);
}

void main()
{
   struct tsimpul *akar = NULL, *temp = NULL;
   int n, x;
   printf("Jumlah simpul di dalam pohon\n");
   scanf("%d", &n);
   while (n-- > 0)
   {
      printf("Masukkan nilai data\n");
      scanf("%d", &x);
      akar = sisip(akar, x);
   }
   printf("Pohon yang tercipta adalah :\n");
   inorder1(akar);
   printf("\n Masukkan kunci simpul yang dicari\n");
   scanf("%d", &n);
   temp = cari(akar, n);
   if (temp != NULL)
      printf("Nilai data ada di dalam pohon \n");
   else
      printf("Nilai data tidak ada di dalam pohon \n");
}
