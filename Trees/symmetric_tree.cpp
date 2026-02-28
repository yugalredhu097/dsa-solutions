// Problem: Symmetric Tree
// Link: https://leetcode.com/problems/symmetric-tree/
// Approach: Recursive DFS (Mirror Check)
// Time Complexity: O(n)
// Space Complexity: O(h) where h is the height of the tree

/*
Explanation:
A binary tree is symmetric if the left subtree is a mirror
reflection of the right subtree.

Approach:
1. Use a helper function to compare two nodes.
2. Two nodes are symmetric if:
   - Both are NULL, or
   - Both are non-NULL and have the same value, and
   - Left child of one matches right child of the other, and
   - Right child of one matches left child of the other.
3. Start comparison from root->left and root->right.
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
    bool symmetric(TreeNode* node1, TreeNode* node2) {
        if (node1 == NULL && node2 == NULL) return true;
        if (node1 == NULL || node2 == NULL) return false;
        if (node1->val != node2->val) return false;

        return symmetric(node1->left, node2->right) &&
               symmetric(node1->right, node2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return symmetric(root->left, root->right);
    }
};