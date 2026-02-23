// Problem: Tree Boundary Traversal
// Link: https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
// Approach: Decompose into Left Boundary, Leaf Nodes, Right Boundary
// Time Complexity: O(n)
// Space Complexity: O(h) for recursion stack

/*
Explanation:
Boundary traversal of a binary tree consists of:
1. Root node
2. Left boundary (excluding leaf nodes)
3. All leaf nodes (left to right)
4. Right boundary (excluding leaf nodes, in reverse order)

Approach:
- Traverse left boundary excluding leaves.
- Traverse all leaf nodes.
- Traverse right boundary excluding leaves.
- Combine them in the correct order.
*/

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
public:
    void Leaf(Node* node, vector<int> &leaf) {
        if (node == NULL) return;

        if (node->left == NULL && node->right == NULL) {
            leaf.push_back(node->data);
            return;
        }
        Leaf(node->left, leaf);
        Leaf(node->right, leaf);
    }

    void Right(Node* node, vector<int> &right) {
        if (node == NULL) return;

        if (node->left != NULL || node->right != NULL) {
            right.push_back(node->data);
        }

        if (node->right)
            Right(node->right, right);
        else
            Right(node->left, right);
    }

    void Left(Node* node, vector<int> &left) {
        if (node == NULL) return;

        if (node->left != NULL || node->right != NULL) {
            left.push_back(node->data);
        }

        if (node->left)
            Left(node->left, left);
        else
            Left(node->right, left);
    }

    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        if (root == NULL) return ans;

        ans.push_back(root->data);

        // If root is the only node
        if (root->left == NULL && root->right == NULL)
            return ans;

        vector<int> left, leaf, right;

        Left(root->left, left);
        Leaf(root, leaf);
        Right(root->right, right);

        for (int x : left) ans.push_back(x);
        for (int x : leaf) ans.push_back(x);

        reverse(right.begin(), right.end());
        for (int x : right) ans.push_back(x);

        return ans;
    }
};