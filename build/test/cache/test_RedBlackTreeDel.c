#include "unity.h"
#include "Rotation.h"
#include "RedBlackTree.h"
#include "Node.h"
#include "InitNode.h"
#include "ErrorCode.h"
#include "CustomAssertion.h"




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

 void test_removeNextLargerSuccessor_delete_10_r_and_NULL(void){

    setNode(&node10,((void *)0),((void *)0),'r');

 Node *root = &node10;



    removeNextLargerSuccessor(&root);

    UnityAssertEqualNumber((_U_SINT)(_UP)((((void *)0))), (_U_SINT)(_UP)((root)), (((void *)0)), (_U_UINT)60, UNITY_DISPLAY_STYLE_HEX32);

}

 void test_removeNextLargerSuccessor_delete_10_b_and_NULL(void){

    setNode(&node10,((void *)0),((void *)0),'b');

 Node *removedNode;

 Node *root = &node10;





    removedNode = removeNextLargerSuccessor(&root);

    UnityAssertEqualNumber((_U_SINT)(_UP)((&node10)), (_U_SINT)(_UP)((removedNode)), (((void *)0)), (_U_UINT)78, UNITY_DISPLAY_STYLE_HEX32);

 if ((((root)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)79);;};

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isDouble(root,removedNode))), (((void *)0)), (_U_UINT)80, UNITY_DISPLAY_STYLE_INT);

}

void test_removeNextLargerSuccessor_return_10_and15_become_parent(void){

    setNode(&node15,((void *)0),((void *)0),'r');

    setNode(&node10,((void *)0),&node15,'b');

 Node *removedNode;

 Node *root = &node10;



    removedNode = removeNextLargerSuccessor(&root);

 UnityAssertEqualNumber((_U_SINT)(_UP)((&node10)), (_U_SINT)(_UP)((removedNode)), (((void *)0)), (_U_UINT)98, UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node15)), (((void *)0)), (_U_UINT)99, UNITY_DISPLAY_STYLE_HEX32);

    assertNode(((void *)0),((void *)0),'b',&node15,100);

}

void test_removeNextLargerSuccessor_return_10_and_become_NULL_left(void){

    setNode(&node15,((void *)0),((void *)0),'r');

    setNode(&node5,((void *)0),((void *)0),'r');

    setNode(&node10,&node5,&node15,'b');

 Node *removedNode;

 Node *root = &node10;



    removedNode = removeNextLargerSuccessor(&root);

 UnityAssertEqualNumber((_U_SINT)(_UP)((&node5)), (_U_SINT)(_UP)((removedNode)), (((void *)0)), (_U_UINT)119, UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node10)), (((void *)0)), (_U_UINT)120, UNITY_DISPLAY_STYLE_HEX32);

    assertNode(((void *)0),((void *)0),'r',&node15,121);

}

void test_removeNextLargerSuccessor_delete_5_r_from_root_10(void){

    setNode(&node5,((void *)0),((void *)0),'r');

    setNode(&node25,((void *)0),((void *)0),'r');

    setNode(&node10,&node5,((void *)0),'b');

    setNode(&node30,&node25,((void *)0),'b');

    setNode(&node20,&node10,&node30,'b');

 Node *root = &node20;

    Node *removedNode;



    removedNode = removeNextLargerSuccessor(&root);

    UnityAssertEqualNumber((_U_SINT)(_UP)((&node5)), (_U_SINT)(_UP)((removedNode)), (((void *)0)), (_U_UINT)144, UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualNumber((_U_SINT)(_UP)((&node20)), (_U_SINT)(_UP)((root)), (((void *)0)), (_U_UINT)145, UNITY_DISPLAY_STYLE_HEX32);

    assertNode(&node10,&node30,'b',&node20,146);

    assertNode(((void *)0),((void *)0),'b',&node10,147);

    assertNode(&node25,((void *)0),'b',&node30,148);

    assertNode(((void *)0),((void *)0),'r',&node25,149);

}

void test_removeNextLargerSuccessor_should_remove_the_succesor_of_5_of_left_grandchild_case5(void){

  setNode(&node5,((void *)0),((void *)0),'b');

  setNode(&node15,((void *)0),((void *)0),'b');

  setNode(&node25,((void *)0),((void *)0),'b');

  setNode(&node35,((void *)0),((void *)0),'b');

  setNode(&node10,&node5,&node15,'b');

  setNode(&node30,&node25,&node35,'b');

  setNode(&node20,&node10,&node30,'b');

  Node *parent = &node20, *ReturnedRoot;



  ReturnedRoot = removeNextLargerSuccessor(&parent);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node5)), (_U_SINT)(_UP)((ReturnedRoot)), (((void *)0)), (_U_UINT)173, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node20)), (_U_SINT)(_UP)((parent)), (((void *)0)), (_U_UINT)174, UNITY_DISPLAY_STYLE_HEX32);

  assertNode(&node10,&node30,'d',&node20,175);

  assertNode(((void *)0),&node15,'b',&node10,176);

  assertNode(&node25,&node35,'r',&node30,177);

  assertNode(((void *)0),((void *)0),'r',&node15,178);

  assertNode(((void *)0),((void *)0),'b',&node25,179);

  assertNode(((void *)0),((void *)0),'b',&node35,180);

}

