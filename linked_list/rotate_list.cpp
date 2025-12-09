// Problem: Rotate List
// Link: https://leetcode.com/problems/rotate-list/
// Approach: Length calculation + break & reconnect
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
We want to rotate a linked list to the right by k positions.

Example:
1 -> 2 -> 3 -> 4 -> 5, k = 2
Result:
4 -> 5 -> 1 -> 2 -> 3

Steps:
1. Count the length of the list (n).
2. Compute effective rotations: k = k % n.
   If k == 0, return head directly.
3. To rotate:
   - Break the list at position (n - k).
   - newHead = node after the break.
   - Last node of newHead should connect back to old head.
4. Return newHead.

This approach rotates list in one pass (after counting length)
and uses O(1) extra memory.
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == NULL || head->next == NULL) 
            return head;

        // Step 1: Count the length of the list
        ListNode* temp = head;
        int cnt = 0;

        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }

        // Step 2: Reduce k
        k = k % cnt;
        if (k == 0) return head;

        // Step 3: Find the break point (cnt - k)
        int breakPos = cnt - k;
        int current = 0;
        ListNode* node = head;
        ListNode* newHead = nullptr;

        while (node != NULL) {
            current++;

            if (current == breakPos) {
                newHead = node->next;
                node->next = NULL;   // break the list
                break;
            }
            node = node->next;
        }

        // Step 4: Attach the broken part to the front
        temp = newHead;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = head;

        return newHead;
    }
};
