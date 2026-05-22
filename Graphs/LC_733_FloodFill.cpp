// Problem: Flood Fill
// Platform: LeetCode
// Problem ID: 733
// Link: https://leetcode.com/problems/flood-fill/
// Approach: BFS Traversal on Grid
// Time Complexity: O(n * m)
// Space Complexity: O(n * m)

/*
Explanation:

We are given:
- A 2D image grid
- Starting cell (sr, sc)
- New color

Goal:
Replace all connected cells having
same original color with new color.

------------------------------------------------

Key Idea:

This is a standard BFS/DFS flood fill problem.

Starting from (sr, sc):
- Explore all 4-directionally connected cells
- Only visit cells having original color
- Paint them with new color

------------------------------------------------

BFS Steps:

1. Push starting cell into queue
2. Mark visited
3. Change color
4. Explore neighbors:
   - up
   - down
   - left
   - right

------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> floodFill(
        vector<vector<int>>& image,
        int sr,
        int sc,
        int color
    ) {

        int row = image.size();
        int col = image[0].size();

        vector<vector<int>> visited(
            row,
            vector<int>(col, 0)
        );

        queue<pair<int,int>> q;

        q.push({sr, sc});

        visited[sr][sc] = 1;

        int original = image[sr][sc];

        image[sr][sc] = color;

        while(!q.empty()){

            int i = q.front().first;
            int j = q.front().second;

            q.pop();

            // Up
            if(i > 0 &&
               image[i-1][j] == original &&
               !visited[i-1][j]){

                q.push({i-1, j});

                visited[i-1][j] = 1;

                image[i-1][j] = color;
            }

            // Down
            if(i < row-1 &&
               image[i+1][j] == original &&
               !visited[i+1][j]){

                q.push({i+1, j});

                visited[i+1][j] = 1;

                image[i+1][j] = color;
            }

            // Left
            if(j > 0 &&
               image[i][j-1] == original &&
               !visited[i][j-1]){

                q.push({i, j-1});

                visited[i][j-1] = 1;

                image[i][j-1] = color;
            }

            // Right
            if(j < col-1 &&
               image[i][j+1] == original &&
               !visited[i][j+1]){

                q.push({i, j+1});

                visited[i][j+1] = 1;

                image[i][j+1] = color;
            }
        }

        return image;
    }
};