#include "unity.h"
#include "Rotation.h"
#include "RedBlackTree.h"
#include "Node.h"
#include "InitNode.h"
#include "ErrorCode.h"
#include "CustomAssertion.h"
#include "CException.h"
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

void test_addRedBlackTree_add_10_to_empty_tree(void){

 setNode(&node10,((void *)0),((void *)0),'r');

 Node *root = ((void *)0);



 addRedBlackTree(&root,&node10);





 UnityAssertEqualNumber((_U_SINT)(_UP)((&node10)), (_U_SINT)(_UP)((root)), (((void *)0)), (_U_UINT)53, UNITY_DISPLAY_STYLE_HEX32);

 assertNode(((void *)0),((void *)0),'b',root,54);

}

void test_addRedBlackTree_add_left_5_to_10_tree(void){

 setNode(&node5,((void *)0),((void *)0),'r');

 setNode(&node10,((void *)0),((void *)0),'b');

 Node *root = &node10;



 addRedBlackTree(&root,&node5);



 UnityAssertEqualNumber((_U_SINT)(_UP)((&node10)), (_U_SINT)(_UP)((root)), (((void *)0)), (_U_UINT)74, UNITY_DISPLAY_STYLE_HEX32);

 assertNode(&node5,((void *)0),'b',&node10,75);

 assertNode(((void *)0),((void *)0),'r',&node5,76);

}

void test_addRedBlackTree_add_right_15_to_10_tree(void){

 setNode(&node15,((void *)0),((void *)0),'r');

 setNode(&node10,((void *)0),((void *)0),'b');

 Node *root = &node10;



 addRedBlackTree(&root,&node15);



 UnityAssertEqualNumber((_U_SINT)(_UP)((&node10)), (_U_SINT)(_UP)((root)), (((void *)0)), (_U_UINT)96, UNITY_DISPLAY_STYLE_HEX32);

 assertNode(((void *)0),&node15,'b',&node10,97);

 assertNode(((void *)0),((void *)0),'r',&node15,98);

}

void test_addRedBlackTree_add_right_10_to_10_tree(void){

 int e;

 setNode(&node10,((void *)0),((void *)0),'b');

 setNode(&node10,((void *)0),((void *)0),'b');

 Node *root = &node10;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addRedBlackTree(&root,&node10);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((e)), (_U_SINT)((ERR_EQUIVALENT_ERR)), (((void *)0)), (_U_UINT)120, UNITY_DISPLAY_STYLE_INT);

 }

}

void test_addRedBlackTree_add_left_1_to_5_to_10_tree(void){

 setNode(&node1,((void *)0),((void *)0),'r');

 setNode(&node5,((void *)0),((void *)0),'r');

 setNode(&node10,&node5,((void *)0),'b');

 Node *root = &node10;



 addRedBlackTree(&root,&node1);



 UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node5)), (((void *)0)), (_U_UINT)145, UNITY_DISPLAY_STYLE_HEX32);

 assertNode(&node1,&node10,'b',root,146);

 assertNode(((void *)0),((void *)0),'r',&node1,147);

 assertNode(((void *)0),((void *)0),'r',&node10,148);



}

void test_addRedBlackTree_add_10_to_tree_should_left_right_rotate(void){

  setNode(&node10,((void *)0),((void *)0),'r');

  setNode(&node5,((void *)0),((void *)0),'r');

  setNode(&node15,&node5,((void *)0),'b');

  Node *root = &node15;



  addRedBlackTree(&root, &node10);

  UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node10)), (((void *)0)), (_U_UINT)172, UNITY_DISPLAY_STYLE_HEX32);



  assertNode(&node5,&node15,'b',&node10,174);

  assertNode(((void *)0),((void *)0),'r',&node5,175);

  assertNode(((void *)0),((void *)0),'r',&node15,176);

}

void test_addRedBlackTree_add_10_to_tree_should_left_rotate(void){

  setNode(&node30,((void *)0),((void *)0),'r');

  setNode(&node20,((void *)0),((void *)0),'r');

  setNode(&node10,((void *)0),&node20,'b');

  Node *root = &node10;



  addRedBlackTree(&root, &node30);

  UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node20)), (((void *)0)), (_U_UINT)202, UNITY_DISPLAY_STYLE_HEX32);



  assertNode(&node10,&node30,'b',&node20,204);

  assertNode(((void *)0),((void *)0),'r',&node10,205);

  assertNode(((void *)0),((void *)0),'r',&node30,206);

}

