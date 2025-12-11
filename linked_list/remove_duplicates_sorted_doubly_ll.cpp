// Problem: Remove duplicates from a sorted Doubly Linked List
// Link: https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1
// Approach: Traverse once, delete duplicate nodes in-place
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
Given a sorted doubly linked list, duplicates will be adjacent.
So we traverse the list and delete nodes where:

    temp->data == temp->next->data

Steps:
1. If list is empty or has only one node, return.
2. Traverse with pointer 'temp'.
3. If current node equals next node:
     - Fix prev and next pointers around the duplicate node.
     - Delete the duplicate node.
     - Continue from the next node.
4. Otherwise simply move temp forward.

Because DLL supports O(1) deletion (due to prev pointer),
the entire removal works efficiently in O(n).
*/

class Solution {
  public:
    Node* removeDuplicates(Node *head) {

        if (head == NULL || head->next == NULL)
            return head;

        Node* temp = head;

        while (temp->next != NULL) {

            Node* nextnode = temp->next;

            if (temp->data == nextnode->data) {

                // If deleting head, move head forward
                if (temp == head) {
                    head = nextnode;
                }

                // Fix pointers around the duplicate
                nextnode->prev = temp->prev;
                if (temp->prev)
                    temp->prev->next = nextnode;

                delete temp;
                temp = nextnode;
            }
            else {
                temp = temp->next;
            }
        }

        return head;
    }
};
