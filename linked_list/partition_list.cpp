// Problem: Partition List
// Link: https://leetcode.com/problems/partition-list/
// Approach: Two dummy lists (less than x & greater/equal to x)
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
We need to rearrange the linked list such that:
- All nodes with values < x come before nodes with values >= x
- The relative order of nodes in each partition is preserved

Approach:
1. Create two dummy lists:
   - less list  → nodes with value < x
   - more list  → nodes with value >= x
2. Traverse the original list:
   - Attach nodes to the appropriate list.
3. Connect the less list to the more list.
4. Terminate the more list to avoid cycles.
5. Return the head of the new list.

This method maintains stability and works in-place.
*/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        if (head == NULL || head->next == NULL)
            return head;

        // Dummy heads
        ListNode* lesshead = new ListNode(-1);
        ListNode* morehead = new ListNode(-1);

        ListNode* less = lesshead;
        ListNode* more = morehead;
        ListNode* temp = head;

        // Partition nodes
        while (temp != NULL) {
            if (temp->val < x) {
                less->next = temp;
                less = less->next;
            } else {
                more->next = temp;
                more = more->next;
            }
            temp = temp->next;
        }

        // Combine the two lists
        less->next = morehead->next;
        more->next = NULL;

        return lesshead->next;
    }
};
