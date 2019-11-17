#pragma once

#include "Tree.h"
#include "TreeNode.h"
#include <vector>
#include "LinkedStack.h"

template<class T>
class BinaryTree :  public Tree<T> {
private:
    TreeNode<T>* root;

    int height(TreeNode<T>* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + std::max(height(root->left), height(root->right));
    }

public:
    BinaryTree() : root(nullptr) {};

    BinaryTree(std::vector<T> &array) {
        // not implemented yet
    }

    BinaryTree(TreeNode<T>* root) : root(root) {}

    bool contains(T val) override {
        // not implemented yet
        return false;
    }

    // https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
    // Used this source as a reference--made a lot of progress on my own but found
    // it difficult to solve
    std::vector<T> traverseInOrder() override {
        std::vector<T> result;
        LinkedStack<TreeNode<T>*> myStack;
        TreeNode<T>* curr = root;

        while (curr != nullptr || !myStack.isEmpty()) {
            while (curr != nullptr) {
                myStack.push(curr);
                curr = curr->left;
            }
            curr = myStack.peek();
            myStack.pop();
            result.push_back(curr->val);
            curr = curr->right;
        }
        return result;
    }

    std::vector<T> traversePreOrder() override {
        // don't bother
    }

    // https://www.geeksforgeeks.org/iterative-postorder-traversal/
    // Used this source as reference to write this function
    std::vector<T> traversePostOrder() override {
        std::vector<T> result;
        if (root == nullptr) {
            return result;
        }

        LinkedStack<TreeNode<T>*> myStack;
        LinkedStack<TreeNode<T>*> myStack2;
        TreeNode<T>* curr;
        myStack.push(root);

        while (!myStack.isEmpty()) {
            curr = myStack.peek();
            myStack.pop();
            myStack2.push(curr);
            if (curr->left != nullptr) {
                myStack.push(curr->left);
            }
            if (curr->right != nullptr) {
                myStack.push(curr->right);
            }
        }

        while (!myStack2.isEmpty()) {
            curr = myStack2.peek();
            myStack2.pop();
            result.push_back(curr->val);
        }
        return result;
    }

    void destructorHelper(TreeNode<T>* node) {
        if (node == nullptr) {
            return;
        }

        // must store left/right nodes so we can access after deleting root
        TreeNode<T>* left = node->left;
        TreeNode<T>* right = node->right;

        delete node;
        destructorHelper(left);
        destructorHelper(right);
    }

    virtual ~BinaryTree() {
        destructorHelper(root);
    }

    // Stores the path to the node containing the value
    // Wasn't sure if this could be simplified given our assumptions
    bool findPath(TreeNode<T>* node, std::vector<int> &paths, int n) {
        if (node == nullptr) {
            return false;
        }
        paths.push_back(node->val);
        if (node->val == n) {
            return true;
        }
        if (node->left != nullptr && findPath(node->left, paths, n) ||
            node->right != nullptr && findPath(node->right, paths, n)) {
            return true;
        }
        paths.pop_back();
        return false;
    }

    // https://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/
    // This function and the function "findPath" were written with the help of this source.
    // Compares the paths to the nodes containing the values and returns the first
    // occurring difference in paths--similar to the method we used in class when
    // brainstorming ideas on how to solve this problem. Simplified to fit our assumptions.
    T LCA(T node1, T node2) {
        std::vector<T> path1; // stores path to node 1
        std::vector<T> path2; // stores path to node 2

        // no need to check if nodes exist, due to assumptions
        findPath(root, path1, node1);
        findPath(root, path2, node2);

        // compares the paths to the nodes
        int i;
        for (i = 0; i < path1.size() && i < path2.size(); i++) {
            if (path1[i] != path2[i]) {
                break; // break at first occurring difference in paths
            }
        }
        return path1[i - 1];
    }

    bool add(const T & val) override {
        // not implemented yet
    }

    bool remove(const T &) override {
        // not implemented yet
    }

    int height() override {
        return height(root);
    }
};
