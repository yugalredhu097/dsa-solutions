// Problem: Binary Tree Maximum Path Sum
// Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Approach: DFS with Postorder Traversal
// Time Complexity: O(n)
// Space Complexity: O(h) where h is the height of the tree

/*
Explanation:
A path in a binary tree is any sequence of nodes where each pair
of adjacent nodes has a parent-child relationship.
The path does not need to pass through the root.

Approach:
1. Use DFS to compute the maximum gain from each node.
2. For each node:
   - Compute the maximum gain from left and right subtrees.
   - Ignore negative gains by taking max(0, gain).
3. Update the global maximum path sum using:
   node->val + leftGain + rightGain
4. Return the maximum gain that can be extended to the parent.

This ensures all possible paths are considered efficiently.
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
    int maxsum(TreeNode* node, int &maxi) {
        if (node == NULL) return 0;

        int leftGain  = max(0, maxsum(node->left, maxi));
        int rightGain = max(0, maxsum(node->right, maxi));

        // Update global maximum
        maxi = max(maxi, node->val + leftGain + rightGain);

        // Return max gain including current node
        return node->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxsum(root, maxi);
        return maxi;
    }
};