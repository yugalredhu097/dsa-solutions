// Problem: Find Smallest Letter Greater Than Target
// Link: https://leetcode.com/problems/find-smallest-letter-greater-than-target/
// Approach: Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(1)

/*
Explanation:
Given a sorted array of characters `letters` and a target character,
we need to find the smallest character in the array that is strictly
greater than the target.

The array is considered circular, meaning if no character is greater
than the target, we return the first character of the array.

Approach:
1. Convert characters to numeric form for easy comparison.
2. Use binary search to find the smallest index where
   letters[mid] > target.
3. If such an index exists, return that character.
4. Otherwise, return the first character (wrap-around case).

Binary search ensures an efficient solution.
*/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<int> temp;

        // Convert letters to integer values
        for (int i = 0; i < letters.size(); i++) {
            temp.push_back(letters[i] - 'a');
        }

        int t = target - 'a';
        int idx = -1;
        int s = 0, e = temp.size() - 1;

        // Binary search
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (temp[mid] > t) {
                idx = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        // Wrap-around case
        return (idx == -1) ? letters[0] : letters[idx];
    }
};
