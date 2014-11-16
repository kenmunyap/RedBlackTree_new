#include <stdio.h>
#include "Rotation.h"
#include "Node.h"

void rightRotate(Node **nodePtr){

		Node *checkRightChild = (*nodePtr)->left; 
		Node *currentRoot = (*nodePtr)->left;
		Node *saveNode = currentRoot->right;
	
		(*nodePtr)->left = NULL; 
		if(checkRightChild->right != NULL){
			currentRoot->right = *nodePtr; 
			currentRoot->right->left = saveNode;
		}else{
			currentRoot->right = *nodePtr; 
		}
		*nodePtr = currentRoot; 
}

void leftRotate(Node **nodePtr){

	Node *checkLeftChild = (*nodePtr)->right;
	Node *currentRoot = (*nodePtr)->right;
	Node *saveNode = currentRoot->left;


		(*nodePtr)->right = NULL; 
		if(checkLeftChild->left != NULL){
			currentRoot->left = *nodePtr;
			currentRoot->left->right = saveNode;
		}else{
			currentRoot->left = *nodePtr;
		}
		*nodePtr = currentRoot;
}

void leftRightRotate(Node **nodePtr){
	leftRotate(&(*nodePtr)->left);
	rightRotate(*(&nodePtr));
}

void rightLeftRotate(Node **nodePtr){
	rightRotate(&(*nodePtr)->right);
	leftRotate(*(&nodePtr));
}




