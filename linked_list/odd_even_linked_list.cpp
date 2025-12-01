// Problem: Odd Even Linked List
// Link: https://leetcode.com/problems/odd-even-linked-list/
// Approach: Two-pointer rearrangement (Odd and Even pointers)
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
We rearrange the nodes so that all odd-indexed nodes come first,
followed by all even-indexed nodes, while preserving their relative order.

- odd pointer tracks nodes at odd positions
- even pointer tracks nodes at even positions
- firsteven stores the head of the even list

We iterate while even and even->next exist:
- Connect odd nodes together
- Connect even nodes together
- Move both pointers forward

Finally, attach the even list at the end of the odd list.
*/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) 
            return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* firsteven = even;

        while (even != NULL && even->next != NULL) {
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }

        odd->next = firsteven;
        return head;
    }
};
