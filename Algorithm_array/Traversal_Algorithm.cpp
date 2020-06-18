#include <iostream>

using namespace std;

const int number = 15;

// �ϳ��� ��� ������ �����մϴ�.
typedef struct node* treePointer;
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
} node;

// ���� ��ȸ�� �����մϴ�.
void preorder_haha(treePointer ptr_haha) {
	if (ptr_haha) {
		cout << ptr_haha->data << ' ';
		preorder_haha(ptr_haha->leftChild);
		preorder_haha(ptr_haha->rightChild);
	}
}

// ���� ��ȸ�� �����մϴ�.
void inorder_haha(treePointer ptr_haha) {
	if (ptr_haha) {
		inorder_haha(ptr_haha->leftChild);
		cout << ptr_haha->data << ' ';
		inorder_haha(ptr_haha->rightChild);
	}
}

// ���� ��ȸ�� �����մϴ�.
void postorder_haha(treePointer ptr_haha) {
	if (ptr_haha) {
		postorder_haha(ptr_haha->leftChild);
		postorder_haha(ptr_haha->rightChild);
		cout << ptr_haha->data << ' ';
	}
}

int main_Travesal(void) {
	node nodes[number + 1];
	for (int i = 1; i <= number; i++) {
		nodes[i].data = i;
		nodes[i].leftChild = NULL;
		nodes[i].rightChild = NULL;
	}
	for (int i = 1; i <= number; i++) {
		if (i % 2 == 0) {
			nodes[i / 2].leftChild = &nodes[i];
		}
		else {
			nodes[i / 2].rightChild = &nodes[i];
		}
	}
	//printf("%d", nodes[1].leftChild->data);
	//preorder_haha(&nodes[1]);
	inorder_haha(&nodes[1]);
	//postorder_haha(&nodes[1]);
	return 0;
}