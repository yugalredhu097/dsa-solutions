// Problem: Implement Queue using Stacks
// Link: https://leetcode.com/problems/implement-queue-using-stacks/
// Approach: Two Stacks
// Time Complexity:
//   push  -> O(1)
//   pop   -> Amortized O(1)
//   peek  -> Amortized O(1)
// Space Complexity: O(n)

/*
Explanation:
We use two stacks:
- s1: used for push operations
- s2: used for pop and peek operations

Idea:
1. Push elements directly into s1.
2. For pop/peek:
   - If s2 is not empty, use it directly.
   - Otherwise, move all elements from s1 to s2.
     This reverses the order and gives queue behavior.
3. Empty when both stacks are empty.

This ensures amortized constant time operations.
*/

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;

    MyQueue() {}

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();
        s2.pop();
        return val;
    }

    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

