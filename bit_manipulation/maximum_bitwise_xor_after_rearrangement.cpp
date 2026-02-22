// Problem: Maximum Bitwise XOR After Rearrangement
// Link: https://leetcode.com/problems/maximum-bitwise-xor-after-rearrangement/
// Approach: Greedy + Bit Manipulation
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
We are given two binary strings `s` and `t`.
We are allowed to rearrange string `t` to maximize the bitwise XOR
between `s` and the rearranged version of `t`.

Approach:
1. Count the number of '1's and '0's in string `t`.
2. Traverse string `s`:
   - If s[i] is '0', try to place '1' in t to maximize XOR.
   - If s[i] is '1', try to place '0' in t to maximize XOR.
3. If the preferred bit is unavailable, place the remaining bit.
4. After building the rearranged string `t1`, compute XOR with `s`.

This greedy strategy ensures the maximum possible XOR.
*/

class Solution {
public:
    string maximumXor(string s, string t) {
        string t1 = "";
        int cnt1 = 0, cnt2 = 0;

        // Count 1s and 0s in t
        for (char c : t) {
            if (c == '1') cnt1++;
            else cnt2++;
        }

        // Rearrange t greedily
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                if (cnt1 > 0) {
                    t1.push_back('1');
                    cnt1--;
                } else {
                    t1.push_back('0');
                    cnt2--;
                }
            } else {
                if (cnt2 > 0) {
                    t1.push_back('0');
                    cnt2--;
                } else {
                    t1.push_back('1');
                    cnt1--;
                }
            }
        }

        // Compute XOR result
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            ans.push_back(((s[i] - '0') ^ (t1[i] - '0')) + '0');
        }

        return ans;
    }
};