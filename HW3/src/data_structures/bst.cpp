#include <bst.hpp>
#include <stack.hpp>

// Operator Overloading

bool operator<( const std::pair<int, int>& lhs, const std::pair<int, int>& rhs ) {
    return (lhs.first < rhs.first) || (lhs.first == rhs.first && lhs.second < rhs.second);
}

bool operator>( const std::pair<int, int>& lhs, const std::pair<int, int>& rhs ) {
    return (lhs.first > rhs.first) || (lhs.first == rhs.first && lhs.second > rhs.second);
}

bool operator==( const std::pair<int, int>& lhs, const std::pair<int, int>& rhs ) {
    return (lhs.first == rhs.first && lhs.second == rhs.second);
}


template<class T>
BSTNode<T>::BSTNode() {
    this->left = this->right = NULL;
    this->height = 0;
}

template<class T>
BSTNode<T>::BSTNode(T key, int height, BSTNode *left, BSTNode *right) {
    this->key = key;
    this->height = height;
    this->left = left;
    this->right = right;
}

template<class T>
BSTNode<T>::~BSTNode() {
    this->left = this->right = NULL;
}


template<class T>
void BST<T>::clear(BSTNode<T> *node) {
    if (node == NULL)
        return;
    this->clear(node->left);
    this->clear(node->right);
    delete node;
}

template<class T>
BSTNode<T> *BST<T>::find(T key, BSTNode<T> *node) {
    if (node == NULL || node->key == key)
        return node;
    if (key < node->key)
        return this->find(key, node->left);
    else
        return this->find(key, node->right);
}

template<class T>
BSTNode<T> *BST<T>::findMaximum(BSTNode<T> *node) {
    if (node == NULL || node->right == NULL)
        return node;
    return this->findMaximum(node->right);
}

template<class T>
BSTNode<T> *BST<T>::insert(T key, BSTNode<T> *node) {
    if (node == NULL)
        return new BSTNode<T>(key, 0, NULL, NULL);
    else if (key < node->key) 
        node->left = this->insert(key, node->left);
    else 
        node->right = this->insert(key, node->right);
    return node;
}

template<class T>
BSTNode<T> *BST<T>::remove(T key, BSTNode<T> *node) {
    if (node->key == key) {
        if (node->left == NULL && node->right == NULL) {
            delete node;
            return NULL;
        } else if (node->left == NULL && node->right != NULL) {
            BSTNode<T> *p = node->right;
            delete node;
            return p;
        } else if (node->left != NULL && node->right == NULL) {
            BSTNode<T> *p = node->left;
            delete node;
            return p;
        } else {
            BSTNode<T> *p = this->findMaximum(node->left);
            node->key = p->key;
            node->left = this->remove(p->key, node->left);
        }
    } else if (key < node->key)
        node->left = this->remove(key, node->left);
    else
        node->right = this->remove(key, node->right);
    return node;
}


template<class T>
BST<T>::BST() {
    this->root = NULL;
}

template<class T>
BST<T>::~BST() {
    this->clear(this->root);
 }


template<class T>
BSTNode<T> *BST<T>::find(T key) {
    return this->find(key, this->root);
}

template<class T>
BSTNode<T> *BST<T>::findMaximum() {
    return this->findMaximum(this->root);
}


template<class T>
BSTNode<T> *BST<T>::insert(T key) {
    return this->root = this->insert(key, this->root);
}

template<class T>
BSTNode<T> *BST<T>::remove(T key) {
    return this->root = this->remove(key, this->root);
}

template class BSTNode<int>;
template class BST<int>;

template class BSTNode<std::pair<int, int> >;
template class BST<std::pair<int, int> >;
