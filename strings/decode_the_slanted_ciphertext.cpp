// Problem: Decode the Slanted Ciphertext
// Link: https://leetcode.com/problems/decode-the-slanted-ciphertext/
// Approach: Matrix Construction + Diagonal Traversal
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:

We are given:
- encodedText → a string
- rows → number of rows in the matrix

Goal:
Decode the original text by reading diagonally.

------------------------------------------------

Key Idea:

1. The string is written row-wise into a matrix
   with dimensions:
       rows × (n / rows)

2. Then the message is formed by reading diagonals:
   starting from each column of the first row.

------------------------------------------------

Steps:

1. Compute number of columns:
      col = encodedText.size() / rows

2. Fill matrix row-wise.

3. Traverse diagonally:
   For each column j:
      move (i++, j++)

4. Build result string.

5. Remove trailing spaces.

------------------------------------------------

Example:

encodedText = "ch   ie   pr"
rows = 3

Matrix:
c h _
_ i e
_ _ p r

Diagonal traversal gives original text.
*/

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {

        if (encodedText.size() == 0)
            return "";

        int col = encodedText.size() / rows;

        vector<string> mat(rows, string(col, ' '));

        // Fill matrix row-wise
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < col; j++) {
                mat[i][j] = encodedText[i * col + j];
            }
        }

        string ans = "";

        // Traverse diagonally
        for (int j = 0; j < col; j++) {

            int i = 0, k = j;

            while (i < rows && k < col) {
                ans.push_back(mat[i][k]);
                i++;
                k++;
            }
        }

        // Remove trailing spaces
        while (!ans.empty() && ans.back() == ' ')
            ans.pop_back();

        return ans;
    }
};