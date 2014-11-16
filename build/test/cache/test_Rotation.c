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

void test_rightRotation_3_elements(void){

 setNode(&node1,((void *)0),((void *)0),'b');

 setNode(&node5,&node1,((void *)0),'b');

 setNode(&node10,&node5,((void *)0),'b');

 Node *root = &node10;





 rightRotate(&root);



 UnityAssertEqualNumber((_U_SINT)(_UP)((node1.left)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)49, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node1.right)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)50, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node10.left)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)51, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node10.right)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)52, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node5.left)), (_U_SINT)(_UP)((&node1)), (((void *)0)), (_U_UINT)53, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node5.right)), (_U_SINT)(_UP)((&node10)), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node5)), (((void *)0)), (_U_UINT)55, UNITY_DISPLAY_STYLE_HEX32);

}

void test_rightRotation_4_elements(void){

 setNode(&node15,((void *)0),((void *)0),'b');

 setNode(&node1,((void *)0),((void *)0),'b');

 setNode(&node5,&node1,((void *)0),'b');

 setNode(&node10,&node5,&node15,'b');

 Node *root = &node10;





 rightRotate(&root);



 UnityAssertEqualNumber((_U_SINT)(_UP)((node1.left)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)78, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node1.right)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)79, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node15.left)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)80, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node15.right)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)81, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node10.left)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)82, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node10.right)), (_U_SINT)(_UP)((&node15)), (((void *)0)), (_U_UINT)83, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node5.left)), (_U_SINT)(_UP)((&node1)), (((void *)0)), (_U_UINT)84, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node5.right)), (_U_SINT)(_UP)((&node10)), (((void *)0)), (_U_UINT)85, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node5)), (((void *)0)), (_U_UINT)86, UNITY_DISPLAY_STYLE_HEX32);

}

void test_rightRotation_5_elements(void){



 setNode(&node1,((void *)0),((void *)0),'b');

 setNode(&node15,((void *)0),((void *)0),'b');

 setNode(&node30,((void *)0),((void *)0),'b');

 setNode(&node5,&node1,&node15,'b');

 setNode(&node10,&node5,&node30,'b');

 Node *root = &node10;





 rightRotate(&root);



 UnityAssertEqualNumber((_U_SINT)(_UP)((node1.left)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)111, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node1.right)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)112, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node15.left)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)113, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node15.right)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)114, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node30.left)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)115, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node30.right)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)116, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node10.left)), (_U_SINT)(_UP)((&node15)), (((void *)0)), (_U_UINT)117, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node10.right)), (_U_SINT)(_UP)((&node30)), (((void *)0)), (_U_UINT)118, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node5.left)), (_U_SINT)(_UP)((&node1)), (((void *)0)), (_U_UINT)119, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node5.right)), (_U_SINT)(_UP)((&node10)), (((void *)0)), (_U_UINT)120, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node5)), (((void *)0)), (_U_UINT)121, UNITY_DISPLAY_STYLE_HEX32);

}

void test_leftRotation_3_elements(void){

 setNode(&node10,((void *)0),((void *)0),'b');

 setNode(&node5,((void *)0),&node10,'b');

 setNode(&node1,((void *)0),&node5,'b');

 Node *root = &node1;





 leftRotate(&root);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node10.left)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)145, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node10.right)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)146, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node1.left)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)147, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node1.right)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)148, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node5.left)), (_U_SINT)(_UP)((&node1)), (((void *)0)), (_U_UINT)149, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node5.right)), (_U_SINT)(_UP)((&node10)), (((void *)0)), (_U_UINT)150, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node5)), (((void *)0)), (_U_UINT)151, UNITY_DISPLAY_STYLE_HEX32);

}

