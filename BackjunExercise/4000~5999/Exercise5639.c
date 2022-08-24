#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10000

typedef struct tagNode
{
	int data;
	struct tagNode *left;
	struct tagNode *right;
} Node;

Node *createNode(int newData)
{
	Node *newNode = (Node *)malloc(sizeof(Node));

	newNode->data = newData;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}
void destroyNode(Node *node)
{
	free(node);
}
void destroyTree(Node *root)
{
	if (root->left != NULL)
		destroyTree(root->left);
	if (root->right != NULL)
		destroyTree(root->right);

	root->left = NULL;
	root->right = NULL;

	destroyNode(root);
}

void postorderPrintTree(Node *root)
{
	if (root == NULL)
		return;

	postorderPrintTree(root->left);
	postorderPrintTree(root->right);
	printf("%d\n", root->data);
}
void makePreorderTree(Node **tree, int val)
{
	if ((*tree) == NULL)
	{
		(*tree) = createNode(val);
		return;
	}
	else if ((*tree)->data > val)
	{
		makePreorderTree(&(*tree)->left, val);
	}
	else if ((*tree)->data < val)
	{
		makePreorderTree(&(*tree)->right, val);
	}
}

int main(void)
{
	int size = 0;
	int val;
	Node *root = NULL;

	while (scanf("%d", &val) != EOF)
	{
		makePreorderTree(&root, val);
	}

	postorderPrintTree(root);
	destroyTree(root);
}
