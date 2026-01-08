// Problem: Infix to Prefix Conversion
// Link: https://www.geeksforgeeks.org/problems/infix-to-prefix-conversion/1
// Approach: Reverse + Stack-based parsing
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
To convert an infix expression to prefix:

Steps:
1. Reverse the infix expression.
2. Replace '(' with ')' and vice versa.
3. Convert the modified expression to postfix.
4. Reverse the postfix expression to get prefix.

Operator Precedence:
^   -> 3 (right associative)
* / -> 2
+ - -> 1
*/

class Solution {
  public:

    // Reverse a string
    void reverse(string &st) {
        int s = 0, e = st.size() - 1;
        while (s < e) {
            swap(st[s++], st[e--]);
        }
    }

    // Operator precedence
    int prio(char c) {
        if (c == '^') return 3;
        if (c == '*' || c == '/') return 2;
        if (c == '+' || c == '-') return 1;
        return -1;
    }

    string infixToPrefix(string &s) {

        // Step 1: Reverse infix expression
        reverse(s);

        // Step 2: Replace brackets
        for (char &c : s) {
            if (c == '(') c = ')';
            else if (c == ')') c = '(';
        }

        stack<char> st;
        string ans = "";

        // Step 3: Convert to postfix
        for (int i = 0; i < s.size(); i++) {

            // Operand
            if ((s[i] >= 'a' && s[i] <= 'z') ||
                (s[i] >= 'A' && s[i] <= 'Z') ||
                (s[i] >= '0' && s[i] <= '9')) {
                ans += s[i];
            }
            // Opening bracket
            else if (s[i] == '(') {
                st.push(s[i]);
            }
            // Closing bracket
            else if (s[i] == ')') {
                while (!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                if (!st.empty())
                    st.pop();
            }
            // Operator
            else {
                if (s[i] == '^') {
                    while (!st.empty() && st.top() != '(' &&
                           prio(s[i]) <= prio(st.top())) {
                        ans += st.top();
                        st.pop();
                    }
                }
                else {
                    while (!st.empty() && st.top() != '(' &&
                           prio(s[i]) < prio(st.top())) {
                        ans += st.top();
                        st.pop();
                    }
                }
                st.push(s[i]);
            }
        }

        // Pop remaining operators
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        // Step 4: Reverse postfix to get prefix
        reverse(ans);
        return ans;
    }
};
