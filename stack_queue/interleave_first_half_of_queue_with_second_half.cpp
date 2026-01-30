// Problem: Interleave the First Half of the Queue with Second Half
// Link: https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1
// Approach: Split queue into two halves and interleave
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
Given a queue with an even number of elements, the task is to
interleave the first half of the queue with the second half.

Example:
Input Queue:  1 2 3 4
Output Queue: 1 3 2 4

Approach:
1. Split the queue into two equal halves.
2. Store the first half in `firstHalf` queue.
3. Store the second half in `secondHalf` queue.
4. Push elements alternately from firstHalf and secondHalf
   back into the original queue.

This maintains the relative order while interleaving.
*/

class Solution {
public:
    void rearrangeQueue(queue<int> &q) {
        int n = q.size();

        queue<int> firstHalf;
        queue<int> secondHalf;

        // Store first half
        for (int i = 0; i < n / 2; i++) {
            firstHalf.push(q.front());
            q.pop();
        }

        // Store second half
        for (int i = 0; i < n / 2; i++) {
            secondHalf.push(q.front());
            q.pop();
        }

        // Interleave both halves
        while (!firstHalf.empty() && !secondHalf.empty()) {
            q.push(firstHalf.front());
            firstHalf.pop();

            q.push(secondHalf.front());
            secondHalf.pop();
        }
    }
};
