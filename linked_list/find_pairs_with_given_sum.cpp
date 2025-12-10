// Problem: Find pairs with given sum in Doubly Linked List
// Link: https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1
// Approach: Two-pointer technique on DLL
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
The list is sorted. We must find all unique pairs (a, b) such that:
a + b = target.

Steps:
1. Set `first` pointer at the head.
2. Move `last` pointer to the end of the DLL.
3. Use two-pointer technique:
   - If first->data + last->data == target → store pair, move both pointers.
   - If sum > target → move last backward.
   - If sum < target → move first forward.
4. Continue until first and last cross.

This works in O(n) time because each pointer moves at most n steps.
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {

        vector<pair<int,int>> ans;

        if (head == NULL || head->next == NULL)
            return ans;

        // Pointer to the start
        Node* first = head;

        // Pointer to the end
        Node* last = head;
        while (last->next != NULL) {
            last = last->next;
        }

        // Two-pointer traversal
        while (first->data < last->data) {
            int sum = first->data + last->data;

            if (sum == target) {
                ans.push_back({first->data, last->data});
                first = first->next;
                last = last->prev;
            }
            else if (sum > target) {
                last = last->prev;
            }
            else {
                first = first->next;
            }
        }

        return ans;
    }
};
