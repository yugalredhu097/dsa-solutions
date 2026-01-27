// Problem: Maximum Matrix Sum
// Link: https://leetcode.com/problems/maximum-matrix-sum/
// Approach: Greedy + Observation
// Time Complexity: O(n^2)
// Space Complexity: O(1)

/*
Explanation:
We can flip the sign of any element any number of times.
The goal is to maximize the sum of the matrix.

Key Observations:
1. Taking the absolute value of every element gives the maximum possible sum.
2. If the number of negative elements is even:
   - We can make all elements positive.
3. If the number of negative elements is odd:
   - If there is at least one zero, we can still make all elements positive.
   - Otherwise, one element must remain negative.
     In this case, subtract twice the smallest absolute value from the total sum.

Approach:
1. Count negative elements and zero elements.
2. Compute the sum of absolute values.
3. If negatives are odd and no zero exists:
   - Subtract 2 × minimum absolute value.
*/

class Solution {
public:

    long long summation(vector<vector<int>>& matrix) {
        long long sum = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                sum += abs(matrix[i][j]);
            }
        }
        return sum;
    }

    long long maxMatrixSum(vector<vector<int>>& matrix) {

        int cnt = 0;        // count of negative elements
        int zerocnt = 0;    // count of zero elements
        int n = matrix.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] < 0) cnt++;
                if (matrix[i][j] == 0) zerocnt++;
            }
        }

        long long sum = summation(matrix);

        // If odd number of negatives and no zero exists
        if (cnt % 2 != 0 && zerocnt == 0) {

            int mini = INT_MAX;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    mini = min(mini, abs(matrix[i][j]));
                }
            }

            sum -= 2LL * mini;
        }

        return sum;
    }
};
