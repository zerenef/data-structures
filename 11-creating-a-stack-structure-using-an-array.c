#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct stack{
  int top;
  unsigned capacity;
  int *array;
};

struct stack *createStack(unsigned);
int isFull(struct stack *);
int isEmpty(struct stack *);
void push(struct stack *, int);
int pop(struct stack *);
int peek(struct stack *);

int main() {
  struct stack *stack = createStack(50);
  push(stack, 5);
  push(stack, 4);
  push(stack, 8);
  printf("%d yigindan cikarildi\n", pop(stack));
  printf("top eleman %d\n", peek(stack));
  return 0;
}

struct stack *createStack(unsigned capacity){
  struct stack *stack = (struct stack*)malloc(sizeof(struct stack));
  stack->capacity = capacity;
  stack->top = -1;
  stack->array = (int*)malloc(stack->capacity * sizeof(int)); 
  return stack;
}

int isFull(struct stack *stack){
  return stack->top == stack->capacity - 1;
}

int isEmpty(struct stack *stack){
  return stack->top == -1;
}

void push(struct stack *stack, int data){
  if (isFull(stack)) return;
  stack->top++;
  stack->array[stack->top] = data;
  printf("%d yigina eklendi\n", x);
}

int pop(struct stack *stack){
  if (isEmpty(stack)) return INT_MIN;
  return stack->array[stack->top--];
}

int peek(struct stack *stack){
  if (isEmpty(stack)) return INT_MIN;
  return stack->array[stack->top];
}
