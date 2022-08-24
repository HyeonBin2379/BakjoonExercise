#include <stdio.h>
#include <stdlib.h>

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

Node *makePreorder(int *inorder, int *postorder, int start, int end, int *nextroot)
{
	Node *root;
	int i;

	if (start > end) {
		return NULL;
	}

	root = createNode(postorder[(*nextroot)--]);
	for (i = start; i <= end; i++)
	{
		if (inorder[i] == root->data)
			break;
	}

	root->right = makePreorder(inorder, postorder, i+1, end, nextroot);
	root->left = makePreorder(inorder, postorder, start, i-1, nextroot);
	return root;
}

Node *makeTree(int *inorder, int *postorder, int rootIndex)
{
	int *pIndex = &rootIndex;
	return makePreorder(inorder, postorder, 0, rootIndex, pIndex);
}

void preorderPrintTree(Node *root)
{
	if (root == NULL)
		return;

	printf("%d ", root->data);
	preorderPrintTree(root->left);
	preorderPrintTree(root->right);
}

int main(void)
{
	int nodeCount;
	int *inorder, *postorder;
	Node *root;

	scanf("%d", &nodeCount);
	inorder = (int *)malloc(sizeof(int) * nodeCount);
	postorder = (int *)malloc(sizeof(int) * nodeCount);
	for (int i = 0; i < nodeCount; i++)
	{
		scanf("%d", &inorder[i]);
	}
	for (int i = 0; i < nodeCount; i++)
	{
		scanf("%d", &postorder[i]);
	}

	root = makeTree(inorder, postorder, nodeCount-1);
	preorderPrintTree(root);
	printf("\n");

	destroyTree(root);
	free(inorder);
	free(postorder);
	exit(0);
}
