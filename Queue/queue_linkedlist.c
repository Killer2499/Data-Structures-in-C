/*Queue - Linked List implementation*/
#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* next;
};
// Two global variables to store address of front and rear nodes.
struct Node* front = NULL;
struct Node* rear = NULL;
// To Enqueue an integer
void Enqueue() {
    printf("Enter element \n");
    int x;
    scanf("%d",&x);
	struct Node* temp =
		(struct Node*)malloc(sizeof(struct Node));
	temp->data =x;
	temp->next = NULL;
	if(front == NULL && rear == NULL){
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}
// To Dequeue an integer.
void Dequeue() {
	struct Node* temp = front;
	if(front == NULL) {
		printf("Queue is Empty\n");
		return;
			}
	if(front == rear) {
		front = rear = NULL;
	}
	else {
		front = front->next;
	}
	free(temp);
}
void Print() {
    if(front==NULL&&rear==NULL)
    {
        printf("Queue is empty");
    }
    else{
	struct Node* temp = front;
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
			}
    }
	printf("\n");
}
int main(){
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
