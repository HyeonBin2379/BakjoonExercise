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

	return stack;
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
	Stack *word = createStack(100010);
	char str[100010] = {0, };
	char open_ch;
	int i = 0;
	int reverse = 1;

	fgets(str, sizeof(str), stdin);

	for (i = 0; str[i] != '\0'; i++)
	{
		char ch = str[i];

		// 태그 시작점
		if (ch == '<')
		{
			reverse = 0;
			while (!isEmpty(word))
			{
				open_ch = top(word);
				printf("%c", open_ch);
				pop(word);
			}
			printf("%c", ch);
		}
		// 태그 종료점
		else if (ch == '>')
		{
			reverse = 1;
			printf("%c", ch);
		}
		else if (ch == ' ' || i >= strlen(str)-2)
		{
			if (i >= strlen(str)-2)
				push(word, ch);
			
			while (!isEmpty(word))
			{
				open_ch = top(word);
				printf("%c", open_ch);
				pop(word);
			}
			if (ch == ' ')
				printf("%c", ch);
		}
		else
		{
			push(word, ch);
			if (reverse == 0) {
				open_ch = pop(word);
				printf("%c", open_ch);
			}
		}
	}
	while (!isEmpty(word))
	{
		printf("%c", pop(word));
	}
	exit(0);
}
