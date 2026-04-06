// Problem: Insert into a Binary Search Tree
// Link: https://leetcode.com/problems/insert-into-a-binary-search-tree/
// Approach: Recursive BST Insertion
// Time Complexity: O(h) where h = height of tree
// Space Complexity: O(h)

/*
Explanation:

We are given:
- Root of a Binary Search Tree (BST)
- A value to insert

Goal:
Insert the value into the BST while maintaining BST properties.

------------------------------------------------

BST Property:

- Left subtree values < root
- Right subtree values > root

------------------------------------------------

Approach:

1. If root is NULL → create and return new node

2. Compare value with current node:
   - If val < node->val → go left
   - If val > node->val → go right

3. Insert at the correct NULL position

------------------------------------------------

This ensures BST remains valid.
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

    void insert(TreeNode* &node, int val) {

        if (node->val > val && node->left == NULL) {
            node->left = new TreeNode(val);
            return;
        }

        if (node->val < val && node->right == NULL) {
            node->right = new TreeNode(val);
            return;
        }

        if (node->val > val) {
            insert(node->left, val);
        }
        else {
            insert(node->right, val);
        }
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {

        if (root == NULL) {
            return new TreeNode(val);
        }

        insert(root, val);

        return root;
    }
};