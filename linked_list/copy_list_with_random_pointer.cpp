// Problem: Copy List with Random Pointer
// Link: https://leetcode.com/problems/copy-list-with-random-pointer/description/
// Approach: Interweaving nodes (no extra space)
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
We need to create a deep copy of a linked list where each node has:
- next pointer
- random pointer (may point anywhere or be null)

We use the optimal O(1) space method (3 passes):

PASS 1: Clone nodes and interleave them with original list.
Example:
Original: A -> B -> C
Becomes:  A -> A' -> B -> B' -> C -> C'

PASS 2: Set random pointers of cloned nodes.
If temp->random exists:
    temp->next->random = temp->random->next

PASS 3: Detach the cloned list from the original.
Split into:
Original: A -> B -> C
Clone:    A' -> B' -> C'

This gives a deep copied list without using a hash map.
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;

        Node* temp = head;

        // PASS 1: Clone nodes and interleave them
        while (temp != NULL) {
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = copy->next;
        }

        // PASS 2: Assign random pointers to the cloned nodes
        temp = head;
        while (temp != NULL) {
            if (temp->random)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }

        // PASS 3: Separate the cloned list from original
        temp = head;
        Node* newhead = head->next;

        while (temp != NULL) {
            Node* copy = temp->next;
            temp->next = copy->next;

            if (copy->next != NULL)
                copy->next = copy->next->next;
            else
                copy->next = NULL;

            temp = temp->next;
        }

        return newhead;
    }
};
