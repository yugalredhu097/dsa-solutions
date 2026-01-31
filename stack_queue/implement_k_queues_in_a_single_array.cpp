// Problem: Implement k Queues in a Single Array
// Link: https://www.geeksforgeeks.org/problems/implement-k-queues-in-a-single-array/1
// Approach: Use vector of queues to simulate k queues
// Time Complexity: O(1) for enqueue and dequeue
// Space Complexity: O(n)

/*
Explanation:
The task is to implement k queues using a single array of size n.
Each queue should support enqueue, dequeue, isEmpty, and isFull operations.

Approach:
1. Maintain a vector of k queues.
2. Track the total number of elements across all queues using `currsize`.
3. `enqueue(x, i)` pushes element x into the i-th queue and increments size.
4. `dequeue(i)` removes and returns front element from the i-th queue.
5. `isEmpty(i)` checks if the i-th queue is empty.
6. `isFull()` checks if total elements equal the maximum allowed size.

This approach provides constant-time operations and is easy to implement.
*/

class kQueues {
public:
    vector<queue<int>> q;
    int maxsize = 0;
    int currsize = 0;

    kQueues(int n, int k) {
        maxsize = n;
        currsize = 0;
        q = vector<queue<int>>(k, queue<int>());
    }

    void enqueue(int x, int i) {
        q[i].push(x);
        currsize++;
    }

    int dequeue(int i) {
        if (!q[i].empty()) {
            int val = q[i].front();
            q[i].pop();
            currsize--;
            return val;
        }
        return -1;
    }

    bool isEmpty(int i) {
        return q[i].empty();
    }

    bool isFull() {
        return currsize == maxsize;
    }
};
