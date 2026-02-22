// Problem: Check Digitorial Permutation
// Link: https://leetcode.com/problems/check-digitorial-permutation/
// Approach: Digit Factorial Sum + Sorting
// Time Complexity: O(d log d) where d is number of digits
// Space Complexity: O(1)

/*
Explanation:
A number is a digitorial permutation if:
- We compute the sum of factorials of its digits
- The digits of the original number and the resulting sum
  are permutations of each other

Approach:
1. Precompute factorials of digits 0–9.
2. Compute the sum of factorials of digits of the given number.
3. Convert both numbers to strings.
4. If their lengths differ, return false.
5. Sort both strings and compare them.

If they match, the number is a digitorial permutation.
*/

class Solution {
public:
    bool isDigitorialPermutation(int n) {
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        mpp[1] = 1;
        mpp[2] = 2;
        mpp[3] = 6;
        mpp[4] = 24;
        mpp[5] = 120;
        mpp[6] = 720;
        mpp[7] = 5040;
        mpp[8] = 40320;
        mpp[9] = 362880;

        int sum = 0;
        int k = n;

        // Sum of factorials of digits
        while (k > 0) {
            sum += mpp[k % 10];
            k /= 10;
        }

        string s = to_string(n);
        string t = to_string(sum);

        if (s.size() != t.size()) return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};