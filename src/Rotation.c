#include <stdio.h>
#include "Rotation.h"
#include "Node.h"

/**
 *  Title : Right Rotate
 *  Objective : Right Rotate node
 *  Input : nodePtr
 *  Return : None
 */
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

/**
 *  Title : Left Rotate
 *  Objective : Left Rotate Node
 *  Input : nodePtr
 *  Return : None
 */
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

/**
 *  Title : Left Right Rotate
 *  Objective : Left rotate node, then Right Rotate Node
 *  Input : nodePtr
 *  Return : None
 *  Call funtion of leftRotate and rightRotate
 */
void leftRightRotate(Node **nodePtr){
	leftRotate(&(*nodePtr)->left);
	rightRotate(*(&nodePtr));
}

/**
 *  Title : Right Left Rotate
 *  Objective : Right rotate node, then Left Rotate Node
 *  Input : nodePtr
 *  Return : None
 *  Call funtion of rightRotate and leftRotate
 */
void rightLeftRotate(Node **nodePtr){
	rightRotate(&(*nodePtr)->right);
	leftRotate(*(&nodePtr));
}




