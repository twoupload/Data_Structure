#include <stdio.h>
#include <stdbool.h>
typedef int BData;

typedef struct _bTreeNode
{
	BData item;
	struct _bTreeNode* left_child;
	struct _bTreeNode* right_child;
}BTreeNode;

BTreeNode* CreateNode(BData item)
{
	BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
	node->item = item;
	node->left_child = NULL;
	node->right_child = NULL;

	return node;
}

void DestoryNode(BTreeNode* node)
{
	free(node);
}

void CreateLeftSubtree(BTreeNode* root, BTreeNode* left)
{
	if (root->left_child != NULL)
	{
		exit(1);
	}
	root->left_child = left;
}

void CreateRightSubtree(BTreeNode* root, BTreeNode* right)
{
	if (root->right_child != NULL)
	{
		exit(1);
	}
	root->left_child = right;
}


// Inorder Tree
void Inorder(BTreeNode* root)
{ // LCR
	if (root != NULL)
	{
		Inorder(root->left_child);
		printf("%d ", root->item);
		Inorder(root->right_child);
	}
}

// Preorder Tree
void Preorder(BTreeNode* root) 
{
	// CLR
	if (root != NULL)
	{
		printf("%d ", root->item);
		Preorder(root->left_child);
		Preorder(root->right_child);
	}
}

// Postorder Tree
void Postorder(BTreeNode* root)
{
	if (root != NULL)
	{
		Postorder(root->left_child);
		Postorder(root->right_child);
		printf("%d ", root->item);
	}
}

// levelorder Tree
void Levelorder(BTreeNode* root)
{
	Queue queue;
	if (root == NULL) return;

	InitQueue(&queue);
	EnQueue(&queue, root);
	while (!IsEmpty(&queue))
	{
		root = Peek(&queue);
		Dequeue(&queue);

		printf("%d ", root->item);
		if (root->left_child != NULL)
			EnQueue(&queue, root->left_child);
		if (root->right_child != NULL)
			EnQueue(&queue, root->right_child);
	}
}

// Calculating Directory Size
int CalDirectorySize(BTreeNode* root)
{
	int left_size, right_size;
	if (root == NULL) return 0;
	else {
		left_size = CalDirectorySize(root->left_child);
		right_size = CalDirectorySize(root->right_child);
		return (root->item + left_size + right_size);
	}
}

// Calculating Expreession Tree
int CalculateExpTree(BTreeNode* root)
{
	int op1, op2;
	if (root == NULL) return 0;
	if (root->left_child == NULL && root->right_child == NULL)
		return root->item;
	op1 = CalculateExpTree(root->left_child);
	op2 = CalculateExpTree(root->right_child);

	switch (root->item)
	{
		case '+': return op1 + op2;
		case '-': return op1 - op2;
		case '*': return op1 * op2;
		case '/': return op1 / op2;
	}
	return 0;
}

//Building Expreesion Tree
BTreeNode* MakeExpTree(char* exp, int len)
{
	Stack stack;
	BTreeNode* node, * right_node, * left_node;

	InitStack(&stack);
	for (int i = 0; i < len; i++) {
		if ('0' <= exp[i] && exp[i] <= '9')
			node = CreateNode(exp[i]);
		else {
			right_node = Peek(&stack), Pop(&stack);
			left_node = Peek(&stack), Pop(&stack);

			node = CreateNode(exp[i]);
			CreateRightSubtree(node, right_node);
			CreateLeftSubtree(node, left_node);
		}
		Push(&stack, node);
	}
	return Peek(&stack);
}

// Threaded Binary Tree

typedef int BData;
typedef struct _bTreeNode
{
	BData item;
	struct _bTreeNode* left_child;
	struct _bTreeNode* right_child;
	bool isThreaded;
}BTreeNode;

BTreeNode* leftMost(BTreeNode* node)
{
	if (node == NULL) return NULL;
	while (node->left_child != NULL)
		node = node->left_child;
	return node;
}

void inorder(BTreeNode* node)
{
	BTreeNode* cur = leftMost(node);
	while (cur != NULL) {
		printf("%d ", node->item);

		if (cur->isThreaded)
			cur = cur->right_child;
		else
			cur = leftMost(cur->right_child);
	}
}