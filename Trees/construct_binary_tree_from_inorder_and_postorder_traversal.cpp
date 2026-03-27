// Problem: Construct Binary Tree from Inorder and Postorder Traversal
// Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// Approach: Recursion + Hash Map
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:

We are given:
- inorder   → Left → Root → Right
- postorder → Left → Right → Root

Goal:
Reconstruct the binary tree.

------------------------------------------------

Key Idea:

1. The last element of postorder is always the root.

2. Find this root in inorder array.
   This splits the tree into:
   - left subtree
   - right subtree

3. Number of nodes in right subtree:
      numRight = inEnd - inRoot

4. Recursively build:
   - Right subtree first
   - Then left subtree

------------------------------------------------

Why build right first?

Because in postorder:
[ left | right | root ]

So before root (last element), the right subtree appears
just before it.

------------------------------------------------

Optimization:

We use a hash map to store indices of inorder values
for O(1) lookup.

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

    TreeNode* tree(vector<int> &postorder, int posStart, int posEnd,
                   vector<int> &inorder, int inStart, int inEnd,
                   unordered_map<int,int> &mpp) {

        if (inStart > inEnd || posStart > posEnd)
            return NULL;

        TreeNode* node = new TreeNode(postorder[posEnd]);

        int inRoot = mpp[node->val];
        int numRight = inEnd - inRoot;

        // Build right subtree first
        node->right = tree(postorder, posEnd - numRight, posEnd - 1,
                           inorder, inRoot + 1, inEnd, mpp);

        // Then left subtree
        node->left = tree(postorder, posStart, posEnd - numRight - 1,
                          inorder, inStart, inRoot - 1, mpp);

        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        unordered_map<int,int> mpp;

        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }

        return tree(postorder, 0, postorder.size() - 1,
                    inorder, 0, inorder.size() - 1, mpp);
    }
};