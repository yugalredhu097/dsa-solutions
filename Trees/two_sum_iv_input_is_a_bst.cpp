// Problem: Two Sum IV - Input is a BST
// Link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
// Approach: Two BST Iterators (Inorder + Reverse Inorder)
// Time Complexity: O(n)
// Space Complexity: O(h)

/*
Explanation:

We are given a Binary Search Tree (BST)
and an integer k.

Goal:
Return true if there exist two nodes such that:

node1->val + node2->val == k

------------------------------------------------

Key Idea:

Use BST property to simulate Two Sum
on a sorted array.

BST inorder traversal gives sorted values.

Instead of storing all values,
use two iterators:

1. Left Iterator:
   Gives next smallest value

2. Right Iterator:
   Gives next largest value

Then apply two-pointer logic.

------------------------------------------------

Steps:

1. Push leftmost path into stackLeft
2. Push rightmost path into stackRight

3. While pointers do not meet:
   - sum = left + right
   - If sum == k → true
   - If sum < k → move left pointer
   - If sum > k → move right pointer

------------------------------------------------

This avoids storing full inorder traversal.
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

    void pushLeft(TreeNode* node, stack<TreeNode*> &st) {

        while (node != NULL) {
            st.push(node);
            node = node->left;
        }
    }

    void pushRight(TreeNode* node, stack<TreeNode*> &st) {

        while (node != NULL) {
            st.push(node);
            node = node->right;
        }
    }

    bool findTarget(TreeNode* root, int k) {

        if (root == NULL)
            return false;

        stack<TreeNode*> stLeft;
        stack<TreeNode*> stRight;

        pushLeft(root, stLeft);
        pushRight(root, stRight);

        while (!stLeft.empty() && !stRight.empty()) {

            TreeNode* l = stLeft.top();
            TreeNode* r = stRight.top();

            if (l == r)
                return false;

            int sum = l->val + r->val;

            if (sum == k)
                return true;

            else if (sum > k) {

                stRight.pop();

                if (r->left)
                    pushRight(r->left, stRight);
            }
            else {

                stLeft.pop();

                if (l->right)
                    pushLeft(l->right, stLeft);
            }
        }

        return false;
    }
};