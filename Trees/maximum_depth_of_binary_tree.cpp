// Problem: Maximum Depth of Binary Tree
// Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Approach: Recursive DFS
// Time Complexity: O(n)
// Space Complexity: O(h) where h is the height of the tree

/*
Explanation:
The maximum depth (or height) of a binary tree is the number of
nodes along the longest path from the root to a leaf.

Approach:
1. If the current node is NULL, return 0.
2. Recursively compute the depth of the left subtree.
3. Recursively compute the depth of the right subtree.
4. Return 1 + max(leftDepth, rightDepth).

This DFS approach naturally computes the tree height.
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
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;

        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);

        return 1 + max(leftHeight, rightHeight);
    }
};
