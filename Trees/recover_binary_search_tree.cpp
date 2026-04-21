// Problem: Recover Binary Search Tree
// Link: https://leetcode.com/problems/recover-binary-search-tree/
// Approach: Inorder Traversal + Detect Swapped Nodes
// Time Complexity: O(n)
// Space Complexity: O(h)

/*
Explanation:

Two nodes in a BST were swapped by mistake.

Goal:
Recover the tree without changing structure.

------------------------------------------------

Key Property of BST:

Inorder traversal gives sorted order.

Example:

Correct inorder:
1 2 3 4 5

Swapped:
1 4 3 2 5

Violations occur where:
prev->val > curr->val

------------------------------------------------

Approach:

Use inorder traversal and track:

1. prev   → previous node in inorder
2. first  → first misplaced node
3. second → second misplaced node

------------------------------------------------

Cases:

1. Adjacent swapped nodes:
   One violation

2. Non-adjacent swapped nodes:
   Two violations

We:
- set first = prev on first violation
- update second = curr on every violation

Finally swap(first->val, second->val)

------------------------------------------------

This restores BST ordering.
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
private:

    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* node) {

        if (!node)
            return;

        inorder(node->left);

        // Detect violation
        if (prev && prev->val > node->val) {

            if (!first)
                first = prev;

            second = node;
        }

        prev = node;

        inorder(node->right);
    }

public:

    void recoverTree(TreeNode* root) {

        inorder(root);

        swap(first->val, second->val);
    }
};