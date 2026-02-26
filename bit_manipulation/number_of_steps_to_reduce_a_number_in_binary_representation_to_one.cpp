// Problem: Number of Steps to Reduce a Number in Binary Representation to One
// Link: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/
// Approach: String Simulation
// Time Complexity: O(n^2) in worst case (due to string modifications)
// Space Complexity: O(n)

/*
Explanation:
Given a binary string representing a number, we repeatedly apply:
1. If the number is even, divide it by 2 (remove last bit).
2. If the number is odd, add 1 to it.

We count the number of steps required to reduce the number to 1.

Approach:
- While the binary string length is greater than 1:
  - If the last bit is '0', remove it (divide by 2).
  - If the last bit is '1', simulate adding 1 by handling carry
    from right to left.
- Count each operation as one step.
*/

class Solution {
public:
    int numSteps(string s) {
        int cnt = 0;

        while (s.size() > 1) {
            // If odd (last bit is 1), add 1
            if (s.back() == '1') {
                int i = s.size() - 1;
                while (i >= 0 && s[i] == '1') {
                    s[i] = '0';
                    i--;
                }
                if (i < 0) {
                    s.insert(s.begin(), '1');
                } else {
                    s[i] = '1';
                }
                cnt++;
            }
            // If even (last bit is 0), divide by 2
            else {
                s.pop_back();
                cnt++;
            }
        }

        return cnt;
    }
};