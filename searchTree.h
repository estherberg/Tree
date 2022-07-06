#include "Tree.h"
template <class T>
class SearchTree : public Tree<T>
{
public:
	// protocol for search trees
	void add(T value);//maatefet
	bool search(T value)
	{
		return search(this->root, value);//maatefet
	}
	typename Tree<T>::Node* papa(T val)
	{
		return papa(this->root, val);
	}
	int level(T val)
	{
		if (!search(this->root, val))
			return -1;
		return level(this->root, val);//maatefet
	}
	typename Tree<T>::Node* processesor()
	{
		return processesor(this->root);
	}


	void remove(T value)
	{
		remove(this->root, value);
	}
private:

	typename Tree<T>::Node* papa(typename Tree<T> ::Node* shoresh, T val);
	typename Tree<T>::Node* search1(T val)
	{
		return search1(this->root, val);//return the node with val
	}
	typename Tree<T>::Node* search1(typename Tree<T>::Node* root, T val);
	void add(typename Tree<T>::Node* current, T val);//adds a value to the tree
	bool search(typename Tree<T>::Node* current, T val);//says if a value was found o not
	void remove(typename Tree<T>::Node* shoresh, T val);//remove a value from the tree
	int level(typename Tree<T>::Node* shoresh, T val);//return the tree level
	typename Tree<T> ::Node* processesor(typename Tree<T> ::Node* shoresh);//give me the okev private cause only used from a function and dosent work 4 all cases only for this case
};

//		 #include "SearchTree.h"
template <class T>
void SearchTree<T>::add(T val)
{
	// add value to binary search tree
	if (!this->root)
	{
		this->root = new typename Tree<T>::Node(val);
		return;
	}
	add(this->root, val);
}
template <class T>
bool SearchTree<T>::search(typename Tree<T> ::Node* current, T val)
{
	// see if argument value occurs in tree
	if (!current)
		return false; // not found
	if (current->value == val)
		return true;
	if (current->value < val)
		return search(current->right, val);
	else
		return search(current->left, val);
}
template <class T>
void SearchTree<T>::add(typename Tree<T> ::Node* current, T val)
{
	if (current->value <= val)
		// add to right subtree
		if (!current->right)
		{
			current->right = new typename Tree<T>::Node(val);
			return;
		}
		else add(current->right, val);
	else
		// add to left subtree
		if (!current->left)
		{
			current->left = new typename Tree<T>::Node(val);
			return;
		}
		else add(current->left, val);
}
template <class T>
void SearchTree<T>::remove(typename Tree<T> ::Node* shoresh, T val)//reomve value val from a tree
{
	if (!this->search(val)) return;

	//the option of root with 2 sons will be cared in the next code lines...
	typename Tree<T> ::Node* hul = search1(val);
	typename Tree<T> ::Node* papas = papa(val);

	//first case if im shoresh
	if (papas == NULL)
	{
		if (!hul->right && !hul->left)//if the only one
		{
			delete hul;
			shoresh = NULL;
			return;
		}
		if (hul->right && !hul->left)//if  only has a right son
		{
			shoresh = hul->right;
			delete hul;
			return;
		}
		if (hul->left && !hul->right)//if i only have a left son
		{
			shoresh = hul->left;
			delete hul;
			return;
		}

	}
	if (!hul->right && !hul->left)//if have no kids
	{
		if (papas->right == hul)
			papas->right = NULL;
		else
			papas->left = NULL;
		delete hul;
	}
	typename Tree<T> ::Node* proc = processesor(hul);//processor
	typename Tree<T> ::Node* papi = papa(proc->value);//processors father
														//if have two kids
	if (hul->right && hul->left)
	{

		//if proc has no sons
		if (!proc->right && !proc->left)
		{
			//if proc is a right son
			if (papi->right == proc)
			{
				papi->right = NULL;
			}
			else papi->left = NULL;//if proc is a left son
			T vi = proc->value;
			delete proc;
			hul->value = vi;
			return;
		}
		//if proc has a right son
		if (proc->right)
		{
			T vi = proc->value;
			if (papi->right == proc)//if proc is a right son
				papi->right = proc->right;
			else//is a left son
				papi->left = proc->right;
			delete proc;
			hul->value = vi;
			return;
		}
	}
	//if only have one son
	if (hul->left && papas->left == hul)
	{
		papas->left = hul->left;
		delete hul;
		return;
	}
	if (hul->left && papas->right == hul)
	{
		papas->right = hul->left;
		delete hul;
		return;
	}
	if (hul->right && papas->right == hul)
	{
		papas->right = hul->right;
		delete hul;
		return;
	}
	if (hul->right && papas->left == hul)
	{
		papas->left = hul->right;
		delete hul;
		return;
	}


}
template<class T>
typename Tree<T>::Node* SearchTree<T>::papa(typename Tree<T> ::Node* shoresh, T val)
{
	if (!shoresh || shoresh->value == val)
		return NULL;
	if (shoresh->right && shoresh->right->value == val || shoresh->left && shoresh->left->value == val)
		return shoresh;
	if (shoresh->value > val)
		return papa(shoresh->left, val);
	return papa(shoresh->right, val);
}
template<class T>
int SearchTree<T>::level(typename Tree<T>::Node* shoresh, T val)
{
	if (!shoresh)
		return -1;
	if (shoresh->right->value == val || shoresh->left->value == val)
		return 1;
	if (shoresh->value > val)
		return (level(shoresh->left, val) + 1);
	else return (level(shoresh->right, val) + 1);
}

template<class T>
typename Tree<T>::Node* SearchTree<T>::processesor(typename Tree<T> ::Node* shoresh)
{
	if (shoresh->right)
	{
		typename Tree<T> ::Node* temp = shoresh->right;
		while (temp->left != NULL)
		{
			temp = temp->left;
		}
		return temp;
	}
	return 0;
}

template<class T>
typename Tree<T>::Node* SearchTree<T>::search1(typename Tree<T>::Node* root, T val)
{
	if (!root)
		return NULL;
	if (root->value == val)
		return root;
	if (root->value > val)
		return search1(root->left, val);
	return search1(root->right, val);
}