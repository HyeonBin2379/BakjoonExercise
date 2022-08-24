#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 600010

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

	newStack->top = 0;
	newStack->capacity = capacity;
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
	return stack->top == 0;
}
int getSize(Stack *stack)
{
	return stack->top;
}

int main(void)
{
	Stack *left = createStack(600010);
	Stack *right = createStack(600010);
	char str[MAXSIZE] = {0, };
	int len, input;

	scanf("%s", str);
	len = strlen(str);
	//printf("len: %d\n", len);

	for (int i = 0; i < len; i++)
	{
		push(left, str[i]);
	}

	scanf("%d", &input);

	for (int i = 0; i < input; i++)
	{
		char cmd;

		scanf("\n%c", &cmd);

		if (cmd == 'L')
		{
			if (!isEmpty(left))
			{
				push(right, pop(left));
			}
		}
		else if (cmd == 'D')
		{
			if (!isEmpty(right))
			{
				push(left, pop(right));
			}
		}
		else if (cmd == 'B')
		{
			if (!isEmpty(left))
				pop(left);
		}
		else if (cmd == 'P')
		{
			char ch;

			scanf("\n%c", &ch);
			push(left, ch);
		}
	}

	while (!isEmpty(left))
	{
		push(right, pop(left));
	}

	while (!isEmpty(right))
	{
		printf("%c", pop(right));
	}
	printf("\n");
	exit(0);
}
