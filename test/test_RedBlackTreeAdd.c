#include <stdio.h>
#include "unity.h"
#include "RedBlackTree.h"
#include "Rotation.h"
#include "Node.h"
#include "InitNode.h"
#include "CustomAssertion.h"
#include "CException.h"
#include "ErrorCode.h"
Node node1,node2,node4,node5,node7,node10,node12,node15,node18,node20,node22,node25,node30,node35,node40,node45,node60;



void setUp(void){

	resetNode(&node1,1);
	resetNode(&node2,2);
	resetNode(&node4,4);
	resetNode(&node5,5);
	resetNode(&node7,7);
	resetNode(&node10,10);
	resetNode(&node12,12);
	resetNode(&node15,15);
	resetNode(&node18,18);
	resetNode(&node20,20);
    resetNode(&node22,22);
	resetNode(&node25,25);
	resetNode(&node30,30);
	resetNode(&node35,35);
	resetNode(&node40,40);
	resetNode(&node45,45);
	resetNode(&node60,60);
}

void tearDown(void){}



/**
*
*      root      root
*      /  add10    /
*     v    --->   v
*    NULL      10(RED)
**/
void test_addRedBlackTree_add_10_to_empty_tree(void){
	setNode(&node10,NULL,NULL,'r');
	Node *root = NULL;

	addRedBlackTree(&root,&node10);


	TEST_ASSERT_EQUAL_PTR(&node10,root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL ,'b', root);
}

/**
*
*      root 		root
*       /		 /
*      v	        v
*     10             10(b)
*           -->       /
*          add 5     V
*		    5(r)
**/
void test_addRedBlackTree_add_left_5_to_10_tree(void){
	setNode(&node5,NULL,NULL,'r');
	setNode(&node10,NULL,NULL,'b');
	Node *root = &node10;

	addRedBlackTree(&root,&node5);

	TEST_ASSERT_EQUAL_PTR(&node10,root);
	TEST_ASSERT_EQUAL_NODE(&node5, NULL ,'b', &node10);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL ,'r', &node5);
}

/**
*
*	root 		root
*        /		 /
*       v	        v
*      10             10(b)
*            -->        \
*	   add 15        V
*			15(r)
**/
void test_addRedBlackTree_add_right_15_to_10_tree(void){
	setNode(&node15,NULL,NULL,'r');
	setNode(&node10,NULL,NULL,'b');
	Node *root = &node10;

	addRedBlackTree(&root,&node15);

	TEST_ASSERT_EQUAL_PTR(&node10,root);
	TEST_ASSERT_EQUAL_NODE(NULL, &node15,'b', &node10);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL ,'r', &node15);
}

/**
*
*	root 		root
*        /		 /
*       v	        v
*       10            10(b)
*              -->     \
*	     add 15     V
*			10(r)
**/
void test_addRedBlackTree_add_right_10_to_10_tree(void){
	int e;
	setNode(&node10,NULL,NULL,'b');
	setNode(&node10,NULL,NULL,'b');
	Node *root = &node10;

	Try{
		addRedBlackTree(&root,&node10);
	}Catch(e){
		TEST_ASSERT_EQUAL(e,ERR_EQUIVALENT_ERR);
	}
}

/**
*
*	root 		root        root
*   	 /		 /            /
*       v	        v            v
*       10            10(b)         5(b)
*                      /	   /   \
*	              V           v     v
*		     5(r)        1(r)  10(r)
*	    --->     /
*	 add 1	    v
*	          1(r)
**/
void test_addRedBlackTree_add_left_1_to_5_to_10_tree(void){
	setNode(&node1,NULL,NULL,'r');
	setNode(&node5,NULL,NULL,'r');
	setNode(&node10,&node5,NULL,'b');
	Node *root = &node10;

	addRedBlackTree(&root,&node1);

	TEST_ASSERT_EQUAL_PTR(root,&node5);
	TEST_ASSERT_EQUAL_NODE(&node1, &node10 ,'b', root	);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL ,'r', &node1);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL ,'r', &node10);

}


/**
 *      root            root                root
 *       |    add 10      /       rotate      /
 *       v   ------->    v        ----->     v
 *      15(b)           15 (b)              10(b)
 *      /                /                 /  \
 *     v                v                5(r) 15(r)
 *    5(r)             5(r)
 *						\
 *						 v
 *                      10(r)
 */
void test_addRedBlackTree_add_10_to_tree_should_left_right_rotate(void){
  setNode(&node10,NULL,NULL,'r');
  setNode(&node5,NULL,NULL,'r');
  setNode(&node15,&node5,NULL,'b');
  Node *root = &node15;

  addRedBlackTree(&root, &node10);
  TEST_ASSERT_EQUAL_PTR(root, &node10);

  TEST_ASSERT_EQUAL_NODE(&node5, &node15, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);
}





/**
 *      root            root                root
 *       |    add 10      /       rotate      /
 *       v   ------->    v        ----->     v
 *      10(b)           10 (b)              20(b)
 *       \               \                  /  \
 *        v               v               10(r) 30(r)
 *	    20(r)           20(r)
 *						  \
 *						   v
 * 			              30(r)
 */
void test_addRedBlackTree_add_10_to_tree_should_left_rotate(void){
  setNode(&node30,NULL,NULL,'r');
  setNode(&node20,NULL,NULL,'r');
  setNode(&node10,NULL,&node20,'b');
  Node *root = &node10;

  addRedBlackTree(&root, &node30);
  TEST_ASSERT_EQUAL_PTR(root, &node20);

  TEST_ASSERT_EQUAL_NODE(&node10, &node30, 'b', &node20);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node30);
}



