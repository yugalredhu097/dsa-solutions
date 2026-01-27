// Problem: Sort a Stack
// Link: https://www.geeksforgeeks.org/problems/sort-a-stack/1
// Approach: Using an auxiliary stack
// Time Complexity: O(n^2)
// Space Complexity: O(n)

/*
Explanation:
We are given a stack and need to sort it in increasing order
using only stack operations.

Approach:
1. Use an auxiliary stack `temp`.
2. Pop elements from the original stack one by one.
3. While the top of `temp` is greater than the current element,
   move elements back to the original stack.
4. Insert the current element into its correct position in `temp`.
5. Finally, assign `temp` back to the original stack.

This works similar to insertion sort but using stacks.
*/

class Solution {
  public:
    void sortStack(stack<int> &st) {

        stack<int> temp;

        while (!st.empty()) {
            int curr = st.top();
            st.pop();

            // Move elements back until correct position is found
            while (!temp.empty() && curr < temp.top()) {
                st.push(temp.top());
                temp.pop();
            }

            temp.push(curr);
        }

        // Assign sorted stack back
        st = temp;
    }
};
