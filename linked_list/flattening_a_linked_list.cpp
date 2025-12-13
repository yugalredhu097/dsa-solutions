// Problem: Flattening a Linked List
// Link: https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1
// Approach: Iterative merge of bottom-linked sorted lists
// Time Complexity: O(n * m)  (n lists, m nodes per list on average)
// Space Complexity: O(1)

/*
Explanation:
Each node has two pointers:
- next   → points to next list
- bottom → points to nodes within the same list (sorted)

Goal:
Flatten the structure so that all nodes are connected using
the bottom pointer only, in sorted order.

Approach:
1. Each vertical list is already sorted.
2. Repeatedly merge:
   - root list with root->next list using bottom pointers.
3. After merging:
   - Move root->next forward.
4. Continue until only one list remains.

This is similar to merging multiple sorted linked lists one by one.
*/

class Solution {
public:

    // Merge two sorted lists using bottom pointers
    Node* merge(Node* &root, Node* &temp) {

        Node* t1 = root;
        Node* t2 = temp;

        Node* dummy = new Node(-1);
        Node* curr = dummy;

        while (t1 != NULL && t2 != NULL) {
            if (t1->data <= t2->data) {
                curr->bottom = t1;
                curr = curr->bottom;
                t1 = t1->bottom;
            }
            else {
                curr->bottom = t2;
                curr = curr->bottom;
                t2 = t2->bottom;
            }
        }

        // Attach remaining nodes
        if (t1)
            curr->bottom = t1;
        else
            curr->bottom = t2;

        // Fix next pointers
        root->next = temp->next;
        temp->next = NULL;

        return dummy->bottom;
    }

    Node* flatten(Node *root) {

        if (root == NULL || root->next == NULL)
            return root;

        // Iteratively merge lists
        while (root->next != NULL) {
            Node* temp = root->next;
            root = merge(root, temp);
        }

        return root;
    }
};
