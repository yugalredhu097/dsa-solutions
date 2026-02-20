// Problem: Diameter of Binary Tree
// Link: https://leetcode.com/problems/diameter-of-binary-tree/
// Approach: DFS with Height Calculation
// Time Complexity: O(n)
// Space Complexity: O(h) where h is the height of the tree

/*
Explanation:
The diameter of a binary tree is the length of the longest path
between any two nodes in the tree. This path may or may not pass
through the root.

Approach:
1. Use DFS to compute the height of each subtree.
2. At each node, calculate:
   diameter = max(diameter, leftHeight + rightHeight)
3. Return the height of the current node as:
   1 + max(leftHeight, rightHeight)

This allows computing the diameter in a single traversal.
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
    int height(TreeNode* node, int &diameter) {
        if (node == NULL) return 0;

        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);

        diameter = max(diameter, lh + rh);

        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};