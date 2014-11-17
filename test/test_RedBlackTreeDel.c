#include "unity.h"
#include "Node.h"
#include "Rotation.h"
#include "InitNode.h"
#include "RedBlackTree.h"
#include "CustomAssertion.h"
#include "ErrorCode.h"
#include <stdio.h>
#include <CException.h>

Node node1,node2,node3,node4,node5,node6,node7,node8,node10,node12,node13,node15,node18,node20,node22,node24,node25,node30,node35,node40,node45,node60;



void setUp(void){

	resetNode(&node1,1);
	resetNode(&node2,2);
    resetNode(&node3,3);
	resetNode(&node4,4);
	resetNode(&node5,5);
    resetNode(&node6,6);
	resetNode(&node7,7);
    resetNode(&node8,8);
	resetNode(&node10,10);
	resetNode(&node12,12);
    resetNode(&node13,13);
	resetNode(&node15,15);
	resetNode(&node18,18);
	resetNode(&node20,20);
    resetNode(&node22,22);
    resetNode(&node24,24);
	resetNode(&node25,25);
	resetNode(&node30,30);
	resetNode(&node35,35);
	resetNode(&node40,40);
	resetNode(&node45,45);
	resetNode(&node60,60);
}

void tearDown(void){}

////////
//	removeSuccessor
////////

/**
 *      root           root
 *       |    del 5     |
 *       V   ------->   V
 *      10r             -
 *     /  \           
 *   NULL  NULL      
 */
 void test_removeNextLargerSuccessor_delete_10_r_and_NULL(void){
    setNode(&node10,NULL,NULL,'r');
	Node *root = &node10;

    removeNextLargerSuccessor(&root);
    TEST_ASSERT_EQUAL_PTR(NULL, root);
}

/**
 *      root           root
 *       |    del 5     |
 *       V   ------->   V
 *      10b             -
 *     /  \           
 *   NULL  NULL      
 */
 void test_removeNextLargerSuccessor_delete_10_b_and_NULL(void){
    setNode(&node10,NULL,NULL,'b');
	Node *removedNode;
	Node *root = &node10;


    removedNode = removeNextLargerSuccessor(&root);
    TEST_ASSERT_EQUAL_PTR(&node10, removedNode);
	TEST_ASSERT_NULL(root);
	TEST_ASSERT_EQUAL(1,isDouble(root,removedNode));
}

/**
 *      root           root
 *       |    del 5     |
 *       V   ------->   V
 *      10b            15b
 *     /  \           /  \
 *   NULL  15r      NULL  NULL
 */
void test_removeNextLargerSuccessor_return_10_and15_become_parent(void){
    setNode(&node15,NULL,NULL,'r');
    setNode(&node10,NULL,&node15,'b');
	Node *removedNode;
	Node *root = &node10;

    removedNode = removeNextLargerSuccessor(&root);
	TEST_ASSERT_EQUAL_PTR(&node10, removedNode);
    TEST_ASSERT_EQUAL_PTR(root, &node15);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);
}

/**
 *      root           root
 *       |    del 5     |
 *       V   ------->   V
 *      10b            10b
 *     /  \           /  \
 *    5r  15r      NULL  15r
 */
void test_removeNextLargerSuccessor_return_10_and_become_NULL_left(void){
    setNode(&node15,NULL,NULL,'r');
    setNode(&node5,NULL,NULL,'r');
    setNode(&node10,&node5,&node15,'b');
	Node *removedNode;
	Node *root = &node10;

    removedNode = removeNextLargerSuccessor(&root);
	TEST_ASSERT_EQUAL_PTR(&node5, removedNode);
    TEST_ASSERT_EQUAL_PTR(root, &node10);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);
}

/**
 *       root           root
 *        |    del 30    |
 *        V   ------->   V
 *       20b            20b
 *      /   \          /   \
 *   10b   30b       10b    30b
 *   /  \   / \            /
 *  5r  -  25r -          25r
 */
