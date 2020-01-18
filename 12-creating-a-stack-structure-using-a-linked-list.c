#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct stack{
  int data;
  struct stack *next;
};

struct stack *newNode(int);
int isEmpty(struct stack *);
void push(struct stack **, int);
int pop(struct stack **);
int peek(struct stack *);

int main(){
  struct stack *stack = NULL;
  push(&stack, 1);
  push(&stack, 2);
  push(&stack, 3);
  printf("%d yigindan cikarildi\n", pop(&stack));
  printf("top eleman %d\n", peek(stack));
  return 0;
}

struct stack *newNode(int data) { 
  struct stack *node = (struct stack*)malloc(sizeof(struct stack)); 
  node->data = data; 
  node->next = NULL; 
  return node; 
}

int isEmpty(struct stack *s) { 
  return !s;
}

void push(struct stack **stack, int data){
	struct stack *node = newNode(data);
	node->next = (*stack);
	(*stack) = node;
  printf("%d yigina eklendi\n", data);
}

int pop(struct stack **stack){
  if (isEmpty(*stack)) return INT_MIN;
	struct stack* tmp = (*stack);
	(*stack) = (*stack)->next;
	int popped = tmp->data;
	free(tmp);
	return popped;
}

int peek(struct stack *stack){
  if (isEmpty(stack)) return INT_MIN;
	return stack->data;
}
