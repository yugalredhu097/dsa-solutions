// Problem: Binary Tree Inorder Traversal
// Link: https://leetcode.com/problems/binary-tree-inorder-traversal/
// Approach: Recursive Tree Traversal
// Time Complexity: O(n)
// Space Complexity: O(h) where h is the height of the tree (recursion stack)

/*
Explanation:
In inorder traversal, nodes are visited in the order:
Left → Root → Right.

Approach:
1. Recursively traverse the left subtree.
2. Visit the current node and add its value.
3. Recursively traverse the right subtree.

This traversal is especially useful for Binary Search Trees,
as it returns values in sorted order.
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
    void inorder(TreeNode* node, vector<int> &ans) {
        if (node == NULL) return;

        inorder(node->left, ans);
        ans.push_back(node->val);
        inorder(node->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};
