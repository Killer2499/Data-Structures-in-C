#include <stdio.h>
#define CAPACITY 100 // maximum size of stack


// create a structure stack
struct stack {
  int numbers[CAPACITY];
  int top; // index of the top most element
};

// creating a stack 's'
struct stack s;

// function to push numbers at the top of stack
void Push(int num) {
  // check if the stack has some space left
  if(s.top >= CAPACITY-1) {
    printf("Stack is full\n");
    return ;
  }

  // increase the top index by 1
  s.top = s.top + 1; // s.top += 1 or s.top++
  // insert the 'num' in 'numbers' array
  s.numbers[s.top] = num;
}

// function to check if the stack if empty
// @returns 1 if stack is empty otherwise 0
int isEmpty() {
  if(s.top == -1)
    return 1;
  return 0;
}

int Pop() {
  // check if the stack is empty
  if(isEmpty()) {
    printf("Stack is empty\n");
    return NULL;
  }

  // store the top most element in num variable
  int num = s.numbers[s.top];
  // decrease the top index by 1
  s.top = s.top - 1; // s.top -= 1 or s.top--

  // return num
  return num;
}

// function to display all element stacks
void Display() {
  if(isEmpty()) {
    printf("Stack is empty\n");
    return ;
  }

  printf("The elements in stack are:\n");
  for(int i = s.top; i>=0; i--) {
    printf("%d\n", s.numbers[i]);
  }
}

int main() {
  // initialzing stack's top to be -1
  s.top = -1;
  int n,flag=1, choice = 1;
  printf("Stack Operations: \n");

  while(flag) {
    printf ("------------------------------------------\n");
    printf ("      1    -->    PUSH               \n");
    printf ("      2    -->    POP               \n");
    printf ("      3    -->    DISPLAY               \n");
    printf ("      4    -->    EXIT           \n");
    printf ("------------------------------------------\n");

    // take user input
    printf("Enter your choice: \n");
    scanf("%d",&choice);

    switch(choice) {
      case 1:
        printf("Enter the number you want to push : ");
        scanf("%d",&n);
        Push(n);
        break;

      case 2:
        n = Pop();
        printf("Popped Element : %d\n",n);
        break;

      case 3:
        Display();
        break;

      case 4:
        flag = 0;
        break;

      default: 
        printf("Wrong Choice!!!\n");
    }
  }

  return 0;

}

