//1. by level order traversal 



//2. recursively create a tree
//create root
//root->left->recursive
//root->right->recursive

//assume if i/p ==-1 then null and !=-1 valid data



#include <bits/stdc++.h>
using namespace std;


class BinaryTreeNode {
public:
    int val; 
    BinaryTreeNode* left; 
    BinaryTreeNode* right; 

    // Constructor
    BinaryTreeNode(int value) : val(value), left(nullptr), right(nullptr) {}

    // Destructor (for memory cleanup)
    ~BinaryTreeNode() {
        delete left;
        delete right;
    }    
};

BinaryTreeNode* buildBinaryTree(const vector<int>& data, int& index) {
    // Base case: If index is out of bounds or current data is -1 (indicating nullptr)
    if (index >= data.size() || data[index] == -1) {
        index++; // Move index to next element
        return nullptr;
    }

    // Create new node with current data
    BinaryTreeNode* newNode = new BinaryTreeNode(data[index++]);

    // Recursively build left and right subtrees
    newNode->left = buildBinaryTree(data, index);
    newNode->right = buildBinaryTree(data, index);

    return newNode;
}

void change(BinaryTreeNode* node) {
    if (node == nullptr)
        return;
     BinaryTreeNode*temp= node->left;
     node->left=node->right;
     node->right=temp;       

}

void printInorder(BinaryTreeNode* &node) {
    if (node == NULL)
        return;

     
    printInorder(node->left);
   cout << node->val << " ";
    printInorder(node->right);
}

int main() {
    // Example data to build a binary tree: {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1}
    vector<int> data = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int index = 0;

    // Build the binary tree from data
    BinaryTreeNode* root = buildBinaryTree(data, index);

    // Print the inorder traversal of the binary tree
    cout << "Inorder traversal of the binary tree:" << std::endl;
    printInorder(root);
    cout << std::endl;
    change(root);
    printInorder(root);
    cout << std::endl;

    // Clean up memory (optional in a short example like this)
    delete root;

    return 0;
}
