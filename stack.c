#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define STACK_LENGTH 5
#define EMPTY (-1)
#define STACK_EMPTY INT_MIN

int myStack[STACK_LENGTH];
int top = EMPTY;

bool push(int value);
int pop();

int main(){

  push(1);
  push(2);
  push(3);

  int t;
  while ((t = pop()) != STACK_EMPTY) {
    printf("t = %d\n", t);
  }

  return 0;
}

bool push(int value) {
  
  if (top >= STACK_LENGTH-1){
    return false;
  }

  ++top;
  myStack[top] = value;
  return true;
}

int pop() {
  if (top == EMPTY){
    return STACK_EMPTY;
  }

  int result = myStack[top];
  --top;

  return result;
}