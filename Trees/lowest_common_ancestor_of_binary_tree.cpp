// Problem: Lowest Common Ancestor of a Binary Tree
// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// Approach: Recursive DFS
// Time Complexity: O(n)
// Space Complexity: O(h) where h is the height of the tree

/*
Explanation:
The Lowest Common Ancestor (LCA) of two nodes p and q
is the lowest node in the tree that has both p and q
as descendants.

Approach:
1. If the current node is NULL, p, or q → return it.
2. Recursively search in left and right subtrees.
3. If both sides return non-null → current node is the LCA.
4. If only one side returns non-null → propagate that node upward.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (root == NULL || root == p || root == q)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left == NULL)
            return right;

        if (right == NULL)
            return left;

        return root;
    }
};