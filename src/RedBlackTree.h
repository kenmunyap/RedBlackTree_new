#ifndef RedBlackTree_H
#define RedBlackTree_H

#include "Node.h"

void addRedBlackTree(Node **rootPtr,Node *newNode);
void _addRedBlackTree(Node **rootPtr, Node *newNode);

Node *delRedBlackTree(Node **rootPtr,Node *newNode);
Node *_delRedBlackTree(Node **rootPtr,Node *newNode);

void caseOneLeftRemove(Node **rootPtr,Node *removedNode);
void caseTwoLeftRemove(Node **rootPtr,Node *removedNode);
void caseThreeLeftRemove(Node **rootPtr,Node *removedNode);

void caseOneRightRemove(Node **rootPtr,Node *removedNode);
void caseTwoRightRemove(Node **rootPtr,Node *removedNode);
void caseThreeRightRemove(Node **rootPtr,Node *removedNode);

void caseTotalRemove(Node **rootPtr,Node *removedNode);
Node *removeNextLargerSuccessor(Node **parentPtr);

int isRed(Node *node);
int isBlack(Node *node);
int isDouble(Node *node, Node *removedNode);

#endif // RedBlackTree_H
