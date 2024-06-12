#include <iostream>
using namespace std;


/*
void main()
{
	int data[] = {0,6,3,5,9,7,8,4,2};
	int btree[16] = { 0 };
	cout << "原始数组内容：" << endl;
	for (int i = 1; i < 9; i++)
		cout << "[" << data[i] << "] ";
	cout << endl;
	int level;
	for (int i = 1; i < 9; i++) {
		for (level = 1; btree[level] != 0;) {
			if (data[i] > btree[level])
				level = level * 2 + 1;
			else
				level = level * 2;
		}
		btree[level] = data[i];
	}

	cout << "二叉树内容：" << endl;
	for (int i = 1; i < 16; i++)
		cout << "[" << btree[i] << "] ";
	cout << endl;
	system("pause");
}
*/

/*
struct Node {
	int val;
	struct Node* left;
	struct Node* right;
};
typedef Node* Binarytree;
Binarytree rootNode=NULL;

void add(int val) {
	Binarytree newnode = new Node;
	newnode->val = val;
	newnode->left = NULL;
	newnode->right = NULL;
	Binarytree current = NULL;
	if (!rootNode)
		rootNode = newnode;
	else {
		current = rootNode;
		while (true) {
			if (val > current->val)
				if (current->right)
					current = current->right;
				else {
					current->right = newnode;
					break;
				}
			else
				if (current->left)
					current = current->left;
				else {
					current->left = newnode;
					break;
				}
		}
	}
}

void inorder(Binarytree rootnode) {
	if (rootnode) {
		inorder(rootnode->left);
		cout << rootnode->val << endl;
		inorder(rootnode->right);
	}
}

void main()
{
	int content[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (int i = 0; i < 10; i++)
		add(content[i]);
	inorder(rootNode);
	system("pause");
}
*/