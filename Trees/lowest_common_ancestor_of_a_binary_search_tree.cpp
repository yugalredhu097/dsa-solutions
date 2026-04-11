// Problem: Lowest Common Ancestor of a Binary Search Tree
// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// Approach: BST Property + Recursion
// Time Complexity: O(h)
// Space Complexity: O(h)

/*
Explanation:

We are given a Binary Search Tree (BST) and two nodes p and q.

Goal:
Find their Lowest Common Ancestor (LCA).

------------------------------------------------

Key BST Property:

- Left subtree values < root
- Right subtree values > root

------------------------------------------------

Approach:

1. If both p and q are smaller than root:
   → LCA lies in left subtree

2. If both p and q are greater than root:
   → LCA lies in right subtree

3. Otherwise:
   → root is the LCA

------------------------------------------------

This works because BST preserves ordering.
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

    void LCA(TreeNode* node, TreeNode* p, TreeNode* q, TreeNode* &ans) {

        if (node == NULL)
            return;

        // If current node is one of them OR lies between them
        if ((node == p || node == q) ||
            (node->val < p->val && node->val > q->val) ||
            (node->val < q->val && node->val > p->val)) {

            ans = node;
            return;
        }

        // Go left
        if (node->val > p->val && node->val > q->val) {
            LCA(node->left, p, q, ans);
        }
        // Go right
        else if (node->val < p->val && node->val < q->val) {
            LCA(node->right, p, q, ans);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        TreeNode* ans;

        LCA(root, p, q, ans);

        return ans;
    }
};