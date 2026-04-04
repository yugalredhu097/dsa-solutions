// Problem: Search in a Binary Search Tree
// Link: https://leetcode.com/problems/search-in-a-binary-search-tree/
// Approach: Recursive BST Search
// Time Complexity: O(h) where h = height of tree
// Space Complexity: O(h)

/*
Explanation:

We are given the root of a Binary Search Tree (BST)
and a target value.

Goal:
Find the node in the BST whose value equals target.
Return the subtree rooted at that node.

------------------------------------------------

Key Property of BST:

- Left subtree values < root
- Right subtree values > root

------------------------------------------------

Approach:

1. If node is NULL → return NULL

2. If node->val == target → return node

3. If target < node->val → search in left subtree

4. If target > node->val → search in right subtree

------------------------------------------------

This reduces the search space efficiently.
*/

 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    void search(TreeNode* node, TreeNode* &ans, int target) {

        if (node == NULL) {
            ans = NULL;
            return;
        }

        if (node->val == target) {
            ans = node;
            return;
        }

        if (node->val > target) {
            search(node->left, ans, target);
        }
        else {
            search(node->right, ans, target);
        }
    }

    TreeNode* searchBST(TreeNode* root, int val) {

        TreeNode* ans;

        search(root, ans, val);

        return ans;
    }
};