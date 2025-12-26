// Problem: Sort Characters By Frequency
// Link: https://leetcode.com/problems/sort-characters-by-frequency/
// Approach: Sorting + frequency counting
// Time Complexity: O(n log n)
// Space Complexity: O(n)

/*
Explanation:
We need to sort characters in a string based on their frequency
in decreasing order.

Approach:
1. Sort the string so identical characters come together.
2. Traverse the sorted string and count frequency of each character.
3. Store (frequency, character) pairs in a vector.
4. Sort this vector by frequency.
5. Build the result string by repeating each character
   according to its frequency (highest frequency first).

This approach is simple and effective for this problem.
*/

class Solution {
public:
    string frequencySort(string s) {

        vector<pair<int, char>> freq;
        int n = s.size();

        // Step 1: Sort the string
        sort(s.begin(), s.end());

        // Step 2: Count frequencies
        int i = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n && s[j] == s[i]) {
                j++;
            }
            freq.push_back({j - i, s[i]});
            i = j;
        }

        // Step 3: Sort by frequency
        sort(freq.begin(), freq.end());

        // Step 4: Build answer
        string ans = "";
        for (int i = freq.size() - 1; i >= 0; i--) {
            ans.append(freq[i].first, freq[i].second);
        }

        return ans;
    }
};
