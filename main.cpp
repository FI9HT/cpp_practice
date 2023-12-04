#include <stdio.h>
#include <unistd.h>

#include <iostream>
#include <vector>
#include <functional>

#include "algorithm/sort.h"
#include "data_structure/tree/binary_tree.h"

using namespace std;

// vector<int> v {9, 9, 9, 8, 8, 8, 7, 7, 8, 7, 6, 8, 7, 5, 5, 5, 9, 4, 3, 3, 9, 2, 0, 1, 0};

class C1 {
public:
    int c1Num_;
};
class C2 {
public:
    C2() {}
    C2(C2 *c2) : c2Num_(c2->c2Num_), c2NumM_(c2->c2NumM_) { 
        cout << "C2 copy" << endl;
    }
    int c2Num_;
    int c2NumM_;
};

int main()
{
    // TreeNode<int> *node = BinaryTree<int>::createSimpleTree();
    // BinaryTree<int> *bt = new BinaryTree<int>();
    // bt->preOrderTraversalIteration(node);
    // bt->midOrderTraversalIteration(node);
    // bt->postOrderTraversalIteration(node);
    
    C1 *c1 = new C1();
    C2 c2 = static_cast<C2*>(c1);


    return 0;
}