void test_removeNextLargerSuccessor_delete_5_r_from_root_10(void){
    setNode(&node5,NULL,NULL,'r');
    setNode(&node25,NULL,NULL,'r');
    setNode(&node10,&node5,NULL,'b');
    setNode(&node30,&node25,NULL,'b');
    setNode(&node20,&node10,&node30,'b');
	Node *root = &node20;
    Node *removedNode;

    removedNode = removeNextLargerSuccessor(&root);
    TEST_ASSERT_EQUAL_PTR(&node5,removedNode);
    TEST_ASSERT_EQUAL_PTR(&node20,root);
    TEST_ASSERT_EQUAL_NODE(&node10, &node30, 'b', &node20);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node10);
    TEST_ASSERT_EQUAL_NODE(&node25, NULL, 'b', &node30);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node25);
}

/**
 *       root           root
 *        |    suc 5     |               \ \
 *        V   ------->   V     ------>    20d
 *       20b            20b             /    \
 *      /   \          //   \          10b   30r
 *   10b    30b       10d    30b       / \   /  \ 
 *   /  \   /  \      / \    /  \     - 15r 25b 35b
 *  5b 15b 25b 35b   -  15r 25r 35b
 */
void test_removeNextLargerSuccessor_should_remove_the_succesor_of_5_of_left_grandchild_case5(void){
  setNode(&node5,NULL,NULL,'b');
  setNode(&node15,NULL,NULL,'b');
  setNode(&node25,NULL,NULL,'b');
  setNode(&node35,NULL,NULL,'b');
  setNode(&node10,&node5,&node15,'b');
  setNode(&node30,&node25,&node35,'b');
  setNode(&node20,&node10,&node30,'b');
  Node *parent = &node20, *ReturnedRoot;

  ReturnedRoot = removeNextLargerSuccessor(&parent);
  TEST_ASSERT_EQUAL_PTR(&node5, ReturnedRoot);
  TEST_ASSERT_EQUAL_PTR(&node20, parent);
  TEST_ASSERT_EQUAL_NODE(&node10, &node30, 'd', &node20);
  TEST_ASSERT_EQUAL_NODE(NULL, &node15, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(&node25, &node35, 'r', &node30);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node25);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node35);
}

/**
 *         root                root
 *          |      suc 5        |
 *          V     ------->      V
 *         20b                 20b
 *      /      \             /     \
 *    10b      30b        10b      30b
 *   /  \     /  \       /  \      /  \
 * 5b   15b 25b  35b    7b   15b 25b  35b
 *  \
 *   7r
 */
void test_removeNextLargerSuccessor_should_remove_the_succesor_of_5_of_left_grandchild_case6(void){
 
  setNode(&node15,NULL,NULL,'b');
  setNode(&node25,NULL,NULL,'b');
  setNode(&node35,NULL,NULL,'b');
  setNode(&node5,NULL,&node7,'b');
  setNode(&node7,NULL,NULL,'r');
  setNode(&node10,&node5,&node15,'b');
  setNode(&node30,&node25,&node35,'b');
  setNode(&node20,&node10,&node30,'b');
  Node *parent = &node20, *ReturnedRoot;

  ReturnedRoot = removeNextLargerSuccessor(&parent);
  TEST_ASSERT_EQUAL_PTR(&node5, ReturnedRoot);
  TEST_ASSERT_EQUAL_PTR(&node20, parent);
  TEST_ASSERT_EQUAL_NODE(&node10, &node30, 'b', &node20);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node25);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node35);
  TEST_ASSERT_EQUAL_NODE(&node7, &node15, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(&node25, &node35, 'b', &node30);
}








/////////
// case one left
////////
/**
 *	 root
 *     /
 *    v    
 *    2b    rmv 1     2b  	  left rt      4b
 *   /  \  ======>   /   \    ======>     /  \
 *  1b  4b          null 4b             2b   5b
 *       \                \     
 *       5r               5r
 */
 void test_delRedBlackTree_delete_1_b_into_NULL_from_root_2_left_rotate(void){
    setNode(&node1,NULL,NULL,'b');
    setNode(&node5,NULL,NULL,'r');
	setNode(&node4,NULL,&node5,'b');
    setNode(&node2,&node1,&node4,'b');
	Node *root = &node2;

    delRedBlackTree(&root, &node1);
    TEST_ASSERT_EQUAL_PTR(root, &node4);
	TEST_ASSERT_EQUAL_NODE(&node2, &node5, 'b', &node4);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node2);
}

