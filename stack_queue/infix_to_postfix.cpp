// Problem: Infix to Postfix Conversion
// Link: https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1
// Approach: Stack-based expression parsing
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
We convert an infix expression to postfix using a stack.

Rules:
1. Operands are added directly to the output.
2. '(' is pushed to the stack.
3. ')' pops operators until '(' is found.
4. Operators are handled based on precedence:
   - Higher precedence operators are popped first.
   - '^' is right-associative.

Operator Precedence:
^  -> 3
* / -> 2
+ - -> 1
*/

class Solution {
public:

    int prio(char c) {
        if (c == '^') return 3;
        if (c == '*' || c == '/') return 2;
        if (c == '+' || c == '-') return 1;
        return -1;
    }

    string infixToPostfix(string& s) {

        stack<char> st;
        string ans = "";

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
                    st.pop(); // remove '('
            }
            // Operator
            else {
                while (!st.empty() && st.top() != '(' &&
                      ((prio(s[i]) < prio(st.top())) ||
                      (prio(s[i]) == prio(st.top()) && s[i] != '^'))) {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }

        // Pop remaining operators
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};
