#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct stack{
  int top;
  unsigned capasity;
  int *array;
};

struct stack *createStack(unsigned);
char peek(struct stack *);
void push(struct stack *, char);
int evPost(char *);

int main(){
  char arrChar[] = "8532*-/";
  printf("Sonuc = %d\n", evPost(arrChar));
  return 0;
}

struct stack *createStack(unsigned capasity){
  struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
  stack->top = -1;
  stack->capasity = capasity;
  stack->array = (int *)malloc(stack->capasity * sizeof(int));
  return stack;
}

char peek(struct stack *s){
  return s->array[s->top];
}

char pop(struct stack *s){
  return s->array[s->top--];
}

void push(struct stack *s, char op){
  s->array[++s->top] = op;
}

int evPost(char *exp){
  struct stack *stack = createStack(strlen(exp));
  for (int i = 0; exp[i]; i++){
    if(isdigit(exp[i])) push(stack, exp[i] - '0');
		else {
      int val1 = pop(stack);
      int val2 = pop(stack);
      switch (exp[i]){
        case '+': push(stack, val2 + val1); break;
        case '-': push(stack, val2 - val1); break;
        case '*': push(stack, val2 * val1); break;
        case '/': push(stack, val2 / val1); break;
        default: printf("boyle bir operator yok"); break;
      }
		}
  }
  return pop(stack);
}