// Problem: Bottom View of Binary Tree
// Link: https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
// Approach: BFS + Horizontal Distance Mapping
// Time Complexity: O(n log n)
// Space Complexity: O(n)

/*
Explanation:
The bottom view of a binary tree contains the nodes that are visible
when the tree is viewed from the bottom.

Approach:
1. Perform BFS (level order traversal).
2. Track horizontal distance (HD) from root:
   - root → 0
   - left child → HD - 1
   - right child → HD + 1
3. For each HD, overwrite the value in the map.
   Since BFS goes level by level, the last node encountered
   at each HD will represent the bottommost node.
4. Extract values from the map in sorted HD order.
*/

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        if (root == NULL) return ans;

        map<int, int> mpp;  // horizontal distance -> node value
        queue<pair<Node*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {
            Node* node = q.front().first;
            int col = q.front().second;
            q.pop();

            // Overwrite to ensure bottommost node is stored
            mpp[col] = node->data;

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