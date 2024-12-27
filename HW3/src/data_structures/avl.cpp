#include <bst.hpp>

template<class T>
AVL<T>::AVL() {
    this->null = new BSTNode<T>();
    this->null->left = this->null->right = this->null;
    this->null->height = 0;
}

template<class T>
int AVL<T>::balanceFactor(BSTNode<T> *node) {
    return node->right->height - node->left->height;
}

template<class T>
void AVL<T>::update(BSTNode<T> *node) {
    if (node == this->null)
        return;
    node->height = std::max(node->left->height, node->right->height) + 1;
}

template<class T>
BSTNode<T>* AVL<T>::rotateRight(BSTNode<T> *node) {
    BSTNode<T> *q = node->left;
    node->left = q->right;
    q->right = node;
    this->update(node);
    this->update(q);
    return q;
}

template<class T>
BSTNode<T>* AVL<T>::rotateLeft(BSTNode<T> *node)
{
    BSTNode<T> *q = node->right;
    node->right = q->left;
    q->left = node;
    this->update(node);
    this->update(q);
    return q;
}

template<class T>
BSTNode<T> *AVL<T>::balance(BSTNode<T> *node) {
    this->update(node);
    if (this->balanceFactor(node) == 2) {
        if (this->balanceFactor(node->right) < 0)
            node->right = this->rotateRight(node->right);
        return this->rotateLeft(node);
    }
    if (this->balanceFactor(node) == -2)
    {
        if (this->balanceFactor(node->left) > 0)
            node->left = this->rotateLeft(node->left);
        return this->rotateRight(node);
    }
    return node;
}


template<class T>
BSTNode<T>* AVL<T>::insert(T key, BSTNode<T> *node) {
    if (node == this->null) { // key does not exists in a tree
        node = new BSTNode<T>(key, 1, this->null, this->null);
    } else if (key < node->key) { // Insert to the left
        node->left = this->insert(key, node->left);
    } else // Insert to the right
        node->right = this->insert(key, node->right);
    node = this->balance(node);
    return node;
}

template<class T>
BSTNode<T> *AVL<T>::insert(T key) {
    return BST<T>::insert(key);
}

template class AVL<int>;
