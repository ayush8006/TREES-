#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

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

void inorder_recusive(BinaryTreeNode* root) {
    if (root == nullptr) return;

    inorder_recusive(root->left);
    cout<<root->val<<" ";
     inorder_recusive(root->right);
   
}
vector<int> inOrder_Iterative(BinaryTreeNode* root) {
    vector<int> result;
    stack<BinaryTreeNode*> st;
    BinaryTreeNode* current = root;

    while (current != nullptr || !st.empty()) {
        while (current != nullptr) {
            st.push(current);
            current = current->left;
        }
        current = st.top();
        st.pop();
        result.push_back(current->val);
        current = current->right;
    }

    return result;
}


void preorder_recusive(BinaryTreeNode* root) {
    if (root == nullptr) return;

    cout<<root->val<<" ";
    preorder_recusive(root->left);
    preorder_recusive(root->right);
   
}


vector<int> preOrder_Iterative(BinaryTreeNode* root) {
    vector<int> result;
    if (root == nullptr) return result;

    stack<BinaryTreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        BinaryTreeNode* current = st.top();
        st.pop();
        result.push_back(current->val);

        if (current->right) {
            st.push(current->right);
        }
        if (current->left) {
            st.push(current->left);
        }
    }

    return result;
}


void postorder_recusive(BinaryTreeNode* root) {
    if (root == nullptr) return;

    postorder_recusive(root->left);
    postorder_recusive(root->right);   
    cout<<root->val<<" ";
}


vector<int> postOrder_Iterative(BinaryTreeNode* root) {
    vector<int> result;
    if (root == nullptr) return result;

    stack<BinaryTreeNode*> st1, st2;
    st1.push(root);

    while (!st1.empty()) {
        BinaryTreeNode* current = st1.top();
        st1.pop();
        st2.push(current);

        if (current->left) {
            st1.push(current->left);
        }
        if (current->right) {
            st1.push(current->right);
        }
    }

    while (!st2.empty()) {
        result.push_back(st2.top()->val);
        st2.pop();
    }

    return result;
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

    std::cout << "inorder traversal : " << std::endl;
    inorder_recusive(root);

     std::cout<< std::endl;

     
    std::cout << "inorder traversal iterative : " << std::endl;
  
    vector<int> result1= inOrder_Iterative(root);
    for (int val : result1) {
        cout << val << " ";
    }
    cout << endl;

    std::cout << "preorder traversal :" << std::endl;
    preorder_recusive(root);

    std::cout<< std::endl;

    
    std::cout << "preorder traversal iterative :" << std::endl;
   
    vector<int> result2 = preOrder_Iterative(root);
    for (int val : result2) {
        cout << val << " ";
    }
    cout << endl;


    std::cout << "postorder traversal :" << std::endl;
     postorder_recusive(root);

     std::cout<< std::endl;

    std::cout << "postorder traversal iterative:" << std::endl;
   
    vector<int> result3 = postOrder_Iterative(root);
    for (int val : result3) {
        cout << val << " ";
    }
    cout << endl;

    delete root; // Clean up memory

    return 0;
}
