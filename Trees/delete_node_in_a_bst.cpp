// Problem: Delete Node in a BST
// Link: https://leetcode.com/problems/delete-node-in-a-bst/
// Approach: Recursive BST Deletion
// Time Complexity: O(h) where h = height of tree
// Space Complexity: O(h)

/*
Explanation:

We are given:
- Root of a Binary Search Tree (BST)
- A key to delete

Goal:
Delete the node with given key while maintaining BST properties.

------------------------------------------------

Cases:

1. Node not found → return root

2. Node has no child:
   → delete and return NULL

3. Node has one child:
   → return the child

4. Node has two children:
   → Find inorder successor (smallest in right subtree)
   → Replace current node value with successor
   → Delete successor from right subtree

------------------------------------------------

Key Idea:

Use recursion to locate the node and handle cases accordingly.

------------------------------------------------

Inorder Successor:
Leftmost node in right subtree.
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

    TreeNode* deletion(TreeNode* &root, int key) {

        if (!root)
            return NULL;

        if (key < root->val) {
            root->left = deletion(root->left, key);
        }
        else if (key > root->val) {
            root->right = deletion(root->right, key);
        }
        else {

            // Case 1 & 2: one or zero child
            if (!root->left) return root->right;
            if (!root->right) return root->left;

            // Case 3: two children
            TreeNode* temp = root->right;

            while (temp->left)
                temp = temp->left;

            root->val = temp->val;

            root->right = deletion(root->right, temp->val);
        }

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        return deletion(root, key);
    }
};