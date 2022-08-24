#include <stdio.h>
#include <stdlib.h>

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

int main(void)
{
	int len, gap;
	int count = 0;
	Queue *queue = createQueue();
	Node *popped;

	scanf("%d%d", &len, &gap);
	
	for (int i = 1; i <= len; i++)
	{
		enqueue(queue, createNode(i));
	}

	while (!isEmpty(queue))
	{
		if (count++ % gap != gap-1) {
			popped = dequeue(queue);
			enqueue(queue, createNode(popped->data));
			continue;
		}
		else {
			popped = dequeue(queue);
			if (getSize(queue) == len-1)
				printf("<%d", popped->data);
			else
				printf(", %d", popped->data);
		}
	}

	printf(">\n");
	destroyQueue(queue);
	exit(0);
}
