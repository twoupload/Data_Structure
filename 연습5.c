#include <stdio.h>

typedef struct BSTree {
	int key;
	struct BSTree* leftChild;
	struct BSTree* rightChild;
}BST;

BST* createNode(int key) {
	BST* root = (BST*)malloc(sizeof(BST));
	root->key = key;
	root->leftChild = NULL;
	root->rightChild = NULL;
	return root;
}

void desNode(BST* root) {
	free(root);
}

void cLeftSubTree(BST* root, int key) {
	if (root->leftChild != NULL) exit(1);
	root->leftChild = key;
}

void cRightSubTree(BST* root, int key) {
	if (root->rightChild != NULL) exit(1);
	root->rightChild = key;
}

BST* Search(BST* root, int key) {
	if (root == NULL || root->key == key) return root;
	else if (root->key > key) return Search(root->leftChild, key);
	else return Search(root->rightChild, key);
}

BST* Insert(BST* root, int key) {
	if (root == NULL) createNode(key);
	if (key < root->key) {
		root->leftChild = Insert(root->leftChild, key);
		root = ReBalancing(root);
		return root;
	}
	else if (key > root->key) {
		root->rightChild = Insert(root->rightChild, key);
		root = ReBalancing(root);
		return root;
	}
	else exit(1);
}

int GetBalancingFactor(BST* root) {
	if (root == NULL) return 0;
	return GetHeight(root->rightChild)
}