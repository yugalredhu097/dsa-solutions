// Problem: Binary Watch
// Link: https://leetcode.com/problems/binary-watch/
// Approach: Brute Force + Bit Counting
// Time Complexity: O(12 * 60 * log(max(hours, minutes)))
// Space Complexity: O(1)

/*
Explanation:
A binary watch has:
- 4 LEDs for hours (0–11)
- 6 LEDs for minutes (0–59)

Given `turnedOn`, we need to return all possible times
where the total number of set bits (1s) in hour and minute
equals `turnedOn`.

Approach:
1. Try all possible hour values (0 to 11).
2. Try all possible minute values (0 to 59).
3. Count set bits in both hour and minute.
4. If total set bits == turnedOn, format and store the time.
5. Ensure minutes are always printed with two digits.
*/

class Solution {
public:
    int bits(int a, int b) {
        int cntA = 0, cntB = 0;

        while (a > 0) {
            cntA += (a & 1);
            a >>= 1;
        }

        while (b > 0) {
            cntB += (b & 1);
            b >>= 1;
        }

        return cntA + cntB;
    }

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        string temp;

        for (int hour = 0; hour < 12; hour++) {
            for (int minute = 0; minute < 60; minute++) {
                if (bits(hour, minute) == turnedOn) {
                    temp = to_string(hour) + ":";
                    if (minute < 10) temp += "0";
                    temp += to_string(minute);
                    ans.push_back(temp);
                }
            }
        }

        return ans;
    }
};
