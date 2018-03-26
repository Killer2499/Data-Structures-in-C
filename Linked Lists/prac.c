#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 101


struct node{
	int data;
	struct node* link;
};
struct node*top=NULL;
void Push(int x)
{
	struct node* temp= (struct node*)malloc(sizeof(struct node*));
	temp->data=x;
	temp->link=top;
	top=temp;
}
void Pop()
{
	struct node*temp;
	if(top==NULL) return;
	temp=top;
	top=top->link;
	free(temp);
}
void Print()
{
	struct node*temp;
	printf("Stack is\n");
while(temp!=NULL)
print("%d",temp->data);
		}

}
int main(){
	Push(3);
	Push(5);
	Print();
	Pop();

}