/**
 *	 root
 *     /
 *    v    
 *    2b    rmv 1     2b  	  left rt      4b
 *   /  \  ======>   /   \    ======>     /  \
 *  1b  5b          null 4b             2b   5b
 *      /                /   
 *     4r               5r
 */
 void test_delRedBlackTree_delete_1_b_into_NULL_from_root_2_right_left_rotate(void){
    setNode(&node1,NULL,NULL,'b');
	setNode(&node4,NULL,NULL,'r');
	setNode(&node5,&node4,NULL,'b');
    setNode(&node2,&node1,&node5,'b');
	Node *root = &node2;

    delRedBlackTree(&root, &node1);
    TEST_ASSERT_EQUAL_PTR(root, &node4);
	TEST_ASSERT_EQUAL_NODE(&node2, &node5, 'b', &node4);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node2);
}

////////
//case two left
//////////

/**
 *      root           root
 *       |    del 1     |
 *       V   ------->   V
 *      2b             2d
 *     /  \           /  \
 *    1b  3b      NULL   3r
 */
void test_delRedBlackTree_delete_1_black_into_NULL_from_root_2_right_3_change_into_red(void){
    setNode(&node1,NULL,NULL,'b');
    setNode(&node3,NULL,NULL,'b');
    setNode(&node2,&node1,&node3,'b');
	Node *root = &node2;

    _delRedBlackTree(&root, &node1);
    TEST_ASSERT_EQUAL_PTR(root, &node2);
    TEST_ASSERT_EQUAL_NODE(NULL, &node3, 'd', &node2);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node3);
}

/**
 *      root           root
 *       |    del 1     |
 *       V   ------->   V
 *      2r             2b
 *     /  \          //  \
 *    1b  3b      NULL   3r
 */
void test_delRedBlackTree_delete_1_black_into_NULL_from_root_2_red_change_black(void){
    setNode(&node1,NULL,NULL,'b');
    setNode(&node3,NULL,NULL,'b');
    setNode(&node2,&node1,&node3,'r');
	Node *root = &node2;

    delRedBlackTree(&root, &node1);
    TEST_ASSERT_EQUAL_PTR(root, &node2);
    TEST_ASSERT_EQUAL_NODE(NULL, &node3, 'b', &node2);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node3);
}

//////////
//case three left
/////////

/**
 *	 root
 *     /
 *    v    
 *    2b    rmv 1     2b  	  left rt     4b    double      4b
 *   /  \  ======>   /   \    ======>     /  \  =======>   /  \
 *  1b  4r          null 4r             2r   5b           2b   5b
 *      / \              / \  			 \                 \
 *     3b 5b            3b 5b			  3b               3r
 */
 void test_delRedBlackTree_delete_1_b_into_NULL_from_right_left_rotate(void){
    setNode(&node1,NULL,NULL,'b');
	setNode(&node5,NULL,NULL,'b');
	setNode(&node3,NULL,NULL,'b');
	setNode(&node4,&node3,&node5,'r');
    setNode(&node2,&node1,&node4,'b');
	Node *root = &node2;

    _delRedBlackTree(&root, &node1);
    TEST_ASSERT_EQUAL_PTR(root, &node4);
	TEST_ASSERT_EQUAL_NODE(&node2, &node5, 'b', &node4);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(NULL, &node3, 'b', &node2);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node3);
}

/**
 *	 root
 *     /
 *    v    
 *    2b    rmv 1     2b  	  left rt      5b			 5b
 *   /  \  ======>   /   \    ======>     /  \  ======> /  \
 *  1b  5r          null 5r             2r   6b		   3r  6b
 *      / \              / \  			 \			  / \
 *     3b 6b            3b 6b			  3b		 2b 4b
 *		\				 \					\
 *      4r 				 4b		     		4r
 */
 void test_delRedBlackTree_delete_1_into_NULL_from_right_left_rotate(void){
    setNode(&node1,NULL,NULL,'b');
	setNode(&node6,NULL,NULL,'b');
	setNode(&node4,NULL,NULL,'r');
	setNode(&node3,NULL,&node4,'b');
	setNode(&node5,&node3,&node6,'r');
    setNode(&node2,&node1,&node5,'b');
	Node *root = &node2;

    _delRedBlackTree(&root, &node1);
    TEST_ASSERT_EQUAL_PTR(root, &node5);
	TEST_ASSERT_EQUAL_NODE(&node2, &node4, 'r', &node3);
	TEST_ASSERT_EQUAL_NODE(&node3, &node6, 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node4);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node2);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node6);
}

