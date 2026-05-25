// Problem: Rotting Oranges
// Platform: LeetCode
// Problem ID: 994
// Link: https://leetcode.com/problems/rotting-oranges/
// Approach: Multi-Source BFS
// Time Complexity: O(n * m)
// Space Complexity: O(n * m)

/*
Explanation:

We are given a grid:
- 0 → empty cell
- 1 → fresh orange
- 2 → rotten orange

Goal:
Find minimum time required to rot all oranges.

------------------------------------------------

Key Idea:

All rotten oranges spread rot simultaneously.

This is a classic Multi-Source BFS problem.

------------------------------------------------

Algorithm:

1. Push all rotten oranges into queue
2. Process BFS level by level
3. Each level represents 1 minute
4. Rot adjacent fresh oranges

------------------------------------------------

After BFS:

- If fresh oranges remain → return -1
- Otherwise return total minutes

------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Check if all oranges are rotten
    bool isrotten(vector<vector<int>> &v){

        int found = 0;

        for(int i = 0; i < v.size(); i++){

            for(int j = 0; j < v[0].size(); j++){

                if(v[i][j] == 1)
                    found++;
            }
        }

        return (found == 0);
    }

    // Check if grid contains only empty cells
    bool notfound(vector<vector<int>> &v){

        int zero = 0;

        for(int i = 0; i < v.size(); i++){

            for(int j = 0; j < v[0].size(); j++){

                if(v[i][j] == 0)
                    zero++;
            }
        }

        return (zero == v.size() * v[0].size());
    }

    int orangesRotting(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        int ans = 0;

        queue<pair<int,int>> q;

        // Push all rotten oranges
        for(int i = 0; i < row; i++){

            for(int j = 0; j < col; j++){

                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }

        // Multi-source BFS
        while(!q.empty()){

            int size = q.size();

            for(int l = 1; l <= size; l++){

                int i = q.front().first;
                int j = q.front().second;

                q.pop();

                // Up
                if(i > 0 && grid[i-1][j] == 1){

                    grid[i-1][j] = 2;

                    q.push({i-1, j});
                }

                // Down
                if(i < row-1 && grid[i+1][j] == 1){

                    grid[i+1][j] = 2;

                    q.push({i+1, j});
                }

                // Left
                if(j > 0 && grid[i][j-1] == 1){

                    grid[i][j-1] = 2;

                    q.push({i, j-1});
                }

                // Right
                if(j < col-1 && grid[i][j+1] == 1){

                    grid[i][j+1] = 2;

                    q.push({i, j+1});
                }
            }

            ans++;
        }

        // Special case: all empty cells
        if(notfound(grid))
            return 0;

        return (isrotten(grid)) ? ans - 1 : -1;
    }
};