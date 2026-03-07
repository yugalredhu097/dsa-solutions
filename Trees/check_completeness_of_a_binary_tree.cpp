// Problem: Check Completeness of a Binary Tree
// Link: https://leetcode.com/problems/check-completeness-of-a-binary-tree/
// Approach: Level Order Traversal (BFS)
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
A binary tree is complete if:
1. Every level except possibly the last is completely filled.
2. All nodes in the last level are as far left as possible.

Approach:
1. Perform level order traversal using a queue.
2. If a NULL node is encountered, mark that NULL has been seen.
3. After a NULL is seen, if any non-null node appears later,
   the tree is not complete.
4. If traversal finishes without violating the rule,
   the tree is complete.
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
    bool isCompleteTree(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);

        bool nullSeen = false;

        while (!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            if (node == NULL) {
                nullSeen = true;
            }
            else {

                if (nullSeen) return false;

                q.push(node->left);
                q.push(node->right);
            }
        }

        return true;
    }
};