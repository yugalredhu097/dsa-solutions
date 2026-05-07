// Problem: BFS Traversal
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/
// Approach: Breadth First Search (BFS) using Queue
// Time Complexity: O(V + E)
// Space Complexity: O(V)

/*
Explanation:

We are given an adjacency list of a graph.

Goal:
Return BFS traversal starting from node 0.

------------------------------------------------

Key Idea:

- Use a queue to process nodes level by level
- Mark nodes as visited to avoid revisiting

------------------------------------------------

Steps:

1. Initialize visited array
2. Push starting node (0) into queue
3. While queue is not empty:
   - Pop front node
   - Add it to answer
   - Push all unvisited neighbors

------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        
        vector<int> visited(adj.size(), 0);
        queue<int> q;
        vector<int> ans;

        visited[0] = 1;
        q.push(0);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(int neighbor : adj[node]){
                if(!visited[neighbor]){
                    visited[neighbor] = 1;
                    q.push(neighbor);
                }
            }
        }

        return ans;
    }
};