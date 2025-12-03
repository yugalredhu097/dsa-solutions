// Problem: Palindrome Linked List
// Link: https://leetcode.com/problems/palindrome-linked-list/
// Approach: Two pointer + reverse second half
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
1. Use fast and slow pointers to find the middle of the linked list.
2. Reverse the second half of the list.
3. Compare the first half and the reversed second half:
   - If all values match, it's a palindrome.
4. Restore the linked list by reversing the second half again (important).
5. Return true/false based on comparison.

This method uses O(1) extra space because we reverse pointers in place.
*/

class Solution {
public:
    // Reverse a linked list recursively
    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* newhead = reverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        
        return newhead;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;

        // Step 1: Find middle using slow & fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* newhead = reverse(slow->next);

        // Step 3: Compare first and second halves
        ListNode* first = head;
        ListNode* second = newhead;
        while (second != NULL) {
            if (first->val != second->val) {
                reverse(newhead); // Restore the original list
                return false;
            }
            first = first->next;
            second = second->next;
        }

        // Step 4: Restore list and return result
        reverse(newhead);
        return true;
    }
};
