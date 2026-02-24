// Problem: Sum of Root To Leaf Binary Numbers
// Link: https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
// Approach: DFS + Path Construction
// Time Complexity: O(n)
// Space Complexity: O(h) for recursion stack

/*
Explanation:
Each root-to-leaf path in the binary tree represents a binary number
(where node values are either 0 or 1).

We need to:
1. Generate all root-to-leaf paths.
2. Treat each path as a binary number.
3. Convert each binary string to decimal.
4. Return the sum of all such numbers.

Approach:
- Perform DFS.
- Build a string representing the current path.
- When a leaf is reached, store the path.
- Convert all stored binary strings to integers and sum them.
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
    void allpaths(vector<string> &ans, string &temp, TreeNode* node) {
        if (node == NULL) return;

        // Add current node value
        temp.push_back(node->val == 1 ? '1' : '0');

        // If leaf node, store the path
        if (node->left == NULL && node->right == NULL) {
            ans.push_back(temp);
            temp.pop_back();
            return;
        }

        allpaths(ans, temp, node->left);
        allpaths(ans, temp, node->right);

        // Backtrack
        temp.pop_back();
    }

    int sumRootToLeaf(TreeNode* root) {
        vector<string> paths;
        string temp;
        allpaths(paths, temp, root);

        int sum = 0;
        for (string &s : paths) {
            sum += stoi(s, nullptr, 2);
        }

        return sum;
    }
};