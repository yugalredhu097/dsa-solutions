// Problem: Count Valid Parentheses (GeeksforGeeks)
// Link: https://www.geeksforgeeks.org/problems/count-the-number-of-valid-parentheses/1
// Approach: Backtracking / Recursion
// Time Complexity: O(Catalan number)
// Space Complexity: O(n) (recursion stack)

/*
Explanation:
We generate all valid parentheses strings of length n.

Rules:
- We can add '(' if open < n/2
- We can add ')' if close < open
- When the string length becomes n, we count one valid way.
*/

class Solution {
public:
    void validparanthesis(int &cnt, int n, string &temp, int open, int close) {
        if (temp.size() == n) {
            cnt++;
            return;
        }

        if (open < n / 2) {
            temp.push_back('(');
            validparanthesis(cnt, n, temp, open + 1, close);
            temp.pop_back();
        }

        if (close < open) {
            temp.push_back(')');   // ✅ FIXED: should be ')'
            validparanthesis(cnt, n, temp, open, close + 1);
            temp.pop_back();
        }
    }

    int findWays(int n) {
        int cnt = 0;
        string temp = "";
        validparanthesis(cnt, n, temp, 0, 0);
        return cnt;
    }
};
