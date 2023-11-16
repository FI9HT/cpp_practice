#include <stdio.h>
#include <unistd.h>

#include <iostream>
#include <vector>
#include <functional>

#include "algorithm/sort.h"
#include "data_structure/tree/binary_tree.h"

using namespace std;

// vector<int> v {9, 9, 9, 8, 8, 8, 7, 7, 8, 7, 6, 8, 7, 5, 5, 5, 9, 4, 3, 3, 9, 2, 0, 1, 0};

int main()
{
    TreeNode<int> *node = BinaryTree<int>::createSimpleTree();
    BinaryTree<int> *bt = new BinaryTree<int>();
    bt->preOrderTraversalIteration(node);
    bt->midOrderTraversalIteration(node);
    bt->postOrderTraversalIteration(node);
    
    return 0;
}