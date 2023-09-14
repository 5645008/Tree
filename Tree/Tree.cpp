#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

#define SIZE 100
int top = -1;
TreeNode* stack[SIZE];

void push(TreeNode* p)
{
	if (top < SIZE - 1 && p != NULL)
		stack[++top] = p;
}

TreeNode* pop()
{
	TreeNode* p = NULL;
	if (top >= 0)
		p = stack[top--];
	return p;
}

//전위순회
void preorder_iter(TreeNode* root)
{
	push(root);
	while (1) {
		root = pop();
		if (!root) break;
		printf("%d ", root->data);
		push(root->right);
		push(root->left);
	}
}
//중위순회
void inorder_iter(TreeNode* root)
{
	while (1) {
		for (; root; root = root->left)
			push(root);
		root = pop();
		if (!root) break;
		printf("%d ", root->data);
		root = root->right;
	}
}



//후위순회
void postorder_iter(TreeNode* root)
{
	while (1) {
		do {
			if (root->data != NULL && root != NULL) {
				push(root);
				root = root->left;
			}
			else { break; }
		} while (root != NULL);
		root = pop();
		if (!root) break;
		if (root->right != NULL) {
			if (root->right->data == NULL)
			{
				printf("%d ", root->data);
				root->data = NULL;
			}
			else {
				push(root);
				root = root->right;
			}
		}
		else {
			printf("%d ", root->data);
			root->data = NULL;
		}
	}
}


//주어진 트리
TreeNode n1 = { 4,  NULL, NULL };
TreeNode n2 = { 5,  NULL,  NULL };
TreeNode n3 = { 10, NULL, NULL };
TreeNode n4 = { 11, NULL, NULL };
TreeNode n5 = { 3, &n1,  &n2 };
TreeNode n6 = { 6, NULL,  NULL };
TreeNode n7 = { 8, NULL,  NULL };
TreeNode n8 = { 9, &n3,  &n4 };
TreeNode n9 = { 2, &n5,  &n6 };
TreeNode n10 = { 7, &n7,  &n8 };
TreeNode n11 = { 1, &n9,  &n10 };
TreeNode* root = &n11;

//메인
int main(void)
{
	printf("1. 전위 순회\n");
	preorder_iter(root);
	printf("\n\n");

	printf("2. 중위 순회\n");
	inorder_iter(root);
	printf("\n\n");

	printf("3. 후위 순회\n");
	postorder_iter(root);
	printf("\n\n");

	return 0;
}
