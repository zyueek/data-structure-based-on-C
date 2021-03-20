#include<iostream>
#include<cmath>
using namespace std;
class initree{
private:
	struct treenode{
		treenode *left;
		treenode *right;
		int value;
		treenode(int value1, treenode *right1 = nullptr,treenode *left1 = nullptr)
		{
			value = value1;
			left = left1;
			right = right1;
		}
	};
	treenode *root;
	void insert(treenode *&, int);
	void remove(treenode *&, int);
	void order(treenode *&);
	void makedeletion(treenode *&);
public:
	initree()
	{
		root = nullptr;
	}
	void insert(int num)
	{
		insert(root, num);
	}
	void remove(int num)
	{
		remove(root,num);
	}
	void order()
	{
		order(root);
	}
	bool search(int);
	void makedeletion()
	{
		makedeletion(root);
	}
};
void initree::insert(treenode *&tree, int num)
{
		if (!tree)
		{
			tree = new treenode(num);
			return;
		}
		else if (num < tree->value)
			insert(tree->left, num);
		else
			insert(tree->right, num);
}
void initree::remove(treenode *&tree, int num)
{
	if (num < tree->value)
		remove(tree->left, num);
	else if (num>tree->value)
		remove(tree->right, num);
	else
		makedeletion(tree);
}
void initree::makedeletion(treenode *&tree)
{
	treenode *dnode = tree;
	treenode *point;
	if (tree->right == nullptr)
	{
		tree = tree->right;
	}
	else if (tree->left == nullptr)
	{
		tree = tree->left;
	}
	else 
	{
		point = tree->right;
		while (point->left != nullptr)
			point = point->left;
		point->left = tree->left;
		tree = tree->right;
	}
	delete dnode;
}
bool initree::search(int num)
{
	treenode *tree = root;
	while (tree)
	{
		if (tree->value == num)
			return true;
		else if (num > tree->value)
			tree = tree->right;
		else
			tree = tree->right;
	}
	return false;
}
void initree::order(treenode *&tree)
{
	if (tree)
	{
		cout << tree->value << " ";
		order(tree->left);
		order(tree->right);
	}
}
int main()
{
	initree tree;
	tree.insert(4);
	tree.insert(1);
	tree.insert(2);
	tree.insert(5);
	tree.remove(2);
	tree.order();
	return 0;
}
