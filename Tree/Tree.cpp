#include <stdio.h>
#include <stdlib.h>

//수식트리
typedef struct treeNode {
	int data;
	struct treeNode* left, * right;
}TreeNode;

TreeNode n1 = { 2,NULL, NULL };
TreeNode n2 = { 3,NULL, NULL };
TreeNode n3 = { 4,NULL, NULL };
TreeNode n4 = { 5,NULL, NULL };
TreeNode n5 = { (int)'+',&n1, &n2};
TreeNode n6 = { (int)'*',&n3, &n4 };
TreeNode n7 = { 6,NULL, NULL };
TreeNode n8 = { 7,NULL, NULL };
TreeNode n9 = { (int)'+',&n5, &n6 };
TreeNode n10 = { (int)'/',&n7, &n8 };
TreeNode n11 = { (int)'-',&n9, &n10 };
TreeNode n12 = { 9, NULL, NULL };
TreeNode n13 = { (int)'+',&n11, &n12 };
TreeNode* root = &n13;


//노드 수
int node = 0;


//수식 계산 함수
float evaluate(TreeNode* root)
{
	
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL) {
		node++;
		return root->data;
	}
	else {
		float op1 = evaluate(root->left);
		float op2 = evaluate(root->right);

		switch (root->data) {
		case '+':
			node++;
			printf("%0.2f + %0.2f = %0.2f\n", op1, op2, op1 + op2);
			return op1 + op2;
		case '-':
			node++;
			printf("%0.2f - %0.2f = %0.2f\n", op1, op2, op1 - op2);
			return op1 - op2;
		case '*':
			node++;
			printf("%0.2f * %0.2f = %0.2f\n", op1, op2, op1 * op2);
			return op1 * op2;
		case '/':
			node++;
			printf("%0.2f / %0.2f = %0.2f\n", op1, op2, op1 / op2);
			return op1 / op2;
		}

	}
	return 0;
}

//메인
int main(void)
{
	evaluate(root);
	printf("총 노드의 수는 %d개 입니다.", node);
	return 0;
}