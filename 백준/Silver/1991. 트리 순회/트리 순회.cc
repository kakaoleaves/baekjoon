#include <iostream>
#include <vector>
using namespace std;

typedef struct TreeNode
{
	char data;
	TreeNode *left;
	TreeNode *right;
} TreeNode;

TreeNode* createNode(char data)
{
	TreeNode *newNode = new TreeNode;
	newNode->data = data;
	newNode->left = nullptr;
	newNode->right = nullptr;
	return newNode;
}

TreeNode* searchNode(TreeNode* root, char data) {
	if (root == nullptr || root->data == data) return root;
	TreeNode* left = searchNode(root->left, data);
	if (left != nullptr) return left;
	return searchNode(root->right, data);	
}

void preorder(TreeNode* root) {
	if (root == nullptr) return;
	cout << root->data;
	preorder(root->left);
	preorder(root->right);
}

void inorder(TreeNode* root) {
	if (root == nullptr) return;
	inorder(root->left);
	cout << root->data;
	inorder(root->right);
}

void postorder(TreeNode* root) {
	if (root == nullptr) return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; // 이진 트리의 노드의 개수 1 <= N <= 26

    cin >> n;

	TreeNode* root = nullptr;

	for (int i = 0; i < n; ++i) {
		char data, left, right;
		cin >> data >> left >> right;

		if (i == 0) {
			root = createNode(data);
			if (left != '.') root->left = createNode(left);
			if (right != '.') root->right = createNode(right);
		}
		else {
			TreeNode* node = searchNode(root, data);
			if (left != '.') node->left = createNode(left);
			if (right != '.') node->right = createNode(right);
		}
	}

	preorder(root); cout << '\n';
	inorder(root); cout << '\n';
	postorder(root); cout << '\n';
    
    return 0;
}
