// Problem: Sort a linked list of 0s, 1s and 2s
// Link: https://www.geeksforgeeks.org/problems/sort-a-linked-list-of-0s-1s-and-2s/1
// Approach: Three dummy pointer approach (Dutch National Flag idea)
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
We categorize nodes into three separate lists:
- zero list (stores nodes with data = 0)
- one list  (stores nodes with data = 1)
- two list  (stores nodes with data = 2)

Steps:
1. Traverse the original list and append nodes to the respective 0, 1, and 2 lists.
2. Connect the 0 list to the 1 list and then to the 2 list.
3. Handle edge cases (if no 1s or no 2s).
4. Return the head of the combined sorted list.

This method uses three extra dummy nodes but keeps memory constant (O(1)).
*/

class Solution {
public:
    Node* segregate(Node* head) {
        if (head == NULL || head->next == NULL) 
            return head;

        Node* temp = head;

        // Dummy heads for 0, 1, 2 partitions
        Node* zerohead = new Node(-1);
        Node* zero = zerohead;
        Node* onehead = new Node(-1);
        Node* one = onehead;
        Node* twohead = new Node(-1);
        Node* two = twohead;

        // Partition the list
        while (temp != NULL) {
            if (temp->data == 0) {
                zerohead->next = temp;
                zerohead = zerohead->next;
            } 
            else if (temp->data == 1) {
                onehead->next = temp;
                onehead = onehead->next;
            } 
            else {
                twohead->next = temp;
                twohead = twohead->next;
            }
            temp = temp->next;
        }

        // Connect linked lists: 0 -> 1 -> 2
        zerohead->next = (one->next) ? one->next : two->next;
        onehead->next = two->next;
        twohead->next = NULL;

        // The new head is the first real node of zero list
        return zero->next;
    }
};
