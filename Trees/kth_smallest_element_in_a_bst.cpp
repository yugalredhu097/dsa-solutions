// Problem: Kth Smallest Element in a BST
// Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// Approach: Inorder Traversal
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:

We are given a Binary Search Tree (BST).

Goal:
Find the kth smallest element.

------------------------------------------------

Key Property of BST:

Inorder traversal of BST gives elements in sorted order.

------------------------------------------------

Approach:

1. Perform inorder traversal:
   Left → Root → Right

2. Store elements in a vector.

3. Return element at index (k - 1)

------------------------------------------------

Example:

BST:
    3
   / \
  1   4
   \
    2

Inorder → [1, 2, 3, 4]

k = 2 → answer = 2
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

    void inorder(TreeNode* node, vector<int> &num) {

        if (node == NULL)
            return;

        inorder(node->left, num);
        num.push_back(node->val);
        inorder(node->right, num);
    }

    int kthSmallest(TreeNode* root, int k) {

        vector<int> num;

        inorder(root, num);

        return num[k - 1];
    }
};