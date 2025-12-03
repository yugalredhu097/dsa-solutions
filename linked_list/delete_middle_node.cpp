// Problem: Delete the Middle Node of a Linked List
// Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
// Approach: Slow & Fast Pointers (Tortoise and Hare)
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
We use two pointers:
- slow moves one step at a time
- fast moves two steps at a time

When fast reaches the end of the list, slow will be at the middle node.
We also maintain a prev pointer to track the node before slow.

Steps:
1. Traverse the list using fast and slow pointers.
2. When slow reaches the middle, remove it by skipping slow.
3. If the list has only one node, return head->next (NULL).
*/

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (prev) {
            prev->next = slow->next;
        } else {
            head = slow->next;  // only one node case
        }

        return head;
    }
};
