// Problem: Sort List
// Link: https://leetcode.com/problems/sort-list/
// Approach: Merge Sort on Linked List
// Time Complexity: O(n log n)
// Space Complexity: O(log n)  (recursion stack)

/*
Explanation:
We need to sort a singly linked list in O(n log n) time.

The best approach is Merge Sort because:
- Linked lists allow easy splitting using slow & fast pointers
- Merging two sorted lists can be done in O(n)

Steps:
1. Find the middle of the list using slow & fast pointers.
2. Split the list into two halves.
3. Recursively sort both halves.
4. Merge the two sorted halves.

This guarantees O(n log n) time complexity.
*/

class Solution {
public:

    // Find middle node of linked list
    ListNode* middlenode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Merge two sorted linked lists
    ListNode* merge(ListNode* lefthead, ListNode* righthead) {

        ListNode* t1 = lefthead;
        ListNode* t2 = righthead;

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        while (t1 != NULL && t2 != NULL) {
            if (t1->val <= t2->val) {
                curr->next = t1;
                curr = curr->next;
                t1 = t1->next;
            }
            else {
                curr->next = t2;
                curr = curr->next;
                t2 = t2->next;
            }
        }

        // Attach remaining nodes
        if (t1)
            curr->next = t1;
        else
            curr->next = t2;

        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {

        // Base case
        if (head == NULL || head->next == NULL)
            return head;

        // Step 1: Split list
        ListNode* mid = middlenode(head);
        ListNode* lefthead = head;
        ListNode* righthead = mid->next;
        mid->next = NULL;

        // Step 2: Sort halves
        lefthead = sortList(lefthead);
        righthead = sortList(righthead);

        // Step 3: Merge
        return merge(lefthead, righthead);
    }
};
