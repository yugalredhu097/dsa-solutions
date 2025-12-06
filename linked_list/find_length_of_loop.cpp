// Problem: Find the Length of Loop
// Link: https://www.geeksforgeeks.org/problems/find-length-of-loop/1
// Approach: Floyd's Cycle Detection + cycle length counting
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
1. Use fast and slow pointers to detect if a loop exists.
2. When fast == slow, a cycle is detected.
3. To find the length of the cycle:
   - Keep a pointer (fast1) at the next node.
   - Move fast1 around the loop until it returns to slow.
   - Count the number of steps taken.

Example:
List: 1 -> 2 -> 3 -> 4 -> 5 -> 3
Loop length = 3 (nodes 3, 4, 5)

This approach does not modify the original list and uses O(1) extra space.
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        if (head == NULL || head->next == NULL)
            return 0;

        Node* slow = head;
        Node* fast = head;

        // Step 1: Detect loop
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow) {
                // Step 2: Count loop length
                int length = 1;
                Node* fast1 = fast->next;

                while (fast1 != fast) {
                    length++;
                    fast1 = fast1->next;
                }

                return length;
            }
        }

        return 0; // no cycle found
    }
};
