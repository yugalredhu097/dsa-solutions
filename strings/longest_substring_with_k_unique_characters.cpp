// Problem: Longest Substring with Exactly K Unique Characters
// Link: https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
// Approach: Sliding Window + Hash Map
// Time Complexity: O(n)
// Space Complexity: O(k)

/*
Explanation:
Given a string and an integer k, we need to find the length
of the longest substring that contains exactly k unique characters.

Approach:
1. Use the sliding window technique with two pointers (l, r).
2. Maintain a hashmap to store frequency of characters in the window.
3. Expand the window by moving r and updating frequencies.
4. If the number of unique characters exceeds k, shrink the window
   from the left until it becomes <= k.
5. Whenever the number of unique characters equals k,
   update the maximum length.
*/

class Solution {
public:
    int longestKSubstr(string &s, int k) {
        unordered_map<char, int> mpp;
        int l = 0, r = 0;
        int n = s.size();
        int maxi = -1;

        while (r < n) {
            mpp[s[r]]++;

            while (r < n && mpp.size() == k) {
                maxi = max(maxi, r - l + 1);
                r++;
                if (r >= n) break;
                mpp[s[r]]++;
            }

            if (r >= n) break;

            while (mpp.size() > k) {
                mpp[s[l]]--;
                if (mpp[s[l]] == 0)
                    mpp.erase(s[l]);
                l++;
            }

            r++;
        }

        return maxi;
    }
};