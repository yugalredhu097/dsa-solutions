// Problem: Balanced Binary Tree
// Link: https://leetcode.com/problems/balanced-binary-tree/
// Approach: DFS with Height Check
// Time Complexity: O(n)
// Space Complexity: O(h) where h is the height of the tree

/*
Explanation:
A binary tree is height-balanced if the height difference
between the left and right subtrees of every node is at most 1.

Approach:
1. Compute height of left and right subtrees using DFS.
2. If any subtree is unbalanced, return -1.
3. If height difference exceeds 1, return -1.
4. Otherwise, return the height of the current node.
5. The tree is balanced if the final result is not -1.

This approach checks balance and height in a single traversal.
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
    int height(TreeNode* root) {
        if (root == NULL) return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        if (lh == -1 || rh == -1) return -1;
        if (abs(lh - rh) > 1) return -1;

        return max(lh, rh) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};
