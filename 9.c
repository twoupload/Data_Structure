#include <stdio.h>
#include <stdbool.h>

// 이진 트리의 구조 생성
typedef int Key;
typedef struct _BSTNode
{
	Key key;
	struct _bTreeNode* left_child;
	struct _bTreeNode* right_child;
}BSTNode;

// Operation
BSTNode* CreateNode(Key key);
void DestroyNode(BSTNode* node);
bool Verify(BSTNode* root)
{
	if (root != NULL)
	{
		if (root->key <= min || root->key >= max) return false;
		else return Verify(root->left_child, min, root->key) && Verify(root->right_child, root->key, max);
	}
	else
		return true;
}

BSTNode* Search(BSTNode* root, Key key)
{
	if (root == NULL || root->key == key) return root;
	else if (root->key > key) return Search(root->left_child, key);
	else return Search(root->right_child, key);
}

//반복문을 이용한 방법
/*
BSTNode* Search(BSTNode* root, Key key)
{
	BSTNode* cur = root;
	while (cur != NULL) {
		if (cur->key == key) break;
		else if (cur->key > key) cur = cur->left_child;
		else cur = cur->right_child;
	}
	return cur;
}
*/

void Insert(BSTNode* root, Key key)
{
	if (root->key == key) exit(1);
	else if (root->key > key) {
		if (root->left_child == NULL)
			CreateLeftSubtree(root, key);
		else
			Insert(root->left_child, key);
	}
	else {
		if (root->right_child == NULL)
			CreateRightSubtree(root, key);
		else
			Insert(root->right_child, key);
	}
}


void Insert(BSTNode* root, Key key)
{
	BSTNode* cur = root;
	while (cur != NULL) {
		if (cur->key > key) {
			if (cur->left_child == NULL) {
				CreateLeftSubtree(cur, key);
				break;
			}
			else
				cur = cur->left_child;
		}
		else {
			if (cur->right_child == NULL) {
				CreateRightSubtree(cur, key);
				break;
			}
			else
				cur = cur->right_child;
		}
	}
}

BSTNode* Remove(BSTNode* root, Key key)
{
	BSTNode* cur = root;
	if (root->left_child == NULL && root->right_child == NULL) {
		DestroyNode(cur);
		root = NULL;
	}
	else if (root->left_child == NULL || root->right_child == NULL) {
		if (root->left_child != NULL) {
			root = root->left_child;
			DestroyNode(cur);
		}
		else {
			root = root->right_child;
			DestoryNode(cur);
		}
	}
	else {
		cur = cur->right_child;
		while (cur->left_child != NULL)
			cur = cur->left_child;
		root->key = cur->key;
		root->right_child = Remove(root->right_child, cur->key);
	}
	return root;
}

BSTNode* Remove(BSTNode* root, Key key)
{
	BSTNode* cur = root, * parent = NULL;
	while (cur != NULL && cur->key != key) {
		parent = cur;
		if (cur->key > key)
			cur = cur->left_child;
		else
			cur = cur->right_child;
	}

	if (cur == NULL) exit(1);
	if (cur->left_child == NULL && cur->right_child == NULL) {
		if (parent != NULL) {
			if (parent->left_child == cur)
				parent->left_child = NULL;
			else
				parent->right_child = NULL;
		}
		else
			root = NULL;
	}

	else if (cur->left_child == NULL || cur->right_child == NULL) {
		BSTNode* child;
		if (cur->left_child != NULL)
			child = cur->left_child;
		else
			child = cur->right_child;
		if (parent != NULL) {
			if (parent->left_child == cur)
				parent->left_child == child;
			else
				parent->right_child = child;
		}
		else {
			root = child;
		}
	}
	else {
		BSTNode* succ_parent = cur, * succ = cur->right_child;
		while (succ->left_child != NULL) {
			succ_parent = succ;
			succ = succ->left_child;
		}
		if (succ_parent->right_child == succ)
			succ_parent->right_child = succ->right_child;
		else
			succ_parent->left_child = succ->right_child;
		cur->key = succ->key;
		cur = succ;
	}
	DestroyNode(cur);
	return root;
}
void Traverse(BSTNode* root);
void ClearTree(BSTNode* root);