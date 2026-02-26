// Problem: Top View of Binary Tree
// Link: https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
// Approach: BFS + Horizontal Distance Mapping
// Time Complexity: O(n log n)
// Space Complexity: O(n)

/*
Explanation:
The top view of a binary tree contains the nodes that are visible
when the tree is viewed from the top.

Approach:
1. Use BFS (level order traversal).
2. Track horizontal distance (HD) from root:
   - root → 0
   - left child → HD - 1
   - right child → HD + 1
3. Use a map to store the first node encountered at each HD.
4. Since BFS processes level by level, the first node at each
   horizontal distance is the topmost node.
5. Extract map values in sorted HD order.

This ensures correct top view ordering from left to right.
*/

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
public:
    vector<int> topView(Node *root) {
        vector<int> ans;
        if (root == NULL) return ans;

        map<int, int> mpp;  // horizontal distance -> node value
        queue<pair<Node*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {
            Node* node = q.front().first;
            int col = q.front().second;
            q.pop();

            // Store first occurrence at this column
            if (mpp.find(col) == mpp.end()) {
                mpp[col] = node->data;
            }

            if (node->left)
                q.push({node->left, col - 1});
            if (node->right)
                q.push({node->right, col + 1});
        }

        for (auto &p : mpp) {
            ans.push_back(p.second);
        }

        return ans;
    }
};