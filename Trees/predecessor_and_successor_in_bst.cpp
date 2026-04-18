// Problem: Predecessor and Successor in BST
// Link: https://www.geeksforgeeks.org/problems/predecessor-and-successor/1
// Approach: Iterative BST Traversal
// Time Complexity: O(h)
// Space Complexity: O(1)

/*
Explanation:

We are given a Binary Search Tree (BST) and a key.

Goal:
Find:

1. Predecessor:
   Largest node value < key

2. Successor:
   Smallest node value > key

------------------------------------------------

BST Property:

- Left subtree values < root
- Right subtree values > root

------------------------------------------------

Approach:

Find Predecessor:
- If node->data < key:
    possible predecessor
    move right for closer value
- Else move left

Find Successor:
- If node->data > key:
    possible successor
    move left for closer value
- Else move right

------------------------------------------------

This avoids full traversal.
*/

 /*
BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
public:

    vector<Node*> findPreSuc(Node* root, int key) {

        Node* pred = NULL;
        Node* succ = NULL;

        Node* node = root;

        // Find predecessor
        while (node) {

            if (node->data < key) {
                pred = node;
                node = node->right;
            }
            else {
                node = node->left;
            }
        }

        node = root;

        // Find successor
        while (node) {

            if (node->data > key) {
                succ = node;
                node = node->left;
            }
            else {
                node = node->right;
            }
        }

        return {pred, succ};
    }
};