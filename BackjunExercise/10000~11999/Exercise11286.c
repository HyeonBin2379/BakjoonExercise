#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct tagHeap
{
	ElementType *arr;
	int capacity;
	int size;
} Heap;

Heap *createHeap(int capacity)
{
	Heap *newHeap = (Heap *)malloc(sizeof(Heap));

	newHeap->capacity = capacity;
	newHeap->size = 0;
	newHeap->arr = (ElementType *)calloc(capacity, sizeof(ElementType));

	return newHeap;
}
void destroyHeap(Heap *heap)
{
	free(heap->arr);
	free(heap);
}
void insertData(Heap *heap, ElementType newData)
{
	int currentPos = ++heap->size;

	while (currentPos != 1 && abs(newData) <= abs(heap->arr[currentPos/2]))
	{
		if (abs(newData) == abs(heap->arr[currentPos/2])
				&& newData > heap->arr[currentPos/2])
			break;

		heap->arr[currentPos] = heap->arr[currentPos/2];
		currentPos /= 2;
	}

	heap->arr[currentPos] = newData;
}
void swap(ElementType *elem1, ElementType *elem2)
{
	int temp = *elem1;
	*elem1 = *elem2;
	*elem2 = temp;
}
ElementType deleteData(Heap *heap)
{
	int remove = heap->arr[1];
	int parent = 1;
	int child = 2;

	if (heap->size == 0)
		return 0;

	heap->arr[1] = heap->arr[heap->size--];
	while (child <= heap->size)
	{
		if (child < heap->size && abs(heap->arr[child]) > abs(heap->arr[child+1]))
			child++;
		else if (child < heap->size && (abs(heap->arr[child]) == abs(heap->arr[child+1])
				&& heap->arr[child] > heap->arr[child+1]))
			child++;

		if (abs(heap->arr[child]) > abs(heap->arr[parent]))
			break;
		else if (abs(heap->arr[child]) == abs(heap->arr[parent]) && heap->arr[child] > heap->arr[parent])
			break;

		swap(&heap->arr[parent], &heap->arr[child]);
		parent = child;
		child = parent*2;
	}

	return remove;
}

int main(void)
{
	int capacity;
	int zeroCnt = 0;
	Heap *heap;

	scanf("%d", &capacity);
	heap = createHeap(capacity);

	for (int i = 0; i < capacity; i++)
	{
		int val;

		scanf("%d", &val);

		if (val != 0)
			insertData(heap, val);
		else
			printf("%d\n", deleteData(heap));
	}

	destroyHeap(heap);
	exit(0);
}
