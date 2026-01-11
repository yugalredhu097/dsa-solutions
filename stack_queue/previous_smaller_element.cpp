// Problem: Previous Smaller Element
// Link: https://www.geeksforgeeks.org/problems/previous-smaller-element-1587115620/1
// Approach: Monotonic Increasing Stack
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
For each element in the array, we need to find the nearest
smaller element on its left side.

Approach:
1. Traverse the array from left to right.
2. Maintain a monotonic increasing stack.
3. Pop elements from the stack that are greater than or equal
   to the current element.
4. After popping:
   - If stack is empty → no smaller element exists → -1
   - Otherwise → top of stack is the previous smaller element
5. Push the current element onto the stack.
*/

class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {

        int n = arr.size();
        vector<int> pse(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }

            pse[i] = st.empty() ? -1 : st.top();

            st.push(arr[i]);
        }

        return pse;
    }
};
