#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
//Ʈ�� ����
typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode n1 = { 42,NULL, NULL };
TreeNode n2 = { 62,NULL, NULL };
TreeNode n3 = { 64,NULL, NULL };
TreeNode n4 = { 25,NULL, NULL };
TreeNode n5 = { 46,&n1, NULL };
TreeNode n6 = { 55,NULL, NULL };
TreeNode n7 = { 63,&n2, &n3 };
TreeNode n8 = { 70,NULL, NULL };
TreeNode n9 = { 16,NULL, &n4 };
TreeNode n10 = { 53,&n5, &n6 };
TreeNode n11 = { 65,&n7, &n8 };
TreeNode n12 = { 41,&n9, &n10 };
TreeNode n13 = { 74,&n11, NULL };
TreeNode n14 = { 60,&n12, &n13 };
TreeNode* root = &n14;

//�湮�� ��带 �� ����
int visit = 0;

//������ȸ
void link_inorder(TreeNode* root) {
	if (root != NULL) {
		visit++;
		link_inorder(root->left);
		printf("%d ", root->key);
		link_inorder(root->right);
	}
}
//Ž��(�ݺ�)
TreeNode* search(TreeNode* node, int key)
{
	while (node != NULL) {
		if (key == node->key) {
			visit++;
			return node;
		}
		else if (key < node->key) {
			visit++;
			node = node->left;
		}
		else {
			visit++;
			node = node->right;
		}
	}
	return NULL;
}


TreeNode* new_node(int item)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

//����(���)
TreeNode* insert_node(TreeNode* node, int key)
{
	if (node == NULL) {
		visit++;
		return new_node(key);
	}
	if (key < node->key) {
		visit++;
		node->left = insert_node(node->left, key);
}
	else if (key > node->key) {
		visit++;
		node->right = insert_node(node->right, key);
	}
	return node;
}

//����(�ݺ�)
TreeNode* Insert_nodes(TreeNode* node, int key)
{
	if (node == NULL) {
		visit++;
		return new_node(key);
	}
	while (node != NULL) {
		if (key < node->key) {
			visit++;
			node = node->left;
		}
		else {
			visit++;
			node = node->right;
		}
	}
	return node;
}


TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;
	while (current->left != NULL)
		current = current->left;
	return current;
}
//����(���)
TreeNode* delete_node(TreeNode* root, int key)
{
	if (root == NULL) {
		visit++;
		return root;
	}
	if (key < root->key) {
		visit++;
		root->left = delete_node(root->left, key);
	}
	if (key > root->key) {
		visit++;
		root->right = delete_node(root->right, key);
	}
	else {
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			visit++;
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			visit++;
			return temp;
		}
		TreeNode* temp = min_value_node(root->right);
		visit++;
		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}

//����(�ݺ�)
TreeNode* Delete_nodes(TreeNode* root, int key)
{
	if (root == NULL) {
		visit++;
		return root;
	}
	while (root != NULL) {
		if (key < root->key) {
			visit++;
			root = root->left;
		}
		else {
			visit++;
			root = root->right;
		}
	}
	if(root->key == key)
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			visit++;
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			visit++;
			return temp;
		}
		TreeNode* temp = min_value_node(root->right);
		visit++;
		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
	return root;
}



int main(void)
{
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
	printf("| s     : �˻�               |\n");
	printf("| i     : ��� �߰�          |\n");
	printf("| d     : ��� ����          |\n");
	printf("| t     : ���� ��ȸ          |\n");
	printf("| I     : ��� �߰�(�ݺ�)    |\n");
	printf("| D     : ��� ����(�ݺ�)    |\n");
	printf("| c     : ����               |\n");
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");

	char command;
	do {
		int number = 0;
		int result = 0;
		printf("�޴� �Է�: ");
		command = getchar();
		
		switch (command) {
		case 's':
		{
			printf("�̻��� �� �Է�:");
			scanf("%d", &number);
			search(root, number);
			printf("�˻� ����: %d\n", number);
			printf("�湮�� ����� ��: %d\n", visit);
			link_inorder(root);
			printf("\n");
			visit = 0;
			break;
		}
		case 'i':
			printf("������ �� �Է�:");
			scanf("%d", &number);
			insert_node(root, number);
			printf("�湮�� ����� ��: %d\n", visit);
			link_inorder(root);
			printf("\n");
			visit = 0;
			break;
		case 'd':
			printf("������ �� �Է�:");
			scanf("%d", &number);
			delete_node(root, number);
			printf("�湮�� ����� ��: %d\n", visit);
			link_inorder(root);
			printf("\n");
			visit = 0;
			break;
		case 't':
			link_inorder(root);
			printf("�湮�� ����� ��: %d\n", visit);
			visit = 0;
			break;
		case 'I':
			printf("������ �� �Է�:");
			scanf("%d", &number);
			Insert_nodes(root, number);
			printf("�湮�� ����� ��: %d\n", visit);
			link_inorder(root);
			printf("\n");
			visit = 0;
			break;
		case 'D':
			printf("������ �� �Է�:");
			scanf("%d", &number);
			Delete_nodes(root, number);
			printf("�湮�� ����� ��: %d\n", visit);
			link_inorder(root);
			printf("\n");
			visit = 0;
			break;
		}
	} while (command != 'c');
	return 0;
}