#ifndef TREE
#define TREE
 
using namespace std;

template <typename T>
class Tree
{
private:
    int dato;
    struct Tree* Left;
    struct Tree* Right;
public:
    Tree(int val);
    bool Addchild(int val1, int val2);
    bool DeleteChild();
    T Search(int value, T);
    int ReadValue();
};
 
#endif