///////////
// case one right
///////////

/**
 *	   root
 *       /
 *      v    
 *      3b    rmv 5     3b      right rt     2b
 *     /  \  ======>   /   \    ======>     /  \
 *    2b  5b          2b  NULL             1b   3b
 *   /                /   
 *  1r               1R
 */
 void test_delRedBlackTree_delete_5_b_into_NULL_from_root_2_right_rotate(void){
    setNode(&node1,NULL,NULL,'r');
	setNode(&node2,&node1,NULL,'b');
	setNode(&node3,&node2,&node5,'b');
    setNode(&node5,NULL,NULL,'b');
	Node *root = &node3;

    delRedBlackTree(&root, &node5);
    TEST_ASSERT_EQUAL_PTR(root, &node2);
	TEST_ASSERT_EQUAL_NODE(&node1, &node3, 'b', &node2);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node3);
}

/**
 *	 root
 *     /
 *    v    
 *    3b    rmv 4     3b  	 right rt      2b
 *   /  \  ======>   /   \    ======>     /  \
 *  1b  4b          2b  NULL             1b   3b
 *    \               \     
 *    2r              1r
 */
 void test_delRedBlackTree_delete_4_b_into_NULL_from_root_2_left_right_rotate(void){
    setNode(&node1,NULL,&node2,'b');
    setNode(&node2,NULL,NULL,'r');
	setNode(&node3,&node1,&node4,'b');
    setNode(&node4,NULL,NULL,'b');
	Node *root = &node3;

    delRedBlackTree(&root, &node4);
    TEST_ASSERT_EQUAL_PTR(root, &node2);
	TEST_ASSERT_EQUAL_NODE(&node1, &node3, 'b', &node2);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node3);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
}


///////////
//case two right
//////////

/**
 *      root           root
 *       |    del 3     |
 *       V   ------->   V
 *      2b             2d
 *     /  \           /  \
 *    1b  3b         1r  NULL
 */
void test_delRedBlackTree_delete_3_black_into_NULL_from_root_2_left_1_change_into_red(void){
    setNode(&node1,NULL,NULL,'b');
    setNode(&node3,NULL,NULL,'b');
    setNode(&node2,&node1,&node3,'b');
	Node *root = &node2;

    _delRedBlackTree(&root, &node3);
    TEST_ASSERT_EQUAL_PTR(root, &node2);
    TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'd', &node2);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
}

/**
 *      root           root
 *       |    del 3     |
 *       V   ------->   V
 *      2r             2b
 *     /  \           /  \
 *    1b  3b         1r  NULL
 */
void test_delRedBlackTree_delete_3_black_into_NULL_from_root_2_red_change_black(void){
    setNode(&node1,NULL,NULL,'b');
    setNode(&node3,NULL,NULL,'b');
    setNode(&node2,&node1,&node3,'r');
	Node *root = &node2;

    delRedBlackTree(&root, &node3);
    TEST_ASSERT_EQUAL_PTR(root, &node2);
    TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node2);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
}

//////////
//case three right
/////////

