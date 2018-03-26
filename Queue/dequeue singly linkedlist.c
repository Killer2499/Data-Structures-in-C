#include<stdio.h>
struct node
{
 int info;
 struct node *next;
}*front,*rear;
void EnqueueRear()
{
 struct node *temp=(struct node*)malloc(sizeof(struct node));
 printf("\nEnter element: ");
 scanf("%d",&temp->info);
 temp->next=NULL;
 if(front==NULL && rear==NULL)
 {
  front=rear=temp;
  return;
 }
 rear->next=temp;
 rear=rear->next;
}
void DequeueFront()
{
 if(front==NULL)
 {
  printf("\nEmpty DEqueue\n");
  return;
 }
 else if(front==rear)
 {
  struct node *ptr=front;
  front=rear=NULL;
  free(ptr);
 }
 else
 {
  struct node *ptr=front;
  front=front->next;
  free(ptr);
 }
}
void EnqueueFront()
{
 struct node *temp=(struct node*)malloc(sizeof(struct node));
 printf("\nEnter element: ");
 scanf("%d",&temp->info);
 if(front==NULL && rear==NULL)
 {
  front=rear=temp;
  temp->next=NULL;
  return;
 }
 temp->next=front;
 front=temp;
}
void DequeueRear()
{
 if(rear==front && rear==NULL)
 {
  printf("Empty DEqueue");
  return;
 }
 else if(rear==front)
 {
  rear=front=NULL;
  free(rear);
  free(front);
 }
 else
 {
  struct node *ptr=front;
  struct node *temp;
  while(ptr->next!=NULL)
  {
   temp=ptr;
   ptr=ptr->next;
  }
  temp->next=NULL;
  free(ptr);
  rear=temp;
 }
}
void show()
{
 if(front==NULL && rear==NULL)
 {
  printf("\nEmpty DEqueue\n");
  return;
 }
 struct node *ptr=front;
 while(ptr!=NULL)
 {
  printf("%d\t",ptr->info);
  ptr=ptr->next;
 }
}
void main()
{
 int ch;
 printf("\n1. Enqueue at rear");
  printf("\n2. Enqueue at Front");
  printf("\n3. Dequeue from front");
  printf("\n4. Dequeue from rear");
  printf("\n5. Show");
  printf("\n6. Exit");
 while(1)
 {

  printf("\nEnter your choice: ");
  scanf("%d",&ch);
  switch (ch)
  {
   case 1: EnqueueRear(); break;
   case 2: EnqueueFront(); break;
   case 3: DequeueFront(); break;
   case 4: DequeueRear(); break;
   case 5: show(); break;
   default: exit(1); break;

  }
 }
}
