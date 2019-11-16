#include "BinaryTree.h"
#include "gtest/gtest.h"

TEST(tree, demo) {
    TreeNode<int>* root = new TreeNode<int>(3);
    root->setLeft(new TreeNode<int>(1));
    root->setRight(new TreeNode<int>(5));

    root->getLeft()->setLeft(new TreeNode<int>(2));
    root->getLeft()->setRight(new TreeNode<int>(7));

    root->getRight()->setLeft(new TreeNode<int>(5));

    BinaryTree<int> tree(root);

    ASSERT_EQ(tree.height(),3);
}

TreeNode<int>* TestingTree() {
    TreeNode<int>* root = new TreeNode<int>(3);
    root->setLeft(new TreeNode<int>(1));
    root->setRight(new TreeNode<int>(5));

    root->getLeft()->setLeft(new TreeNode<int>(2));
    root->getLeft()->setRight(new TreeNode<int>(7));

    root->getRight()->setLeft(new TreeNode<int>(5));
    return root;
}

TEST(tree, In_Order_Iteratively) {
    // tests an empty tree
    BinaryTree<int> emptyBinaryTree(nullptr);
    std::vector<int> emptyTreeVector = emptyBinaryTree.traverseInOrder();
    ASSERT_EQ(emptyTreeVector.size(), 0);

    // tests a tree with multiple nodes
    std::vector<int> result = {2, 1, 7, 3, 5, 5};
    BinaryTree<int> tree(TestingTree());
    ASSERT_EQ(result, tree.traverseInOrder());
}

TEST(tree, Post_Order_Iteratively) {
    // tests an empty tree
    BinaryTree<int> emptyBinaryTree(nullptr);
    std::vector<int> emptyTreeVector = emptyBinaryTree.traversePostOrder();
    ASSERT_EQ(emptyTreeVector.size(), 0);

    // tests a tree with multiple nodes
    std::vector<int> result = {2, 7, 1, 5, 5, 3};
    BinaryTree<int> tree(TestingTree());
    ASSERT_EQ(result, tree.traversePostOrder());
}

TEST(tree, Lowest_Common_Ancestor) {

}

