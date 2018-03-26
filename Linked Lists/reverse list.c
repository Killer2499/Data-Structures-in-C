#include<stdio.h>
struct node{
    int data;
    struct node *next;
}*start=NULL;
void create()
{
    struct node *newnode,*p;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter the data in the node  ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(start==NULL)
    {
        start=newnode;
    }
    else{
        p=start;
        while(p->next!=NULL)
         {
                p=p->next;
         }
         p->next=newnode;
    }
}
void display()
{
    struct node *p=start;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
void reverse()
{
    struct node *p=start,*q=start->next;
    p->next=NULL;
    while(q->next!=NULL)
    {
        start=q;
        q=q->next;
        start->next=p;
        p=start;
    }
    start=q;
    start->next=p;
}
int main()
{
    for(int i=0;i<5;i++)
    {
        create();
    }
    display();
    reverse();
    display();
}