#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
//��ũ ǥ����
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

//��ũ-������ȸ
void link_preorder(TreeNode* root) {
	if (root != NULL) {
		printf("%d ", root->data);
		link_preorder(root->left);
		link_preorder(root->right);
	}
}

//��ũ-������ȸ
void link_inorder(TreeNode* root) {
	if (root != NULL) {
		link_inorder(root->left);
		printf("%d ", root->data);
		link_inorder(root->right);
	}
}

//��ũ-������ȸ
void link_postorder(TreeNode* root) {
	if (root != NULL) {
		link_postorder(root->left);
		link_postorder(root->right);
		printf("%d ", root->data);
	}
}

//�迭 ǥ����
int Tree[16] = { NULL, 1, 2, 7, 3, 6, 8, 9, 4, 5, NULL, NULL, NULL, NULL, 10, 11 };
int array_root = Tree[1];

//�迭-������ȸ
void array_preorder(int root) {
	if (Tree[root] != NULL) {
		printf("%d ", Tree[root]);
		array_preorder(root * 2);
		array_preorder(root * 2 + 1);
	}
}

//�迭-������ȸ
void array_inorder(int root) {
	if (Tree[root] != NULL) {
		array_inorder(root * 2);
		printf("%d ", Tree[root]);
		array_inorder(root * 2 + 1);
	}
}

//�迭-������ȸ
void array_postorder(int root) {
	if (Tree[root] != NULL) {
		array_postorder(root * 2);
		array_postorder(root * 2 + 1);
		printf("%d ", Tree[root]);
	}
}





void main()
{
	//��ũ ǥ����
	printf("<Linked Tree>\n");
	printf("1. ���� ��ȸ\n");
	link_preorder(root);
	printf("\n\n");

	printf("2. ���� ��ȸ\n");
	link_inorder(root);
	printf("\n\n");

	printf("3. ���� ��ȸ\n");
	link_postorder(root);
	printf("\n\n");

	//�迭 ǥ����
	printf("<Array Tree>\n");
	printf("1. ���� ��ȸ\n");
	array_preorder(array_root);
	printf("\n\n");

	printf("2. ���� ��ȸ\n");
	array_inorder(array_root);
	printf("\n\n");

	printf("3. ���� ��ȸ\n");
	array_postorder(array_root);
	printf("\n\n");



}