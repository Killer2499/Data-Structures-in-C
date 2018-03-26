#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define CAPACITY 100 // maximum size of stack

struct stack {
  int numbers[CAPACITY];
  int top; // index of the top most element
};

struct stack s;

void push(int num) {
  if(s.top >= CAPACITY-1) {
    printf("Stack is full\n");
    return ;
  }

  s.top = s.top + 1;
  s.numbers[s.top] = num;
}

int isEmpty() {
  if(s.top == -1)
    return 1;
  return 0;
}

int pop() {
  // check if the stack is empty
  if(isEmpty()) {
    printf("Incorrect postfix expression\n");
    exit(1);
  }

  int num = s.numbers[s.top];
  s.top = s.top - 1; 
  return num;
}

void evaluatePostfix(char* exp)
{
    int i;
 
    // Scan all characters one by one
    for (i = 0; exp[i]!='\0'; ++i)
    {   
        if (exp[i] == ' ')
          continue;

        // If the scanned character is an operand (number here),
        // push it to the stack.

        else if (isdigit(exp[i])){
          int p=0,n = 1;
          while(isdigit(exp[i])){
            p += (exp[i] - 48) * n ;
            i++;
            n = n*10;}
            n=0;
            while(p>0){
              n = n*10 + (p%10);
              p = p/10;
            }
            i--;
            //printf("%d\n",n );
           push( n );
        }
 
        //  If the scanned character is an operator, pop two
        // elements from stack apply the operator

        else  
        {
            int val1 = pop();
            int val2 = pop();
            switch (exp[i])
            {
             case '+': push(val2 + val1); break;
             case '-': push(val2 - val1); break;
             case '*': push(val2 * val1); break;
             case '/': push(val2/val1);   break;
            }
        }
    }
    if ( s.top != 0 )
    	printf("Incorrect postfix expression!\n");
    else
        printf ("Value of {%s} is %d\n", exp, pop());
}

int main()
{
    char exp[150];
    s.top = -1;
    printf("Enter the postfix expression: \n");
    scanf("%[^\n]s",exp);
    evaluatePostfix(exp);
    return 0;
}