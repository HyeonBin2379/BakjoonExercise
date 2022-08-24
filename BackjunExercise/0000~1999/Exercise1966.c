#include <stdio.h>
#include <stdlib.h>

#define SIZE 101

typedef struct tagNode
{
	int key;
	int index;
	int target;
} Node;

typedef struct tagQueue
{
	Node queue[SIZE];
	int front;
	int rear;
	int size;
} Queue;

void initQueue(Queue* q)
{
	q->front = 0;
	q->rear = 0;
	q->size = 0;
}

int isEmpty(Queue* q)
{
	return q->rear == q->front;
}

int isFull(Queue* q)
{
	return (q->rear + 1) % SIZE == q->front;
}

void enqueue(Queue* q, Node e)
{
	int position = q->rear;

	if (isFull(q))
		return;

	q->rear = (position + 1) % SIZE;
	q->queue[q->rear] = e;
	q->size++;
}

Node dequeue(Queue* q)
{
	int position = q->front;

	if (isEmpty(q))
		exit(1);

	q->front = (position + 1) % SIZE;
	q->size--;
	return q->queue[q->front];
}

void printQueue(Queue* q)
{
	int idx = (q->front + 1) % SIZE;

	for (int i = 0; i < q->size; i++)
	{
		printf("%d[%d %d] ", q->queue[idx].index, q->queue[idx].key, q->queue[idx].target);
		idx = (idx + 1) % SIZE;
	}
	printf("\n");
}

int isLarge(Queue* q)
{
	int idx, max;

	if (isEmpty(q))
		return -1;

	idx = (q->front + 1) % SIZE;
	max = q->queue[idx].key;

	for (int i = 0; i < q->size - 1; i++)
	{
		idx = (idx + 1) % SIZE;
		if (max < q->queue[idx].key)
			return 1;
	}
	
	return 0;
}

int main(void)
{
	Queue q; 
	Node tmp;
	int test_case;

	scanf("%d", &test_case);

	for (int i = 0; i < test_case; i++)
	{
		int n, m, cnt;
		scanf("%d%d", &n, &m);

		initQueue(&q);
		cnt = 0;

		for (int j = 0; j < n; j++)
		{
			scanf("%d", &tmp.key);
			tmp.index = j;
			
			if (j == m)
				tmp.target = 1;
			else
				tmp.target = 0;

			enqueue(&q, tmp);
		}

		do
		{
			while (isLarge(&q) != 0)
			{
		//		printQueue(&q);
				tmp = dequeue(&q);
		//		printQueue(&q);
				enqueue(&q, tmp);
			}

		//	printQueue(&q);
			tmp = dequeue(&q);
			cnt++;
		} while (tmp.target != 1);

		printf("%d\n", cnt);
	}

	exit(0);
}
