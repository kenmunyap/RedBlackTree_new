#include <stdio.h>
#include "Rotation.h"
#include "RedBlackTree.h"
#include "ErrorCode.h"
#include "Node.h"
#include "InitNode.h"
#include "CException.h"

/**
 *  Title : _addRedBlackTree
 *  Objective : to recursive add to red black tree and balance it
 *  Input : rootPtr and newNode
 *  Return : recursive _addRedBlackTree
 *  root > newNode go left side
 *  root < newNode go right side
 *  balance the tree after adding
 */
void _addRedBlackTree(Node **rootPtr, Node *newNode){
		
		if(*rootPtr == NULL){
			*rootPtr = newNode;
			(*rootPtr)->color = 'r';
			return;
		}
        
        if((*rootPtr)->left != NULL && (*rootPtr)->right != NULL){
            if((*rootPtr)->left->color == 'r' && (*rootPtr)->right->color == 'r'){  
                             (*rootPtr)->color = 'r';
                             (*rootPtr)->left->color = 'b';
                             (*rootPtr)->right->color = 'b';
            }
        }
            
        if((*rootPtr)->data > newNode->data){
			_addRedBlackTree(&(*rootPtr)->left, newNode);	
		}else if((*rootPtr)->data < newNode->data){
			_addRedBlackTree(&(*rootPtr)->right, newNode);	
		}else{
			Throw(ERR_EQUIVALENT_ERR);
		}
		
        if((*rootPtr)->left != NULL && (*rootPtr)->left->left != NULL){
            if((*rootPtr)->left->color == 'r' && (*rootPtr)->left->left->color == 'r'){
                    rightRotate(rootPtr);
                    (*rootPtr)->right->color = 'r'; 
            }
        }else if((*rootPtr)->left != NULL && (*rootPtr)->left->right != NULL){
            if((*rootPtr)->left->color == 'r' && (*rootPtr)->left->right->color == 'r'){
                    leftRightRotate(rootPtr);
                    (*rootPtr)->right->color = 'r';
            }
        }else if((*rootPtr)->right != NULL && (*rootPtr)->right->right != NULL){
            if((*rootPtr)->right->color == 'r' && (*rootPtr)->right->right->color == 'r'){
                    leftRotate(rootPtr);
                    (*rootPtr)->left->color = 'r';
            }
        }else if((*rootPtr)->right != NULL && (*rootPtr)->right->left != NULL){
            if((*rootPtr)->right->color == 'r' && (*rootPtr)->right->left->color == 'r'){
                    rightLeftRotate(rootPtr);
                    (*rootPtr)->left->color = 'r';
            }
        }        
}

/**
 *  Title : addRedBlackTree
 *  Objective : main function of add red black tree
 *  Input : rootPtr and newNode
 *  Return : None
 *  call _addRedBlackTree and change root into black color
 */
void addRedBlackTree(Node **rootPtr,Node *newNode){
		_addRedBlackTree(rootPtr,newNode);
       (*rootPtr)->color = 'b';	
}


/**
 *  Title : delRedBlackTree
 *  Objective : main function of delete red black tree
 *  Input : rootPtr and newNode
 *   
 *  call _delRedBlackTree and when root is not NULL root change into black color
 */
Node *delRedBlackTree(Node **rootPtr,Node *newNode){
  Node *node =_delRedBlackTree(rootPtr,newNode);
  if(*rootPtr != NULL){
    (*rootPtr)->color='b';
   }
  return node;
}

/**
 *  Title : _delRedBlackTree
 *  Objective : to recursive del to red black tree and balance it
 *  Input : rootPtr and newNode
 *  Return: Node and recursive _delRedBlackTree
 *  root > newNode go left side
 *  root < newNode go right side
 *  delete node that selected and delete it
 *  balance the tree after delete
 */
