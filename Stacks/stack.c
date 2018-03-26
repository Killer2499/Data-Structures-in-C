#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 101
int A[101];
int top=-1;
void push(int x){
	if(top==MAX_SIZE-1){
		printf("Error!Stack Overflow");
		return;
	}
	A[++top]=x;
}
void pop(){
    if(top==-1){
      printf("Stack is empty");
      return;
    }
	top--;
}
int Top(){
	return A[top];
}
void Print(){
	int i;
	printf("Stack");
	for(i=0;i<=top;i++){
		printf("%d",A[i]);
	}
	printf("\n");
}
int main()
{
   push(2);Print();
   push(5);Print();
   pop();Print();
   push(7);Print();
   Top();
}

