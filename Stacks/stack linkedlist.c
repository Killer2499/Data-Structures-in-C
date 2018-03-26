#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};
struct node* top=NULL;

void push(int x){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=top;
	top=temp;
}
void pop(){
	struct node* temp;
	if(top==NULL) return;
	temp=top;
	top=top->next;
	free(temp);

}
void Print(){
	struct node* temp=top;
	int i;
	printf("Stack:");
	while(temp!=NULL){
		printf("%d",temp->data);
		temp=temp->next;
	}

	printf("\n");
}
int main(){
	push(3);
	push(4);
	push(5);
	Print();
}