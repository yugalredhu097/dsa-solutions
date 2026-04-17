// Problem: Remove Duplicates from Sorted List II
// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// Approach: Dummy Node + Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:

We are given a sorted linked list.

Goal:
Delete all nodes that have duplicate values,
leaving only distinct numbers.

------------------------------------------------

Example:

Input:
1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5

Output:
1 -> 2 -> 5

------------------------------------------------

Key Idea:

Since list is sorted,
duplicates appear consecutively.

Use:

1. dummy node:
   Helps handle deletion at head

2. prev:
   Last confirmed unique node

3. curr:
   Current traversal node

------------------------------------------------

Steps:

1. If curr and curr->next have same value:
   - Store duplicate value
   - Skip all nodes with that value
   - Link prev->next to next unique node

2. Else:
   Move prev and curr forward

------------------------------------------------

This removes all repeated values completely.
*/

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != NULL && curr->next != NULL) {

            // Duplicate found
            if (curr->val == curr->next->val) {

                int dup = curr->val;

                while (curr != NULL && curr->val == dup) {
                    curr = curr->next;
                }

                prev->next = curr;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};