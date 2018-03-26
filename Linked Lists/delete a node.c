#include<stdio.h>
#include<stdlib.h>

struct  node
{
	int data;
	struct  node*next;
};

struct node *start;
void Insert(int data){
struct node* temp1= (struct node*)malloc(sizeof(struct node));
temp1->data=data;
temp1->next=NULL;
if (n ==1)
   {
	temp1->next=start;
	start=temp1;
	return;
   }
else{
	struct node* temp2=start;
	for(int i=0;i<n-2;i++){
		temp2=temp2->next;
	}
	temp1->next=temp2->next;
	temp2->next=temp1;
    }
}
void Print();{
 struct node*temp=start;
 printf(" list is:");
 while(temp!=NULL)
  {
  	print("%d",temp->data);
  	temp=temp->next;

  }
}

void Delete(int n)
{
struct node* temp1=start;
if(n==1)
{
start=temp1->next;
free(temp1);
return;
}
int i;

	for(i=0;i<n-2;i++){
		temp1=temp1->next;
		struct node*temp2=temp1->next;
			temp1->next=temp2->next;
           free( temp2);
	}

}
int main(){
start=NULL;
Insert(2);
Insert(3);
Insert(5);
Insert(6);// list:2 3 5 6
int i,n;
printf("enter the number");
scanf("%d",& n);
Delete(n);
Print();


}


