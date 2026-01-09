// Problem: Postfix to Infix Conversion
// Link: https://www.geeksforgeeks.org/problems/postfix-to-infix-conversion/1
// Approach: Stack-based expression conversion
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
To convert a postfix expression to infix:

Steps:
1. Traverse the postfix expression from left to right.
2. If the character is an operand, push it onto the stack.
3. If the character is an operator:
   - Pop two operands from the stack.
   - Form a new infix expression:
       (operand2 operator operand1)
   - Push the new expression back onto the stack.
4. The final element in the stack is the infix expression.

Parentheses are added to preserve correct precedence.
*/

class Solution {
  public:
    string postToInfix(string &exp) {

        stack<string> st;

        for (int i = 0; i < exp.size(); i++) {

            // Operand
            if ((exp[i] >= 'a' && exp[i] <= 'z') ||
                (exp[i] >= 'A' && exp[i] <= 'Z') ||
                (exp[i] >= '0' && exp[i] <= '9')) {

                string temp = "";
                temp += exp[i];
                st.push(temp);
            }
            // Operator
            else {
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();

                string converted = "(" + op2 + exp[i] + op1 + ")";
                st.push(converted);
            }
        }

        return st.top();
    }
};
