// Problem: Number of Provinces
// Platform: LeetCode
// Problem ID: 547
// Link: https://leetcode.com/problems/number-of-provinces/
// Approach: BFS on Adjacency Matrix
// Time Complexity: O(n^2)
// Space Complexity: O(n)

/*
Explanation:

We are given an adjacency matrix:
isConnected[i][j] = 1

Meaning:
city i and city j are directly connected.

Goal:
Find number of connected components (provinces).

------------------------------------------------

Key Idea:

Each province is a connected component.

We traverse all cities:
- If city not visited:
    start BFS
    mark all connected cities
    increment province count

------------------------------------------------

BFS Logic:

1. Push starting node into queue
2. Mark visited
3. Explore all connected neighbors
4. Repeat until queue empty

------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void bfs(
        int node,
        vector<vector<int>> &C,
        vector<int> &visited
    ){

        visited[node] = 1;

        queue<int> q;
        q.push(node);

        while(!q.empty()){

            int curr = q.front();
            q.pop();

            for(int i = 0; i < C[curr].size(); i++){

                if(C[curr][i]){

                    if(!visited[i]){

                        q.push(i);

                        visited[i] = 1;
                    }
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int provinces = 0;

        vector<int> visited(isConnected.size(), 0);

        for(int i = 0; i < isConnected.size(); i++){

            if(!visited[i]){

                bfs(i, isConnected, visited);

                provinces++;
            }
        }

        return provinces;
    }
};