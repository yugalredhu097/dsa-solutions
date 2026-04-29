// Problem: Maximum Sum BST in Binary Tree
// Link: https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
// Approach: Postorder Traversal + Tree DP
// Time Complexity: O(n)
// Space Complexity: O(h)

/*
Explanation:

We are given a binary tree.

Goal:
Find the maximum sum of values among all subtrees
that are valid Binary Search Trees (BST).

------------------------------------------------

Key Idea:

For every node, determine:

1. Is left subtree a BST?
2. Is right subtree a BST?
3. Can current node form a BST with them?

------------------------------------------------

For each subtree return:

{minValue, maxValue, sum}

Where:

minValue = minimum node in subtree
maxValue = maximum node in subtree
sum      = subtree sum if valid BST

------------------------------------------------

BST Condition:

node->val > max(left subtree)
node->val < min(right subtree)

------------------------------------------------

If valid:

currSum = leftSum + rightSum + node->val

Update global answer.

------------------------------------------------

If invalid:

Return poisoned values:

{INT_MIN, INT_MAX, ...}

So parent cannot treat it as BST.

------------------------------------------------

Traversal must be postorder
because children are processed first.
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

    array<int,3> solve(TreeNode* node, int &ans) {

        // {minVal, maxVal, sum}

        if (node == NULL)
            return {INT_MAX, INT_MIN, 0};

        auto left  = solve(node->left, ans);
        auto right = solve(node->right, ans);

        // Valid BST
        if (node->val > left[1] && node->val < right[0]) {

            int currSum = left[2] + right[2] + node->val;

            ans = max(ans, currSum);

            int minVal = min(left[0], node->val);
            int maxVal = max(right[1], node->val);

            return {minVal, maxVal, currSum};
        }

        // Invalid BST
        return {INT_MIN, INT_MAX, 0};
    }

    int maxSumBST(TreeNode* root) {

        int ans = 0;

        solve(root, ans);

        return ans;
    }
};