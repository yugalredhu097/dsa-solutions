// Problem: Add 1 to a Number Represented as Linked List
// Link: https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1
// Approach: Recursion + carry handling
// Time Complexity: O(n)
// Space Complexity: O(n)  // due to recursion stack

/*
Explanation:
We treat the linked list like a number:

Example:
Input: 1 -> 9 -> 9
Output: 2 -> 0 -> 0

Approach:
1. Use recursion to reach the last node.
2. Add 1 to the last node and propagate carry backward.
3. Each recursive call returns:
   - 0, if no carry is produced
   - 1, if carry must continue
4. If carry persists after reaching the head,
   we add a new node at the front with value 1.

This avoids reversing the list and makes code clean and simple.
*/

class Solution {
public:

    // Recursive function to add 1 from the end
    int helper(Node* temp) {
        if (temp == NULL)
            return 1;  // carry 1 to add at the last node

        int carry = helper(temp->next);

        temp->data = temp->data + carry;

        // If no carry now, propagate 0
        if (temp->data < 10)
            return 0;

        // If carry remains, set current to 0 and propagate 1
        temp->data = 0;
        return 1;
    }

    Node* addOne(Node* head) {
        int carry = helper(head);

        // If carry remains after processing all digits,
        // we need a new head node
        if (carry == 1) {
            Node* newnode = new Node(1);
            newnode->next = head;
            return newnode;
        }

        return head;
    }
};
