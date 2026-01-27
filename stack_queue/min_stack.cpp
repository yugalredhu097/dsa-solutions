// Problem: Min Stack
// Link: https://leetcode.com/problems/min-stack/
// Approach: Stack storing (value, current minimum)
// Time Complexity:
//   push  -> O(1)
//   pop   -> O(1)
//   top   -> O(1)
//   getMin -> O(1)
// Space Complexity: O(n)

/*
Explanation:
We need to design a stack that supports retrieving the minimum
element in constant time.

Approach:
- Use a stack of pairs.
- Each element stores:
    {value, minimum_so_far}
- When pushing:
    - If stack is empty, min = value
    - Otherwise, min = min(current value, previous minimum)
- This way, the top of the stack always knows the minimum
  up to that point.
*/

class MinStack {
public:
    stack<pair<int, int>> st;

    MinStack() {}

    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
        } else {
            st.push({val, min(st.top().second, val)});
        }
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
