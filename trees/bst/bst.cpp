#include "pch.h"
#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
class Bst
{
	struct node* root;
public:
	Bst()
	{
		root = NULL;
	}
	struct node* insert(struct node *curr, int ele)
	{
		if (root == NULL)
		{
			struct node *temp = new node;
			temp->data = ele;
			temp->left = NULL;
			temp->right = NULL;
			cout << "inserted" << endl;
			root = temp;
			return temp;
		}
		if (curr == NULL)
		{
			struct node *temp = new node;
			temp->data = ele;
			temp->left = NULL;
			temp->right = NULL;
			cout << "inserted" << endl;
			curr = temp;
			cout << root->data << endl;
			return temp;
		}
		if (ele < curr->data)
		{
			cout << "moving left " << ele << endl;
			curr->left = insert(curr->left, ele);

		}
		else if(ele > curr->data)
		{
			cout << "moving right " << ele << endl;
			curr->right = insert(curr->right, ele);
		}
	}
	void inorder(struct node* curr)
	{
		if (curr != NULL)
		{
			inorder(curr->left);
			cout << curr->data;
			inorder(curr->right);
		}
	}
	void postorder(struct node *curr)
	{

	}
	void preorder(struct node *curr)
	{

	}
	struct node* getroot()
	{
		if (root == NULL)
		{
			cout << "NULL" << endl;
		}
		return root;
	}
};
int main()
{
	class Bst bst; bst.insert(bst.getroot(), 9); bst.insert(bst.getroot(), 8); bst.insert(bst.getroot(), 17); bst.insert(bst.getroot(), 20);
	bst.inorder(bst.getroot());
}