/**
 *	  root
 *      /
 *     v    
 *     4b    rmv 5     4b  	  right rt    2b    double     2b
 *    /  \  ======>   /   \    ======>   /  \  =======>   /  \
 *   2r  5b          2r  NULL           1b  4r           1b   4b
 *  / \             / \  			        /                 /  
 * 1b 3b           1b 3b			       3b                3r
 */
 void test_delRedBlackTree_delete_5_b_into_NULL_use_case3_and_case2_right(void){
    setNode(&node1,NULL,NULL,'b');
	setNode(&node3,NULL,NULL,'b');
	setNode(&node5,NULL,NULL,'b');
	setNode(&node4,&node2,&node5,'b');
    setNode(&node2,&node1,&node3,'r');
	Node *root = &node4;

    _delRedBlackTree(&root, &node5);
    TEST_ASSERT_EQUAL_PTR(root, &node2);
	TEST_ASSERT_EQUAL_NODE(&node1, &node4, 'b', &node2);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
    TEST_ASSERT_EQUAL_NODE(&node3, NULL, 'b', &node4);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node3);
}


 /**
 *	    root
 *       /
 *      v    
 *      7b    rmv 8     7b  	right rt     4b			   4b
 *     /  \  ======>   /   \    ======>     /  \  ======> /  \
 *    4r  8b          4r  NULL             3b  7r		 3b  6r
 *   / \              / \  			 		   /            /  \ 
 *  3b 6b            3b 6b			  		  6b           5b  7b
 *	   /				 /					  /
 *    5r				5r		     		 5r
 */
 void test_delRedBlackTree_delete_8_into_NULL_using_case3_and_case1_right(void){
    setNode(&node3,NULL,NULL,'b');
	setNode(&node6,&node5,NULL,'b');
	setNode(&node5,NULL,NULL,'r');
	setNode(&node4,&node3,&node6,'r');
	setNode(&node7,&node4,&node8,'b');
    setNode(&node8,NULL,NULL,'b');
	Node *root = &node7;

    _delRedBlackTree(&root, &node8);
    TEST_ASSERT_EQUAL_PTR(root, &node4);
	TEST_ASSERT_EQUAL_NODE(&node3, &node6, 'b', &node4);
	TEST_ASSERT_EQUAL_NODE(&node5, &node7, 'r', &node6);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node3);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node7);
}




/////////
// Test Main 
////////
/**
 *      root              root
 *       |    remove 5     |
 *       V   ---------->   V
 *      10                NULL
 */
void test_delRedBlackTree_should_throw_if_not_found(void){
    setNode(&node10, NULL, NULL,'b');
    setNode(&node5, NULL, NULL,'b');
	Node *root = &node10;

  ErrorCode e;
  Try{
    delRedBlackTree(&root, &node5);
    TEST_FAIL_MESSAGE("Error, expected to be throw, But receive none");
  }
  Catch(e){
    TEST_ASSERT_EQUAL_PTR(root, &node10);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', root);
  }
}

/**
 *      root              root
 *       |    del 10       |
 *       V   ---------->   V
 *      10                NULL
 */
void test_delRedBlackTree_should_delete_the_root(void){
    setNode(&node10, NULL, NULL,'b');
    Node *root = &node10;

    delRedBlackTree(&root, &node10);
    TEST_ASSERT_EQUAL_PTR(NULL, root);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node10);
}

/**
 *      root           root
 *       |    del 5     |
 *       V   ------->   V
 *      10b            10b
 *      /              /
 *    5r             NULL
 */
void test_delRedBlackTree_delete_5_red_into_NULL_from_root_10_left(void){
    setNode(&node5,NULL,NULL,'r');
    setNode(&node10,&node5,NULL,'b');
	Node *root = &node10;

    delRedBlackTree(&root, &node5);
    TEST_ASSERT_EQUAL_PTR(root, &node10);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node10);
}

/**
 *      root           root
 *       |    del 15    |
 *       V   ------->   V
 *      10b            10b
 *        \              \
 *        15r            NULL
 */
void test_delRedBlackTree_delete_15_red_into_NULL_from_root_10_right(void){
    setNode(&node15,NULL,NULL,'r');
    setNode(&node10,NULL,&node15,'b');
	Node *root = &node10;

    delRedBlackTree(&root, &node15);
    TEST_ASSERT_EQUAL_PTR(root, &node10);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node10);
}

/**
 *      root           root
 *       |    del 5     |
 *       V   ------->   V
 *      10b            10b
 *     /  \           /  \
 *    5r  15r      NULL  15r
 */
void test_delRedBlackTree_delete_5_red_into_NULL_from_root_10_left_15_remain_red(void){
    setNode(&node15,NULL,NULL,'r');
    setNode(&node5,NULL,NULL,'r');
    setNode(&node10,&node5,&node15,'b');
	Node *root = &node10;

    delRedBlackTree(&root, &node5);
    TEST_ASSERT_EQUAL_PTR(root, &node10);
    TEST_ASSERT_EQUAL_NODE(NULL, &node15, 'b', &node10);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);
}

/**
 *      root           root
 *       |    del 15    |
 *       V   ------->   V
 *      10b            10b
 *     /  \            /  \
 *    5r  15r        5r   NULL
 */