void test_removeNextLargerSuccessor_should_remove_the_succesor_of_5_of_left_grandchild_case6(void){



  setNode(&node15,((void *)0),((void *)0),'b');

  setNode(&node25,((void *)0),((void *)0),'b');

  setNode(&node35,((void *)0),((void *)0),'b');

  setNode(&node5,((void *)0),&node7,'b');

  setNode(&node7,((void *)0),((void *)0),'r');

  setNode(&node10,&node5,&node15,'b');

  setNode(&node30,&node25,&node35,'b');

  setNode(&node20,&node10,&node30,'b');

  Node *parent = &node20, *ReturnedRoot;



  ReturnedRoot = removeNextLargerSuccessor(&parent);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node5)), (_U_SINT)(_UP)((ReturnedRoot)), (((void *)0)), (_U_UINT)208, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node20)), (_U_SINT)(_UP)((parent)), (((void *)0)), (_U_UINT)209, UNITY_DISPLAY_STYLE_HEX32);

  assertNode(&node10,&node30,'b',&node20,210);

  assertNode(((void *)0),((void *)0),'b',&node7,211);

  assertNode(((void *)0),((void *)0),'b',&node15,212);

  assertNode(((void *)0),((void *)0),'b',&node25,213);

  assertNode(((void *)0),((void *)0),'b',&node35,214);

  assertNode(&node7,&node15,'b',&node10,215);

  assertNode(&node25,&node35,'b',&node30,216);

}

 void test_delRedBlackTree_delete_1_b_into_NULL_from_root_2_left_rotate(void){

    setNode(&node1,((void *)0),((void *)0),'b');

    setNode(&node5,((void *)0),((void *)0),'r');

 setNode(&node4,((void *)0),&node5,'b');

    setNode(&node2,&node1,&node4,'b');

 Node *root = &node2;



    delRedBlackTree(&root, &node1);

    UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node4)), (((void *)0)), (_U_UINT)247, UNITY_DISPLAY_STYLE_HEX32);

 assertNode(&node2,&node5,'b',&node4,248);

    assertNode(((void *)0),((void *)0),'b',&node5,249);

    assertNode(((void *)0),((void *)0),'b',&node2,250);

}

 void test_delRedBlackTree_delete_1_b_into_NULL_from_root_2_right_left_rotate(void){

    setNode(&node1,((void *)0),((void *)0),'b');

 setNode(&node4,((void *)0),((void *)0),'r');

 setNode(&node5,&node4,((void *)0),'b');

    setNode(&node2,&node1,&node5,'b');

 Node *root = &node2;



    delRedBlackTree(&root, &node1);

    UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node4)), (((void *)0)), (_U_UINT)271, UNITY_DISPLAY_STYLE_HEX32);

 assertNode(&node2,&node5,'b',&node4,272);

    assertNode(((void *)0),((void *)0),'b',&node5,273);

    assertNode(((void *)0),((void *)0),'b',&node2,274);

}

void test_delRedBlackTree_delete_1_black_into_NULL_from_root_2_right_3_change_into_red(void){

    setNode(&node1,((void *)0),((void *)0),'b');

    setNode(&node3,((void *)0),((void *)0),'b');

    setNode(&node2,&node1,&node3,'b');

 Node *root = &node2;



    _delRedBlackTree(&root, &node1);

    UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node2)), (((void *)0)), (_U_UINT)296, UNITY_DISPLAY_STYLE_HEX32);

    assertNode(((void *)0),&node3,'d',&node2,297);

    assertNode(((void *)0),((void *)0),'r',&node3,298);

}

