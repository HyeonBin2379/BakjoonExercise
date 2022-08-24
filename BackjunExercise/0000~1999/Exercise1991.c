#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagNode
{
	char data;

	struct tagNode * left;
	struct tagNode * right;
} Node;

Node * createNode(char newData)
{
	Node * newNode = (Node *)malloc(sizeof(Node));

	newNode->data = newData;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}
void destroyNode(Node * node)
{
	free(node);
}
void destroyTree(Node * root)
{
	if (root == NULL)
		return;

	destroyTree(root->left);
	destroyTree(root->right);
	destroyNode(root);
}

void preorderPrintTree(Node * node)
{
	if (node == NULL)
		return;

	printf("%c", node->data);
	preorderPrintTree(node->left);
	preorderPrintTree(node->right);
}
void inorderPrintTree(Node * node)
{
	if (node == NULL)
		return;

	inorderPrintTree(node->left);
	printf("%c", node->data);
	inorderPrintTree(node->right);
}
void postorderPrintTree(Node * node)
{
	if (node == NULL)
		return;

	postorderPrintTree(node->left);
	postorderPrintTree(node->right);
	printf("%c", node->data);
}

int main(void)
{
	Node* treeNodes[26];
	char input[26][3] = {0, };
	int test;

	scanf("%d", &test);
	getchar();
	for (int i = 0; i < test; i++)
	{
		for (int j = 0; j < 3; j++) {
			scanf("%c", &input[i][j]);
			getchar();
		}

		treeNodes[i] = createNode(i + 'A');
	}

	/*
	forr (int i = 0; i < test; i++)
	{
		for (int j = 0; j < 3; j++)
			printf("%c ", input[i][j]);
		printf("\n");
	}
	*/

	for (int i = 0; i < sizeof(input)/sizeof(input[0]); i++)
	{
		for (int j = 1; j < strlen(input[i]); j++)
		{
			switch (j)
			{
			case 1:
				if (input[i][j] != '.')
					treeNodes[input[i][0] - 'A']->left = treeNodes[input[i][j] - 'A'];
				break;
			case 2:
				if (input[i][j] != '.')
					treeNodes[input[i][0] - 'A']->right = treeNodes[input[i][j] - 'A'];
				break;
			}
		}
	}

	preorderPrintTree(treeNodes[0]);
	printf("\n");
	inorderPrintTree(treeNodes[0]);
	printf("\n");
	postorderPrintTree(treeNodes[0]);
	printf("\n");

	destroyTree(treeNodes[0]);
	exit(0);
}
