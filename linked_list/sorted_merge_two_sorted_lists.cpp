// Problem: Merge Two Sorted Linked Lists
// Link: https://www.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1
// Approach: Two-pointer merge using a dummy node
// Time Complexity: O(n + m)
// Space Complexity: O(1)

/*
Explanation:
We are given two sorted linked lists and must merge them into a single
sorted list, maintaining order.

Approach:
1. Use two pointers (temp1, temp2) to traverse both lists.
2. Use a dummy node to simplify list construction.
3. Pick the smaller value at each step and append to the merged list.
4. If one list finishes, append the remaining part of the other list.
5. Return dummy->next as the merged head.

This is identical to the merge step of merge sort.
*/

class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {

        if (head1 == NULL && head2 == NULL) return NULL;
        if (head1 == NULL) return head2;
        if (head2 == NULL) return head1;

        // Dummy node to ease list creation
        Node* dummy = new Node(-1);
        Node* curr = dummy;

        Node* temp1 = head1;
        Node* temp2 = head2;

        // Merge while both lists have elements
        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->data <= temp2->data) {
                curr->next = temp1;
                curr = curr->next;
                temp1 = temp1->next;
            }
            else {
                curr->next = temp2;
                curr = curr->next;
                temp2 = temp2->next;
            }
        }

        // Append remaining nodes
        if (temp1 != NULL)
            curr->next = temp1;
        else
            curr->next = temp2;

        return dummy->next;
    }
};
