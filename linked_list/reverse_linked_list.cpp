// Problem: Reverse Linked List
// Link: https://leetcode.com/problems/reverse-linked-list/
// Approach: Recursive approach
// Time Complexity: O(n)
// Space Complexity: O(n) due to recursion stack

/*
Explanation:
We use recursion to reverse the list.
At each step:
- We store the next node
- Reverse the current node's pointer to point to prev
- Move prev and curr one step forward
- Recursively repeat until curr becomes NULL

Finally, 'prev' will be the new head of the reversed list.
*/

class Solution {
public:
    void reverse(ListNode* &curr, ListNode* &prev) {
        if (curr == NULL) {
            return;
        }

        ListNode* nextnode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextnode;

        return reverse(curr, prev);
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        reverse(curr, prev);
        return prev;
    }
};
