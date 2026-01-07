// Problem: Implement Stack using Queues
// Link: https://leetcode.com/problems/implement-stack-using-queues/
// Approach: Single Queue Rotation
// Time Complexity:
//   push  -> O(n)
//   pop   -> O(1)
//   top   -> O(1)
// Space Complexity: O(n)

/*
Explanation:
We implement a stack (LIFO) using a single queue.

Key Idea:
- When pushing an element, first push it into the queue.
- Then rotate the queue so that the newly added element
  comes to the front.
- This ensures that the front of the queue always represents
  the top of the stack.

Operations:
1. push(x):
   - Push x into the queue.
   - Rotate the queue size-1 times.
2. pop():
   - Remove and return the front element.
3. top():
   - Return the front element.
4. empty():
   - Check if the queue is empty.
*/

class MyStack {
public:
    queue<int> q;

    MyStack() {}

    void push(int x) {
        int size = q.size();
        q.push(x);

        // Rotate the queue
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if (q.empty())
            return -1;

        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        if (q.empty())
            return -1;

        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
