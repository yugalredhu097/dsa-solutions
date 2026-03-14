// Problem: The k-th Lexicographical String of All Happy Strings of Length n
// Link: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/
// Approach: Backtracking / Recursion
// Time Complexity: O(3^n)
// Space Complexity: O(n)

/*
Explanation:

A happy string is a string that:
1. Consists only of characters 'a', 'b', 'c'
2. No two adjacent characters are the same

Example:
Valid: "ab", "abc", "aca"
Invalid: "aa", "bb", "cc"

Goal:
Return the k-th lexicographical happy string of length n.
If fewer than k happy strings exist, return "".

------------------------------------------------

Approach: Backtracking

We generate all possible happy strings using recursion.

Steps:

1. Build the string character by character.
2. At each step try characters: 'a', 'b', 'c'.
3. Only add a character if it is different from
   the previous character.
4. When the string length becomes n:
      increase the counter.
5. If the counter equals k, store the answer.

To optimize:
Once we find the answer, we stop further recursion.

------------------------------------------------

Example:

n = 3

Possible happy strings:
abc
aba
aca
acb
bab
bac
bca
bcb
cab
cac
cba
cbc

Return the k-th one.
*/

class Solution {
public:

    int cnt = 0;
    string ans = "";

    void backtrack(int n, int k, string &curr) {

        if (curr.size() == n) {
            cnt++;

            if (cnt == k)
                ans = curr;

            return;
        }

        for (char c : {'a','b','c'}) {

            if (curr.empty() || curr.back() != c) {

                curr.push_back(c);

                backtrack(n, k, curr);

                curr.pop_back();

                if (!ans.empty())
                    return;
            }
        }
    }

    string getHappyString(int n, int k) {

        string curr = "";

        backtrack(n, k, curr);

        return ans;
    }
};