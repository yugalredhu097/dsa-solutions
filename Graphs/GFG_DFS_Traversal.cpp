// Problem: DFS Traversal
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/
// Approach: Depth First Search (DFS) using Recursion
// Time Complexity: O(V + E)
// Space Complexity: O(V)

/*
Explanation:

We are given an adjacency list of a graph.

Goal:
Return DFS traversal starting from node 0.

------------------------------------------------

Key Idea:

DFS explores as deep as possible before backtracking.

We use:
- visited array → avoid revisiting nodes
- recursion → traverse depth-first

------------------------------------------------

Steps:

1. Mark current node visited
2. Add node to answer
3. Visit all unvisited neighbors recursively

------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    void dfsHelper(
        int node,
        vector<vector<int>> &adj,
        vector<int> &visited,
        vector<int> &ans
    ){

        visited[node] = 1;

        ans.push_back(node);

        for(int neighbor : adj[node]){

            if(!visited[neighbor]){
                dfsHelper(neighbor, adj, visited, ans);
            }
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {

        vector<int> ans;

        vector<int> visited(adj.size(), 0);

        dfsHelper(0, adj, visited, ans);

        return ans;
    }
};