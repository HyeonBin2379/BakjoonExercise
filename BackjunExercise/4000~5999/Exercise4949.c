#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 102

typedef int ElementType;

typedef struct tagStack
{
	int top;
	char str[MAXSIZE];
} Stack;

Stack *createStack(void)
{
	Stack *stack = (Stack *)malloc(sizeof(Stack));

	stack->top = -1;
	memset(stack->str, 0, sizeof(stack->str)-1);

	return stack;
}
void destroyStack(Stack *stack)
{
	free(stack);
}
int isEmpty(Stack *stack)
{
	return stack->top == -1;
}
int isFull(Stack *stack)
{
	return stack->top == sizeof(stack->str)-1;
}
void push(Stack *stack, ElementType newData)
{
	stack->str[++stack->top] = newData;
}
int pop(Stack *stack)
{
	if (isEmpty(stack))
		return -1;
	else
		return stack->str[stack->top--];
}
ElementType top(Stack *stack)
{
	if (isEmpty(stack))
		return 0;
	else
		return stack->str[stack->top];
}
int checkMatching(char *str, int len)
{
	Stack *stack = createStack();

	for (int i = 0; i < len; i++)
	{
		char ch, open_ch;

		ch = str[i];

		switch(ch)
		{
			case '(': case '[':
				push(stack, ch);
				break;
			case ')': case ']':
				if (isEmpty(stack))
					return 0;
				else {
					open_ch = top(stack);
					pop(stack);
					if ((open_ch == '(' && ch != ')') || (open_ch == '[' && ch != ']'))
						return 0;
					break;
				}
		}
	}

	if (isEmpty(stack) == 0) 
	{
		destroyStack(stack);
		return 0;
	}
	else
	{
		destroyStack(stack);
		return 1;
	}
}

int main(void)
{
	char str[MAXSIZE];

	while (1)
	{
		int len;

		memset(str, 0, sizeof(str));
		fgets(str, sizeof(str), stdin);
		str[strlen(str)-1] = '\0';
		len = strlen(str);

		if (strcmp(str, ".") == 0)
			break;

		if (checkMatching(str, len) == 1)
			printf("yes\n");
		else
			printf("no\n");
	}

	exit(0);
}
