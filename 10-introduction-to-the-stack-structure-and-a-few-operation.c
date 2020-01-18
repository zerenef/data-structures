#include <stdio.h>
#include <stdlib.h>

#define capacity 5
struct stack{
  int top;  int array[capacity];
};

int isEmpty(struct stack *stack){
  return stack->top == -1;
}

void push(struct stack *stack, int data){
  if(stack->top == capacity - 1) return;
  stack->array[stack->top++] = data;
  printf("%d yigina eklendi\n",data);
}

int pop(struct stack *stack){
  if(isEmpty(stack)) return 0;
  return stack->array[stack->top--];
}

int peek(struct stack *stack){
  if(isEmpty(stack)) return 0;
  return stack->array[stack->top];
}

int main(){
  struct stack *stack = (struct stack*)malloc(sizeof(struct stack));
  stack->top = -1;
  push(stack, 1);
  push(stack, 2);
  push(stack, 3);
  printf("%d yigindan cikarildi\n", pop(stack));
  printf("en ust eleman %d\n", peek(stack));
  return 0;
}