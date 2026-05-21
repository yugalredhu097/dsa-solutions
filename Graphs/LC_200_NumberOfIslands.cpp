// Problem: Number of Islands
// Platform: LeetCode
// Problem ID: 200
// Link: https://leetcode.com/problems/number-of-islands/
// Approach: BFS Traversal on Grid
// Time Complexity: O(n * m)
// Space Complexity: O(n * m)

/*
Explanation:

We are given a 2D grid:
- '1' → land
- '0' → water

Goal:
Count number of connected islands.

------------------------------------------------

Key Idea:

Each island is a connected component
in the grid.

We use BFS to traverse all connected
land cells.

------------------------------------------------

BFS Traversal:

From a land cell:
- Visit all 4 directions
- Mark visited cells
- Continue until component fully explored

------------------------------------------------

Algorithm:

1. Traverse entire grid
2. If unvisited land found:
   - increment island count
   - run BFS
3. BFS marks complete island visited

------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void bfs(
        vector<vector<char>> &grid,
        vector<vector<int>> &visited,
        int a,
        int b
    ){

        visited[a][b] = 1;

        queue<pair<int,int>> q;

        q.push({a,b});

        while(!q.empty()){

            int i = q.front().first;
            int j = q.front().second;

            q.pop();

            // Up
            if(i > 0 &&
               grid[i-1][j] != '0' &&
               !visited[i-1][j]){

                q.push({i-1,j});

                visited[i-1][j] = 1;
            }

            // Down
            if(i < grid.size()-1 &&
               grid[i+1][j] != '0' &&
               !visited[i+1][j]){

                q.push({i+1,j});

                visited[i+1][j] = 1;
            }

            // Left
            if(j > 0 &&
               grid[i][j-1] != '0' &&
               !visited[i][j-1]){

                q.push({i,j-1});

                visited[i][j-1] = 1;
            }

            // Right
            if(j < grid[0].size()-1 &&
               grid[i][j+1] != '0' &&
               !visited[i][j+1]){

                q.push({i,j+1});

                visited[i][j+1] = 1;
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int islands = 0;

        vector<vector<int>> visited(
            grid.size(),
            vector<int>(grid[0].size(), 0)
        );

        for(int i = 0; i < grid.size(); i++){

            for(int j = 0; j < grid[0].size(); j++){

                if(grid[i][j] != '0' &&
                   !visited[i][j]){

                    islands++;

                    bfs(grid, visited, i, j);
                }
            }
        }

        return islands;
    }
};