void test_delRedBlackTree_delete_1_black_into_NULL_from_root_2_red_change_black(void){

    setNode(&node1,((void *)0),((void *)0),'b');

    setNode(&node3,((void *)0),((void *)0),'b');

    setNode(&node2,&node1,&node3,'r');

 Node *root = &node2;



    delRedBlackTree(&root, &node1);

    UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node2)), (((void *)0)), (_U_UINT)316, UNITY_DISPLAY_STYLE_HEX32);

    assertNode(((void *)0),&node3,'b',&node2,317);

    assertNode(((void *)0),((void *)0),'r',&node3,318);

}

 void test_delRedBlackTree_delete_1_b_into_NULL_from_right_left_rotate(void){

    setNode(&node1,((void *)0),((void *)0),'b');

 setNode(&node5,((void *)0),((void *)0),'b');

 setNode(&node3,((void *)0),((void *)0),'b');

 setNode(&node4,&node3,&node5,'r');

    setNode(&node2,&node1,&node4,'b');

 Node *root = &node2;



    _delRedBlackTree(&root, &node1);

    UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node4)), (((void *)0)), (_U_UINT)344, UNITY_DISPLAY_STYLE_HEX32);

 assertNode(&node2,&node5,'b',&node4,345);

    assertNode(((void *)0),((void *)0),'b',&node5,346);

    assertNode(((void *)0),&node3,'b',&node2,347);

 assertNode(((void *)0),((void *)0),'r',&node3,348);

}

 void test_delRedBlackTree_delete_1_into_NULL_from_right_left_rotate(void){

    setNode(&node1,((void *)0),((void *)0),'b');

 setNode(&node6,((void *)0),((void *)0),'b');

 setNode(&node4,((void *)0),((void *)0),'r');

 setNode(&node3,((void *)0),&node4,'b');

 setNode(&node5,&node3,&node6,'r');

    setNode(&node2,&node1,&node5,'b');

 Node *root = &node2;



    _delRedBlackTree(&root, &node1);

    UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node5)), (((void *)0)), (_U_UINT)373, UNITY_DISPLAY_STYLE_HEX32);

 assertNode(&node2,&node4,'r',&node3,374);

 assertNode(&node3,&node6,'b',&node5,375);

    assertNode(((void *)0),((void *)0),'b',&node4,376);

    assertNode(((void *)0),((void *)0),'b',&node2,377);

 assertNode(((void *)0),((void *)0),'b',&node6,378);

}

 void test_delRedBlackTree_delete_5_b_into_NULL_from_root_2_right_rotate(void){

    setNode(&node1,((void *)0),((void *)0),'r');

 setNode(&node2,&node1,((void *)0),'b');

 setNode(&node3,&node2,&node5,'b');

    setNode(&node5,((void *)0),((void *)0),'b');

 Node *root = &node3;



    delRedBlackTree(&root, &node5);

    UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node2)), (((void *)0)), (_U_UINT)403, UNITY_DISPLAY_STYLE_HEX32);

 assertNode(&node1,&node3,'b',&node2,404);

    assertNode(((void *)0),((void *)0),'b',&node1,405);

    assertNode(((void *)0),((void *)0),'b',&node3,406);

}

 void test_delRedBlackTree_delete_4_b_into_NULL_from_root_2_left_right_rotate(void){

    setNode(&node1,((void *)0),&node2,'b');

    setNode(&node2,((void *)0),((void *)0),'r');

 setNode(&node3,&node1,&node4,'b');

    setNode(&node4,((void *)0),((void *)0),'b');

 Node *root = &node3;



    delRedBlackTree(&root, &node4);

    UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node2)), (((void *)0)), (_U_UINT)427, UNITY_DISPLAY_STYLE_HEX32);

 assertNode(&node1,&node3,'b',&node2,428);

    assertNode(((void *)0),((void *)0),'b',&node3,429);

    assertNode(((void *)0),((void *)0),'b',&node1,430);

}

void test_delRedBlackTree_delete_3_black_into_NULL_from_root_2_left_1_change_into_red(void){

    setNode(&node1,((void *)0),((void *)0),'b');

    setNode(&node3,((void *)0),((void *)0),'b');

    setNode(&node2,&node1,&node3,'b');

 Node *root = &node2;



    _delRedBlackTree(&root, &node3);

    UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node2)), (((void *)0)), (_U_UINT)453, UNITY_DISPLAY_STYLE_HEX32);

    assertNode(&node1,((void *)0),'d',&node2,454);

    assertNode(((void *)0),((void *)0),'r',&node1,455);

}

