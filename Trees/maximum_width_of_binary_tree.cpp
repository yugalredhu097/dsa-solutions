// Problem: Maximum Width of Binary Tree
// Link: https://leetcode.com/problems/maximum-width-of-binary-tree/
// Approach: Level Order Traversal + Index Normalization
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
The width of a binary tree at a given level is defined as the length
between the leftmost and rightmost non-null nodes, including null nodes in between.

Approach:
1. Perform BFS while assigning an index to each node
   (similar to complete binary tree indexing).
2. For each level:
   - Normalize indices by subtracting the first index (to prevent overflow).
   - Track the first and last index.
3. Width of the level = last_index - first_index + 1.
4. Keep track of the maximum width.

Using index normalization avoids large number overflow.
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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;

        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            long long start = q.front().second;
            long long first = 0, last = 0;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                long long idx = q.front().second - start;
                q.pop();

                if (i == 0) first = idx;
                if (i == size - 1) last = idx;

                if (node->left)
                    q.push({node->left, 2 * idx});
                if (node->right)
                    q.push({node->right, 2 * idx + 1});
            }

            ans = max(ans, last - first + 1);
        }

        return (int)ans;
    }
};