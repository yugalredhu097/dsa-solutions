// Problem: Prefix to Infix Conversion
// Link: https://www.geeksforgeeks.org/problems/prefix-to-infix-conversion/1
// Approach: Stack-based expression conversion
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
To convert a prefix expression to infix:

Steps:
1. Traverse the prefix expression from right to left.
2. If the character is an operand, push it onto the stack.
3. If the character is an operator:
   - Pop two operands from the stack.
   - Form a new infix expression:
       (operand1 operator operand2)
   - Push the new expression back onto the stack.
4. The final element in the stack is the infix expression.

Parentheses are added to preserve operator precedence.
*/

class Solution {
  public:
    string preToInfix(string pre_exp) {

        stack<string> st;

        // Traverse from right to left
        for (int i = pre_exp.size() - 1; i >= 0; i--) {

            // Operand
            if ((pre_exp[i] >= 'a' && pre_exp[i] <= 'z') ||
                (pre_exp[i] >= 'A' && pre_exp[i] <= 'Z') ||
                (pre_exp[i] >= '0' && pre_exp[i] <= '9')) {

                string temp = "";
                temp += pre_exp[i];
                st.push(temp);
            }
            // Operator
            else {
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();

                string converted = "(" + op1 + pre_exp[i] + op2 + ")";
                st.push(converted);
            }
        }

        return st.top();
    }
};
