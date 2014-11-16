#include <stdio.h>
#include "unity.h"
#include "Rotation.h"
#include "Node.h"
#include "InitNode.h"


Node node1,node5,node10,node15,node20,node25,node30,node35,node40,node45;

void setUp(void){

	resetNode(&node1,1);
	resetNode(&node5,5);
	resetNode(&node10,10);
	resetNode(&node15,15);
	resetNode(&node20,20);
	resetNode(&node25,25);
	resetNode(&node30,30);
	resetNode(&node35,35);
	resetNode(&node40,40);
	resetNode(&node45,45);
}

void tearDown(void){}


//////////
// RIGHT ROTATE
//////////

/**
*
*		<-root	
*	 10
*	 / \		 5
*   5		--> /  \
*  /		   1   10
* 1
**/
void test_rightRotation_3_elements(void){
	setNode(&node1,NULL,NULL,'b');
	setNode(&node5,&node1,NULL,'b');
	setNode(&node10,&node5,NULL,'b');
	Node *root = &node10;
	
	
	rightRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(node1.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node10.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left,&node1);
	TEST_ASSERT_EQUAL_PTR(node5.right,&node10);
	TEST_ASSERT_EQUAL_PTR(root,&node5);	
}

/**
*
*		<-root	
*	 10
*	 / \		 5
*   5	12	--> /  \
*  /		   1   10
* 1					 \	
*  					 15
**/
void test_rightRotation_4_elements(void){
	setNode(&node15,NULL,NULL,'b');
	setNode(&node1,NULL,NULL,'b');
	setNode(&node5,&node1,NULL,'b');
	setNode(&node10,&node5,&node15,'b');
	Node *root = &node10;
	
	
	rightRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(node1.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node15.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node15.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node10.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right,&node15);
	TEST_ASSERT_EQUAL_PTR(node5.left,&node1);
	TEST_ASSERT_EQUAL_PTR(node5.right,&node10);
	TEST_ASSERT_EQUAL_PTR(root,&node5);	
}

/**
*
*		<-root	
*	 10
*	 / \		 5
*   5	30	--> /  \
*  / \		   1   10
* 1	 15			  /	 \	
*  				 15	 30
**/
void test_rightRotation_5_elements(void){
	
	setNode(&node1,NULL,NULL,'b');
	setNode(&node15,NULL,NULL,'b');
	setNode(&node30,NULL,NULL,'b');
	setNode(&node5,&node1,&node15,'b');
	setNode(&node10,&node5,&node30,'b');
	Node *root = &node10;
	
	
	rightRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(node1.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node15.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node15.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node30.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node30.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node10.left,&node15);
	TEST_ASSERT_EQUAL_PTR(node10.right,&node30);
	TEST_ASSERT_EQUAL_PTR(node5.left,&node1);
	TEST_ASSERT_EQUAL_PTR(node5.right,&node10);
	TEST_ASSERT_EQUAL_PTR(root,&node5);	
}

//////////
// LEFT ROTATE
//////////

/**
*
*		<-root	
*	  1
*	 / \		 5
*   	5	--> /  \
*    	 \	   1   10
*		 10 
**/
void test_leftRotation_3_elements(void){
	setNode(&node10,NULL,NULL,'b');
	setNode(&node5,NULL,&node10,'b');
	setNode(&node1,NULL,&node5,'b');
	Node *root = &node1;
	
	
	leftRotate(&root);
	TEST_ASSERT_EQUAL_PTR(node10.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node1.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left,&node1);
	TEST_ASSERT_EQUAL_PTR(node5.right,&node10);
	TEST_ASSERT_EQUAL_PTR(root,&node5);	
}

