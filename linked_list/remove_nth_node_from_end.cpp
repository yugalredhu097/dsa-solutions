// Problem: Remove Nth Node From End of List
// Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Approach: Length calculation + dummy node
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
1. First, we calculate the length of the linked list.
2. We use a dummy node to handle edge cases (like removing the head).
3. We iterate until we reach the (length - n)th node.
4. Then we delete that node by skipping it in the links.

This avoids multiple passes and keeps memory usage constant.
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return head;

        // Find length of list
        ListNode* temp1 = head;
        int size = 1;
        while (temp1 != NULL) {
            size++;
            temp1 = temp1->next;
        }

        // Use dummy node to handle deleting head
        ListNode* dummynode = new ListNode(-1, head);
        ListNode* prev = dummynode;
        ListNode* curr = prev->next;
        ListNode* nextnode;

        // Traverse and find the node to delete
        while (curr != NULL) {
            size--;
            nextnode = curr->next;

            if (size == n) {
                curr->next = NULL;
                prev->next = nextnode;
                break;
            }

            prev = curr;
            curr = curr->next;
        }

        return dummynode->next;
    }
};
