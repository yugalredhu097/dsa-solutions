// Problem: Rotating the Box
// Platform: LeetCode
// Problem ID: 1861
// Link: https://leetcode.com/problems/rotating-the-box/
// Approach: Simulation (Gravity) + Matrix Rotation
// Time Complexity: O(n * m)
// Space Complexity: O(n * m)

/*
Explanation:

We are given a box represented as a 2D grid:
- '#' → stone
- '*' → obstacle
- '.' → empty

Goal:
Simulate gravity (stones fall to the right),
then rotate the box 90° clockwise.

------------------------------------------------

Key Idea:

Step 1: Apply gravity row-wise

For each row:
- Process segments separated by '*'
- Count number of stones '#'
- Place them at the rightmost side of segment
- Fill remaining with '.'

------------------------------------------------

Step 2: Rotate matrix

For original cell (i, j):
→ New position = (j, row - 1 - i)

------------------------------------------------

Example:

Before:
# . # *

After gravity:
. # # *

Then rotate

------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void update(vector<vector<char>> &mat, int row, int s, int e, int stone){
        for(int i = e - 1; i >= s; i--){
            if(stone > 0){
                mat[row][i] = '#';
                stone--;
            }
            else{
                mat[row][i] = '.';
            }
        }
    }

    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int row = boxGrid.size();
        int col = boxGrid[0].size();

        // Step 1: Apply gravity
        for(int i = 0; i < row; i++){
            int j = 0, k = 0;

            while(k < col){
                int stone = 0;

                while(k < col && boxGrid[i][k] != '*'){
                    if(boxGrid[i][k] == '#') stone++;
                    k++;
                }

                update(boxGrid, i, j, k, stone);

                j = k + 1;
                k++;
            } 
        }

        // Step 2: Rotate the matrix
        vector<vector<char>> ans(col, vector<char>(row));

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                ans[j][row - 1 - i] = boxGrid[i][j];
            }
        }

        return ans;
    }
};