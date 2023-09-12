#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
//링크 표현법
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
};

TreeNode n1 = { 4,NULL, NULL };
TreeNode n2 = { 5,NULL, NULL };
TreeNode n3 = { 10,NULL, NULL };
TreeNode n4 = { 11,NULL, NULL };
TreeNode n5 = { 3,&n1, &n2 };
TreeNode n6 = { 6,NULL, NULL };
TreeNode n7 = { 8,NULL, NULL };
TreeNode n8 = { 9,&n3, &n4 };
TreeNode n9 = { 2,&n5, &n6 };
TreeNode n10 = { 7,&n7, &n8 };
TreeNode n11 = { 1,&n9, &n10 };
TreeNode* root = &n11;

//링크-전위순회
void link_preorder(TreeNode* root) {
	if (root != NULL) {
		printf("%d ", root->data);
		link_preorder(root->left);
		link_preorder(root->right);
	}
}

//링크-중위순회
void link_inorder(TreeNode* root) {
	if (root != NULL) {
		link_inorder(root->left);
		printf("%d ", root->data);
		link_inorder(root->right);
	}
}

//링크-후위순회
void link_postorder(TreeNode* root) {
	if (root != NULL) {
		link_postorder(root->left);
		link_postorder(root->right);
		printf("%d ", root->data);
	}
}

//배열 표현법
int Tree[16] = { NULL, 1, 2, 7, 3, 6, 8, 9, 4, 5, NULL, NULL, NULL, NULL, 10, 11 };
int array_root = Tree[1];

//배열-전위순회
void array_preorder(int root) {
	if (Tree[root] != NULL) {
		printf("%d ", Tree[root]);
		array_preorder(root * 2);
		array_preorder(root * 2 + 1);
	}
}

//배열-중위순회
void array_inorder(int root) {
	if (Tree[root] != NULL) {
		array_inorder(root * 2);
		printf("%d ", Tree[root]);
		array_inorder(root * 2 + 1);
	}
}

//배열-후위순회
void array_postorder(int root) {
	if (Tree[root] != NULL) {
		array_postorder(root * 2);
		array_postorder(root * 2 + 1);
		printf("%d ", Tree[root]);
	}
}





void main()
{
	//링크 표현법
	printf("<Linked Tree>\n");
	printf("1. 전위 순회\n");
	link_preorder(root);
	printf("\n\n");

	printf("2. 중위 순회\n");
	link_inorder(root);
	printf("\n\n");

	printf("3. 후위 순회\n");
	link_postorder(root);
	printf("\n\n");

	//배열 표현법
	printf("<Array Tree>\n");
	printf("1. 전위 순회\n");
	array_preorder(array_root);
	printf("\n\n");

	printf("2. 중위 순회\n");
	array_inorder(array_root);
	printf("\n\n");

	printf("3. 후위 순회\n");
	array_postorder(array_root);
	printf("\n\n");



}