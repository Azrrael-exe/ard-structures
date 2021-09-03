#include "tree.h"
#include <stdlib.h>
#include <string.h>

template <typename T>
Tree<T>::Tree(T val, char Id='root'){
    this->dato = val;
    this->id = Id;
    this->Left = NULL;
    this->Right = NULL;
}
template <typename T>
bool Tree<T>::Addchild(T val1, T val2) {
    if(this->Left->dato == NULL && this->Right->dato == NULL){
        try{
            if(val1->dato != NULL && val2->dato != NULL){
                this->Left->dato = val1->dato
                this->Left->Left = val1->Left
                this->Left->Right = val1->Right
                this->Right->dato = val2->dato
                this->Right->Left = val2->Left
                this->Right->Right = val2->Right
                return true;
            } else {
                return false;
            }
        }
        catch(){
            this->Left =  new Tree(val1,str.append(this->id,'L');
            this->Right = new Tree(val2),str.append(this->id,'R');
            return true;
        }
    } else {
        return false;
    }
}    
template <typename T>
bool Tree<T>::DeleteChild() {
    if(this->Left->dato != NULL && this->Right->dato != NULL){
        this->Left = NULL;
        this->Right = NULL;
        return true;
    } else {
        return false;
    }
}
template <typename T>
T Tree<T>::ReadValue() {
    return this->dato;
}
//template <typename T>
//T Tree<T>::Search(T root, int Id){
  //  if (root == NULL || root->Id ==Id)
    //    return root;
    //if (root->Id < Id)
      //  return search(root->right, Id);
    //return search(root->left, Id);
//}
