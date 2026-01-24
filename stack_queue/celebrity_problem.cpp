// Problem: The Celebrity Problem (GeeksforGeeks)
// Link: https://www.geeksforgeeks.org/problems/the-celebrity-problem/1
// Approach: Two-pointer elimination
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
A celebrity is someone who:
1. Is known by everyone.
2. Knows no one.

Approach:
- Use two pointers i and j.
- If i knows j, then i cannot be a celebrity → move i forward.
- Else j cannot be a celebrity → move j backward.
- After elimination, verify the candidate by checking:
  - Candidate knows nobody.
  - Everyone knows the candidate.
*/

class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int i = 0, j = n - 1;

        // Step 1: Find potential celebrity
        while (i < j) {
            if (mat[i][j] == 1)
                i++;   // i knows j → i not celebrity
            else
                j--;   // i does not know j → j not celebrity
        }

        // Step 2: Verify candidate i
        for (int k = 0; k < n; k++) {
            if (k != i) {
                if (mat[i][k] == 1 || mat[k][i] == 0)
                    return -1;
            }
        }

        return i;
    }
};
