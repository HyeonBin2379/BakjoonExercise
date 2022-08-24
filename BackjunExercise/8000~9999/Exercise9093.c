#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ElementType;

typedef struct tagNode
{
	ElementType data;
} Node;
typedef struct tagStack
{
	int top;
	int capacity;
	Node *nodes;
} Stack;

Stack *createStack(int capacity)
{
	Stack *stack = (Stack *)malloc(sizeof(Stack));

	stack->top = 0;
	stack->capacity = capacity;
	stack->nodes = (Node *)malloc(sizeof(Node) * capacity);
}
void destroyStack(Stack *stack)
{
	free(stack->nodes);
	free(stack);
}
int isEmpty(Stack *stack)
{
	return (stack->top == 0);
}
int isFull(Stack *stack)
{
	return (stack->top == stack->capacity-1);
}
void push(Stack *stack, ElementType newData)
{
	int position = stack->top;

	stack->nodes[position].data = newData;
	stack->top++;
}
ElementType pop(Stack *stack)
{
	int position = --(stack->top);

	return stack->nodes[position].data;
}
ElementType top(Stack *stack)
{
	int position = stack->top-1;

	return stack->nodes[position].data;
}

int main(void)
{
	char str[1001];
	int testCase;

	scanf("%d ", &testCase);
	for (int i = 0; i < testCase; i++)
	{
		int j = 0;
		char open_ch;
		Stack *stack = createStack(20);

		fgets(str, sizeof(str)-1, stdin);
		str[strlen(str)] = '\0'; 

		for (j = 0; j < strlen(str)-1; j++)
		{
			char ch = str[j];

			if (ch == ' ' || j == strlen(str)-2)
			{
				if (j == strlen(str)-2)
					push(stack, ch);

				while (!isEmpty(stack))
				{
					open_ch = top(stack);
					printf("%c", open_ch);
					pop(stack);
				}
				if (ch == ' ')
					printf("%c", ch);
			}
			else if (isFull(stack))
			{
				if (ch != ' ')
					push(stack, ch);

				while (!isEmpty(stack))
				{
					open_ch = top(stack);
					printf("%c", open_ch);
					pop(stack);
				}
			}
			else
				push(stack, ch);
		}
		printf("\n");

		memset(str, 0, sizeof(str));
		destroyStack(stack);
	}

	exit(0);
}
