// Problem: Floor in a Binary Search Tree
// Link: https://www.geeksforgeeks.org/problems/floor-in-bst/1
// Approach: Iterative BST Traversal
// Time Complexity: O(h)
// Space Complexity: O(1)

/*
Explanation:

We are given a Binary Search Tree (BST) and a value k.

Goal:
Find the floor of k:
→ largest value in BST ≤ k

------------------------------------------------

Key Idea:

Use iterative traversal:

1. If node value == k → return k

2. If node value > k:
   → move left

3. If node value < k:
   → store as potential answer
   → move right to find closer value

------------------------------------------------

This avoids recursion and uses O(1) space.
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

    int findMaxFork(Node* root, int k) {

        int ans = -1;

        while (root) {

            if (root->data == k)
                return k;

            if (root->data > k) {
                root = root->left;
            }
            else {
                ans = root->data;
                root = root->right;
            }
        }

        return ans;
    }
};