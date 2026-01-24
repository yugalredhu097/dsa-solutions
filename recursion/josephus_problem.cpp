// Problem: Josephus Problem (GeeksforGeeks)
// Link: https://www.geeksforgeeks.org/problems/josephus-problem/1
// Approach: Recursion (Josephus recurrence relation)
// Time Complexity: O(n)
// Space Complexity: O(n) (recursive stack)

/*
Explanation:
The Josephus problem follows a recurrence relation:

Let f(n, k) be the position (0-based) of the survivor.
- Base case: f(1, k) = 0
- Recursive case: f(n, k) = (f(n-1, k) + k) % n

Since the problem expects a 1-based index,
we return f(n, k) + 1.
*/

class Solution {
public:
    int recursion(int n, int k) {
        if (n == 1) return 0;
        return (recursion(n - 1, k) + k) % n;
    }

    int josephus(int n, int k) {
        return recursion(n, k) + 1;
    }
};
