#include <stdio.h>
#include <stdlib.h>

typedef enum visitMode 
{visited, notVisited}
Mode;
typedef int ElementType;
typedef struct tagVertex
{
	ElementType data;
	Mode visit;
	int index;
	int rank;

	int capacity;
	int eCount;
	struct tagEdge *adjList;
} Vertex;
typedef struct tagEdge
{
	Vertex *from;
	Vertex *target;
	int index;
} Edge;
typedef struct tagGraph
{
	Vertex *vertices;
	int vCount;
	int capacity;
} Graph;

typedef struct tagInput
{
	int from;
	int target;
} Input;

void createEdge(Edge **edge, Vertex *from, Vertex *target)
{
	(*edge) = (Edge *)malloc(sizeof(Edge));

	(*edge)->from = from;
	(*edge)->target = target;
	(*edge)->index = -1;
}
void destroyEdge(Edge *edge)
{
	free(edge);
}
void createVertex(Vertex **vertex, ElementType newData, int capacity)
{
	(*vertex) = (Vertex *)malloc(sizeof(Vertex));

	(*vertex)->data = newData;
	(*vertex)->index = -1;
	(*vertex)->rank = 0;
	(*vertex)->visit = notVisited;

	(*vertex)->adjList = (Edge *)malloc(sizeof(Edge) * capacity);
	(*vertex)->eCount = 0;
	(*vertex)->capacity = capacity;
}
void destroyVertex(Vertex *vertex)
{
	destroyEdge(vertex->adjList);
}
void createGraph(Graph **graph, int capacity)
{
	(*graph) = (Graph *)malloc(sizeof(Graph));

	(*graph)->vertices = (Vertex *)malloc(sizeof(Vertex)*capacity);
	(*graph)->vCount = 0;
	(*graph)->capacity = capacity;
}
void destroyGraph(Graph *graph)
{
	free(graph);
}

void addEdge(Vertex *vertex, Edge *newEdge)
{
	Edge *current = vertex->adjList;

	if (vertex->eCount == vertex->capacity)
		return;

	current[vertex->eCount] = *newEdge;
	current[vertex->eCount].index = vertex->eCount++;
	destroyEdge(newEdge);
}
void addVertex(Graph **graph, Vertex *newVertex)
{
	Vertex *current = (*graph)->vertices;

	if ((*graph)->vCount == (*graph)->capacity)
		return;

	current[(*graph)->vCount] = *newVertex;
	current[(*graph)->vCount].index = (*graph)->vCount++;
	destroyVertex(newVertex);
}
void printGraph(Graph *graph)
{
	Vertex *vertex = graph->vertices;
	Edge *edge = NULL;

	if (graph->vCount == 0)
		return;

	for (int i = 0; i < graph->vCount; i++)
	{
		printf("%d: ", vertex[i].data);

		if (vertex[i].eCount == 0)
		{
			printf("\n");
			continue;
		}

		edge = vertex[i].adjList;
		for (int j = 0; j < vertex[i].eCount; j++)
		{
			printf("%d ", edge[j].target->data);
		}

		printf("\n");
	}

	printf("\n");
}
int compare(const void *_elem1, const void *_elem2)
{
	Input *elem1 = (Input *)_elem1;
	Input *elem2 = (Input *)_elem2;

	if (elem1->from > elem2->from)
		return 1;
	else if (elem1->from < elem2->from)
		return -1;
	else
	{
		if (elem1->target > elem2->target)
			return 1;
		else if (elem1->target < elem2->target)
			return -1;
	}
	return 0;
}
void dfs(Vertex *v, int prior)
{
	Edge *e = NULL;

	v->visit = visited;
	v->rank = prior;
	e = v->adjList;

	for (int i = 0; i < v->eCount; i++)
	{
		if (e[i].target != NULL && e[i].target->visit == notVisited)
		{
			dfs(e[i].target, prior+1);
		}
	}
}

int main(void)
{
	int vCount, eCount, start;
	Graph *graph;
	Vertex *v;
	Input *arr;

	// 그래프 정점 생성
	scanf("%d%d%d", &vCount, &eCount, &start);
	createGraph(&graph, vCount);
	for (int i = 0; i < vCount; i++)
	{
		createVertex(&v, i+1, eCount);
		addVertex(&graph, v);
	}

	// 그래프 간선값 입력 및 오름차순 정렬
	arr = (Input *)malloc(sizeof(Input) * eCount);
	for (int i = 0; i < eCount; i++)
	{
		scanf("%d%d", &arr[i].from, &arr[i].target);
	}
	qsort(arr, eCount, sizeof(Input), compare); 

	// 그래프 간선 추가
	for (int i = 0; i < eCount; i++)
	{
		Edge *e;
		int from = arr[i].from-1;
		int target = arr[i].target-1;

		createEdge(&e, &graph->vertices[from], &graph->vertices[target]);
		addEdge(&graph->vertices[from], e);
		createEdge(&e,  &graph->vertices[target], &graph->vertices[from]);
		addEdge(&graph->vertices[target], e);
	}

	// 깊이우선탐색 및 순위 설정
	dfs(&graph->vertices[start-1], 1);

	// 결과 출력
	for (int i = 0; i < vCount; i++)
	{
		printf("%d\n", graph->vertices[i].rank);
	}

	// 메모리 할당 해제
	destroyGraph(graph);
	exit(0);
}
