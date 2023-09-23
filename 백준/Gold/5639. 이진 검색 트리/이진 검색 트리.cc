#include <iostream>
#include <vector>
using namespace std;

typedef struct TreeNode
{
	int data;
	TreeNode *left;
	TreeNode *right;
} TreeNode;

TreeNode* createNode(int data)
{
	TreeNode *newNode = new TreeNode;
	newNode->data = data;
	newNode->left = nullptr;
	newNode->right = nullptr;
	return newNode;
}

TreeNode* searchNode(TreeNode* root, int data) {
	if (root == nullptr || root->data == data) return root;
	if (data < root->data) return searchNode(root->left, data);
	return searchNode(root->right, data);
}

void insert(TreeNode* root, int data) {
	TreeNode* node = createNode(data);
	TreeNode* cur = root;
	TreeNode* parent = nullptr;

	while (cur != nullptr) {
		parent = cur;
		if (data < cur->data) cur = cur->left;
		else cur = cur->right;
	}

	if (data < parent->data) parent->left = node;
	else parent->right = node;
}

void preorder(TreeNode* root) {
	if (root == nullptr) return;
	cout << root->data << '\n';
	preorder(root->left);
	preorder(root->right);
}

void inorder(TreeNode* root) {
	if (root == nullptr) return;
	inorder(root->left);
	cout << root->data << '\n';
	inorder(root->right);
}

void postorder(TreeNode* root) {
	if (root == nullptr) return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	int root, prev, cur;

	cin >> root;
	TreeNode* bst = createNode(root);
	prev = root;

	while (cin >> cur)
		insert(bst, cur);

	postorder(bst);

    return 0;
}