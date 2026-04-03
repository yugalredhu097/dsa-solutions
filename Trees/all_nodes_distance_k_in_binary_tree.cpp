// Problem: All Nodes Distance K in Binary Tree
// Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
// Approach: BFS + Parent Mapping
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:

We are given:
- A binary tree
- A target node
- An integer k

Goal:
Return all nodes at distance k from the target node.

------------------------------------------------

Key Idea:

A binary tree does not have parent pointers,
so we first convert it into an undirected graph
by storing parent relationships.

------------------------------------------------

Steps:

1. Build Parent Map:
   Use BFS to store:
   parent[child] = parent node

2. BFS from target:
   - Use queue starting from target
   - Track visited nodes to avoid cycles
   - Expand in 3 directions:
       left child
       right child
       parent

3. Stop when distance = k

4. Remaining nodes in queue are answer

------------------------------------------------

This effectively treats the tree as a graph.
*/

 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        vector<int> ans;

        if (root == NULL)
            return ans;

        unordered_map<TreeNode*, TreeNode*> parent;

        queue<TreeNode*> q;

        // Step 1: Build parent map
        q.push(root);

        while (!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }

            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        // Step 2: BFS from target
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);

        int dist = 0;

        while (!q.empty() && dist < k) {

            int size = q.size();

            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                // left child
                if (node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    q.push(node->left);
                }

                // right child
                if (node->right && !visited.count(node->right)) {
                    visited.insert(node->right);
                    q.push(node->right);
                }

                // parent
                if (parent.count(node) && !visited.count(parent[node])) {
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                }
            }

            dist++;
        }

        // Step 3: Collect result
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};