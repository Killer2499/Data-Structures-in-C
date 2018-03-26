#include<stdio.h>
int front=-1,rear=-1;
int A[101],N;
int IsEmpty()
{
    if(front == -1 && rear == -1)
        return 1;
    else
        return 0;
}

int IsFull()
{
    if((rear+1)%N==front)
        return 1;
    else
        return 0;
}

void Enqueue()
{
    printf("Enter element \n");
    int x;
    scanf("%d",&x);
    if(IsFull()==1)
    {
        printf("Queue is Full\n");
        return;
    }
    if (IsEmpty()==1)
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear+1)%N;
    }
    A[rear] = x;
}

void Dequeue()
{
    if(IsEmpty()==1)
    {
        printf("Queue is Empty \n");
        return;
    }
    else if(front == rear )
    {
        rear = front = -1;
    }
    else
    {
        front = (front+1)%N;
    }
}


void Print()
{
    if(IsEmpty()==1)
    {
        printf("Queue is Empty \n");
        return;
    }
    else
    {
    int count = (rear-front+N)%N+ 1;
    printf("Queue       : ");
    for(int i = 0; i <count; i++)
    {
        int index =(front+i)%N;
        printf("%d  ",A[index]);
    }
    }
    printf("\n\n");
}


int main()
{
printf("Enter size of the Queue\n");
scanf("%d",&N);
int ch;
printf("1:insert 2:delete 3:display default :exit\n");
do
{
printf("enter choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: Enqueue();
break;
case 2: Dequeue();
break;
case 3: Print();
break;
case 4: exit(0);
}
}while(ch<=4) ;
}