Node *_delRedBlackTree(Node **rootPtr,Node *newNode){
	Node *node; Node *temp1; Node *temp2; char col;
		if((*rootPtr) == NULL || newNode == NULL){
			Throw(ERR_NODE_UNAVAILABLE);
		}
		
		if((*rootPtr) != NULL){
			if((*rootPtr)->data == newNode->data){   
                if((*rootPtr)->right != NULL){
                    node = removeNextLargerSuccessor(&(*rootPtr)->right);
                    temp1 = (*rootPtr)->left;
                    temp2 = (*rootPtr)->right;
                    col = (*rootPtr)->color;
                    *rootPtr = node;
                            (*rootPtr)->right = temp2;
                            (*rootPtr)->left = temp1;
                            (*rootPtr)->color = col;
                    goto here;
                }else if((*rootPtr)->left != NULL){
                    node = removeNextLargerSuccessor(&(*rootPtr)->left); 
                    temp1 = (*rootPtr)->left;
                    temp2 = (*rootPtr)->right;
                    col = (*rootPtr)->color;
                    *rootPtr = node;
                            (*rootPtr)->right = temp2;
                            (*rootPtr)->left = temp1;
                            (*rootPtr)->color = col;
                    goto here;
                }else{
                    *rootPtr = NULL;
                    return node;
                }
                
                return node;
            }
			
			if((*rootPtr)->data > newNode->data){
				node = _delRedBlackTree(&(*rootPtr)->left, newNode);
			}else if((*rootPtr)->data < newNode->data){
				node = _delRedBlackTree(&(*rootPtr)->right, newNode);
			}
            
            here:
            caseTotalRemove(rootPtr,newNode);

           return node;  
		}
	return node; 
	
}

/**
 *  Title : removeNextLargerSuccessor
 *  Objective : remove node that selected and return to removeNode
 *  Input : parentPtr
 *  Return: removedNode
 *  To left every time checking
 *
 *  Selected Node to remove and return next value
 */
Node *removeNextLargerSuccessor(Node **parentPtr){
	Node *removeNode;
	if((*parentPtr)->left != NULL){
		removeNode = removeNextLargerSuccessor(&(*parentPtr)->left);
	}else if((*parentPtr)->right == NULL && (*parentPtr)->left == NULL){
			removeNode = *parentPtr;
		    *parentPtr = NULL;
			return removeNode;
	}else if((*parentPtr)->right != NULL && (*parentPtr)->left == NULL){
            Node *temp = (*parentPtr)->right;
			removeNode = *parentPtr;
			(*parentPtr)->right->color = 'b'; 
            (*parentPtr) = NULL;
			*parentPtr = temp;
            temp = NULL;
			return removeNode;
	}
	 caseTotalRemove(parentPtr,removeNode);
	return removeNode;	
}

/**
 *  Title : caseTotalRemove
 *  Objective : combine all case left and right
 *  Input : rootPtr and removeNode
 *  Return : none
 */
void caseTotalRemove(Node **rootPtr,Node *removedNode){
    if(isDouble((*rootPtr)->left, removedNode)){
      if(isBlack((*rootPtr)->right)){
        if(isRed((*rootPtr)->right->right) || isRed((*rootPtr)->right->left)){
            caseOneLeftRemove((&(*rootPtr)),removedNode);
        }else if(isBlack((*rootPtr)->right->right) || isBlack((*rootPtr)->right->left)){
            caseTwoLeftRemove((&(*rootPtr)),removedNode);
        }
      }else if(isRed((*rootPtr)->right)){
            caseThreeLeftRemove((&(*rootPtr)),removedNode);
       }
    }else if(isDouble((*rootPtr)->right,removedNode)){
      if(isBlack((*rootPtr)->left)){
        if(isRed((*rootPtr)->left->left) || isRed((*rootPtr)->left->right)){
            caseOneRightRemove((&(*rootPtr)),removedNode);
        }else if(isBlack(*rootPtr) || isRed(*rootPtr)){
            caseTwoRightRemove((&(*rootPtr)),removedNode);
        }
      }else if(isRed((*rootPtr)->left)){
            caseThreeRightRemove((&(*rootPtr)),removedNode);
       }
    }
}