/**
 *      root            root                root
 *       |    add 10      /       rotate      /
 *       v   ------->    v        ----->     v
 *      10(b)           10 (b)              15(b)
 *       \               \                  /  \
 *        v               v               10(r) 20(r)
 *	 20(r)           20(r)
 *					        /
 *					       v
 *	                                      15(r)
 */

void test_addRedBlackTree_add_10_to_tree_should_right_left_rotate(void){
  setNode(&node15,NULL,NULL,'r');
  setNode(&node20,NULL,NULL,'r');
  setNode(&node10,NULL,&node20,'b');
  Node *root = &node10;

  addRedBlackTree(&root, &node15);
  TEST_ASSERT_EQUAL_PTR(root, &node15);

  TEST_ASSERT_EQUAL_NODE(&node10, &node20, 'b', &node15);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node20);
}

/**
*   root                  root                root
*     /                     /                   /
*    v       add 7         v                   v
*   10(b)    ----->       10(b)     ---->     10(r)
*   / \                   / \                 /  \
*  5(r)15(r)            5(r) 15(r)           5(b) 15(b)
*                        \                    \
*                        7(r)                 7(r)
*
**/

 void test_addRedBlackTree_add_7_to_4_node(void){
	setNode(&node7,NULL,NULL,'r');
	setNode(&node5,NULL,NULL,'r');
	setNode(&node15,NULL,NULL,'r');
	setNode(&node10,&node5,&node15,'b');
	Node *root = &node10;

	_addRedBlackTree(&root, &node7);
    	TEST_ASSERT_EQUAL_PTR(root, &node10);

	TEST_ASSERT_EQUAL_NODE(&node5, &node15, 'r', &node10);
	TEST_ASSERT_EQUAL_NODE(NULL, &node7, 'b', &node5);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node7);
}

/**
*   root                  root                root
*     /                     /                   /
*    v       add 12        v                   v
*   10(b)    ----->       10(b)     ---->     10(r)
*   / \                   / \                 /  \
*  5(r)15(r)            5(r) 15(r)           5(b) 15(b)
*                            /                    /
*                           12(r)                12(r)
*
**/

 void test_addRedBlackTree_add_12_to_4_node(void){
	setNode(&node12,NULL,NULL,'r');
	setNode(&node5,NULL,NULL,'r');
	setNode(&node15,NULL,NULL,'r');
	setNode(&node10,&node5,&node15,'b');
	Node *root = &node10;

	_addRedBlackTree(&root, &node12);
    TEST_ASSERT_EQUAL_PTR(root, &node10);

	TEST_ASSERT_EQUAL_NODE(&node5, &node15, 'r', &node10);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
	TEST_ASSERT_EQUAL_NODE(&node12, NULL, 'b', &node15);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node12);
}

/**
*   root                  root                root
*     /                     /                   /
*    v       add 12        v                   v
*   10(b)    ----->       10(b)     ---->     10(r)
*   / \                   / \                 /  \
*  5(r)15(r)            5(r) 15(r)           5(b) 15(b)
*                             \                    \
*                             18(r)                18(r)
*
**/

 void test_addRedBlackTree_add_18_to_4_node(void){
	setNode(&node18,NULL,NULL,'r');
	setNode(&node5,NULL,NULL,'r');
	setNode(&node15,NULL,NULL,'r');
	setNode(&node10,&node5,&node15,'b');
	Node *root = &node10;

	_addRedBlackTree(&root, &node18);
    TEST_ASSERT_EQUAL_PTR(root, &node10);

	TEST_ASSERT_EQUAL_NODE(&node5, &node15, 'r', &node10);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
	TEST_ASSERT_EQUAL_NODE(NULL, &node18, 'b', &node15);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node18);
}

/**
 *      root           root
 *       |    add 10r   |
 *       V   ------->   V
 *      15b            15b add only
 *         \          /   \
 *         20r      10r   20r
 */
void test_addRedBlackTree_add_10_to_tree_should_add_only(void){
  setNode(&node20,NULL,NULL,'r');
  setNode(&node10,NULL,NULL,'r');
  setNode(&node15,NULL,&node20,'b');
	Node *root = &node15;

  addRedBlackTree(&root, &node10);
  TEST_ASSERT_EQUAL_PTR(root, &node15);

  TEST_ASSERT_EQUAL_NODE(&node10, &node20, 'b', &node15);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node20);
}

////////////////
// Com
////////////////

 void test_addRedBlackTree_add_com_to_4_node(void){
	setNode(&node30,NULL,NULL,'b');
	setNode(&node60,NULL,NULL,'b');

	setNode(&node5,NULL,NULL,'r');
	setNode(&node15,NULL,NULL,'r');
	setNode(&node1,NULL,NULL,'b');
	setNode(&node7,NULL,NULL,'r');
	setNode(&node20,&node4,&node40,'b');

	setNode(&node40,&node30,&node60,'r');
	setNode(&node4,&node1,&node10,'r');
	setNode(&node10,&node5,&node15,'b');

	Node *root = &node20;

	addRedBlackTree(&root, &node7);
    TEST_ASSERT_EQUAL_PTR(root, &node20);

	TEST_ASSERT_EQUAL_NODE(&node4, &node40, 'b', &node20);
	TEST_ASSERT_EQUAL_NODE(&node1, &node10, 'b', &node4);
	TEST_ASSERT_EQUAL_NODE(&node30, &node60, 'b', &node40);
	TEST_ASSERT_EQUAL_NODE(&node5, &node15, 'r', &node10);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node30);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node60);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);
	TEST_ASSERT_EQUAL_NODE(NULL, &node7, 'b', &node5);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node7);
}



