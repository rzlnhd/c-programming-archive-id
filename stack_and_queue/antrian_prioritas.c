/* Program untuk mensimulasikan antrian prioritas */
#include <stdio.h>
#include <stdlib.h>
struct node
{
   int data;
   int priority;
   struct node *link;
};
void insert(struct node **front, struct node **rear, int value, int priority)
{
   struct node *temp, *temp1;
   temp = (struct node *)malloc(sizeof(struct node));
   /* creates new node using data value passed as parameter */
   if (temp == NULL)
   {
      printf("No Memory available Error\n");
      exit(0);
   }
   temp->data = value;
   temp->priority = priority;
   temp->link = NULL;
   if (*rear == NULL) /* This is the first node */
   {
      *rear = temp;
      *front = *rear;
   }
   else
   {
      if ((*front)->priority < priority)
      /* the element to be inserted has highest priority hence should be the first element*/
      {
         temp->link = *front;
         *front = temp;
      }
      else if ((*rear)->priority > priority)
      /* the element to be inserted has lowest priority hence should be the last element*/
      {
         (*rear)->link = temp;
         *rear = temp;
      }

      else
      {
         temp1 = *front;
         while ((temp1->link)->priority >= priority)
            /* find the position and insert the new element */
            temp1 = temp1->link;
         temp->link = temp1->link;
         temp1->link = temp;
      }
   }
   void hapus(struct node * *front, struct node * *rear, int *value, int *priority)
   {
      struct node *temp;
      if ((*front == *rear) && (*rear == NULL))
      {
         printf(" The queue is empty cannot delete Error\n");
         exit(0);
      }
      *value = (*front)->data;
      *priority = (*front)->priority;
      temp = *front;
      *front = (*front)->link;
      if (*rear == temp)
         *rear = (*rear)->link;
      free(temp);
   }

   void main()
   {
      struct node *front = NULL, *rear = NULL;
      int n, value, priority;
      do
      {
         do
         {
            printf("Enter the element to be inserted and its priority\n");
            scanf("%d %d", &value, &priority);
            insert(&front, &rear, value, priority);
            printf("Enter 1 to continue\n");
            scanf("%d", &n);
         } while (n == 1);

         printf("Enter 1 to delete an element\n");
         scanf("%d", &n);
         while (n == 1)
         {
            hapus(&front, &rear, &value, &priority);
            printf("The value deleted is %d\ and its priority is %d \n", value, priority);
            printf("Enter 1 to delete an element\n");
            scanf("%d", &n);
         }
         printf("Enter 1 to delete an element\n");
         scanf("%d", &n);
      } while (n == 1)
   }
