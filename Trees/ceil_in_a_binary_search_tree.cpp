// Problem: Ceil in a Binary Search Tree
// Link: https://www.geeksforgeeks.org/problems/ceil-in-bst/1
// Approach: Iterative BST Traversal
// Time Complexity: O(h)
// Space Complexity: O(1)

/*
Explanation:

We are given a Binary Search Tree (BST) and a value x.

Goal:
Find the ceil of x:
→ smallest value in BST ≥ x

------------------------------------------------

Key Idea:

Use iterative traversal:

1. If node value == x → return x

2. If node value < x:
   → move right

3. If node value > x:
   → store as potential answer
   → move left to find smaller valid value

------------------------------------------------

This ensures we find the closest greater or equal value.
*/

 /*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:

    int findCeil(Node* root, int x) {

        int ans = -1;

        while (root) {

            if (root->data == x)
                return x;

            if (root->data < x) {
                root = root->right;
            }
            else {
                ans = root->data;
                root = root->left;
            }
        }

        return ans;
    }
};