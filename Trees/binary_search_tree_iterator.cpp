// Problem: Binary Search Tree Iterator
// Link: https://leetcode.com/problems/binary-search-tree-iterator/
// Approach: Controlled Inorder Traversal using Stack
// Time Complexity:
//   Constructor -> O(h)
//   next()      -> Amortized O(1)
//   hasNext()   -> O(1)
// Space Complexity: O(h)

/*
Explanation:

We need to design an iterator for a BST that returns
elements in ascending order.

------------------------------------------------

Key Property of BST:

Inorder traversal gives sorted order.

------------------------------------------------

Approach:

Use a stack to simulate inorder traversal lazily.

1. Constructor:
   Push all left nodes from root.

2. next():
   - Pop top node (smallest available)
   - If popped node has right child,
     push all left nodes of right subtree.

3. hasNext():
   - If stack not empty, more nodes exist.

------------------------------------------------

Why stack?

It avoids storing full inorder traversal,
saving memory and allowing lazy iteration.
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

class BSTIterator {
    stack<TreeNode*> st;

public:

    BSTIterator(TreeNode* root) {
        pushAll(root);
    }

    int next() {

        TreeNode* node = st.top();
        st.pop();

        pushAll(node->right);

        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }

private:

    void pushAll(TreeNode* node) {

        while (node != NULL) {
            st.push(node);
            node = node->left;
        }
    }
};

/*
Usage:

BSTIterator* obj = new BSTIterator(root);
int val = obj->next();
bool more = obj->hasNext();
*/