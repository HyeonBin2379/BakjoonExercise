#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
	ElementType data;
	struct tagNode *prev;
	struct tagNode *next;
} Node;

typedef struct tagDeq
{
	Node *front;
	Node *rear;
	int count;
} Deq;

Deq *createDeq(void);
void destroyDeq(Deq *deq);

Node *createNode(ElementType newData);
void destroyNode(Node *node);

void enqueueFront(Deq *deq, Node *newHead);
void enqueueBack(Deq *deq, Node *newNode);
Node *dequeueFront(Deq *deq);
Node *dequeueBack(Deq *deq);

int isEmpty(Deq *deq);
int getSize(Deq *deq);
Node *getFront(Deq *deq);
Node *getRear(Deq *deq);

Deq *createDeq(void)
{
	Deq *deq = (Deq *)malloc(sizeof(Deq));

	deq->front = NULL;
	deq->rear = NULL;
	deq->count = 0;

	return deq;
}
void destroyDeq(Deq *deq)
{
	Node *current = deq->front;
	Node *next;

	while (current != NULL)
	{
		next = current->next;
		destroyNode(current);
		current = next;
	}
	free(deq);
}

Node *createNode(ElementType newData)
{
	Node *newNode = (Node *)malloc(sizeof(Node));

	newNode->data = newData;
	newNode->prev = NULL;
	newNode->next = NULL;

	return newNode;
}
void destroyNode(Node *node)
{
	free(node);
}

void enqueueFront(Deq *deq, Node *newNode)
{
	if (isEmpty(deq))
	{
		deq->front = newNode;
		deq->rear = newNode;
	}
	else
	{
		newNode->next = deq->front;
		deq->front->prev = newNode;
		deq->front = newNode;
	}
	deq->count++;
}
void enqueueBack(Deq *deq, Node *newNode)
{
	if (isEmpty(deq))
	{
		deq->front = newNode;
		deq->rear = newNode;
	}
	else
	{
		newNode->prev = deq->rear;
		deq->rear->next = newNode;
		deq->rear = newNode;
	}
	deq->count++;
}
Node *dequeueFront(Deq *deq)
{
	Node *remove = deq->front;

	if (isEmpty(deq))
		return NULL;

	if (getSize(deq) == 1)
	{
		deq->front = NULL;
		deq->rear = NULL;
	}
	else
	{
		deq->front = remove->next;
		deq->front->prev = NULL;
	}
	remove->next = NULL;

	deq->count--;
	return remove;
}
Node *dequeueBack(Deq *deq)
{
	Node *remove = deq->rear;

	if (isEmpty(deq))
		return NULL;

	if (getSize(deq) == 1)
	{
		deq->front = NULL;
		deq->rear = NULL;
	}
	else
	{
		deq->rear = remove->prev;
		deq->rear->next = NULL;
	}
	remove->prev = NULL;

	deq->count--;
	return remove;
}

int isEmpty(Deq *deq)
{
	return deq->count == 0;
}
int getSize(Deq *deq)
{
	return deq->count;
}
Node *getFront(Deq *deq)
{
	if (isEmpty(deq))
		return NULL;
	else
		return deq->front;
}
Node *getRear(Deq *deq)
{
	if (isEmpty(deq))
		return NULL;
	else
		return deq->rear;
}

int findTargetIndex(Deq *deq, int target)
{
	int index = 0;
	Node *current = deq->front;

	while (target != current->data)
	{
		current = current->next;
		index++;
	}

	return index;
}
void printDeq(Deq *deq)
{
	Node *current = deq->front;

	while (current != NULL)
	{
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

int main(void)
{
	int capacity, count;
	int turn = 0;
	int targets[51];
	Deq *deq;

	scanf("%d%d", &capacity, &count);
	deq = createDeq();
	for (int i = 0; i < capacity; i++)
	{
		enqueueBack(deq, createNode(i+1));
	}

	for(int i = 0; i < count; i++)
	{
		scanf("%d", &targets[i]);
	}

	for (int i = 0; i < count; i++)
	{
		int index;
	
		if (getSize(deq) == 1)
			break;

	      	index = findTargetIndex(deq, targets[i]);

		if (index <= getSize(deq) / 2)
		{
			while (index > 0)
			{
				enqueueBack(deq, dequeueFront(deq));
				turn++;
				index--;
			}
		}
		else
		{
			index = getSize(deq) - index;
			while (index > 0)
			{ 
				enqueueFront(deq, dequeueBack(deq));
				turn++;
				index--;
			}
		}
		dequeueFront(deq);
	}

	printf("%d\n", turn);
	destroyDeq(deq);
	exit(0);
}
