// Problem: Roman to Integer
// Link: https://leetcode.com/problems/roman-to-integer/
// Approach: Hash map + right-to-left traversal
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
Roman numerals follow these rules:
- If a smaller numeral appears before a larger one, it is subtracted.
- Otherwise, values are added normally.

Example:
"IX"  -> 9
"LVIII" -> 58
"MCMXCIV" -> 1994

Approach:
1. Store Roman numeral values in a map.
2. Traverse the string from right to left.
3. If current numeral is smaller than the one to its right,
   subtract it; otherwise, add it.
4. Handle the first character separately if needed.
*/

class Solution {
public:
    int romanToInt(string s) {

        map<char, int> mpp;
        mpp['I'] = 1;
        mpp['V'] = 5;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;

        int num = 0;
        int j = s.size() - 1;

        // Traverse from right to left
        while (j > 0) {
            if (mpp[s[j - 1]] >= mpp[s[j]]) {
                num += mpp[s[j]];
                j--;
            } else {
                num += mpp[s[j]] - mpp[s[j - 1]];
                j -= 2;
            }
        }

        // Add the first character if left
        if (j == 0)
            num += mpp[s[j]];

        return num;
    }
};
