// Problem: Construct Binary Tree from Preorder and Inorder Traversal
// Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Approach: Recursion + Hash Map
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:

We are given two arrays:
- preorder → Root → Left → Right
- inorder  → Left → Root → Right

Goal:
Reconstruct the binary tree.

------------------------------------------------

Key Idea:

1. The first element of preorder is always the root.

2. Find this root in inorder array.
   This splits the tree into:
   - left subtree
   - right subtree

3. Number of elements on the left side:
      numsLeft = inRoot - instart

4. Recursively build:
   - Left subtree
   - Right subtree

------------------------------------------------

Optimization:

We use a hash map to store the index of each value
in inorder traversal for O(1) lookup.

------------------------------------------------

Steps:

1. Build map of inorder values → indices.
2. Recursively construct tree using preorder index.
3. Divide problem into left and right subtrees.

------------------------------------------------

This ensures O(n) time complexity.
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

    TreeNode* tree(vector<int> &preorder, int prestart, int preend,
                   vector<int> &inorder, int instart, int inend,
                   unordered_map<int,int> &mpp) {

        if (prestart > preend || instart > inend)
            return NULL;

        TreeNode* node = new TreeNode(preorder[prestart]);

        int inRoot = mpp[node->val];
        int numsleft = inRoot - instart;

        node->left = tree(preorder, prestart + 1, prestart + numsleft,
                          inorder, instart, inRoot - 1, mpp);

        node->right = tree(preorder, prestart + numsleft + 1, preend,
                           inorder, inRoot + 1, inend, mpp);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        unordered_map<int,int> mpp;

        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }

        return tree(preorder, 0, preorder.size() - 1,
                    inorder, 0, inorder.size() - 1, mpp);
    }
};