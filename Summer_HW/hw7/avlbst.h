#ifndef RBBST_H
#define RBBST_H

#include <iostream>
#include <exception>
#include <cstdlib>
#include <algorithm>
#include "bst.h"

struct KeyError { };

/**
* A special kind of node for an AVL tree, which adds the balance as a data member, plus
* other additional helper functions. You do NOT need to implement any functionality or
* add additional data members or helper functions.
*/
template <typename Key, typename Value>
class AVLNode : public Node<Key, Value>
{
public:
    // Constructor/destructor.
    AVLNode(const Key& key, const Value& value, AVLNode<Key, Value>* parent);
    virtual ~AVLNode();

    // Getter/setter for the node's height.
    char getBalance () const;
    void setBalance (char balance);
    void updateBalance(char diff);

    // Getters for parent, left, and right. These need to be redefined since they
    // return pointers to AVLNodes - not plain Nodes. See the Node class in bst.h
    // for more information.
    virtual AVLNode<Key, Value>* getParent() const override;
    virtual AVLNode<Key, Value>* getLeft() const override;
    virtual AVLNode<Key, Value>* getRight() const override;

protected:
    char balance_;
};

/*
  -------------------------------------------------
  Begin implementations for the AVLNode class.
  -------------------------------------------------
*/

/**
* An explicit constructor to initialize the elements by calling the base class constructor and setting
* the color to red since every new node will be red when it is first inserted.
*/
template<class Key, class Value>
AVLNode<Key, Value>::AVLNode(const Key& key, const Value& value, AVLNode<Key, Value> *parent) :
    Node<Key, Value>(key, value, parent), balance_(0)
{

}

/**
* A destructor which does nothing.
*/
template<class Key, class Value>
AVLNode<Key, Value>::~AVLNode()
{

}

/**
* A getter for the balance of a AVLNode.
*/
template<class Key, class Value>
char AVLNode<Key, Value>::getBalance() const
{
    return balance_;
}

/**
* A setter for the balance of a AVLNode.
*/
template<class Key, class Value>
void AVLNode<Key, Value>::setBalance(char balance)
{
    balance_ = balance;
}

/**
* Adds diff to the balance of a AVLNode.
*/
template<class Key, class Value>
void AVLNode<Key, Value>::updateBalance(char diff)
{
    balance_ += diff;
}

/**
* An overridden function for getting the parent since a static_cast is necessary to make sure
* that our node is a AVLNode.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getParent() const
{
    return static_cast<AVLNode<Key, Value>*>(this->parent_);
}

/**
* Overridden for the same reasons as above.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getLeft() const
{
    return static_cast<AVLNode<Key, Value>*>(this->left_);
}

/**
* Overridden for the same reasons as above.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getRight() const
{
    return static_cast<AVLNode<Key, Value>*>(this->right_);
}


/*
  -----------------------------------------------
  End implementations for the AVLNode class.
  -----------------------------------------------
*/


template <class Key, class Value>
class AVLTree : public BinarySearchTree<Key, Value>
{
public:
    virtual void insert (const std::pair<const Key, Value> &new_item); // TODO
    virtual void remove(const Key& key);  // TODO
protected:
    virtual void nodeSwap( AVLNode<Key,Value>* n1, AVLNode<Key,Value>* n2);

    // Add helper functions here
    void turnLeft(AVLNode<Key, Value>* node);
    void turnRight(AVLNode<Key, Value>* node);
    void insertBalanceHelper(AVLNode<Key, Value>* p, AVLNode<Key, Value>* c);
    void removeBalanceHelper(AVLNode<Key, Value>* n, int diff);
    AVLNode<Key, Value>* successor(AVLNode<Key, Value>* node);
};