void test_delRedBlackTree_delete_3_black_into_NULL_from_root_2_red_change_black(void){

    setNode(&node1,((void *)0),((void *)0),'b');

    setNode(&node3,((void *)0),((void *)0),'b');

    setNode(&node2,&node1,&node3,'r');

 Node *root = &node2;



    delRedBlackTree(&root, &node3);

    UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node2)), (((void *)0)), (_U_UINT)473, UNITY_DISPLAY_STYLE_HEX32);

    assertNode(&node1,((void *)0),'b',&node2,474);

    assertNode(((void *)0),((void *)0),'r',&node1,475);

}

 void test_delRedBlackTree_delete_5_b_into_NULL_use_case3_and_case2_right(void){

    setNode(&node1,((void *)0),((void *)0),'b');

 setNode(&node3,((void *)0),((void *)0),'b');

 setNode(&node5,((void *)0),((void *)0),'b');

 setNode(&node4,&node2,&node5,'b');

    setNode(&node2,&node1,&node3,'r');

 Node *root = &node4;



    _delRedBlackTree(&root, &node5);

    UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node2)), (((void *)0)), (_U_UINT)501, UNITY_DISPLAY_STYLE_HEX32);

 assertNode(&node1,&node4,'b',&node2,502);

    assertNode(((void *)0),((void *)0),'b',&node1,503);

    assertNode(&node3,((void *)0),'b',&node4,504);

 assertNode(((void *)0),((void *)0),'r',&node3,505);

}

 void test_delRedBlackTree_delete_8_into_NULL_using_case3_and_case1_right(void){

    setNode(&node3,((void *)0),((void *)0),'b');

 setNode(&node6,&node5,((void *)0),'b');

 setNode(&node5,((void *)0),((void *)0),'r');

 setNode(&node4,&node3,&node6,'r');

 setNode(&node7,&node4,&node8,'b');

    setNode(&node8,((void *)0),((void *)0),'b');

 Node *root = &node7;



    _delRedBlackTree(&root, &node8);

    UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node4)), (((void *)0)), (_U_UINT)531, UNITY_DISPLAY_STYLE_HEX32);

 assertNode(&node3,&node6,'b',&node4,532);

 assertNode(&node5,&node7,'r',&node6,533);

    assertNode(((void *)0),((void *)0),'b',&node3,534);

    assertNode(((void *)0),((void *)0),'b',&node5,535);

 assertNode(((void *)0),((void *)0),'b',&node7,536);

}

void test_delRedBlackTree_should_throw_if_not_found(void){

    setNode(&node10, ((void *)0), ((void *)0),'b');

    setNode(&node5, ((void *)0), ((void *)0),'b');

 Node *root = &node10;



  ErrorCode e;

  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

    delRedBlackTree(&root, &node5);

    UnityFail( ("Error, expected to be throw, But receive none"), (_U_UINT)559);;

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

    UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node10)), (((void *)0)), (_U_UINT)562, UNITY_DISPLAY_STYLE_HEX32);

    assertNode(((void *)0),((void *)0),'b',root,563);

  }

}















void test_delRedBlackTree_should_delete_the_root(void){

    setNode(&node10, ((void *)0), ((void *)0),'b');

    Node *root = &node10;



    delRedBlackTree(&root, &node10);

    UnityAssertEqualNumber((_U_SINT)(_UP)((((void *)0))), (_U_SINT)(_UP)((root)), (((void *)0)), (_U_UINT)578, UNITY_DISPLAY_STYLE_HEX32);

    assertNode(((void *)0),((void *)0),'b',&node10,579);

}

void test_delRedBlackTree_delete_5_red_into_NULL_from_root_10_left(void){

    setNode(&node5,((void *)0),((void *)0),'r');

    setNode(&node10,&node5,((void *)0),'b');

 Node *root = &node10;



    delRedBlackTree(&root, &node5);

    UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node10)), (((void *)0)), (_U_UINT)596, UNITY_DISPLAY_STYLE_HEX32);

    assertNode(((void *)0),((void *)0),'b',&node10,597);

}

void test_delRedBlackTree_delete_15_red_into_NULL_from_root_10_right(void){

    setNode(&node15,((void *)0),((void *)0),'r');

    setNode(&node10,((void *)0),&node15,'b');

 Node *root = &node10;



    delRedBlackTree(&root, &node15);

    UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node10)), (((void *)0)), (_U_UINT)614, UNITY_DISPLAY_STYLE_HEX32);

    assertNode(((void *)0),((void *)0),'b',&node10,615);

}

