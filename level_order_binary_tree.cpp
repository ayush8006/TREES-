#include <iostream>
#include <queue>
#include<bits/stdc++.h>
using namespace std;


class BinaryTreeNode {
public:
    int val; // Value of the node
    BinaryTreeNode* left; // Pointer to the left child node
    BinaryTreeNode* right; // Pointer to the right child node

    // Constructor by initialization list
    BinaryTreeNode(int value) : val(value), left(nullptr), right(nullptr) {}

    // Destructor (for memory cleanup)
    ~BinaryTreeNode() {
        delete left;
        delete right;
    }
};

// Function to perform level order traversal of a binary tree
void levelOrderTraversal(BinaryTreeNode* root) {
    if (root == nullptr)
        return;

   queue<BinaryTreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        BinaryTreeNode* current = q.front();
        q.pop();

       cout << current->val << " ";

        // Enqueue left child
        if (current->left)
            q.push(current->left);

        // Enqueue right child
        if (current->right)
            q.push(current->right);
    }
}

// Function to build a binary tree from user input
BinaryTreeNode* buildBinaryTree() {
    cout << "Enter the value for the root node: ";
    int rootValue;
   cin >> rootValue;

    BinaryTreeNode* root = new BinaryTreeNode(rootValue);
   queue<BinaryTreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        BinaryTreeNode* current = q.front();
        q.pop();

        int leftValue, rightValue;
        std::cout << "Enter left child value of " << current->val << " (-1 if none): ";
        std::cin >> leftValue;
        if (leftValue != -1) {
            current->left = new BinaryTreeNode(leftValue);
            q.push(current->left);
        }

        std::cout << "Enter right child value of " << current->val << " (-1 if none): ";
        std::cin >> rightValue;
        if (rightValue != -1) {
            current->right = new BinaryTreeNode(rightValue);
            q.push(current->right);
        }
    }

    return root;
}

int main() {
    BinaryTreeNode* root = buildBinaryTree();

    std::cout << "Level order traversal:" << std::endl;
    levelOrderTraversal(root);
    std::cout << std::endl;

    delete root; // Clean up memory

    return 0;
}
