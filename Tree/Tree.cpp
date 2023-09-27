#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
//트리 설정
typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
}TreeNode;


//방문한 노드를 셀 정수
int visit = 0;

//중위순회
void link_inorder(TreeNode* root) {
	if (root != NULL) {
		visit++;
		link_inorder(root->left);
		printf("%d ", root->key);
		link_inorder(root->right);
	}
}
//탐색(반복)
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

//삽입(재귀)
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

//삽입(반복)
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
//삭제(재귀)
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

//삭제(반복)
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



	printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	printf("| s     : 검색               |\n");
	printf("| i     : 노드 추가          |\n");
	printf("| d     : 노드 삭제          |\n");
	printf("| t     : 중위 순회          |\n");
	printf("| I     : 노드 추가(반복)    |\n");
	printf("| D     : 노드 삭제(반복)    |\n");
	printf("| c     : 종료               |\n");
	printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");

	char command;
	do {
		int number = 0;
		int result = 0;
		printf("메뉴 입력: ");
		command = getchar();
		
		switch (command) {
		case 's':
		{
			printf("겁색할 값 입력:");
			scanf_s("%d", &number);
			search(root, number);
			printf("검색 성공: %d\n", number);
			printf("방문한 노드의 수: %d\n", visit);
			link_inorder(root);
			printf("\n\n");
			visit = 0;
			break;
		}
		case 'i':
			printf("삽입할 값 입력:");
			scanf_s("%d", &number);
			root = insert_node(root, number);
			printf("방문한 노드의 수: %d\n", visit);
			link_inorder(root);
			printf("\n");
			visit = 0;
			break;
		case 'd':
			printf("삭제할 값 입력:");
			scanf_s("%d", &number);
			root = delete_node(root, number);
			printf("방문한 노드의 수: %d\n", visit);
			link_inorder(root);
			printf("\n");
			visit = 0;
			break;
		case 't':
			link_inorder(root);
			printf("\n");
			printf("방문한 노드의 수: %d\n", visit);
			visit = 0;
			break;
		case 'I':
			printf("삽입할 값 입력:");
			scanf_s("%d", &number);
			Insert_nodes(root, number);
			printf("방문한 노드의 수: %d\n", visit);
			link_inorder(root);
			printf("\n");
			visit = 0;
			break;
		case 'D':
			printf("삭제할 값 입력:");
			scanf_s("%d", &number);
			deleteNode(root, number);
			printf("방문한 노드의 수: %d\n", visit);
			link_inorder(root);
			printf("\n");
			visit = 0;
			break;
		}
	} while (command != 'c');
	return 0;
}