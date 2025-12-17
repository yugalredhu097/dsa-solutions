// Problem: Merge k Sorted Lists
// Link: https://leetcode.com/problems/merge-k-sorted-lists/
// Approach: Merge all lists into one + Merge Sort on Linked List
// Time Complexity: O(N log N)
// Space Complexity: O(log N)  (recursion stack)

/*
Explanation:
We are given k sorted linked lists and need to merge them into
one sorted linked list.

Approach Used:
1. First, connect all k linked lists into a single linked list.
2. Apply merge sort on the combined list:
   - Find the middle of the list
   - Recursively sort left and right halves
   - Merge two sorted halves

This approach is simple to implement and works efficiently
for large inputs.
*/

class Solution {
public:

    // Merge two sorted linked lists
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        while (head1 != NULL && head2 != NULL) {
            if (head1->val <= head2->val) {
                curr->next = head1;
                curr = curr->next;
                head1 = head1->next;
            } else {
                curr->next = head2;
                curr = curr->next;
                head2 = head2->next;
            }
        }

        if (head1)
            curr->next = head1;
        else
            curr->next = head2;

        return dummy->next;
    }

    // Find middle node of linked list
    ListNode* middlenode(ListNode*& head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Merge sort on linked list
    ListNode* mergesort(ListNode*& head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* left = head;
        ListNode* mid = middlenode(head);
        ListNode* right = mid->next;
        mid->next = NULL;

        left = mergesort(left);
        right = mergesort(right);

        return merge(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Step 1: Combine all lists into one
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        for (int i = 0; i < lists.size(); i++) {
            ListNode* temp = lists[i];
            while (temp != NULL) {
                curr->next = temp;
                curr = curr->next;
                temp = temp->next;
            }
        }

        // Step 2: Sort the combined list
        ListNode* head = dummy->next;
        return mergesort(head);
    }
};