/**
 *  Title : case 1 left remove
 *  Objective : to remove similar case in left
 *  Input : rootPtr and removedNode
 *  Return : None
 */
void caseOneLeftRemove(Node **rootPtr,Node *removedNode){
    char storeColor = (*rootPtr)->color;
    if(isBlack((*rootPtr)->right) && isRed((*rootPtr)->right->right)){
		leftRotate(rootPtr); 
        (*rootPtr)->color = storeColor;
		(*rootPtr)->left->color = 'b';     
		(*rootPtr)->right->color = 'b';
	}else if(isBlack((*rootPtr)->right) && isRed((*rootPtr)->right->left)){
		rightLeftRotate(rootPtr);  
        (*rootPtr)->color = storeColor;
		(*rootPtr)->left->color = 'b';
		(*rootPtr)->right->color = 'b';
	}
   
}

/**
 *  Title : case 2 left remove
 *  Objective : to remove similar case in left
 *  Input : rootPtr and removedNode
 *  Return : None
 */
void caseTwoLeftRemove(Node **rootPtr,Node *removedNode){
   if(isBlack((*rootPtr)) && isBlack((*rootPtr)->right)){
		(*rootPtr)->color = 'd';
		(*rootPtr)->right->color = 'r';
		if(isDouble((*rootPtr)->left,removedNode) && (*rootPtr)->left != NULL){
				(*rootPtr)->left->color = 'b';
		}
	}else if(isRed(*rootPtr) && isBlack((*rootPtr)->right)){
        (*rootPtr)->color = 'b';
		(*rootPtr)->right->color = 'r';
		if(isDouble((*rootPtr)->left,removedNode) && (*rootPtr)->left != NULL){
				(*rootPtr)->left->color = 'b';
		}
	}
}

/**
 *  Title : case 3 left remove
 *  Objective : to remove similar case in left
 *  Input : rootPtr and removedNode
 *  Return : None
 */
void caseThreeLeftRemove(Node **rootPtr,Node *removedNode){
    if(isRed((*rootPtr)->right)){
		leftRotate(rootPtr);
        (*rootPtr)->color = 'b';
        (*rootPtr)->left->color = 'r';
		if(isDouble(((*rootPtr)->left->left),removedNode)){  
			if(isRed((*rootPtr)->left) && isRed((*rootPtr)->left->right->right)){
               caseOneLeftRemove((&(*rootPtr)->left),removedNode);
			}else if(isBlack((*rootPtr)->left->right)){
				caseTwoLeftRemove((&(*rootPtr)->left),removedNode);
			}
		}
	}
}


/**
 *  Title : case 1 right remove
 *  Objective : to remove similar case in left
 *  Input : rootPtr and removedNode
 *  Return : None
 */
void caseOneRightRemove(Node **rootPtr, Node *removedNode){
    char storeColor = (*rootPtr)->color;
    if(isBlack((*rootPtr)->left) && isRed((*rootPtr)->left->left)){
		rightRotate(rootPtr); 
        (*rootPtr)->color = storeColor;
		(*rootPtr)->left->color = 'b';     
		(*rootPtr)->right->color = 'b';
	}else if(isBlack((*rootPtr)->left) && isRed((*rootPtr)->left->right)){
		leftRightRotate(rootPtr);
        (*rootPtr)->color = storeColor;
		(*rootPtr)->left->color = 'b';
		(*rootPtr)->right->color = 'b';
        
	}  
}

/**
 *  Title : case 2 right remove
 *  Objective : to remove similar case in left
 *  Input : rootPtr and removedNode
 *  Return : None
 */
void caseTwoRightRemove(Node **rootPtr,Node *removedNode){
  if(isBlack((*rootPtr)) && isBlack((*rootPtr)->left)){
		(*rootPtr)->color = 'd';
		(*rootPtr)->left->color = 'r';
		if(isDouble((*rootPtr)->right,removedNode) && (*rootPtr)->right != NULL){
				(*rootPtr)->right->color = 'b';
		}
	}else if(isRed(*rootPtr) && isBlack((*rootPtr)->left)){      
        (*rootPtr)->color = 'b';
		(*rootPtr)->left->color = 'r';
		if(isDouble((*rootPtr)->right,removedNode) && (*rootPtr)->right != NULL){
				(*rootPtr)->right->color = 'b';
		}
	}
}