template<class Key, class Value>
void AVLTree<Key, Value>::insert (const std::pair<const Key, Value> &new_item)
{
    // TODO
    // create the new node to be inserted and set initial data members
    AVLNode<Key, Value>* insertNode = new AVLNode<Key, Value>(new_item.first, new_item.second, nullptr);
    insertNode->setBalance(0);   
    insertNode->setRight(nullptr);
    insertNode->setLeft(nullptr);

    // when the avl tree lookin empty
    if(this->root_ == nullptr) 
    {
        this->root_ = insertNode;
        return;
    }

    // set a parent node and a current root node
    AVLNode<Key,Value>* p = nullptr;
    AVLNode<Key,Value>* n = static_cast<AVLNode<Key, Value>*>(this->root_);

    // no conditionals to check; just run until a break
    while(true)
    {
    	// set parent to the new node
        p = n;

        if(new_item.first == p->getKey())
        {
            p->setValue(new_item.second);
            return;
        }
        // when the new item goes left
        else if(new_item.first < p->getKey()) 
        {
            if(p->getLeft() == nullptr) 
            {
                p->setLeft(insertNode);
                insertNode->setParent(p);
                break;
            }

            n = p->getLeft();
        }
        // when the new item goes right 
        else 
        {
            if(p->getRight() == nullptr) 
            {
                p->setRight(insertNode);
                insertNode->setParent(p);
                break;
            }

            n = p->getRight();
        }
    }

    // check balance here
    if(p->getBalance() == -1 || p->getBalance() == 1) 
    {
        p->setBalance(0);
        return;
    }
    else 
    {
    	// for when balance is off. call helper at end to rebalance everything
        if(p->getLeft() == insertNode)
        {
            p->setBalance(-1);
        }
        else 
        {
            p->setBalance(1);
        }

        insertBalanceHelper(p, insertNode);
    }
}

template<class Key, class Value>
void AVLTree<Key, Value>::remove(const Key& key)
{
    // TODO
    // p = parent, c = child
    
	AVLNode<Key, Value>* removeNode = static_cast<AVLNode<Key,Value>*>(this->internalFind(key));

    if(removeNode == nullptr) 
    {
        return;  
    }

    if(removeNode->getLeft() != nullptr && removeNode->getRight() != nullptr) 
    {
        AVLNode<Key, Value>* next = static_cast<AVLNode<Key,Value>*>(this->predecessor(removeNode));
        nodeSwap(removeNode, next);
    }

    AVLNode<Key, Value>* c = removeNode->getLeft();

    if(removeNode->getRight() != nullptr) 
    {
        c = removeNode->getRight();
    }

    AVLNode<Key, Value>* p = removeNode->getParent();

    if(c != nullptr)
    {
        c->setParent(p);
    }

    int diff;

    if(p == nullptr) 
    {
        this->root_ = c;
    } 
    else 
    {
        if(removeNode == p->getLeft()) 
        {
            p->setLeft(c);
            diff = 1;
        } 
        else 
        {
            p->setRight(c);
            diff = -1;
        }
    }

    delete removeNode;

    removeBalanceHelper(p, diff);
}

template<class Key, class Value>
void AVLTree<Key, Value>::nodeSwap( AVLNode<Key,Value>* n1, AVLNode<Key,Value>* n2)
{
    BinarySearchTree<Key, Value>::nodeSwap(n1, n2);
    char tempB = n1->getBalance();
    n1->setBalance(n2->getBalance());
    n2->setBalance(tempB);
}

// helper function to turn left when needed
template<class Key, class Value>
void AVLTree<Key, Value>::turnLeft(AVLNode<Key, Value>* node)
{
	AVLNode<Key, Value>* rParent = node->getParent();
	AVLNode<Key, Value>* temp = node->getRight();
	temp->setParent(rParent);

	if(node->getParent() == nullptr)
	{
		this->root_ = node->getRight();
	}
	else if(rParent->getLeft() == node)
	{
		rParent->setLeft(temp);
	}
	else
	{
		rParent->setRight(temp);
	}

	AVLNode<Key, Value>* temp1 = temp->getLeft();

    temp->setLeft(node);

    node->setParent(temp);
    node->setRight(temp1);

    if (temp1 != nullptr)
    {
        temp1->setParent(node);
    }
}

// helper function to turn right when needed
template<class Key, class Value>
void AVLTree<Key, Value>::turnRight(AVLNode<Key, Value>* node)
{
	AVLNode<Key, Value>* rParent = node->getParent();
	AVLNode<Key, Value>* temp = node->getLeft();
	temp->setParent(rParent);

	if(node->getParent() == nullptr)
	{
		this->root_ = node->getLeft();
	}
	else if(rParent->getLeft() == node)
	{
		rParent->setLeft(temp);
	}
	else
	{
		rParent->setRight(temp);
	}

	AVLNode<Key, Value>* temp1 = temp->getRight();

    temp->setRight(node);

    node->setParent(temp);
    node->setLeft(temp1);

    if (temp1 != nullptr)
    {
        temp1->setParent(node);
    }
}

