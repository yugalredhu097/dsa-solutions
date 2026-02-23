// Problem: Check If a String Contains All Binary Codes of Size K
// Link: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
// Approach: Sliding Window + Hash Set
// Time Complexity: O(n * k)
// Space Complexity: O(2^k)

/*
Explanation:
We need to check whether a string `s` contains every possible
binary code of length `k` as a substring.

Approach:
1. Use a sliding window of size `k` over the string.
2. Insert each substring of length `k` into a hash set.
3. The total number of distinct binary codes of size `k` is 2^k.
4. If the size of the set equals 2^k, all codes are present.

This efficiently checks all possible binary substrings.
*/

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        int n = s.size();

        // Sliding window of size k
        for (int i = 0; i + k <= n; i++) {
            st.insert(s.substr(i, k));
        }

        int binaryCodes = (int)pow(2, k);
        return st.size() == binaryCodes;
    }
};