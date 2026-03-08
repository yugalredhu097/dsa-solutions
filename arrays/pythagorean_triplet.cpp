// Problem: Pythagorean Triplet
// Link: https://www.geeksforgeeks.org/problems/pythagorean-triplet3018/1
// Approach: Hash Set + Squaring
// Time Complexity: O(n^2)
// Space Complexity: O(n)

/*
Explanation:
A Pythagorean triplet consists of three numbers a, b, c such that:
a² + b² = c²

Approach:
1. Square every number in the array and store the results in a hash set.
2. For every pair (i, j), compute:
      arr[i]^2 + arr[j]^2
3. Check if this sum exists in the set.
4. If it exists, a Pythagorean triplet is found.

Using a hash set allows constant-time lookups.
*/

class Solution {
public:
    bool pythagoreanTriplet(vector<int>& arr) {

        unordered_set<long long> st;

        // Store squares of numbers
        for (int x : arr) {
            st.insert(1LL * x * x);
        }

        // Check all pairs
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {

                long long sum = 1LL * arr[i] * arr[i] +
                                1LL * arr[j] * arr[j];

                if (st.count(sum))
                    return true;
            }
        }

        return false;
    }
};