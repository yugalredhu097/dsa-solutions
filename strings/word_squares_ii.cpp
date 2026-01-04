// Problem: Word Squares II
// Link: https://leetcode.com/problems/word-squares/
// Approach: Brute Force + Backtracking
// Time Complexity: O(n! * L) (n = number of words, L = word length)
// Space Complexity: O(n)

/*
Explanation:
We need to form all valid word squares using the given words.
A word square is valid if:
- The first row equals the first column
- The second row equals the second column, and so on

Since each word has fixed length (4 here), we:
1. Try all permutations of 4 different words using backtracking.
2. Once we select 4 words, we check if they form a valid word square.
3. If valid, add it to the answer.

This solution uses brute force with pruning via validation.
*/

class Solution {
public:

    // Check if the selected 4 words form a valid word square
    bool isvalid(vector<string>& temp) {
        string top = temp[0];
        string left = temp[1];
        string right = temp[2];
        string bottom = temp[3];

        if (top[0] != left[0]) return false;
        if (top[3] != right[0]) return false;
        if (bottom[0] != left[3]) return false;
        if (bottom[3] != right[3]) return false;

        return true;
    }

    // Generate permutations of 4 words
    void bruteforce(vector<vector<string>>& ans,
                    vector<string>& words,
                    vector<string>& temp,
                    vector<int>& used) {

        if (temp.size() == 4) {
            if (isvalid(temp))
                ans.push_back(temp);
            return;
        }

        for (int i = 0; i < words.size(); i++) {
            if (used[i]) continue;

            used[i] = 1;
            temp.push_back(words[i]);

            bruteforce(ans, words, temp, used);

            temp.pop_back();
            used[i] = 0;
        }
    }

    vector<vector<string>> wordSquares(vector<string>& words) {

        vector<vector<string>> ans;
        vector<string> temp;
        vector<int> used(words.size(), 0);

        sort(words.begin(), words.end()); // optional ordering

        bruteforce(ans, words, temp, used);
        return ans;
    }
};
