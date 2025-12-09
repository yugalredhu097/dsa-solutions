// Problem: Delete all occurrences of a given key in a Doubly Linked List
// Link: https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1
// Approach: Traverse & delete nodes in-place
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
We traverse the doubly linked list and remove every node whose value is equal to x.

For each matching node:
1. If it is the head, update head_ref to head->next.
2. Update next->prev to skip the deleted node.
3. Update prev->next similarly.
4. Delete the node safely and continue traversal.

Doubly linked list allows O(1) deletion because
we have access to both next and prev pointers.
*/

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {

        Node* temp = *head_ref;

        // Traverse the list
        while (temp != NULL) {

            if (temp->data == x) {

                // Step 1: Update head if needed
                if (temp == *head_ref) {
                    *head_ref = temp->next;
                }

                // Step 2: Update pointers around the node
                Node* nextnode = temp->next;
                Node* prevnode = temp->prev;

                if (nextnode != NULL)
                    nextnode->prev = prevnode;

                if (prevnode != NULL)
                    prevnode->next = nextnode;

                // Step 3: Delete current node
                delete temp;

                // Move to next safely
                temp = nextnode;
            }
            else {
                temp = temp->next;
            }
        }
    }
};
