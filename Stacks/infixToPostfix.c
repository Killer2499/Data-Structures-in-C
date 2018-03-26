 #include <stdio.h>
#include <ctype.h>
#define CAPACITY 50

struct stack {
  int numbers[CAPACITY];
  int top;
};

struct stack s;
// function to push numbers at the top of stack
void Push(int num) {
  if(s.top >= CAPACITY-1) {
    printf("Stack is full\n");
    return ;
  }

  s.top = s.top + 1;

  s.numbers[s.top] = num;
}

// function to check if the stack if empty.
// @returns 1 if stack is empty otherwise 0
int isEmpty() {
  if(s.top == -1)
    return 1;
  return 0;
}

int Pop() {

  if(isEmpty()) {
    printf("Stack is empty\n");
    return NULL;
  }

  int num = s.numbers[s.top];
  s.top = s.top - 1;

  return num;
}

// Returns top most element of the stack
int Peek()
{
  return s.numbers[s.top];
} 

// function to check precedence of an operator
int precedence(char c)
{
  if(c == '(')
    return 0;
  if( c == '+' || c == '-')
    return 1;
  if(c == '*' || c == '/')
    return 2;
  if(c == '^')
    return 3;
}

// function to convert infix expression into postfix expression
// @param infix -> infix expression
// @param postfix -> postfix expression

void infix_to_postfix(char infix[],char postfix[])
{
  s.top = -1;
  int i,j=0; // i -> infix index , j -> postfix index
  char letter,temp;

 for(i=0;infix[i]!='\0';i++)
 {
     letter=infix[i];
     if(isalnum(letter)) {
       postfix[j]=letter;
       j++;
     }
         
     else
         if(letter=='(')
            Push('(');
     else
         if(letter==')')
             while((temp=Pop())!='(')
                   postfix[j++]=temp;
     else
     {
         while(precedence(letter)<=precedence(Peek()) && !isEmpty())
         {
             temp=Pop();
             postfix[j++]=temp;
         }
         Push(letter);
     }
  }
 
  while(!isEmpty())
  {
       temp=Pop();
       postfix[j++]=temp;
  }
 
  postfix[j]='\0';

}


int main() 
{
  char infix[30], postfix[30];
  printf("Enter the infix expression (5*2+3) \n");
  scanf("%[^\n]s", infix);
  infix_to_postfix(infix,postfix);
  printf("The postfix expression is %s \n", postfix);
  return 0;
}