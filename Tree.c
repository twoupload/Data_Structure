// 연결 리스트로 구현하는 Tree

#include <stdio.h>

// 생성.
typedef int BData;

typedef struct _bTreeNode
{
	BTreeNode* item;
	struct _bTreeNode* left_child;
	struct _bTreeNode* Right_child;
}BTreeNode;

// 옵션.
// Create a new node.
BTreeNode* createNode(BData item);
// Destory a node.
void DestroyNode(BTreeNode* node);
// Conect the root a left-side node
void CreateLeftSubtree(BTreeNode* root, BTreeNode* left);
// Conect the root a right-side node.
void CreateLeftSubtree(BTreeNode* root, BTreeNode* left);
// Traverse a tree.
void Inorder(BTreeNode* root);
void Preorder(BTreeNode* root);
void Postorder(BTreeNode* root);
void Levelorder(BTreeNode* root);

// 예1)
int main(void)
{
	BTreeNode* n1 = (BTreeNode*)malloc(sizeof(BTreeNode));
	BTreeNode* n2 = (BTreeNode*)malloc(sizeof(BTreeNode));
	BTreeNode* n3 = (BTreeNode*)malloc(sizeof(BTreeNode));

	n1->item = 10;
	n1->left_child = n2;
	n1->Right_child = NULL;

	n2->item = 20;
	n2->left_child = n3;
	n2->Right_child = NULL;

	n3->item = 30;
	n3->left_child = NULL;
	n3->Right_child = NULL;

	free(n1), free(n2), free(n3);
	return 0;
}

BTreeNode* CreateNode(BData item) {
	BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
	node->item = item;
	node->left_child = NULL;
	node->Right_child = NULL;

	return node;
}

void DestroyNode(BTreeNode* node)
{
	free(node);
}

void CreateLeftSubtree(BTreeNode* root, BTreeNode* left)
{
	if (root->left_child != NULL) exit(1);
	root->left_child = left;
}

void CreateRightSubtree(BTreeNode* root, BTreeNode* Right)
{
	if (root->Right_child != NULL) exit(1);
	root->Right_child = Right;
}

// 예2)
// 이진 트리의 노드 수 계산하기

int Nodes(BTreeNode* node)
{
	int r = 0, l = 0;
	if (node->Right_child != NULL)
		r = Nodes(node->Right_child);
	if (node->left_child != NULL)
		l = Nodes(node->left_child);
	return 1 + r + l;
}

// 예3)
// 이진 트리의 길이 계산하기
int Height(BTreeNode* node)
{
	int r = 0, l = 0;
	if (node->Right_child != NULL)
		r = Nodes(node->Right_child);
	if (node->left_child != NULL)
		l = Nodes(node->left_child);
	return 1 + max(r, l);
}