/**
*
*		<-root	
*	  1
*	 / \		  5
*   15	5	-->  /  \
*    	 \	    1   10
*		  10   /
*			  15
**/
void test_leftRotation_4_elements(void){
	setNode(&node15,NULL,NULL,'b');
	setNode(&node10,NULL,NULL,'b');
	setNode(&node5,NULL,&node10,'b');
	setNode(&node1,&node15,&node5,'b');
	Node *root = &node1;
	
	
	leftRotate(&root);
	TEST_ASSERT_EQUAL_PTR(node10.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node15.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node15.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node1.left,&node15);
	TEST_ASSERT_EQUAL_PTR(node1.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left,&node1);
	TEST_ASSERT_EQUAL_PTR(node5.right,&node10);
	TEST_ASSERT_EQUAL_PTR(root,&node5);	
}

/**
*
*		<-root	
*	  1
*	 / \		  5
*   15	5	-->  /  \
*       / \	    1   30
*	   10 30   / \
*			  15 10
**/
void test_leftRotation_5_elements(void){
	setNode(&node30,NULL,NULL,'b');
	setNode(&node15,NULL,NULL,'b');
	setNode(&node10,NULL,NULL,'b');
	setNode(&node5,&node10,&node30,'b');
	setNode(&node1,&node15,&node5,'b');
	Node *root = &node1;
	
	
	leftRotate(&root);
	TEST_ASSERT_EQUAL_PTR(node10.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node15.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node15.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node30.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node30.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node1.left,&node15);
	TEST_ASSERT_EQUAL_PTR(node1.right,&node10);
	TEST_ASSERT_EQUAL_PTR(node5.left,&node1);
	TEST_ASSERT_EQUAL_PTR(node5.right,&node30);
	TEST_ASSERT_EQUAL_PTR(root,&node5);	
}

/////////
// LEFT RIGHT ROTATE
////////

/**
 *      20         20
 *     /          /         15
 *   10     =>   15   =>   /  \
 *	   \		/         10   20
 *      15     10
 */
void test_leftRightRotate_with_3_elements(void){
	setNode(&node15,NULL,NULL,'b');
	setNode(&node10,NULL,&node15,'b');
	setNode(&node20,&node10,NULL,'b');
	Node *root = &node20;
	
	leftRightRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(node10.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node20.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node20.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node15.left,&node10);
	TEST_ASSERT_EQUAL_PTR(node15.right,&node20);
	TEST_ASSERT_EQUAL_PTR(root,&node15);
}

/**
 *      20          20
 *     /           /         15
 *    10     =>   15   =>   /  \
 *   /  \		  /        10   20
 *  5    15     10        /
 *             /         5
 *            5
 */
void test_leftRightRotate_with_4_elements(void){
	setNode(&node15,NULL,NULL,'b');
	setNode(&node5,NULL,NULL,'b');
	setNode(&node10,&node5,&node15,'b');
	setNode(&node20,&node10,NULL,'b');
	Node *root = &node20;
	
	leftRightRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(node5.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node5.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node20.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node20.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node15.left,&node10);
	TEST_ASSERT_EQUAL_PTR(node15.right,&node20);
	TEST_ASSERT_EQUAL_PTR(node10.left,&node5);
	TEST_ASSERT_EQUAL_PTR(node10.right,NULL);
	TEST_ASSERT_EQUAL_PTR(root,&node15);

}



/**
 *       20             20
 *      /  \           /  \            10
 *     5    25        10   25         /  \
 *   /  \	    =>   /  \      =>    5   20
 *  1    10         5   15         /    /  \
 *        \        /              1    15   25
 *         15     1
 */
void test_leftRightRotate_with_6_elements(void){
	setNode(&node1,NULL,NULL,'b');
	setNode(&node15,NULL,NULL,'b');
	setNode(&node25,NULL,NULL,'b');
	setNode(&node10,NULL,&node15,'b');
	setNode(&node5,&node1,&node10,'b');
	setNode(&node20,&node5,&node25,'b');
	Node *root = &node20;
	
	leftRightRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(node1.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node15.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node15.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node25.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node25.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node10.left,&node5);
	TEST_ASSERT_EQUAL_PTR(node10.right,&node20);
	TEST_ASSERT_EQUAL_PTR(node5.left,&node1);
	TEST_ASSERT_EQUAL_PTR(node5.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node20.left,&node15);
	TEST_ASSERT_EQUAL_PTR(node20.right,&node25);
	TEST_ASSERT_EQUAL_PTR(root,&node10);

}

