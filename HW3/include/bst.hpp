#include <iostream>

template<class T>
struct BSTNode {
    T key;
    int height;
    BSTNode *left;
    BSTNode *right;

    BSTNode();
    BSTNode(T key, int height = 0, BSTNode *left = NULL, BSTNode *right = NULL);  
    ~BSTNode();
};

template<class T>
class BST {
    protected:
        BSTNode<T> *root;
        
        void clear(BSTNode<T> *node);
        BSTNode<T> *find(T key, BSTNode<T> *node);
        BSTNode<T> *findMaximum(BSTNode<T> *node);
        BSTNode<T> *findMinimum(BSTNode<T> *node);
        BSTNode<T> *insert(T key, BSTNode<T> *node);
        BSTNode<T> *remove(T key, BSTNode<T> *node);
    public:
        BST();
        ~BST();
        BSTNode<T> *find(T key);
        BSTNode<T> *findMaximum();
        BSTNode<T> *insert(T key);
        BSTNode<T> *remove(T key);
};

#ifdef USE_AVL
template<class T>
class AVL: public BST<T> {
    private:
        BSTNode<T> *null;
        
        int balanceFactor(BSTNode<T> *node);
        void update(BSTNode<T> *node);
        BSTNode<T> *balance(BSTNode<T> *node);
        BSTNode<T> *rotateRight(BSTNode<T> *node);
        BSTNode<T> *rotateLeft(BSTNode<T> *node);
        
        BSTNode<T> *insert(T key, BSTNode<T> *node);
    public:
        AVL();
        BSTNode<T> *insert(T key);
};
#endif
