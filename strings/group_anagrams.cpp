// Problem: Group Anagrams
// Link: https://leetcode.com/problems/group-anagrams/
// Approach: Character frequency hashing + sorting
// Time Complexity: O(n * k + n log n)
// Space Complexity: O(n * 26)

/*
Explanation:
Two strings are anagrams if they have the same frequency
of each character ('a' to 'z').

Approach:
1. For each string, build a frequency array of size 26.
2. Store (frequency_array, original_index) pairs.
3. Sort these pairs so that anagrams come together.
4. Traverse the sorted list and group strings
   having identical frequency arrays.

This avoids sorting individual strings and uses
fixed-size character frequency comparison.
*/

class Solution {
public:

    // Check if two frequency arrays are equal
    bool isequal(int arr1[], int arr2[]) {
        for (int i = 0; i < 26; i++) {
            if (arr1[i] != arr2[i])
                return false;
        }
        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int n = strs.size();
        vector<pair<array<int, 26>, int>> temp;

        // Step 1: Build frequency arrays
        for (int i = 0; i < n; i++) {
            int raw[26] = {0};

            for (char c : strs[i]) {
                raw[c - 'a']++;
            }

            array<int, 26> freq;
            for (int j = 0; j < 26; j++) {
                freq[j] = raw[j];
            }

            temp.push_back({freq, i});
        }

        // Step 2: Sort by frequency array
        sort(temp.begin(), temp.end());

        // Step 3: Group anagrams
        vector<vector<string>> ans;
        int i = 0;

        while (i < n) {
            vector<string> group;
            int j = i + 1;

            while (j < n &&
                   isequal(temp[j - 1].first.data(),
                           temp[j].first.data())) {

                group.push_back(strs[temp[j - 1].second]);
                j++;
            }

            // Add last string of the group
            group.push_back(strs[temp[j - 1].second]);
            ans.push_back(group);

            i = j;
        }

        return ans;
    }
};