void test_delRedBlackTree_delete_15_red_into_NULL_from_root_10_right_5_remain_red(void){
    setNode(&node15,NULL,NULL,'r');
    setNode(&node5,NULL,NULL,'r');
    setNode(&node10,&node5,&node15,'b');
	Node *root = &node10;

    delRedBlackTree(&root, &node15);
    TEST_ASSERT_EQUAL_PTR(root, &node10);
    TEST_ASSERT_EQUAL_NODE(&node5, NULL, 'b', &node10);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
}

/**
 *      root           root
 *       |    del 5     |
 *       V   ------->   V
 *      10b            10b
 *     /  \           /  \
 *    5b  15b      NULL  15r
 */
void test_delRedBlackTree_delete_5_black_into_NULL_from_root_10_right_15_flip_into_red(void){
    setNode(&node15,NULL,NULL,'b');
    setNode(&node5,NULL,NULL,'b');
    setNode(&node10,&node5,&node15,'b');
	Node *root = &node10;

    delRedBlackTree(&root, &node5);
    TEST_ASSERT_EQUAL_PTR(root, &node10);
    TEST_ASSERT_EQUAL_NODE(NULL, &node15, 'b', &node10);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);
}

/**
 *      root           root
 *       |    del 15    |
 *       V   ------->   V
 *      10b            10b
 *     /  \            /  \
 *    5b  15b        5r   NULL
 */
void test_delRedBlackTree_delete_15_black_into_NULL_from_root_10_right_5_flip_into_red(void){
    setNode(&node15,NULL,NULL,'b');
    setNode(&node5,NULL,NULL,'b');
    setNode(&node10,&node5,&node15,'b');
	Node *root = &node10;

    delRedBlackTree(&root, &node15);
    TEST_ASSERT_EQUAL_PTR(root, &node10);
    TEST_ASSERT_EQUAL_NODE(&node5, NULL, 'b', &node10);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
}

/**
 *      root           root
 *       |    del 1     |
 *       V   ------->   V
 *      2b              5b
 *     /   \          /   \
 *    1b   5r        2b   6b
 *        /  \        \
 *      3b   6b       3r
 */
void test_delRedBlackTree_delete_1_black_from_root_2_and_rotate_left_and_flip_color_of_3_into_red(void){
    setNode(&node3,NULL,NULL,'b');
    setNode(&node6,NULL,NULL,'b');
    setNode(&node1,NULL,NULL,'b');
    setNode(&node5,&node3,&node6,'r');
    setNode(&node2,&node1,&node5,'b');
	Node *root = &node2;

    delRedBlackTree(&root, &node1);
    TEST_ASSERT_EQUAL_PTR(root, &node5);
    TEST_ASSERT_EQUAL_NODE(&node2, &node6, 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(NULL, &node3, 'b', &node2);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node6);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node3);
}

/**
 *      root           root
 *       |    del 3     |
 *       V   ------->   V
 *     	2b              2b
 *     /   \          /   \
 *    1b   5r        1b   5b
 *        /  \              \
 *      3b   6b             6r
 */
void test_delRedBlackTree_delete_3_black_from_root_2_and_flip_color_of_6_into_red(void){
    setNode(&node3,NULL,NULL,'b');
    setNode(&node6,NULL,NULL,'b');
    setNode(&node1,NULL,NULL,'b');
    setNode(&node5,&node3,&node6,'r');
    setNode(&node2,&node1,&node5,'b');
	Node *root = &node2;

    delRedBlackTree(&root, &node3);
    TEST_ASSERT_EQUAL_PTR(root, &node2);
    TEST_ASSERT_EQUAL_NODE(&node1, &node5, 'b', &node2);
    TEST_ASSERT_EQUAL_NODE(NULL, &node6, 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node6);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
}

/**
 *      root           root
 *       |    del 5     |
 *       V   ------->   V
 *     	2b              2b
 *     /   \          /   \
 *    1b   5r        1b   6r
 *        /  \           /  
 *      3b   6b         3b   
 */
void test_delRedBlackTree_delete_5_red_from_root_2_and_6_r_and_3_b(void){
    setNode(&node3,NULL,NULL,'b');
    setNode(&node6,NULL,NULL,'b');
    setNode(&node1,NULL,NULL,'b');
    setNode(&node5,&node3,&node6,'r');
    setNode(&node2,&node1,&node5,'b');
	Node *root = &node2;

    delRedBlackTree(&root, &node5);
    TEST_ASSERT_EQUAL_PTR(root, &node2);
    TEST_ASSERT_EQUAL_NODE(&node1, &node6, 'b', &node2);
    TEST_ASSERT_EQUAL_NODE(&node3, NULL, 'r', &node6);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node3);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
}

