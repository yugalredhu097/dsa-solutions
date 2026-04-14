// Problem: Construct Binary Search Tree from Preorder Traversal
// Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
// Approach: Preorder + Inorder Reconstruction
// Time Complexity: O(n log n)
// Space Complexity: O(n)

/*
Explanation:

We are given preorder traversal of a BST.

Goal:
Construct the BST.

------------------------------------------------

Key Idea:

1. In a BST:
   inorder traversal = sorted order

2. So:
   - Copy preorder → sort it → get inorder

3. Now we have:
   - preorder (root → left → right)
   - inorder  (left → root → right)

4. Use standard tree construction:
   - First element of preorder = root
   - Find root in inorder
   - Split into left & right subtrees

------------------------------------------------

Steps:

1. Create inorder by sorting preorder
2. Store index of each value using hashmap
3. Recursively build tree

------------------------------------------------

Note:

There exists a better O(n) solution using bounds,
but this approach is easier to understand.
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

    TreeNode* build(vector<int> &preorder, int preStart, int preEnd,
                    vector<int> &inorder, int inStart, int inEnd,
                    unordered_map<int,int> &mpp) {

        if (preStart > preEnd || inStart > inEnd)
            return NULL;

        TreeNode* node = new TreeNode(preorder[preStart]);

        int inRoot = mpp[node->val];
        int numsLeft = inRoot - inStart;

        node->left = build(preorder, preStart + 1, preStart + numsLeft,
                           inorder, inStart, inRoot - 1, mpp);

        node->right = build(preorder, preStart + numsLeft + 1, preEnd,
                            inorder, inRoot + 1, inEnd, mpp);

        return node;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {

        vector<int> inorder = preorder;

        sort(inorder.begin(), inorder.end());

        unordered_map<int,int> mpp;

        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size() - 1,
                     inorder, 0, inorder.size() - 1, mpp);
    }
};