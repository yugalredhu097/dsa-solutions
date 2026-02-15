// Problem: Binary Tree Inorder Traversal
// Link: https://leetcode.com/problems/binary-tree-inorder-traversal/
// Approach: Iterative using Stack
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
In inorder traversal, nodes are visited in the order:
Left → Root → Right.

Approach (Iterative):
1. Use a stack to simulate recursion.
2. Traverse left as far as possible, pushing nodes onto the stack.
3. Pop the top node, record its value.
4. Move to the right subtree.
5. Repeat until both stack is empty and current node is NULL.

This avoids recursion while preserving inorder sequence.
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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* node = root;
        vector<int> ans;

        while (true) {
            if (node != NULL) {
                st.push(node);
                node = node->left;
            } else {
                if (st.empty()) break;
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }

        return ans;
    }
};