template<class Key, class Value>
void AVLTree<Key, Value>::insertBalanceHelper(AVLNode<Key, Value>* p, AVLNode<Key, Value>* c)
{
	// grandparent node
	AVLNode<Key, Value> *g = p->getParent();

	// check parent and grandparent
	if(p == nullptr || g == nullptr) 
	{
        return;
    }

    if(p == g->getLeft()) 
    {
    	g->setBalance(g->getBalance() - 1);

        if(g->getBalance() == 0) 
        {
            return; 
        }

        if(g->getBalance() == -1) 
        {
            insertBalanceHelper(g, p);
            return;
        }

        if(c == p->getLeft()) 
        {
            turnRight(g);
            p->setBalance(0);
            g->setBalance(0);
        } 
        else 
        {
            turnLeft(p);
            turnRight(g);

            if(c->getBalance() == -1) 
            {
                p->setBalance(0);
                g->setBalance(1);

            } 
            else if(c->getBalance() == 0) 
            {
                p->setBalance(0);
                g->setBalance(0);
            } 
            else 
            {
                p->setBalance(-1);
                g->setBalance(0);
            }
            c->setBalance(0);
        }
    } 
    else 
    { 
        g->setBalance(g->getBalance() + 1);

        if(g->getBalance() == 0) 
        {
            return; 
        }

        if(g->getBalance() == 1) 
        {
            insertBalanceHelper(g, p);
            return;
        }

        if(c == p->getRight()) 
        {
        	// zig zig
            turnLeft(g);
            p->setBalance(0);
            g->setBalance(0);
        } 
        else 
        { 
        	// zig zag
            turnRight(p);
            turnLeft(g);

            if(c->getBalance() == 1) 
            {
                p->setBalance(0);
                g->setBalance(-1);
            } 
            else if(c->getBalance() == 0) 
            {
                p->setBalance(0);
                g->setBalance(0);
            } 
            else 
            {
                p->setBalance(1);
                g->setBalance(0);
            }
            c->setBalance(0);
        }
    }
}

template<class Key, class Value>
void AVLTree<Key, Value>::removeBalanceHelper(AVLNode<Key, Value>* n, int diff)
{
	if(n == nullptr)
	{
        return;
    }

    AVLNode<Key, Value>* p = n->getParent();
    AVLNode<Key, Value>* c;

    int diff_ = -1;

    if(p != nullptr && n == p->getLeft())
    {
        diff_ = 1;
    }

    if(n->getBalance() + diff == -2)
    {
        c = n->getLeft();
        if(c->getBalance() == -1 || c->getBalance() == 0)
        {
        	// zig zig

            turnRight(n);

            if(c->getBalance() == -1)
            {
                n->setBalance(0);
                c->setBalance(0);
                removeBalanceHelper(p, diff_);
            }

            if(c->getBalance() == 0)
            {
                n->setBalance(-1);
                c->setBalance(1);
                return;
            }
        }
        else
        {
        	// zig zag

            AVLNode<Key, Value>* g = c->getRight();
            turnLeft(c);
            turnRight(n);

            if(g->getBalance() == 1)
            {
                n->setBalance(0);
                c->setBalance(-1);
                g->setBalance(0);
            }

            if(g->getBalance() == 0)
            {
                n->setBalance(0);
                c->setBalance(0);
                g->setBalance(0);
            }

            if(g->getBalance() == 1)
            {
                n->setBalance(1);
                c->setBalance(0);
                g->setBalance(0);
            }
            removeBalanceHelper(p, diff_);
        }
    }
    else if(n->getBalance() == 0)
    {
        n->setBalance(n->getBalance() + diff);
        return;
    }
    else
    {
        n->setBalance(0);
        removeBalanceHelper(p, diff_);
    }

    if(n->getBalance() + diff == 2)
    {
        //zig zig

        c = n->getRight();

        if(c->getBalance() == 1 || c->getBalance() == 0)
        {
            turnLeft(n);
            if(c->getBalance() == 1)
            {
                n->setBalance(0);
                c->setBalance(0);
                removeBalanceHelper(p, diff_);
            }

            if(c->getBalance() == 0)
            {
                n->setBalance(1);
                c->setBalance(-1);
                return;
            }
        }
        else
        {
        	//zig zag

            AVLNode<Key, Value>* g = c->getLeft();
            turnRight(c);
            turnLeft(n);    

            if (g->getBalance() == -1)
            {
                n->setBalance(0);
                c->setBalance(1);
                g->setBalance(0);
            }

            if(g->getBalance() == 0)
            {
                n->setBalance(0);
                c->setBalance(0);
                g->setBalance(0);
            }

            if (g->getBalance() == -1)
            {
                n->setBalance(-1);
                c->setBalance(0);
                g->setBalance(0);
            }

            removeBalanceHelper(p, diff_);
        }
    }
    else if (n->getBalance() == 0)
    {
        n->setBalance(n->getBalance() + diff);
        return;
    }
    else
    {
        n->setBalance(0);
        removeBalanceHelper(p, diff_);
    }
}

#endif
