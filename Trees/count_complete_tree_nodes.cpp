// Problem: Count Complete Tree Nodes
// Link: https://leetcode.com/problems/count-complete-tree-nodes/
// Approach: BFS Traversal (Level Order)
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:

We are given the root of a binary tree.

Goal:
Count the total number of nodes in the tree.

------------------------------------------------

Approach: Breadth-First Search (BFS)

1. If root is NULL → return 0.

2. Use a queue to perform level order traversal.

3. Push the root into the queue.

4. While the queue is not empty:
   - Pop the current node
   - Increment count
   - Push left child (if exists)
   - Push right child (if exists)

5. Return the total count.

------------------------------------------------

Note:

This is a straightforward BFS solution.
There exists a more optimized solution (O(log² n))
for complete binary trees using height comparison.
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
    int countNodes(TreeNode* root) {

        if (root == NULL)
            return 0;

        int cnt = 0;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            cnt++;

            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }

        return cnt;
    }
};