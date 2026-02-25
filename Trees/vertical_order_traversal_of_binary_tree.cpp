// Problem: Vertical Order Traversal of a Binary Tree
// Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// Approach: BFS + Sorting using Map
// Time Complexity: O(n log n)
// Space Complexity: O(n)

/*
Explanation:
In vertical order traversal:
- Nodes are grouped by column index.
- Within the same column:
  1. Nodes are ordered by row (top to bottom).
  2. If multiple nodes share the same row and column,
     they are ordered by value.

Approach:
1. Perform BFS traversal while tracking:
   - row (depth)
   - column (horizontal distance)
2. Store nodes in a map:
   column -> list of (row, value)
3. Sort each column’s list by row, then value.
4. Extract values column-wise to form the answer.
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;

        // column -> list of (row, value)
        map<int, vector<pair<int, int>>> mpp;

        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}}); // node, {row, col}

        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            mpp[col].push_back({row, node->val});

            if (node->left)
                q.push({node->left, {row + 1, col - 1}});
            if (node->right)
                q.push({node->right, {row + 1, col + 1}});
        }

        // Process columns in order
        for (auto &it : mpp) {
            auto &vec = it.second;
            sort(vec.begin(), vec.end());

            vector<int> column;
            for (auto &p : vec) {
                column.push_back(p.second);
            }
            ans.push_back(column);
        }

        return ans;
    }
};