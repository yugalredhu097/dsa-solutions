// Problem: Validate Binary Search Tree
// Link: https://leetcode.com/problems/validate-binary-search-tree/
// Approach: Recursion with Min/Max Constraints
// Time Complexity: O(n)
// Space Complexity: O(h)

/*
Explanation:

We are given a binary tree.

Goal:
Check if it is a valid Binary Search Tree (BST).

------------------------------------------------

BST Property:

- All nodes in left subtree < root
- All nodes in right subtree > root
- This must hold for EVERY node (not just immediate children)

------------------------------------------------

Key Idea:

We pass a valid range (minVal, maxVal) for each node.

For every node:
- node->val must lie strictly between (minVal, maxVal)

------------------------------------------------

Steps:

1. Start with range (-∞, +∞)

2. For left subtree:
   max becomes current node value

3. For right subtree:
   min becomes current node value

4. If any node violates constraint → return false

------------------------------------------------

Why long long?

To handle edge cases like INT_MIN and INT_MAX.
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

    bool check(TreeNode* node, long long minVal, long long maxVal) {

        if (node == NULL)
            return true;

        if (node->val <= minVal || node->val >= maxVal)
            return false;

        return check(node->left, minVal, node->val) &&
               check(node->right, node->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {

        return check(root, LLONG_MIN, LLONG_MAX);
    }
};