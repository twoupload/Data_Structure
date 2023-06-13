#include <stdio.h>

// 이진 트리의 생성
typedef int BData;
typedef struct _bTreeNode
{
	BData item;
	struct _bTreeNode* leftChild;
	struct _bTreeNode* rightChild;
}BTreeNode;

// 관련된 함수
BTreeNode* createNode(BData item)
{
	BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
	node->item = item;
	node->leftChild = NULL;
	node->rightChild = NULL;
	return node;
}

void destoryNode(BTreeNode* node)
{
	free(node);
}

void createLeftSubtree(BTreeNode* node, BTreeNode* left)
{
	if (node->leftChild != NULL) exit(1);
	node->leftChild = left;
}

void createRightSubtree(BTreeNode* node, BTreeNode* right)
{
	if (node->rightChild != NULL) exit(1);
	node->rightChild = right;
}

// Traversal
void Inorder(BTreeNode* root)
{
	if (root != NULL)
	{
		Inorder(root->leftChild);
		printf("%d ", root->item);
		Inorder(root->rightChild);
	}
}

void Preorder(BTreeNode* root)
{
	if (root != NULL)
	{
		printf("%d ", root->item);
		Preorder(root->leftChild);
		Preorder(root->rightChild);
	}
}

void Postorder(BTreeNode* root)
{
	Postorder(root->leftChild);
	Postorder(root->rightChild);
	printf("%d ", root->item);
}

void Levelorder(BTreeNode* root)
{
	Queue queue;
	if (root == NULL) return;

	InitQueue(&queue);
	EnQueue(&queue, root);

	while (!IsEmpty(&queue))
	{
		root = Peek(&queue);
		DeQueue(&queue);

		printf("%d ", root->item);

		if (root->leftChild != NULL)
			EnQueue(&queue, root->leftChild);
		if (root->rightChild != NULL)
			EnQueue(&queue, root->rightChild);
	}
}

// Calculating Directory Size
int CalDirectorySize(BTreeNode* root)
{
	int leftSize, rightSize;
	if (root == NULL) return 0;
	else
	{
		leftSize = CalDirectorySize(root->leftChild);
		rightSize = CaldirectorySize(root->rightChild);
		return (root->item + rightSize + leftSize);
	}
}

// CarculateExpTree
int CarExpTree(BTreeNode* root)
{
	int op1, op2;
	if (root == NULL) return 0;
	if (root->leftChild == NULL && root->rightChild == NULL) return root->item;
	op1 = CalExpTree(root->leftChild);
	op2 = CalExpTree(root->rightChild);

	switch (root->item)
	{
	case '+': return op1 + op2;
	case '-': return op1 - op2;
	case '*': return op1 * op2;
	case '/': return op1 / op2;
	}
	return 0;
}