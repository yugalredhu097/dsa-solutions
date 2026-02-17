// Problem: Binary Tree Postorder Traversal
// Link: https://leetcode.com/problems/binary-tree-postorder-traversal/
// Approach: Iterative using Two Stacks
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
Postorder traversal order is:
Left → Right → Root

Approach (Two Stacks):
1. Push the root into the first stack (st1).
2. Pop from st1, push it into the second stack (st2).
3. Push left and right children of the popped node into st1.
4. Repeat until st1 is empty.
5. Finally, pop all elements from st2 to get postorder traversal.

This approach is simpler to understand than the one-stack method,
at the cost of extra space.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;

        stack<TreeNode*> st1;
        stack<TreeNode*> st2;

        st1.push(root);

        while (!st1.empty()) {
            TreeNode* node = st1.top();
            st1.pop();
            st2.push(node);

            if (node->left != NULL)
                st1.push(node->left);
            if (node->right != NULL)
                st1.push(node->right);
        }

        while (!st2.empty()) {
            ans.push_back(st2.top()->val);
            st2.pop();
        }

        return ans;
    }
};
