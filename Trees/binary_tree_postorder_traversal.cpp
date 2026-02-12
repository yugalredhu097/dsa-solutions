// Problem: Binary Tree Postorder Traversal
// Link: https://leetcode.com/problems/binary-tree-postorder-traversal/
// Approach: Recursive Tree Traversal
// Time Complexity: O(n)
// Space Complexity: O(h) where h is tree height (recursion stack)

/*
Explanation:
In postorder traversal, nodes are visited in the order:
Left → Right → Root.

Approach:
1. Recursively traverse the left subtree.
2. Recursively traverse the right subtree.
3. Add the current node's value to the result.

This ensures correct postorder sequence.
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
    void postorder(TreeNode* node, vector<int> &ans) {
        if (node == NULL) return;

        postorder(node->left, ans);
        postorder(node->right, ans);
        ans.push_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};
