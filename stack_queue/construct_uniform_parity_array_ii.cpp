// Problem: Construct Uniform Parity Array II
// Link: https://leetcode.com/problems/construct-uniform-parity-array-ii/
// Approach: Monotonic Stack + Nearest Smaller Odd Tracking
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:

We are given an array nums.

Goal:
Determine if it is possible to make the array "uniform"
(all elements same parity: either all even or all odd)
based on certain conditions.

------------------------------------------------

Key Idea:

We check two possibilities:
1. Make all elements odd
2. Make all elements even

For this, we need to know for every index:
- nearest smaller odd element on the left
- nearest smaller odd element on the right

We use monotonic stacks to compute:

- nseodd → next smaller odd element index
- pseodd → previous smaller odd element index

------------------------------------------------

Steps:

1. Build nseodd (right side) using stack
2. Build pseodd (left side) using stack

3. Case 1 (make all odd):
   For every even element:
   if it has no smaller odd element on both sides → impossible

4. Case 2 (make all even):
   For every odd element:
   if it has no smaller odd element on both sides → impossible

5. If both cases fail → return false
   else → return true

------------------------------------------------

This approach ensures we efficiently track
valid transformations using monotonic stacks.
*/

class Solution {
public:

    void odd1(vector<int> &nums, vector<int> num) {

        stack<int> st;
        int n = num.size();

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && num[st.top()] > num[i]) {
                st.pop();
            }

            if (st.empty()) nums[i] = n;
            else nums[i] = st.top();

            if (num[i] % 2 != 0)
                st.push(i);
        }
    }

    void odd2(vector<int> &nums, vector<int> num) {

        stack<int> st;
        int n = num.size();

        for (int i = 0; i < n; i++) {

            while (!st.empty() && num[st.top()] > num[i]) {
                st.pop();
            }

            if (st.empty()) nums[i] = n;
            else nums[i] = st.top();

            if (num[i] % 2 != 0)
                st.push(i);
        }
    }

    bool uniformArray(vector<int>& nums1) {

        int n = nums1.size();

        vector<int> nseodd(n);
        odd1(nseodd, nums1);

        vector<int> pseodd(n);
        odd2(pseodd, nums1);

        bool odd = true;
        bool even = true;

        // Case 1: Make all odd
        for (int i = 0; i < n; i++) {

            if (nums1[i] % 2 == 0) {

                if (pseodd[i] == n && nseodd[i] == n) {
                    odd = false;
                    break;
                }
            }
        }

        // Case 2: Make all even
        for (int i = 0; i < n; i++) {

            if (nums1[i] % 2 != 0) {

                if (pseodd[i] == n && nseodd[i] == n) {
                    even = false;
                    break;
                }
            }
        }

        return (even == false && odd == false) ? false : true;
    }
};