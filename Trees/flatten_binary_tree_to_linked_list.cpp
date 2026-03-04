// Problem: Flatten Binary Tree to Linked List
// Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Approach: Preorder Traversal + Rewiring Pointers
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
The goal is to flatten the binary tree into a linked list
in-place following preorder traversal order.

The resulting structure should:
- Use only right pointers
- Set all left pointers to NULL
- Follow preorder traversal sequence

Approach:
1. Perform preorder traversal and store nodes in a vector.
2. Iterate through the vector and rewire pointers:
   - Set left pointer to NULL
   - Connect current node's right pointer to the next node
3. This forms a linked list in preorder order.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void preorder(TreeNode* node, vector<TreeNode*> &pre) {
        if (node == NULL) return;

        pre.push_back(node);
        preorder(node->left, pre);
        preorder(node->right, pre);
    }

    void flatten(TreeNode* root) {
        if (root == NULL) return;

        vector<TreeNode*> pre;
        preorder(root, pre);

        root = pre[0];
        root->left = NULL;
        TreeNode* temp = root;

        for (int i = 1; i < pre.size(); i++) {
            TreeNode* curr = pre[i];
            curr->left = NULL;
            temp->right = curr;
            temp = temp->right;
        }
    }
};