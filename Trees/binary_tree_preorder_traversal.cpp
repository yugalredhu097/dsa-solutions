// Problem: Binary Tree Preorder Traversal
// Link: https://leetcode.com/problems/binary-tree-preorder-traversal/
// Approach: Recursive Tree Traversal
// Time Complexity: O(n)
// Space Complexity: O(h) where h is the height of the tree (recursion stack)

/*
Explanation:
In preorder traversal, nodes are visited in the order:
Root → Left → Right.

Approach:
1. Visit the current node and add its value.
2. Recursively traverse the left subtree.
3. Recursively traverse the right subtree.

This traversal is useful for copying trees or creating
prefix expressions from expression trees.
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
    void preorder(TreeNode* node, vector<int> &ans) {
        if (node == NULL) return;

        ans.push_back(node->val);
        preorder(node->left, ans);
        preorder(node->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};
