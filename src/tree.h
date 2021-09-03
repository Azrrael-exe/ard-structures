#ifndef TREE
#define TREE
 
using namespace std;

template <typename T>
class Tree
{
private:
    T dato;
    struct Tree* Left;
    struct Tree* Right;
    char id;
public:
    Tree(T val, char Id='root');
    bool Addchild(T val1, T val2);
    bool DeleteChild();
    //T Search(T root,char Id);
    T ReadValue();
};
 
#endif