// class Tree (Binary Trees)
// process nodes in Pre/In/Post order
//-----------------------------------
#include <iostream>
using namespace std;
template <class T> class Tree
{
protected:
	//--------------------------------------------------------
	// inner class Node
	// a single Node from a binary tree
	//--------------------------------------------------------
	class Node
	{
	public:
		Node* left;
		Node* right;
		T value;
		Node(T val)
			: value(val), left(0), right(0) {}
		Node(T val, Node* l, Node* r)
			: value(val), left(l), right(r) {}
	}; //end of Node class
	Node* root;

public:
	Tree() { root = 0; } // initialize tree
	~Tree();//dedstructor
	bool isEmpty() const;//says if tree is emoty
	void clear() { clear(root); root = 0; }//maatefet
	void preOrder() { preOrder(root); }//maatefet
	void inOrder() { inOrder(root); }//maatefet
	void postOrder() { postOrder(root); }//maatefet
	virtual void process(T val) { cout << val << " "; }
	virtual void add(T val) = 0;//pure virtual
	virtual bool search(T val) = 0;//pure virualitty
	virtual void remove(T val) = 0;//as above
	void reflect();//maatefet
	int onlyLeftSon();//maatefet
	int height();//maatefet
	int leaves();//maatefet
private:
	void clear(Node* current);//clear the trees values
	void preOrder(Node* current);//the pre order function 
	void inOrder(Node* current);//inorder
	void postOrder(Node* current);//postorder
	int leaves(Node* shoresh);//return the num of the leaves in the tree
	int height(Node* shoresh);//return the trees height
	int onlyLeftSon(Node* shoresh);//return the number of only left sons in the tree
	void reflect(Node* shoresh);//reflects the tree
};

//		 #include "Tree.h"
// class Tree implementation
//----------------------------------------------------------
template <class T>
Tree<T>::~Tree() // deallocate tree
{
	if (root != 0)
		clear(root);
}
template<class T>
void Tree<T>::reflect()
{
	reflect(this->root);
}
template<class T>
int Tree<T>::onlyLeftSon()
{
	return onlyLeftSon(this->root);
}
template<class T>
int Tree<T>::height()
{
	return height(this->root);
}
template<class T>
int Tree<T>::leaves()
{
	return leaves(this->root);
}
template <class T>
void Tree<T>::clear(Node* current)
{
	if (current)
	{ // Release memory associated with children
		if (current->left)
			clear(current->left);
		if (current->right)
			clear(current->right);
		delete current;
	}
}
template <class T>
bool Tree<T>::isEmpty() const
{
	return root == 0;
}

// preOrder processing of tree rooted at current
template <class T>
void Tree<T>::preOrder(Node* current)
{ // visit Node, left child, right child
	if (current)
	{ // process current Node
		process(current->value);
		// then visit children
		preOrder(current->left);
		preOrder(current->right);
	}
}
// inOrder processing of tree rooted at current
template <class T>
void Tree<T>::inOrder(Node* current)
{ // visit left child, Node, right child
	if (current)
	{
		inOrder(current->left);
		process(current->value);
		inOrder(current->right);
	}
}
// postOrder processing of tree rooted at current
template <class T>
void Tree<T>::postOrder(Node* current)
{ // visit left child, right child, node
	if (current)
	{
		postOrder(current->left);
		postOrder(current->right);
		process(current->value);
	}
}

template<class T>
int Tree<T>::leaves(Node* shoresh)
{

	int sum = 0;
	if (!shoresh)
		return 0;
	if (!(shoresh->right && shoresh->left))
		return 1;
	if (shoresh->left)
		sum += leaves(shoresh->left);
	if (shoresh->right)
		sum += leaves(shoresh->right);
	return sum;
}

template<class T>
int Tree<T>::height(Node* shoresh)
{
	int r = 0, l = 0;
	if (!shoresh)
		return 0;
	r = 1 + height(shoresh->right);
	l = 1 + height(shoresh->left);
	if (r >= l)
		return r;
	else return l;
}

template<class T>
int Tree<T>::onlyLeftSon(Node* shoresh)
{
	if (!shoresh)
		return 0;
	int mone = 0;
	if (shoresh->left && !shoresh->right)
		mone += 1;
	mone += onlyLeftSon(shoresh->right) + onlyLeftSon(shoresh->left);
	return mone;
}

template<class T>
void Tree<T>::reflect(Node* shoresh)
{
	if (!shoresh->right && !shoresh->left)
		return;
	if (shoresh->right && shoresh->left)
	{
		Node* temp = shoresh->right;
		shoresh->right = shoresh->left;
		shoresh->left = temp;
		reflect(shoresh->right);
		return reflect(shoresh->left);
	}
	if (shoresh->right)
	{
		shoresh->left = shoresh->right;
		shoresh->right = 0;
		return reflect(shoresh->left);

	}
	if (shoresh->left)
	{
		shoresh->right = shoresh->left;
		shoresh->left = 0;
		return reflect(shoresh->right);
	}
}