#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int getSize(Deq *deq)
{
	return deq->count;
}
int isEmpty(Deq *deq)
{
	return deq->count == 0;
}
ElementType getFront(Deq *deq)
{
	if (isEmpty(deq))
		return -1;
	else
		return deq->front->data;
}
ElementType getRear(Deq *deq)
{
	if (isEmpty(deq))
		return -1;
	else
		return deq->rear->data;
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
void enqueueFront(Deq *deq, Node *newFront)
{
	if (isEmpty(deq))
	{
		deq->front = newFront;
		deq->rear = newFront;
	}
	else
	{
		newFront->next = deq->front;
		deq->front->prev = newFront;
		deq->front = newFront;
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
ElementType dequeueFront(Deq *deq)
{
	Node *remove = deq->front;
	ElementType rdata;

	if (isEmpty(deq)) {
		return -1;
	}

	rdata = remove->data;
	if (deq->count == 1)
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
	return rdata;
}
ElementType dequeueBack(Deq *deq)
{
	Node *remove = deq->rear;
	ElementType rdata;

	if (isEmpty(deq)) {
		return -1;
	}

	rdata = remove->data;
	if (deq->count == 1)
	{
		deq->rear == NULL;
		deq->front == NULL;
	}
	else
	{
		deq->rear = remove->prev;
		deq->rear->next = NULL;
	}
	remove->prev = NULL;

	deq->count--;
	return rdata;
}


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

int main(void)
{
	int testCase;
	Deq *deq;

	scanf("%d", &testCase);
	deq = createDeq();

	for (int i = 0; i < testCase; i++)
	{
		char order[11] = {0, };
		scanf("%s", order);

		if (strcmp(order, "push_front") == 0)
		{
			int val;

			scanf("%d", &val);
			enqueueFront(deq, createNode(val));
		}
		else if (strcmp(order, "push_back") == 0)
		{
			int val;

			scanf("%d", &val);
			enqueueBack(deq, createNode(val));
		}	
		else if (strcmp(order, "pop_back") == 0)
		{
			int val = dequeueBack(deq);
			
			printf("%d\n", val);
		}
		else if (strcmp(order, "pop_front") == 0)
		{
			int val = dequeueFront(deq);
			
			printf("%d\n", val);
		}
		else if (strcmp(order, "size") == 0)
		{
			printf("%d\n", getSize(deq));
		}
		else if (strcmp(order, "empty") == 0)
		{
			printf("%d\n", isEmpty(deq));
		}
		else if (strcmp(order, "front") == 0)
		{
			printf("%d\n", getFront(deq));
		}
		else if (strcmp(order, "back") == 0)
		{
			printf("%d\n", getRear(deq));
		}
		else;
	}

	destroyDeq(deq);
	exit(0);
}