/**
 *       20             20
 *      /  \           /  \           15
 *     5    25        15  25         /  \
 *   /  \	    =>   /         =>   5    20
 *  1    15         5              / \    \
 *      /          /  \           1   10   25
 *     10         1    10
 */
void test_leftRightRotate_with_6_elements_case2(void){
	setNode(&node1,NULL,NULL,'b');
	setNode(&node10,NULL,NULL,'b');
	setNode(&node25,NULL,NULL,'b');
	setNode(&node15,&node10,NULL,'b');
	setNode(&node5,&node1,&node15,'b');
	setNode(&node20,&node5,&node25,'b');
	Node *root = &node20;
	
	leftRightRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(node1.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node10.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node25.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node25.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node15.left,&node5);
	TEST_ASSERT_EQUAL_PTR(node15.right,&node20);
	TEST_ASSERT_EQUAL_PTR(node5.left,&node1);
	TEST_ASSERT_EQUAL_PTR(node5.right,&node10);
	TEST_ASSERT_EQUAL_PTR(node20.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node20.right,&node25);
	TEST_ASSERT_EQUAL_PTR(root,&node15);
}

/////////
// RIGHT LEFT ROTATE
/////////

/**
 *    10      10
 *      \       \           15
 *	    20  =>  15    =>   /  \
 *     /          \      10   20
 *   15           20
 */
void test_rightLeftRotate_with_3_elements(void){
	setNode(&node15,NULL,NULL,'b');
	setNode(&node20,&node15,NULL,'b');
	setNode(&node10,NULL,&node20,'b');
	Node *root = &node10;
	
	rightLeftRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(node10.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node20.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node20.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node15.left,&node10);
	TEST_ASSERT_EQUAL_PTR(node15.right,&node20);
	TEST_ASSERT_EQUAL_PTR(root,&node15);
}

/**
 *    10       10
 *      \        \           15
 *	    20  =>   15    =>   /  \
 *     /  \        \      10   20
 *   15   25       20            \
 *                   \           25
 *                   25
 */
void test_rightLeftRotate_with_4_elements(void){
	setNode(&node15,NULL,NULL,'b');
	setNode(&node25,NULL,NULL,'b');
	setNode(&node20,&node15,&node25,'b');
	setNode(&node10,NULL,&node20,'b');
	Node *root = &node10;
	
	rightLeftRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(node10.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node25.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node25.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node15.left,&node10);
	TEST_ASSERT_EQUAL_PTR(node15.right,&node20);
	TEST_ASSERT_EQUAL_PTR(node20.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node20.right,&node25);
	TEST_ASSERT_EQUAL_PTR(root,&node15);
}

void test_color_fliping(void){



}






void changeRootByVal(Node *node, Node *newNode){
	node = newNode;
	printf("changeRootByVal: node = %x\n",node);

}

void changeRootByRef(Node **nodePtr, Node *newNode){
	*nodePtr = newNode;
	printf("changeRootByRef: node = %x\n",nodePtr);
}


void test_changeRootByVal(){

	Node *root;
	root = &node10;
	
	printf("root is %d with address %x\n",root->data,root); 
	changeRootByVal(root,&node5);
	printf("root is %d with address %x\n",root->data,root); 
}

void test_changeRootByRef(){

	Node *root;
	root = &node10;
	
	printf("root is %d with address %x\n",root->data,root); 
	changeRootByRef(&root,&node5);
	printf("root is %d with address %x\n",root->data,root); 
}
