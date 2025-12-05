// Problem: Linked List Cycle
// Link: https://leetcode.com/problems/linked-list-cycle/
// Approach: Floyd's Cycle Detection (fast & slow pointer)
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
We detect if a cycle exists using two pointers:

1. slow moves one step at a time
2. fast moves two steps at a time

If a cycle exists, fast and slow will eventually meet.
If fast reaches NULL (end of list), then no cycle exists.

This approach uses constant space and does not modify the list.
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;
    }
};