void test_leftRotation_4_elements(void){

 setNode(&node15,((void *)0),((void *)0),'b');

 setNode(&node10,((void *)0),((void *)0),'b');

 setNode(&node5,((void *)0),&node10,'b');

 setNode(&node1,&node15,&node5,'b');

 Node *root = &node1;





 leftRotate(&root);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node10.left)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)173, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node10.right)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)174, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node15.left)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)175, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node15.right)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)176, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node1.left)), (_U_SINT)(_UP)((&node15)), (((void *)0)), (_U_UINT)177, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node1.right)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)178, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node5.left)), (_U_SINT)(_UP)((&node1)), (((void *)0)), (_U_UINT)179, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node5.right)), (_U_SINT)(_UP)((&node10)), (((void *)0)), (_U_UINT)180, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node5)), (((void *)0)), (_U_UINT)181, UNITY_DISPLAY_STYLE_HEX32);

}

void test_leftRotation_5_elements(void){

 setNode(&node30,((void *)0),((void *)0),'b');

 setNode(&node15,((void *)0),((void *)0),'b');

 setNode(&node10,((void *)0),((void *)0),'b');

 setNode(&node5,&node10,&node30,'b');

 setNode(&node1,&node15,&node5,'b');

 Node *root = &node1;





 leftRotate(&root);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node10.left)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)204, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node10.right)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)205, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node15.left)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)206, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node15.right)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)207, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node30.left)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)208, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node30.right)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)209, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node1.left)), (_U_SINT)(_UP)((&node15)), (((void *)0)), (_U_UINT)210, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node1.right)), (_U_SINT)(_UP)((&node10)), (((void *)0)), (_U_UINT)211, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node5.left)), (_U_SINT)(_UP)((&node1)), (((void *)0)), (_U_UINT)212, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node5.right)), (_U_SINT)(_UP)((&node30)), (((void *)0)), (_U_UINT)213, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node5)), (((void *)0)), (_U_UINT)214, UNITY_DISPLAY_STYLE_HEX32);

}

void test_leftRightRotate_with_3_elements(void){

 setNode(&node15,((void *)0),((void *)0),'b');

 setNode(&node10,((void *)0),&node15,'b');

 setNode(&node20,&node10,((void *)0),'b');

 Node *root = &node20;



 leftRightRotate(&root);



 UnityAssertEqualNumber((_U_SINT)(_UP)((node10.left)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)236, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node10.right)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)237, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node20.left)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)238, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node20.right)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)239, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node15.left)), (_U_SINT)(_UP)((&node10)), (((void *)0)), (_U_UINT)240, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node15.right)), (_U_SINT)(_UP)((&node20)), (((void *)0)), (_U_UINT)241, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node15)), (((void *)0)), (_U_UINT)242, UNITY_DISPLAY_STYLE_HEX32);

}

void test_leftRightRotate_with_4_elements(void){

 setNode(&node15,((void *)0),((void *)0),'b');

 setNode(&node5,((void *)0),((void *)0),'b');

 setNode(&node10,&node5,&node15,'b');

 setNode(&node20,&node10,((void *)0),'b');

 Node *root = &node20;



 leftRightRotate(&root);



 UnityAssertEqualNumber((_U_SINT)(_UP)((node5.left)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)263, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node5.right)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)264, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node20.left)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)265, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node20.right)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)266, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node15.left)), (_U_SINT)(_UP)((&node10)), (((void *)0)), (_U_UINT)267, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node15.right)), (_U_SINT)(_UP)((&node20)), (((void *)0)), (_U_UINT)268, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node10.left)), (_U_SINT)(_UP)((&node5)), (((void *)0)), (_U_UINT)269, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node10.right)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)270, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node15)), (((void *)0)), (_U_UINT)271, UNITY_DISPLAY_STYLE_HEX32);



}

