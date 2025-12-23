// Problem: String to Integer (atoi)
// Link: https://leetcode.com/problems/string-to-integer-atoi/
// Approach: Manual parsing + overflow handling
// Time Complexity: O(n)
// Space Complexity: O(n) (temporary string storage)

/*
Explanation:
We convert a string to a 32-bit signed integer following these rules:

1. Ignore leading whitespaces.
2. Handle optional '+' or '-' sign.
3. Skip leading zeros.
4. Read consecutive digits only.
5. Stop parsing when a non-digit character appears.
6. Clamp the result within 32-bit integer range.

We build the numeric part as a string and then convert it using strtoll
to safely handle large values before clamping.
*/

#include <cstdlib>

class Solution {
public:
    int myAtoi(string s) {

        long long sign = 1;
        string temp = "";
        int i = 0;
        int n = s.size();

        while (i < n) {

            // Skip leading spaces
            while (i < n && s[i] == ' ')
                i++;

            if (i >= n)
                break;

            // Handle positive sign
            if (s[i] == '+') {
                i++;

                if (i >= n) break;

                // Skip leading zeros
                while (i < n && s[i] == '0')
                    i++;

                if (i >= n) break;

                // Invalid character
                if (!isdigit(s[i]))
                    break;

                // Read digits
                while (i < n && isdigit(s[i])) {
                    temp.push_back(s[i]);
                    i++;
                }
                break;
            }

            // Handle negative sign
            if (s[i] == '-') {
                sign = -1;
                i++;

                if (i >= n) break;

                // Skip leading zeros
                while (i < n && s[i] == '0')
                    i++;

                if (i >= n) break;

                if (!isdigit(s[i]))
                    break;

                while (i < n && isdigit(s[i])) {
                    temp.push_back(s[i]);
                    i++;
                }
                break;
            }

            // No sign case
            while (i < n && s[i] == '0')
                i++;

            if (i >= n) break;

            if (!isdigit(s[i]))
                break;

            while (i < n && isdigit(s[i])) {
                temp.push_back(s[i]);
                i++;
            }
            break;
        }

        if (temp.size() == 0)
            return 0;

        long long num = sign * strtoll(temp.c_str(), nullptr, 10);

        if (num > INT_MAX) return INT_MAX;
        if (num < INT_MIN) return INT_MIN;

        return num;
    }
};
