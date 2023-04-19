// Binary Tree
#include <stdio.h>

// implement Binary Tree
typedef int BData;

typedef struct _bTreeNode
{
	BData item;
	struct _bTreeNode* left_child;
	struct _bTreeNode* right_child;
} BTreeNode;

// add BTree
int main(void)
{
	BTreeNode* n1 = (BTreeNode*)malloc(sizeof(BTreeNode));
	BTreeNode* n2 = (BTreeNode*)malloc(sizeof(BTreeNode));
	BTreeNode* n3 = (BTreeNode*)malloc(sizeof(BTreeNode));

	n1->item = 10;
	n1->left_child = n2;
	n1->right_child = NULL;

	n2->item = 20;
	n2->left_child = n3;
	n2->right_child = NULL;

	n3->item = 30;
	n3->left_child = NULL;
	n3->right_child = NULL;

	free(n1), free(n2), free(n3);
	return 0;
}

// Operations
BTreeNode* CreateNode(BData item) {
	BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
	node->item = item;
	node->left_child = NULL;
	node->right_child = NULL;
	return node;
}

void DestroyNode(BTreeNode* node)
{
	free(node);
}

void CreateLeftSubtree(BTreeNode* root, BTreeNode* left)
{
	if (root->left_child != NULL)
		exit(1);
	root->left_child = left;
}

void CreatRightSubtree(BTreeNode* root, BTreeNode* right)
{
	if (root->right_child != NULL)
		exit(1);
	root->right_child = right;
}

int main(void)
{
	BTreeNode* node1 = CreateNode(1);
	BTreeNode* node2 = CreateNode(2);
	BTreeNode* node3 = CreateNode(3);
	BTreeNode* node4 = CreateNode(4);
	BTreeNode* node5 = CreateNode(5);
	BTreeNode* node6 = CreateNode(6);

	CreateLeftSubtree(node1, node2);
	CreateRightSubtree(node1, node3);

	CreateLeftSubtree(node2, node4);
	CreateRightSubtree(node2, node5);
	CreateLeftSubtree(node3, node6);

	DestroyNode(node1);
	DestroyNode(node2);
	DestroyNode(node3);
	DestroyNode(node4);
	DestroyNode(node5);
	DestroyNode(node6);

	return 0;
}

// Total Nmber of Nodes
int Nodes(BTreeNode* node)
{
	int r = 0, l = 0;
	if (node->left_child != NULL)
		r = Nodes(node->left_child);
	if (node->right_child != NULL)
		l = Nodes(node->right_child);
	return 1 + r + l;
}

int Height(BTreeNode* node)
{
	int r = 0, l = 0;
	if (node->left_child != NULL)
		r = Height(node->left_child);
	if (node->right_child != NULL)
		l = Height(node->right_child);
	return 1 + max(r, l);
}