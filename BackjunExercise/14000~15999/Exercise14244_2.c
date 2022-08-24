#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode
{
	int data;
	int parent;
	struct tagNode *leftChild;
	struct tagNode *rightSibling;
} Node;

Node *createNode(int newData)
{
	Node *newNode = (Node *)malloc(sizeof(Node));

	newNode->data = newData;
	newNode->parent = -1;
	newNode->leftChild = NULL;
	newNode->rightSibling = NULL;

	return newNode;
}
void destroyNode(Node *node)
{
	free(node);
}
void destroyTree(Node *root)
{
	if (root->rightSibling != NULL)
		destroyTree(root->rightSibling);
	if (root->leftChild != NULL)
		destroyTree(root->leftChild);
	
	root->rightSibling = NULL;
	root->leftChild = NULL;

	destroyNode(root);
}
void addChildNode(Node *parent, Node *child)
{
	if (parent->leftChild == NULL)
	{
		parent->leftChild = child;
		child->parent = parent->data;
	}
	else
	{
		Node *temp = parent->leftChild;
		child->parent = temp->data;
		while (temp->rightSibling != NULL)
		{
			temp = temp->rightSibling;
		}

		temp->rightSibling = child;
	}
}
void printTree(Node *root, int depth)
{
	if (root->parent >= 0)
		printf("%d %d\n", root->parent, root->data);

	if (root->leftChild != NULL)
		printTree(root->leftChild, depth+1);
	if (root->rightSibling != NULL)
		printTree(root->rightSibling, depth);
}
void printNodesAtLevel(Node *node, int level)
{
	if (node == NULL && level < 0)
		return;

	if (level == 0 && node->leftChild == NULL)
		printf("%d %d\n", node->parent, node->data);

	printTree(node->leftChild, level-1);
	printTree(node->rightSibling, level);

}

int main(void)
{
	int n, m;
	Node *arr[50];
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		arr[i] = createNode(i);
	}
	
	for (int i = 0; i < n-1; i++)
	{
		if (0 < i && i < m) 
			addChildNode(arr[0], arr[i+1]);
		else
			addChildNode(arr[i], arr[i+1]);
	}

	printTree(arr[0], 0);
	exit(0);
}
