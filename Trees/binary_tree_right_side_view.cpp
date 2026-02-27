// Problem: Binary Tree Right Side View
// Link: https://leetcode.com/problems/binary-tree-right-side-view/
// Approach: Level Order Traversal (BFS)
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
The right side view of a binary tree contains the nodes that are
visible when the tree is viewed from the right side.

Approach:
1. Perform BFS (level order traversal).
2. Track the level (row) of each node.
3. For each level, keep updating the value in a map.
   Since BFS goes left to right, the last node encountered
   at each level will be the rightmost node.
4. Extract values from the map in level order.
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;

        map<int, int> mpp; // level -> node value
        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int row = q.front().second;
            q.pop();

            // Overwrite value at each level (rightmost survives)
            mpp[row] = node->val;

            if (node->left)
                q.push({node->left, row + 1});
            if (node->right)
                q.push({node->right, row + 1});
        }

        for (auto &p : mpp) {
            ans.push_back(p.second);
        }

        return ans;
    }
};