/**
 *      root           root
 *       |    del 2     |
 *       V   ------->   V
 *      2b              5b
 *     /   \          /   \
 *    1b   5b        1b   6b
 *           \        
 *           6r       
 */
void test_delRedBlackTree_delete_2_black_and_root_into_5b_and_6r(void){
    setNode(&node6,NULL,NULL,'r');
    setNode(&node1,NULL,NULL,'b');
    setNode(&node5,NULL,&node6,'b');
    setNode(&node2,&node1,&node5,'b');
	Node *root = &node2;

    delRedBlackTree(&root, &node2);
    TEST_ASSERT_EQUAL_PTR(root, &node5);
    TEST_ASSERT_EQUAL_NODE(&node1, &node6, 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node6);
}

/**
 *      root           root
 *       |    del 2     |
 *       V   ------->   V
 *      2b              3b
 *     /   \          /   \
 *    1b   5b        1b   5b
 *      \            
 *      3r       
 */
void test_delRedBlackTree_delete_2_black_and_root_into_1b_and_3b(void){
    setNode(&node3,NULL,NULL,'r');
    setNode(&node1,NULL,&node3,'b');
    setNode(&node5,NULL,NULL,'b');
    setNode(&node2,&node1,&node5,'b');
	Node *root = &node2;

    delRedBlackTree(&root, &node2);
    TEST_ASSERT_EQUAL_PTR(root, &node3);
    TEST_ASSERT_EQUAL_NODE(&node1, &node5, 'b', &node3);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
}

/** 
 *        root					   root
 *        /       remove 24        	 /
 *       v        -------->       	v
 *       18r                       18b
 *     /      \                	/    	\
 *   12b      24b              12r     25b
 *  /   \    /   \            /  \ 	   /
 *10b   13b 20b  25b        10b  13b  20r
 */
void test_delRedBlackTree_remove_24B_and_restruct_20_12_into_red(){
  setNode(&node25, NULL, NULL, 'b');
  setNode(&node20, NULL, NULL, 'b');
  setNode(&node13, NULL, NULL, 'b');
  setNode(&node10, NULL, NULL, 'b');
  setNode(&node12, &node10, &node13, 'b');
  setNode(&node24, &node20, &node25, 'b');
  setNode(&node18, &node12, &node24, 'r');
  Node *root = &node18;
  
  delRedBlackTree(&root, &node24);
  TEST_ASSERT_EQUAL_PTR(root, &node18);
  TEST_ASSERT_EQUAL_NODE(&node12, &node25, 'b', &node18);
  TEST_ASSERT_EQUAL_NODE(&node10, &node13, 'r', &node12);
  TEST_ASSERT_EQUAL_NODE(&node20, NULL, 'b', &node25);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node13);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node20);
}

/** 
 *        root					   root
 *        /       remove 12        	 /
 *       v        -------->       	v
 *       18r                       18b
 *     /      \                	/    	\
 *   12b      24b              13b     24r
 *  /   \    /   \            /  \ 	   /  \
 *10b   13b 20b  25b        10r   -  20b  25b
 */
void test_delRedBlackTree_remove_12B_and_restruct_10_24_into_red(){
  setNode(&node25, NULL, NULL, 'b');
  setNode(&node20, NULL, NULL, 'b');
  setNode(&node13, NULL, NULL, 'b');
  setNode(&node10, NULL, NULL, 'b');
  setNode(&node12, &node10, &node13, 'b');
  setNode(&node24, &node20, &node25, 'b');
  setNode(&node18, &node12, &node24, 'r');
  Node *root = &node18;
  
  delRedBlackTree(&root, &node12);
  TEST_ASSERT_EQUAL_PTR(root, &node18);
  TEST_ASSERT_EQUAL_NODE(&node13, &node24, 'b', &node18);
  TEST_ASSERT_EQUAL_NODE(&node10, NULL, 'b', &node13);
  TEST_ASSERT_EQUAL_NODE(&node20, &node25, 'r', &node24);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node25);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node20);
}




