#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100001

typedef char ElementType;
typedef struct tagStack
{
	int capacity;
	int top;
	ElementType *nodes;
} Stack;

Stack *createStack(int capacity)
{
	Stack *newStack = (Stack *)malloc(sizeof(Stack));

	newStack->capacity = capacity;
	newStack->top = 0;
	newStack->nodes = (ElementType *)malloc(sizeof(ElementType) * capacity);
	return newStack;
}
void destroyStack(Stack *stack)
{
	free(stack->nodes);
	free(stack);
}
void push(Stack *stack, ElementType newData)
{
	int position = stack->top;

	stack->nodes[position] = newData;
	stack->top++;
}
ElementType pop(Stack *stack)
{
	int position = --(stack->top);

	return stack->nodes[position];
}
ElementType top(Stack *stack)
{
	int position = stack->top-1;

	return stack->nodes[position];
}
int isEmpty(Stack *stack)
{
	return (stack->top == 0);
}
int getSize(Stack *stack)
{
	return stack->top;
}

int main(void)
{
	int len;
	int stick = 0;
	char str[MAXSIZE] = {0, };
	Stack *stack = createStack(MAXSIZE);

	scanf("%s", str);
	len = strlen(str);

	for (int i = 0 ; i < len; i++)
	{
		if (str[i] == '(')
		{
			if (i < len-1 && str[i+1] == ')')
			{
				i++;
				stick += stack->top;
			}
			else
				push(stack, str[i]);
		}
		else if (str[i] == ')')
		{
			pop(stack);
			stick++;
		}
	}

	printf("%d\n", stick);
	destroyStack(stack);
	exit(0);
}
