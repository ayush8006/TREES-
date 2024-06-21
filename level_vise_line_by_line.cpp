#include <iostream>
#include <queue>
#include <vector>

class BinaryTreeNode {
public:
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
    ~BinaryTreeNode() {
        delete left;
        delete right;
    }
};

void levelOrderLineByLine(BinaryTreeNode* root) {
    if (root == nullptr) return;

    std::queue<BinaryTreeNode*> q;
    q.push(root);
    q.push(nullptr); // Use nullptr as a level marker

    while (!q.empty()) {
        BinaryTreeNode* current = q.front();
        q.pop();

        if (current == nullptr) {
            std::cout << std::endl;
            if (!q.empty()) q.push(nullptr); // Add a new marker for the next level
        } else {
            std::cout << current->val << " ";
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }
}

// Helper function to build a binary tree from given array representation
BinaryTreeNode* buildTree(std::vector<int>& arr, int index) {
    BinaryTreeNode* root = nullptr;
    if (index < arr.size()) {
        if (arr[index] == -1) // -1 represents null node
            return nullptr;

        root = new BinaryTreeNode(arr[index]);
        root->left = buildTree(arr, 2 * index + 1); // Build left subtree
        root->right = buildTree(arr, 2 * index + 2); // Build right subtree
    }
    return root;
}

int main() {
    // Example input array representing the binary tree
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    BinaryTreeNode* root = buildTree(arr, 0);

    std::cout << "Level order traversal line by line:" << std::endl;
    levelOrderLineByLine(root);

    delete root; // Clean up memory

    return 0;
}