void test_leftRightRotate_with_6_elements(void){

 setNode(&node1,((void *)0),((void *)0),'b');

 setNode(&node15,((void *)0),((void *)0),'b');

 setNode(&node25,((void *)0),((void *)0),'b');

 setNode(&node10,((void *)0),&node15,'b');

 setNode(&node5,&node1,&node10,'b');

 setNode(&node20,&node5,&node25,'b');

 Node *root = &node20;



 leftRightRotate(&root);



 UnityAssertEqualNumber((_U_SINT)(_UP)((node1.left)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)297, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node1.right)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)298, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node15.left)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)299, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node15.right)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)300, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node25.left)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)301, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node25.right)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)302, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node10.left)), (_U_SINT)(_UP)((&node5)), (((void *)0)), (_U_UINT)303, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node10.right)), (_U_SINT)(_UP)((&node20)), (((void *)0)), (_U_UINT)304, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node5.left)), (_U_SINT)(_UP)((&node1)), (((void *)0)), (_U_UINT)305, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node5.right)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)306, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node20.left)), (_U_SINT)(_UP)((&node15)), (((void *)0)), (_U_UINT)307, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node20.right)), (_U_SINT)(_UP)((&node25)), (((void *)0)), (_U_UINT)308, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node10)), (((void *)0)), (_U_UINT)309, UNITY_DISPLAY_STYLE_HEX32);



}

void test_leftRightRotate_with_6_elements_case2(void){

 setNode(&node1,((void *)0),((void *)0),'b');

 setNode(&node10,((void *)0),((void *)0),'b');

 setNode(&node25,((void *)0),((void *)0),'b');

 setNode(&node15,&node10,((void *)0),'b');

 setNode(&node5,&node1,&node15,'b');

 setNode(&node20,&node5,&node25,'b');

 Node *root = &node20;



 leftRightRotate(&root);



 UnityAssertEqualNumber((_U_SINT)(_UP)((node1.left)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)333, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node1.right)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)334, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node10.left)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)335, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node10.right)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)336, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node25.left)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)337, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node25.right)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)338, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node15.left)), (_U_SINT)(_UP)((&node5)), (((void *)0)), (_U_UINT)339, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node15.right)), (_U_SINT)(_UP)((&node20)), (((void *)0)), (_U_UINT)340, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node5.left)), (_U_SINT)(_UP)((&node1)), (((void *)0)), (_U_UINT)341, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node5.right)), (_U_SINT)(_UP)((&node10)), (((void *)0)), (_U_UINT)342, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node20.left)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)343, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node20.right)), (_U_SINT)(_UP)((&node25)), (((void *)0)), (_U_UINT)344, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node15)), (((void *)0)), (_U_UINT)345, UNITY_DISPLAY_STYLE_HEX32);

}

void test_rightLeftRotate_with_3_elements(void){

 setNode(&node15,((void *)0),((void *)0),'b');

 setNode(&node20,&node15,((void *)0),'b');

 setNode(&node10,((void *)0),&node20,'b');

 Node *root = &node10;



 rightLeftRotate(&root);



 UnityAssertEqualNumber((_U_SINT)(_UP)((node10.left)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)367, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node10.right)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)368, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node20.left)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)369, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node20.right)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)370, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node15.left)), (_U_SINT)(_UP)((&node10)), (((void *)0)), (_U_UINT)371, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node15.right)), (_U_SINT)(_UP)((&node20)), (((void *)0)), (_U_UINT)372, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node15)), (((void *)0)), (_U_UINT)373, UNITY_DISPLAY_STYLE_HEX32);

}

void test_rightLeftRotate_with_4_elements(void){

 setNode(&node15,((void *)0),((void *)0),'b');

 setNode(&node25,((void *)0),((void *)0),'b');

 setNode(&node20,&node15,&node25,'b');

 setNode(&node10,((void *)0),&node20,'b');

 Node *root = &node10;



 rightLeftRotate(&root);



 UnityAssertEqualNumber((_U_SINT)(_UP)((node10.left)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)394, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node10.right)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)395, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node25.left)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)396, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node25.right)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)397, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node15.left)), (_U_SINT)(_UP)((&node10)), (((void *)0)), (_U_UINT)398, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node15.right)), (_U_SINT)(_UP)((&node20)), (((void *)0)), (_U_UINT)399, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node20.left)), (_U_SINT)(_UP)((((void *)0))), (((void *)0)), (_U_UINT)400, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((node20.right)), (_U_SINT)(_UP)((&node25)), (((void *)0)), (_U_UINT)401, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((root)), (_U_SINT)(_UP)((&node15)), (((void *)0)), (_U_UINT)402, UNITY_DISPLAY_STYLE_HEX32);

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
