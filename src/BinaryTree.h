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
        TreeNode<T>* curr = root;
        myStack.push(curr);
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

    void DestructorHelper(TreeNode<T>* node) {
        if (node == nullptr) {
            return;
        }
        DestructorHelper(node->left);
        DestructorHelper(node->right);
        delete node;
    }

    virtual ~BinaryTree() {
        DestructorHelper(root);
    }

    T LCA(T node1, T node2) {

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