void test_addRedBlackTree_add_10_to_tree_should_right_left_rotate(void){

  setNode(&node15,((void *)0),((void *)0),'r');

  setNode(&node20,((void *)0),((void *)0),'r');

  setNode(&node10,((void *)0),&node20,'b');

  Node *root = &node10;



  addRedBlackTree(&root, &node15);

  UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node15)), (((void *)0)), (_U_UINT)231, UNITY_DISPLAY_STYLE_HEX32);



  assertNode(&node10,&node20,'b',&node15,233);

  assertNode(((void *)0),((void *)0),'r',&node10,234);

  assertNode(((void *)0),((void *)0),'r',&node20,235);

}

 void test_addRedBlackTree_add_7_to_4_node(void){

 setNode(&node7,((void *)0),((void *)0),'r');

 setNode(&node5,((void *)0),((void *)0),'r');

 setNode(&node15,((void *)0),((void *)0),'r');

 setNode(&node10,&node5,&node15,'b');

 Node *root = &node10;



 _addRedBlackTree(&root, &node7);

     UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node10)), (((void *)0)), (_U_UINT)258, UNITY_DISPLAY_STYLE_HEX32);



 assertNode(&node5,&node15,'r',&node10,260);

 assertNode(((void *)0),&node7,'b',&node5,261);

 assertNode(((void *)0),((void *)0),'b',&node15,262);

 assertNode(((void *)0),((void *)0),'r',&node7,263);

}

 void test_addRedBlackTree_add_12_to_4_node(void){

 setNode(&node12,((void *)0),((void *)0),'r');

 setNode(&node5,((void *)0),((void *)0),'r');

 setNode(&node15,((void *)0),((void *)0),'r');

 setNode(&node10,&node5,&node15,'b');

 Node *root = &node10;



 _addRedBlackTree(&root, &node12);

    UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node10)), (((void *)0)), (_U_UINT)286, UNITY_DISPLAY_STYLE_HEX32);



 assertNode(&node5,&node15,'r',&node10,288);

 assertNode(((void *)0),((void *)0),'b',&node5,289);

 assertNode(&node12,((void *)0),'b',&node15,290);

 assertNode(((void *)0),((void *)0),'r',&node12,291);

}

 void test_addRedBlackTree_add_18_to_4_node(void){

 setNode(&node18,((void *)0),((void *)0),'r');

 setNode(&node5,((void *)0),((void *)0),'r');

 setNode(&node15,((void *)0),((void *)0),'r');

 setNode(&node10,&node5,&node15,'b');

 Node *root = &node10;



 _addRedBlackTree(&root, &node18);

    UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node10)), (((void *)0)), (_U_UINT)314, UNITY_DISPLAY_STYLE_HEX32);



 assertNode(&node5,&node15,'r',&node10,316);

 assertNode(((void *)0),((void *)0),'b',&node5,317);

 assertNode(((void *)0),&node18,'b',&node15,318);

 assertNode(((void *)0),((void *)0),'r',&node18,319);

}

void test_addRedBlackTree_add_10_to_tree_should_add_only(void){

  setNode(&node20,((void *)0),((void *)0),'r');

  setNode(&node10,((void *)0),((void *)0),'r');

  setNode(&node15,((void *)0),&node20,'b');

 Node *root = &node15;



  addRedBlackTree(&root, &node10);

  UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node15)), (((void *)0)), (_U_UINT)337, UNITY_DISPLAY_STYLE_HEX32);



  assertNode(&node10,&node20,'b',&node15,339);

  assertNode(((void *)0),((void *)0),'r',&node10,340);

  assertNode(((void *)0),((void *)0),'r',&node20,341);

}











 void test_addRedBlackTree_add_com_to_4_node(void){

 setNode(&node30,((void *)0),((void *)0),'b');

 setNode(&node60,((void *)0),((void *)0),'b');



 setNode(&node5,((void *)0),((void *)0),'r');

 setNode(&node15,((void *)0),((void *)0),'r');

 setNode(&node1,((void *)0),((void *)0),'b');

 setNode(&node7,((void *)0),((void *)0),'r');

 setNode(&node20,&node4,&node40,'b');



 setNode(&node40,&node30,&node60,'r');

 setNode(&node4,&node1,&node10,'r');

 setNode(&node10,&node5,&node15,'b');



 Node *root = &node20;



 addRedBlackTree(&root, &node7);

    UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node20)), (((void *)0)), (_U_UINT)365, UNITY_DISPLAY_STYLE_HEX32);



 assertNode(&node4,&node40,'b',&node20,367);

 assertNode(&node1,&node10,'b',&node4,368);

 assertNode(&node30,&node60,'b',&node40,369);

 assertNode(&node5,&node15,'r',&node10,370);

 assertNode(((void *)0),((void *)0),'b',&node1,371);

 assertNode(((void *)0),((void *)0),'b',&node30,372);

 assertNode(((void *)0),((void *)0),'b',&node60,373);

 assertNode(((void *)0),((void *)0),'b',&node15,374);

 assertNode(((void *)0),&node7,'b',&node5,375);

 assertNode(((void *)0),((void *)0),'r',&node7,376);

}
