// Problem: Intersection of Two Linked Lists
// Link: https://leetcode.com/problems/intersection-of-two-linked-lists/
// Approach: Two pointers (switch heads)
// Time Complexity: O(n + m)
// Space Complexity: O(1)

/*
Explanation:
We use two pointers, tA and tB:

1. Move both pointers forward one step at a time.
2. When tA reaches the end of list A, redirect it to headB.
3. When tB reaches the end of list B, redirect it to headA.
4. If the lists intersect, they will meet at the intersection node.
5. If they don't intersect, both will eventually meet at NULL.

Why this works:
- Each pointer travels the same total distance:
    lengthA + lengthB
- So if there is an intersection, they will align at that node.
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tA = headA;
        ListNode* tB = headB;

        while (tA != tB) {
            tA = tA->next;
            tB = tB->next;

            if (tA == tB) return tA;

            if (tA == NULL) tA = headB;
            if (tB == NULL) tB = headA;
        }

        return tA;
    }
};
