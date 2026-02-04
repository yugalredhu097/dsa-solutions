// Problem: Swap Nodes in Pairs
// Link: https://leetcode.com/problems/swap-nodes-in-pairs/
// Approach: Iterative Linked List Manipulation using Dummy Node
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
Given the head of a singly linked list, the task is to swap every two
adjacent nodes and return the modified list.

Approach:
1. Use a dummy node to simplify edge cases.
2. Maintain three pointers:
   - prev: points to the node before the current pair
   - curr: first node of the pair
   - nextnode: second node of the pair
3. Swap the two nodes by adjusting pointers.
4. Move pointers forward to process the next pair.

This approach swaps nodes in-place without modifying node values.
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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* dummy = new ListNode(-1, head);
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != NULL && curr->next != NULL) {
            ListNode* nextnode = curr->next;

            // Swapping
            curr->next = nextnode->next;
            nextnode->next = curr;
            prev->next = nextnode;

            // Move pointers forward
            prev = curr;
            curr = curr->next;
        }

        return dummy->next;
    }
};
