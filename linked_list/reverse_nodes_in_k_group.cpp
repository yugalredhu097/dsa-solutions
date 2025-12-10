// Problem: Reverse Nodes in k-Group
// Link: https://leetcode.com/problems/reverse-nodes-in-k-group/
// Approach: Check k nodes → cut → reverse → reconnect
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
We reverse the linked list in groups of size k.

Steps:
1. From the current node `temp`, find the k-th node using findkth().
   - If fewer than k nodes remain, stop and return.

2. Detach the group:
      kth->next = NULL

3. Reverse this group using reverse().

4. Connect:
   - If reversing the first group, update head.
   - Otherwise, link previous group's end to the start of reversed group.

5. Move "temp" to the next group and update previous pointer.

This approach ensures:
✔ In-place reversal
✔ Only O(1) additional memory
✔ No recursion, avoids stack overflow
*/

class Solution {
public:

    // Find kth node starting from temp
    ListNode* findkth(ListNode* temp, int k) {
        int cnt = 0;
        while (temp != NULL) {
            cnt++;
            if (cnt == k) break;
            temp = temp->next;
        }
        return temp;
    }

    // Standard reverse linked list
    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* nextnode = nullptr;

        while (curr != NULL) {
            nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevnode = nullptr;

        while (temp != NULL) {

            // Step 1: Find k-th node
            ListNode* kth = findkth(temp, k);
            if (kth == NULL) {                // fewer than k nodes
                if (prevnode) prevnode->next = temp;
                break;
            }

            // Step 2: Detach group
            ListNode* nextnode = kth->next;
            kth->next = NULL;

            // Step 3: Reverse current k-group
            reverse(temp);

            // Step 4: Connect reversed group
            if (temp == head) {
                head = kth;    // new head for first group
            } else {
                prevnode->next = kth;
            }

            // Move prevnode to end of reversed group
            prevnode = temp;

            // Step 5: Move to next group
            temp = nextnode;
        }

        return head;
    }
};
