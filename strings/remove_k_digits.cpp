// Problem: Remove K Digits (LeetCode 402)
// Link: https://leetcode.com/problems/remove-k-digits/
// Approach: Monotonic increasing stack (greedy)
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
We want the smallest possible number after removing exactly k digits.

Approach:
- Use a string as a stack.
- Traverse each digit:
  - While the stack is not empty, k > 0, and the last digit in the stack
    is greater than the current digit, pop from the stack.
- Push the current digit.
- If k remains, remove digits from the end.
- Remove leading zeros from the final string.
- If the string becomes empty, return "0".
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        string st = "";

        for (char c : num) {
            while (!st.empty() && k > 0 && st.back() > c) {
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }

        // Remove remaining digits from the end
        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }

        // Remove leading zeros
        int i = 0;
        while (i < st.size() && st[i] == '0') i++;
        st = st.substr(i);

        return st.empty() ? "0" : st;
    }
};
