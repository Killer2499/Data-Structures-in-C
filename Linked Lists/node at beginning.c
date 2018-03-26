#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};
struct node* start;
void Insert(int x){
	 struct node*temp=( struct node *)malloc(sizeof( struct node));
	temp->data=x;
	temp->next=start;
	start=temp;
	/*if(start!=NULL){                  when node is initially full
		temp->next=start;
		start=temp;
	}*/
}
void Print(){
	struct node*temp=start;
	printf("list is: ");
	while(temp!=NULL){
		printf("%d",temp->data);
		temp=temp->next;
	}
	printf("\n");
	
}
int main(){
	start=NULL;
	printf("enter no of elemnts: \n");
	int i,n,x;
	scanf("%d",&n);
	for(i=0;i<n;i++){
	 printf("enter the numbers");
	 scanf("%d",&x);
	 Insert(x);
	 Print();
	}
	return 0;
}

