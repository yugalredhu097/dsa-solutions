// Problem: Middle of the Linked List
// Link: https://leetcode.com/problems/middle-of-the-linked-list/
// Approach: Fast and Slow Pointer
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
We use two pointers:
- slow moves one step at a time
- fast moves two steps at a time

When fast reaches the end of the list, slow will be at the middle.

This works for:
- Odd length lists (middle node)
- Even length lists (second middle node, as required by problem)
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};
