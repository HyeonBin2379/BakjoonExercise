#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElementType;
typedef struct tagNode
{
	ElementType data;
	struct tagNode *next;
} Node;
typedef struct tagQueue
{
	Node *front;
	Node *rear;
	int count;
} Queue;

int isEmpty(Queue *queue)
{
	return (queue->front == NULL);
}
void enqueue(Queue *queue, Node *newNode)
{
	if (queue->front == NULL)
	{
		queue->front = newNode;
		queue->rear = newNode;
	}
	else
	{
		queue->rear->next = newNode;
		queue->rear = newNode;
	}
	queue->count++;
}
Node *dequeue(Queue *queue)
{
	Node *front = queue->front;

	if (isEmpty(queue))
		return NULL;

	if (queue->front->next == NULL)
	{
		queue->front = NULL;
		queue->rear = NULL;
	}
	else
	{
		queue->front = queue->front->next;
	}
	queue->count--;

	return front;
}
Node *createNode(ElementType newData)
{
	Node *newNode = (Node *)malloc(sizeof(Node));

	newNode->data = newData;
	newNode->next = NULL;

	return newNode;
}
void destroyNode(Node *node)
{
	free(node);
}
Queue *createQueue(void)
{
	Queue *queue = (Queue *)malloc(sizeof(Queue));

	queue->front = NULL;
	queue->rear = NULL;
	queue->count = 0;

	return queue;
}
void destroyQueue(Queue *queue)
{
	while (!isEmpty(queue))
	{
		Node *popped = dequeue(queue);
		destroyNode(popped);
	}
	free(queue);
}
int getSize(Queue *queue)
{
	return queue->count;
}

ElementType getFront(Queue *queue)
{
	if (queue->front != NULL)
		return queue->front->data;
	else
		return -1;
}
ElementType getRear(Queue *queue)
{
	if (queue->rear != NULL)
		return queue->rear->data;
	else
		return -1;
}
void printQueue(Queue *queue)
{
	Node *current = queue->front;
	int size = getSize(queue);

	while (size > 0)
	{
		printf("%d", current->data);
		current = current->next;
		size--;
	}
	printf("\n");
}

int main(void)
{
	Queue *queue = createQueue();
	Node *draw;
	int count;

	scanf("%d", &count);
	for (int i = 0; i < count; i++)
	{
		enqueue(queue, createNode(i+1));
	}

	while (1) {
		draw = dequeue(queue);
		if (isEmpty(queue))
			break;

		draw = dequeue(queue);

		if (isEmpty(queue))
			break;

		enqueue(queue, createNode(draw->data));
	}

	printf("%d\n", draw->data);
	destroyQueue(queue);
	exit(0);
}
