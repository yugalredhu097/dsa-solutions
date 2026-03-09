// Problem: Root to Leaf Paths
// Link: https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1
// Approach: DFS / Backtracking
// Time Complexity: O(n)
// Space Complexity: O(h)

/*
Explanation:
The task is to find all root-to-leaf paths in a binary tree.

A path is valid if it starts from the root and ends at a leaf node.

Approach:
1. Use DFS traversal.
2. Maintain a temporary vector to store the current path.
3. When a leaf node is reached:
   - Add the node value to the path
   - Store the path in the result
4. Backtrack after exploring each branch.
*/

/*

Definition for Binary Tree Node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

*/

class Solution {
public:

    void allpaths(vector<vector<int>> &ans, vector<int> &temp, Node* node) {

        if (node == NULL) return;

        temp.push_back(node->data);

        if (node->left == NULL && node->right == NULL) {
            ans.push_back(temp);
        } else {
            allpaths(ans, temp, node->left);
            allpaths(ans, temp, node->right);
        }

        temp.pop_back();
    }

    vector<vector<int>> Paths(Node* root) {

        vector<vector<int>> ans;
        vector<int> temp;

        allpaths(ans, temp, root);

        return ans;
    }
};