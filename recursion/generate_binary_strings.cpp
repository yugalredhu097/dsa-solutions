// Problem: Generate Binary Strings
// Link: https://www.geeksforgeeks.org/problems/generate-binary-strings/1
// Approach: Backtracking / Recursion
// Time Complexity: O(2^n)
// Space Complexity: O(n) (recursive stack)

/*
Explanation:
The task is to generate all possible binary strings of length `n`.

Approach:
1. Use recursion to build the string character by character.
2. At each step, try adding:
   - '0'
   - '1'
3. Once the length of the temporary string becomes `n`,
   add it to the result list.
4. Backtrack by removing the last character to explore
   other possibilities.

This backtracking approach ensures all 2^n combinations are generated.
*/

class Solution {
public:
    void allbinary(vector<string>& ans, string& temp, int n) {
        if (temp.size() == n) {
            ans.push_back(temp);
            return;
        }

        // Add '0'
        temp.push_back('0');
        allbinary(ans, temp, n);
        temp.pop_back();

        // Add '1'
        temp.push_back('1');
        allbinary(ans, temp, n);
        temp.pop_back();
    }

    vector<string> binstr(int n) {
        vector<string> ans;
        string temp = "";
        allbinary(ans, temp, n);
        return ans;
    }
};
