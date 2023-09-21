#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
	int is_thread;
}TreeNode;

//Ʈ�� ����
TreeNode n1 = { 4,NULL, NULL,1};
TreeNode n2 = { 5,NULL, NULL,1 };
TreeNode n3 = { 10,NULL, NULL,1 };
TreeNode n4 = { 11,NULL, NULL,0 };
TreeNode n5 = { 3,&n1, &n2,0 };
TreeNode n6 = { 6,NULL, NULL,1 };
TreeNode n7 = { 8,NULL, NULL,1 };
TreeNode n8 = { 9,&n3, &n4,0 };
TreeNode n9 = { 2,&n5, &n6,0 };
TreeNode n10 = { 7,&n7, &n8,0 };
TreeNode n11 = { 1,&n9, &n10,0 };
TreeNode* root = &n11;



//���� �ļ��ڸ� ã�� �Լ�
TreeNode* find_successor(TreeNode* p) {
	TreeNode* q = p->right;
	if (q == NULL || p->is_thread == 1)
		return q;
	while (q->left != NULL)
		q = q->left;
	return q;
}
//������ ���� ���� ��ȸ �Լ�
void thread_inorder(TreeNode* t)
{
	TreeNode* q;
	q = t;
	while (q->left)
		q = q->left;
	do
	{
		printf("%d ", q->data);
		q = find_successor(q);
	} while (q);
}


//�θ��带 ã�� �Լ�
TreeNode* parent(TreeNode* child) {
	TreeNode* q = child;
	if (q->is_thread == 1)
		q = q->right;
	if (q->left == child || q->right == child)
		return q;
}

void main()
{
	n1.right = &n5;
	n2.right = &n9;
	n3.right = &n8;
	n6.right = &n11;
	n7.right = &n10;



	printf("1. ���� ��ȸ ���\n");
	thread_inorder(root);
	printf("\n\n");
	
	TreeNode* a = parent(&n4);
	TreeNode* b = parent(&n5);
	TreeNode* c = parent(&n6);
	printf("2. Node 4�� �θ�: %d \n", a->data);
	printf("3. Node 5�� �θ�: %d \n", b->data);
	printf("4. Node 6�� �θ�: %d ", c->data);


}