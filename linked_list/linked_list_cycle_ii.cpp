// Problem: Linked List Cycle II
// Link: https://leetcode.com/problems/linked-list-cycle-ii/
// Approach: Floyd's Cycle Detection + reset pointer
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
We use Floyd's Cycle Detection in two phases:

1. Detect if a cycle exists:
   - Use slow (1 step) and fast (2 steps) pointers.
   - If they meet, a cycle is confirmed.

2. Find the start of the cycle:
   - Move slow pointer back to head.
   - Then move both slow and fast one step at a time.
   - The point where they meet is the node where the cycle begins.

Why this works:
The distance from head to cycle start is equal to the distance from 
meeting point to cycle start when both pointers move at same speed.
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        // Phase 1: Detect cycle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Phase 2: Find cycle start
                slow = head;

                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow; // start of cycle
            }
        }

        return NULL; // no cycle
    }
};