/**
 *  Title : case 3 right remove
 *  Objective : to remove similar case in left
 *  Input : rootPtr and removedNode
 *  Return : None
 */
void caseThreeRightRemove(Node **rootPtr,Node *removedNode){
    if(isRed((*rootPtr)->left)){
		rightRotate(rootPtr);
        (*rootPtr)->color = 'b';
        (*rootPtr)->right->color = 'r';
		if(isDouble((*rootPtr)->right->right, removedNode)){  
			if(isRed((*rootPtr)->right) && isRed((*rootPtr)->right->left->left)){
               caseOneRightRemove((&(*rootPtr)->right),removedNode);
			}else if(isBlack((*rootPtr)->right->left)){
				caseTwoRightRemove((&(*rootPtr)->right),removedNode);
			}
		}
	}
}




/**
 *  Title : Is Red Color
 *  Objective : Check For Red Color
 *  Input : Node
 *  Return : 1 or 0
 */
int isRed(Node *node){
	if((node) != NULL && (node)->color == 'r'){
		return 1;
	}else{
		return 0;
	}
}

/**
 *  Title : Is Black Color
 *  Objective : Check For Black Color
 *  Input : Node
 *  Return : 1 or 0
 */
int isBlack(Node *node){
	if(node != NULL && node->color == 'b'){
		return 1;
	}else if(node == NULL){
		return 1;
	}else{
		return 0;
	}
}

/**
 *  Title : Is Double Black Color
 *  Objective : Check For Double Black Color
 *  Input : Node
 *  Return : 1 or 0
 */
int isDouble(Node *node, Node *removedNode){
	if((node) != NULL && (node)->color == 'd'){
		if(removedNode->color == 'r' || removedNode->color == 'b'){
			return 1;
		}
	}else if(node == NULL && isBlack(removedNode)){
		return 1;
	}else{
		return 0;
	}
}


///////////////
// previous delete case
///////////////

// Node *_delRedBlackTree(Node **rootPtr,Node *newNode){
  // Node *node;
	
	// if((*rootPtr) == NULL){
		// Throw(ERR_NODE_UNAVAILABLE);
	// }
	
	// if((*rootPtr) != NULL){
		// if((*rootPtr)->data == newNode->data){
			// *rootPtr = NULL;
			// return node;
		// }
		
		// if((*rootPtr)->data > newNode->data){
			// _delRedBlackTree(&(*rootPtr)->left, newNode);
		// }else if((*rootPtr)->data < newNode->data){
			// _delRedBlackTree(&(*rootPtr)->right, newNode);	
		// }
		
		
		
		// if((*rootPtr)->right != NULL && (*rootPtr)->left == NULL){
			// if((*rootPtr)->right->color == 'b'){
				// printf("%d",(*rootPtr)->data);
					// (*rootPtr)->color = 'b';
					// (*rootPtr)->right->color = 'r';
			// } 
		// }else if((*rootPtr)->left != NULL && (*rootPtr)->right == NULL){
			// if((*rootPtr)->left->color == 'b'){
				// (*rootPtr)->color = 'b';
				// (*rootPtr)->left->color = 'r';
			// }
		// }
		
		// if((*rootPtr)->right != NULL && (*rootPtr)->right->left != NULL){
			// if((*rootPtr)->right->color == 'r' && (*rootPtr)->right->left->color == 'b'){
				// leftRotate(rootPtr);
				// (*rootPtr)->left->right->color = 'r';
			// }
		// }else if((*rootPtr)->left != NULL && (*rootPtr)->left->left != NULL){
			// if((*rootPtr)->left->color == 'r' && (*rootPtr)->left->left->color == 'b'){
				// rightRotate(rootPtr);
				// (*rootPtr)->right->left->color = 'r';
			// }
		// }
	// }
// }



