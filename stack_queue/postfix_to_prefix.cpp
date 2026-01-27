// Problem: Postfix to Prefix Conversion
// Link: https://www.geeksforgeeks.org/problems/postfix-to-prefix-conversion/1
// Approach: Stack-based expression conversion
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
To convert a postfix expression to prefix:

Steps:
1. Traverse the postfix expression from left to right.
2. If the character is an operand, push it onto the stack.
3. If the character is an operator:
   - Pop two operands from the stack.
   - Form a new prefix expression:
       operator + operand2 + operand1
   - Push the new expression back onto the stack.
4. The final element in the stack is the prefix expression.

This works because postfix expressions place operators
after their operands.
*/

class Solution {
  public:
    string postToPre(string post_exp) {

        stack<string> st;

        // Traverse postfix expression
        for (int i = 0; i < post_exp.size(); i++) {

            // Operand
            if ((post_exp[i] >= 'a' && post_exp[i] <= 'z') ||
                (post_exp[i] >= 'A' && post_exp[i] <= 'Z') ||
                (post_exp[i] >= '0' && post_exp[i] <= '9')) {

                string temp = "";
                temp += post_exp[i];
                st.push(temp);
            }
            // Operator
            else {
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();

                string converted = "";
                converted += post_exp[i];
                converted += op2;
                converted += op1;

                st.push(converted);
            }
        }

        return st.top();
    }
};
