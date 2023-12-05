#include <stdio.h>
#include <unistd.h>

#include <iostream>
#include <vector>
#include <functional>
#include <memory>

#include "algorithm/sort.h"
#include "data_structure/tree/binary_tree.h"
#include "linux/SharedPtr.h"

using namespace std;

// vector<int> v {9, 9, 9, 8, 8, 8, 7, 7, 8, 7, 6, 8, 7, 5, 5, 5, 9, 4, 3, 3, 9, 2, 0, 1, 0};

class C1 {
public:
    C1() { 
        cout << "c1 cnst" << endl; 
    }
    ~C1() {
        cout << "c1 dcnst" << endl;
    }
    void hello() {
        cout << "c1 hello" << endl;
    }
    int c1Num_;
};

int main()
{
    // TreeNode<int> *node = BinaryTree<int>::createSimpleTree();
    // BinaryTree<int> *bt = new BinaryTree<int>();
    // bt->preOrderTraversalIteration(node);
    // bt->midOrderTraversalIteration(node);
    // bt->postOrderTraversalIteration(node);
    
    SharedPtr<C1> p1;

    SharedPtr<C1> p2 = move(p1);
    p2 = p1;
    p2->hello();
    p1->hello();

    

    return 0;
}












