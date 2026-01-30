// Problem: Letter Combinations of a Phone Number
// Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Approach: Backtracking (Recursion)
// Time Complexity: O(4^n) where n = number of digits
// Space Complexity: O(n) (recursive stack, excluding output)

/*
Explanation:
Each digit from 2 to 9 maps to a set of characters like on a phone keypad.
We need to generate all possible strings such that one character is chosen
from each digit in order.

Approach:
1. Use a recursive backtracking function.
2. At each index, get the corresponding characters for the digit.
3. Try each character, add it to a temporary string, and recurse.
4. Once the length of the temporary string equals the number of digits,
   add it to the answer list.
5. Backtrack by removing the last character to explore other combinations.

This ensures all possible combinations are explored.
*/

class Solution {
public:
    void allcombinations(
        vector<string>& ans,
        string& temp,
        string& digits,
        unordered_map<char, string>& mpp,
        int idx
    ) {
        // Base case: combination complete
        if (idx == digits.size()) {
            ans.push_back(temp);
            return;
        }

        string letters = mpp[digits[idx]];
        for (int j = 0; j < letters.size(); j++) {
            temp.push_back(letters[j]);
            allcombinations(ans, temp, digits, mpp, idx + 1);
            temp.pop_back(); // backtracking
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        unordered_map<char, string> mpp;
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";

        vector<string> ans;
        string temp;
        allcombinations(ans, temp, digits, mpp, 0);
        return ans;
    }
};
