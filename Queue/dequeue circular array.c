#include<stdio.h>
int front=-1,rear=-1;
int A[100],N;
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

void EnqueueRear()
{

    if(IsFull()==1)
    {
        printf("DEQueue is Full\n");
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
    printf("Enter element \n");
    int x;
    scanf("%d",&x);
    A[rear] = x;
}

void EnqueueFront()
{
    if(IsFull()==1)
    {
        printf("DEQueue is Full\n");
        return;
    }
    if (IsEmpty()==1)
    {
        front = rear = 0;
    }
    else
    {
        front=(front-1+N)%N;
    }
    printf("Enter element \n");
    int x;
    scanf("%d",&x);
    A[front] = x;
}

void DequeueFront()
{
    if(IsEmpty()==1)
    {
        printf("DEQueue is Empty \n");
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

void DequeueRear()
{
    if(IsEmpty()==1)
    {
        printf("DEQueue is Empty \n");
        return;
    }
    else if(front == rear )
    {
        rear = front = -1;
    }
    else
    {
        rear=(rear-1+N)%N;
    }
}

void Print()
{
    if(IsEmpty()==1)
    {
        printf("DEQueue is Empty \n");
        return;
    }
    else
    {
    int count = (rear-front+N)%N+ 1;
    printf("DEQueue       : ");
    int i;
    for( i = 0; i <count; i++)
    {
        int index =(front+i)%N;
        printf("%d ",A[index]);
    }
    }
    printf("\n\n");
}


int main()
{
printf("Enter size of the Queue\n");
scanf("%d",&N);
int ch;
printf("1:EnqueueRear 2:EnqueueFront 3:DequeueFront 4:DequeueRear 5:display default :exit\n");
do
{
printf("enter choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: EnqueueRear();
break;
case 2: EnqueueFront();
break;
case 3: DequeueFront();
break;
case 4: DequeueRear();
break;
case 5: Print();
break;
default: exit(0);
}
}while(ch<=5) ;
}


