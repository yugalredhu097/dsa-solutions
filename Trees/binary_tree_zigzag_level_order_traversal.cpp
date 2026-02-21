// Problem: Binary Tree Zigzag Level Order Traversal
// Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// Approach: Level Order Traversal using Two Queues
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
Zigzag level order traversal means:
- First level: left to right
- Second level: right to left
- Third level: left to right
…and so on.

Approach:
1. Use two queues to process the tree level by level.
2. Store nodes of the current level in a temporary vector.
3. Reverse the vector for even levels to achieve zigzag order.
4. Push children into the secondary queue for the next level.
5. Swap queues and continue.

This approach clearly separates levels and direction handling.
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;

        queue<TreeNode*> q1, q2;
        q1.push(root);

        vector<int> temp;
        int level = 1, cnt = 1;

        while (!q1.empty()) {
            TreeNode* node = q1.front();
            q1.pop();
            cnt--;

            temp.push_back(node->val);

            if (node->left) q2.push(node->left);
            if (node->right) q2.push(node->right);

            if (cnt == 0) {
                if (level % 2 == 0) {
                    reverse(temp.begin(), temp.end());
                }
                ans.push_back(temp);
                temp.clear();

                level++;
                while (!q2.empty()) {
                    q1.push(q2.front());
                    q2.pop();
                    cnt++;
                }
            }
        }

        return ans;
    }
};