// Problem: Same Tree
// Link: https://leetcode.com/problems/same-tree/
// Approach: Recursive DFS
// Time Complexity: O(n)
// Space Complexity: O(h) where h is the height of the tree

/*
Explanation:
Two binary trees are considered the same if:
1. They have the same structure.
2. Corresponding nodes have the same values.

Approach:
1. If both nodes are NULL, they are identical.
2. If one is NULL and the other is not, they differ.
3. If values differ, they are not the same.
4. Recursively compare left subtrees and right subtrees.

This DFS approach checks both structure and values.
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
    bool issametree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true;
        if (p == NULL || q == NULL) return false;
        if (p->val != q->val) return false;

        return issametree(p->left, q->left) &&
               issametree(p->right, q->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return issametree(p, q);
    }
};