void test_delRedBlackTree_delete_5_red_into_NULL_from_root_10_left_15_remain_red(void){

    setNode(&node15,((void *)0),((void *)0),'r');

    setNode(&node5,((void *)0),((void *)0),'r');

    setNode(&node10,&node5,&node15,'b');

 Node *root = &node10;



    delRedBlackTree(&root, &node5);

    UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node10)), (((void *)0)), (_U_UINT)633, UNITY_DISPLAY_STYLE_HEX32);

    assertNode(((void *)0),&node15,'b',&node10,634);

    assertNode(((void *)0),((void *)0),'r',&node15,635);

}

void test_delRedBlackTree_delete_15_red_into_NULL_from_root_10_right_5_remain_red(void){

    setNode(&node15,((void *)0),((void *)0),'r');

    setNode(&node5,((void *)0),((void *)0),'r');

    setNode(&node10,&node5,&node15,'b');

 Node *root = &node10;



    delRedBlackTree(&root, &node15);

    UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node10)), (((void *)0)), (_U_UINT)653, UNITY_DISPLAY_STYLE_HEX32);

    assertNode(&node5,((void *)0),'b',&node10,654);

    assertNode(((void *)0),((void *)0),'r',&node5,655);

}

void test_delRedBlackTree_delete_5_black_into_NULL_from_root_10_right_15_flip_into_red(void){

    setNode(&node15,((void *)0),((void *)0),'b');

    setNode(&node5,((void *)0),((void *)0),'b');

    setNode(&node10,&node5,&node15,'b');

 Node *root = &node10;



    delRedBlackTree(&root, &node5);

    UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node10)), (((void *)0)), (_U_UINT)673, UNITY_DISPLAY_STYLE_HEX32);

    assertNode(((void *)0),&node15,'b',&node10,674);

    assertNode(((void *)0),((void *)0),'r',&node15,675);

}

void test_delRedBlackTree_delete_15_black_into_NULL_from_root_10_right_5_flip_into_red(void){

    setNode(&node15,((void *)0),((void *)0),'b');

    setNode(&node5,((void *)0),((void *)0),'b');

    setNode(&node10,&node5,&node15,'b');

 Node *root = &node10;



    delRedBlackTree(&root, &node15);

    UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node10)), (((void *)0)), (_U_UINT)693, UNITY_DISPLAY_STYLE_HEX32);

    assertNode(&node5,((void *)0),'b',&node10,694);

    assertNode(((void *)0),((void *)0),'r',&node5,695);

}

void test_delRedBlackTree_delete_1_black_from_root_2_and_rotate_left_and_flip_color_of_3_into_red(void){

    setNode(&node3,((void *)0),((void *)0),'b');

    setNode(&node6,((void *)0),((void *)0),'b');

    setNode(&node1,((void *)0),((void *)0),'b');

    setNode(&node5,&node3,&node6,'r');

    setNode(&node2,&node1,&node5,'b');

 Node *root = &node2;



    delRedBlackTree(&root, &node1);

    UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node5)), (((void *)0)), (_U_UINT)717, UNITY_DISPLAY_STYLE_HEX32);

    assertNode(&node2,&node6,'b',&node5,718);

    assertNode(((void *)0),&node3,'b',&node2,719);

    assertNode(((void *)0),((void *)0),'b',&node6,720);

    assertNode(((void *)0),((void *)0),'r',&node3,721);

}

void test_delRedBlackTree_delete_3_black_from_root_2_and_flip_color_of_6_into_red(void){

    setNode(&node3,((void *)0),((void *)0),'b');

    setNode(&node6,((void *)0),((void *)0),'b');

    setNode(&node1,((void *)0),((void *)0),'b');

    setNode(&node5,&node3,&node6,'r');

    setNode(&node2,&node1,&node5,'b');

 Node *root = &node2;



    delRedBlackTree(&root, &node3);

    UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node2)), (((void *)0)), (_U_UINT)743, UNITY_DISPLAY_STYLE_HEX32);

    assertNode(&node1,&node5,'b',&node2,744);

    assertNode(((void *)0),&node6,'b',&node5,745);

    assertNode(((void *)0),((void *)0),'r',&node6,746);

    assertNode(((void *)0),((void *)0),'b',&node1,747);

}

