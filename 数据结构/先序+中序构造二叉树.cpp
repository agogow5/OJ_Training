#include<iostream>
#include<string>
using namespace std;

string str_pre, str_mid;

struct Node {
	Node *lchild, *rchild;
	char data;
};

void TravelPost(Node *root)
{
	if (root->lchild != nullptr)
		TravelPost(root->lchild);

	if (root->rchild != nullptr)
		TravelPost(root->rchild);

	cout << root->data;
	return;
}

Node * CreateTree(int s1, int e1, int s2, int e2)
{
	Node *root = new Node;
	root->lchild = root->rchild = nullptr;
	root->data = str_pre[s1];

	int pos = str_mid.find_first_of(root->data);
	//×ó×ÓÊ÷
	if (pos != s2)
		root->lchild = CreateTree(s1 + 1, s1 + (pos - s2), s2, pos - 1);
	else
		root->lchild = nullptr;
	//ÓÒ×ÓÊ÷
	if (pos != e2)
		root->rchild = CreateTree(s1 + (pos - s2) + 1, e1, pos + 1, e2);
	else
		root->rchild = nullptr;

	return root;
}

void DestroyTree(Node *root)
{
	if (nullptr != root->lchild)
		DestroyTree(root->lchild);
	if (nullptr != root->rchild)
		DestroyTree(root->rchild);
	delete root;
	return;
}



int main()
{
	cin >> str_pre >> str_mid;
	Node * root = CreateTree(0, str_pre.length() - 1, 0, str_mid.length() - 1);
	TravelPost(root);
	DestroyTree(root);
	return 0;
}