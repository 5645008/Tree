#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
//Ʈ�� ����
typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
}TreeNode;


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
void Insert_nodes(TreeNode* node, int key)
{
	TreeNode* toinsert = new_node(key);
	TreeNode* curr = node;
	TreeNode* prev = NULL;

	while (curr != NULL) {
		prev = curr;
		if (key < curr->key)
			curr = curr->left;
		else
			curr = curr->right;
	}
	if (prev == NULL) {
		prev = toinsert;
		node = prev;
	}

	else if (key < prev->key)
		prev->left = toinsert;

	else
		prev->right = toinsert;
}


TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;
	while (current->left != NULL)
		current = current->left;
	return current;
}
//����(���)
TreeNode* delete_node(TreeNode* root, int key) {
	if (root == NULL) {
		visit++;
		return root;
	}
	
	if (key < root->key) {
		visit++;
		root->left = delete_node(root->left, key);
	}
	else if (key > root->key) {
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
		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
		visit++;
	}
	return root;
}

//����(�ݺ�)
TreeNode* deleteNode(TreeNode* root, int key) {
	TreeNode* current = root;
	TreeNode* parent = NULL;

	while (current != NULL && current->key != key) {
		parent = current;

		if (key < current->key) {
			current = current->left;
		}
		else {
			current = current->right;
		}
	}

	if (current == NULL) {
		return root;
	}

	if (current->left == NULL || current->right == NULL) {
		TreeNode* child = (current->left != NULL) ? current->left : current->right;

		if (parent == NULL) {
			free(current);
			return child;
		}
		else {
			if (current == parent->left) {
				parent->left = child;
			}
			else {
				parent->right = child;
			}

			free(current);
			return root;
		}
	}

	TreeNode* successor = current->right;
	TreeNode* successorParent = current;

	while (successor->left != NULL) {
		successorParent = successor;
		successor = successor->left;
	}

	current->key = successor->key;

	if (successor == successorParent->left) {
		successorParent->left = successor->right;
	}
	else {
		successorParent->right = successor->right;
	}

	free(successor);
	return root;
}



int main(void)
{
	TreeNode* root = NULL;
	root = insert_node(root, 60);
	root = insert_node(root, 41);
	root = insert_node(root, 74);
	root = insert_node(root, 16);
	root = insert_node(root, 53);
	root = insert_node(root, 65);
	root = insert_node(root, 25);
	root = insert_node(root, 46);
	root = insert_node(root, 55);
	root = insert_node(root, 63);
	root = insert_node(root, 70);
	root = insert_node(root, 42);
	root = insert_node(root, 62);
	root = insert_node(root, 64);



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
			scanf_s("%d", &number);
			search(root, number);
			printf("�˻� ����: %d\n", number);
			printf("�湮�� ����� ��: %d\n", visit);
			link_inorder(root);
			printf("\n\n");
			visit = 0;
			break;
		}
		case 'i':
			printf("������ �� �Է�:");
			scanf_s("%d", &number);
			root = insert_node(root, number);
			printf("�湮�� ����� ��: %d\n", visit);
			link_inorder(root);
			printf("\n");
			visit = 0;
			break;
		case 'd':
			printf("������ �� �Է�:");
			scanf_s("%d", &number);
			root = delete_node(root, number);
			printf("�湮�� ����� ��: %d\n", visit);
			link_inorder(root);
			printf("\n");
			visit = 0;
			break;
		case 't':
			link_inorder(root);
			printf("\n");
			printf("�湮�� ����� ��: %d\n", visit);
			visit = 0;
			break;
		case 'I':
			printf("������ �� �Է�:");
			scanf_s("%d", &number);
			Insert_nodes(root, number);
			printf("�湮�� ����� ��: %d\n", visit);
			link_inorder(root);
			printf("\n");
			visit = 0;
			break;
		case 'D':
			printf("������ �� �Է�:");
			scanf_s("%d", &number);
			deleteNode(root, number);
			printf("�湮�� ����� ��: %d\n", visit);
			link_inorder(root);
			printf("\n");
			visit = 0;
			break;
		}
	} while (command != 'c');
	return 0;
}