void test_delRedBlackTree_delete_5_red_from_root_2_and_6_r_and_3_b(void){

    setNode(&node3,((void *)0),((void *)0),'b');

    setNode(&node6,((void *)0),((void *)0),'b');

    setNode(&node1,((void *)0),((void *)0),'b');

    setNode(&node5,&node3,&node6,'r');

    setNode(&node2,&node1,&node5,'b');

 Node *root = &node2;



    delRedBlackTree(&root, &node5);

    UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node2)), (((void *)0)), (_U_UINT)769, UNITY_DISPLAY_STYLE_HEX32);

    assertNode(&node1,&node6,'b',&node2,770);

    assertNode(&node3,((void *)0),'r',&node6,771);

    assertNode(((void *)0),((void *)0),'b',&node3,772);

    assertNode(((void *)0),((void *)0),'b',&node1,773);

}

void test_delRedBlackTree_delete_2_black_and_root_into_5b_and_6r(void){

    setNode(&node6,((void *)0),((void *)0),'r');

    setNode(&node1,((void *)0),((void *)0),'b');

    setNode(&node5,((void *)0),&node6,'b');

    setNode(&node2,&node1,&node5,'b');

 Node *root = &node2;



    delRedBlackTree(&root, &node2);

    UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node5)), (((void *)0)), (_U_UINT)794, UNITY_DISPLAY_STYLE_HEX32);

    assertNode(&node1,&node6,'b',&node5,795);

    assertNode(((void *)0),((void *)0),'b',&node1,796);

    assertNode(((void *)0),((void *)0),'b',&node6,797);

}

void test_delRedBlackTree_delete_2_black_and_root_into_1b_and_3b(void){

    setNode(&node3,((void *)0),((void *)0),'r');

    setNode(&node1,((void *)0),&node3,'b');

    setNode(&node5,((void *)0),((void *)0),'b');

    setNode(&node2,&node1,&node5,'b');

 Node *root = &node2;



    delRedBlackTree(&root, &node2);

    UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node3)), (((void *)0)), (_U_UINT)818, UNITY_DISPLAY_STYLE_HEX32);

    assertNode(&node1,&node5,'b',&node3,819);

    assertNode(((void *)0),((void *)0),'b',&node1,820);

    assertNode(((void *)0),((void *)0),'b',&node5,821);

}

void test_delRedBlackTree_remove_24B_and_restruct_20_12_into_red(){

  setNode(&node25, ((void *)0), ((void *)0), 'b');

  setNode(&node20, ((void *)0), ((void *)0), 'b');

  setNode(&node13, ((void *)0), ((void *)0), 'b');

  setNode(&node10, ((void *)0), ((void *)0), 'b');

  setNode(&node12, &node10, &node13, 'b');

  setNode(&node24, &node20, &node25, 'b');

  setNode(&node18, &node12, &node24, 'r');

  Node *root = &node18;



  delRedBlackTree(&root, &node24);

  UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node18)), (((void *)0)), (_U_UINT)845, UNITY_DISPLAY_STYLE_HEX32);

  assertNode(&node12,&node25,'b',&node18,846);

  assertNode(&node10,&node13,'r',&node12,847);

  assertNode(&node20,((void *)0),'b',&node25,848);

  assertNode(((void *)0),((void *)0),'b',&node13,849);

  assertNode(((void *)0),((void *)0),'b',&node10,850);

  assertNode(((void *)0),((void *)0),'r',&node20,851);

}

void test_delRedBlackTree_remove_12B_and_restruct_10_24_into_red(){

  setNode(&node25, ((void *)0), ((void *)0), 'b');

  setNode(&node20, ((void *)0), ((void *)0), 'b');

  setNode(&node13, ((void *)0), ((void *)0), 'b');

  setNode(&node10, ((void *)0), ((void *)0), 'b');

  setNode(&node12, &node10, &node13, 'b');

  setNode(&node24, &node20, &node25, 'b');

  setNode(&node18, &node12, &node24, 'r');

  Node *root = &node18;



  delRedBlackTree(&root, &node12);

  UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node18)), (((void *)0)), (_U_UINT)875, UNITY_DISPLAY_STYLE_HEX32);

  assertNode(&node13,&node24,'b',&node18,876);

  assertNode(&node10,((void *)0),'b',&node13,877);

  assertNode(&node20,&node25,'r',&node24,878);

  assertNode(((void *)0),((void *)0),'b',&node25,879);

  assertNode(((void *)0),((void *)0),'r',&node10,880);

  assertNode(((void *)0),((void *)0),'b',&node20,881);

}
