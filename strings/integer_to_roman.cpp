// Problem: Integer to Roman
// Link: https://leetcode.com/problems/integer-to-roman/
// Approach: Greedy conversion using Roman numeral rules
// Time Complexity: O(1)
// Space Complexity: O(1)

/*
Explanation:
We convert the given integer into a Roman numeral by repeatedly
matching the largest possible Roman value.

Roman numeral rules handled:
- Subtractive cases like 900 (CM), 400 (CD), 90 (XC), 40 (XL),
  9 (IX), and 4 (IV)
- Standard symbols like M, D, C, L, X, V, I

At each step:
1. Append the corresponding Roman symbol(s).
2. Reduce the number accordingly.
3. Repeat until the number becomes 0.
*/

class Solution {
public:
    string intToRoman(int num) {

        string ans = "";

        while (num > 0) {

            if (num >= 1000) {
                ans += 'M';
                num -= 1000;
            }
            else if (num >= 900) {
                ans += "CM";
                num -= 900;
            }
            else if (num >= 500) {
                ans += 'D';
                num -= 500;
            }
            else if (num >= 400) {
                ans += "CD";
                num -= 400;
            }
            else if (num >= 100) {
                ans += 'C';
                num -= 100;
            }
            else if (num >= 90) {
                ans += "XC";
                num -= 90;
            }
            else if (num >= 50) {
                ans += 'L';
                num -= 50;
            }
            else if (num >= 40) {
                ans += "XL";
                num -= 40;
            }
            else if (num >= 10) {
                ans += 'X';
                num -= 10;
            }
            else if (num >= 9) {
                ans += "IX";
                num -= 9;
            }
            else if (num >= 5) {
                ans += 'V';
                num -= 5;
            }
            else if (num >= 4) {
                ans += "IV";
                num -= 4;
            }
            else {
                ans += 'I';
                num -= 1;
            }
        }

        return ans;
    }
};
