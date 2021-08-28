#include "tree.h"
#include <stdlib.h>
template <typename T>
Tree<T>::Tree(int val, int parent_id){
    this->dato = val;
    this->parent_id = parent_id;
    this->Left = NULL;
    this->Right = NULL;
}
template <typename T>
bool Tree<T>::Addchild(int val1, int val2) {
    if(this->Left->dato != NULL){
        this->Left =  new Tree(val1, this->id);
        this->Right = new Tree(val2, this->id);
        return true;
    } else {
        return false;
    }
}    
template <typename T>
bool Tree<T>::DeleteChild() {
    this->Left = NULL;
    this->Right = NULL;
    return true;
}
template <typename T>
int Tree<T>::ReadValue() {
    return this->dato;
}
template <typename T>
int Tree<T>::Search(T root, int Id){
    if (root == NULL || root->Id ==Id)
        return root;
    if (root->Id < Id)
        return search(root->right, Id);
    return search(root->left, Id);
}
