#ifndef PRACTICE_DATASTRUCTURE_TREE_BINARYTREE_H
#define PRACTICE_DATASTRUCTURE_TREE_BINARYTREE_H

#include <vector>
#include <iostream>

template <typename T>
struct TreeNode
{
    T data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : left(nullptr), right(nullptr) {}
    TreeNode(T data) : data(data), left(nullptr), right(nullptr) {}
    TreeNode(T data, TreeNode *left, TreeNode *right) : data(data), left(left), right(right) {}
};

template <typename T>
class BinaryTree {
public:
    BinaryTree() {}
    ~BinaryTree() {}
    // memory free is called by caller
    static TreeNode<T>* createSimpleTree() {
        TreeNode<int> *node4 = new TreeNode<int>(4);
        TreeNode<int> *node5 = new TreeNode<int>(5);
        TreeNode<int> *node6 = new TreeNode<int>(6);
        TreeNode<int> *node7 = new TreeNode<int>(7);

        TreeNode<int> *node2 = new TreeNode<int>(2, node4, node5);
        TreeNode<int> *node3 = new TreeNode<int>(3, node6, node7);
        
        TreeNode<int> *root = new TreeNode<int>(1, node2, node3);

        return root;
    }
    // recursion 
    static void preOrderTraversalRecursion(TreeNode<T> *node) {
        if (!node) return;
        std::cout << node->data << std::endl;
        preOrderTraversalRecursion(node->left);
        preOrderTraversalRecursion(node->right);
    }
    void midOrderTraversalRecursion(TreeNode<T> *node) {
        if (!node) return;
        preOrderTraversalRecursion(node->left);
        std::cout << node->data << std::endl;
        preOrderTraversalRecursion(node->right);
    }
    void postOrderTraversalRecursion(TreeNode<T> *node) {
        if (!node) return;
        preOrderTraversalRecursion(node->left);
        preOrderTraversalRecursion(node->right);        
        std::cout << node->data << std::endl;
    }
    // iteration
    void preOrderTraversalIteration(TreeNode<T> *root) {
        TreeNode<T> *node = root;
        std::vector<TreeNode<T>* > vec;

        while (!vec.empty() || node) {
            while (node) {
                std::cout << node->data << " ";
                vec.push_back(node);
                node = node->left;
            }
           node = vec.back()->right;
           vec.pop_back();
        }
        std::cout << std::endl;
    }

    void midOrderTraversalIteration(TreeNode<T> *root) {
        TreeNode<T> *node = root;
        std::vector<TreeNode<T>* > vec;

        while (!vec.empty() || node) {
            while (node) {
                vec.push_back(node);
                node = node->left;
            }
            std::cout << vec.back()->data << " ";
            node = vec.back()->right;
            vec.pop_back();
        }
        std::cout << std::endl;        
    }

    void postOrderTraversalIteration(TreeNode<T> *root) {
        TreeNode<T> *node = root;
        std::vector<TreeNode<T>*> vec;
        std::vector<T> reverseResultVec;
        
        while (!vec.empty() || node) {
            while (node) {
                reverseResultVec.push_back(node->data);
                vec.push_back(node);
                node = node->right;
            }
            node = vec.back()->left;
            vec.pop_back();
        }
        for (auto it = reverseResultVec.rbegin(); it != reverseResultVec.rend(); it++) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
private:
    
};

#endif