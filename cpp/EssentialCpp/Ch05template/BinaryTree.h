#pragma once

// forward declaration
template <typename Type>
class BinaryTree;

//----------------------------------------------------------------------
// class BTnode
template <typename valType>
class BTnode
{
	friend class BinaryTree<valType>;
public:
	BTnode(const valType val);

	void insert_value(const valType& val);
	void remove_value()
private:

	valType _val;
	int _cnt; // insert times
	BTnode * _lchild;  // inside class template, not need type parameter
	BTnode * _rchild;  
};

template <typename valType>
BTnode<valType>::BTnode(const valType val)
	: _val(val)
{
	_cnt = 1;
	_lchild = 0;
	_rchild = 0;
}

template <typename valType>
void BTnode<valType>::insert_value(const valType& val)
{
	if(val == _val)
	{
		_cnt++;
		return;
	}


	if(val < _val)  // left
	{
		if(!_lchild)
		{
			_lchild = new BTnode(val);
		}
		else
		{
			_lchild->insert_value(val);
		}
	}
	else  // right
	{
		if(!_rchild)
		{
			_rchild = new BTnode(val);
		}
		else
		{
			_rchild->insert_value(val);
		}
	}
}


//------------------------------------------------------------------------
//  class BinaryTree 

template <typename elemType>
class BinaryTree
{
public:
	BinaryTree();
	BinaryTree(const BinaryTree&);  //copy constructor
	BinaryTree& operator=(const BinaryTree&);  // copy assignment operator
	~BinaryTree();


	bool empty() { return _root == 0; }
	void clear();

	void insert(const elemType &elem);
	void remove(const elemType &elem);


private:
	BTnode<elemType> *_root;   // outside BTnode , must use type parameter

	// copy source tree to target
	void copy(BTnode<elemType> * tar, BTnode<elemType> * src);
};



// default constructor
template <typename elemType>
BinaryTree<elemType>::BinaryTree()
	: _root(0)
{
}

// copy constructor
template <typename elemType>
BinaryTree<elemType>::BinaryTree(const BinaryTree& rhs)
{
	copy(_root, rhs._root);
}


//copy assignment operator
template <typename elemType>
BinaryTree<elemType>& BinaryTree<elemType>::operator=(const BinaryTree& rhs)
{
	if(this!= &rhs)
	{
		clear();
		copy( _root, rhs._root);
	}
	return *this;
}

//destructor

template <typename elemType>
BinaryTree<elemType>::~BinaryTree()
{
	clear();
}


template <typename elemType>
void BinaryTree<elemType>::insert(const elemType& elem)
{
	if(!_root)
	{
		_root = new BTnode<elemType>(elem);
	}
	else
	{
		_root->insert_value(elem);
	}
}

template <typename elemType>
void BinaryTree<elemType>::remove(const elemType& elem)
{
	if(_root)
	{
		if(_root->val == elem)
		{
			remove_root();
		}
		else
		{
			_root->remove_value(elem, _root);
		}
	}
}

