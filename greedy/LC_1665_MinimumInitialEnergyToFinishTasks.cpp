// Problem: Minimum Initial Energy to Finish Tasks
// Platform: LeetCode
// Problem ID: 1665
// Link: https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/
// Approach: Greedy Sorting + Binary Search on Answer
// Time Complexity: O(n log n)
// Space Complexity: O(n)

/*
Explanation:

Each task contains:
- actual = energy consumed
- minimum = minimum energy required to start

Goal:
Find minimum initial energy required to complete all tasks.

------------------------------------------------

Key Idea:

For a task:
energy >= minimum

After completing:
energy -= actual

------------------------------------------------

Greedy Observation:

Tasks with larger:
(minimum - actual)

should be performed earlier.

Why?

Because they require larger reserve energy.

------------------------------------------------

Sorting Strategy:

Sort descending by:
(minimum - actual)

If tie:
larger actual first.

------------------------------------------------

Binary Search:

We binary search the minimum starting energy.

For each candidate energy:
simulate all tasks greedily.

If all tasks completed:
→ possible

Else:
→ increase energy

------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool ispossible(vector<pair<int,int>> &v, int energy){

        for(auto &p : v){

            // Need enough energy before starting
            if(energy < p.second + p.first)
                return false;

            energy -= p.first;
        }

        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {

        int s = 0;
        int e = 0;

        for(auto &p : tasks){
            s += p[0];
            e += p[1];
        }

        vector<pair<int,int>> diff;

        // Store:
        // {actual, minimum - actual}
        for(auto &p : tasks){
            diff.push_back({p[0], (p[1] - p[0])});
        }

        // Greedy sorting
        sort(diff.begin(), diff.end(),
        [](const auto &a, const auto &b){

            if(a.second != b.second){
                return a.second > b.second;
            }

            return a.first > b.first;
        });

        int ans = 0;

        // Binary search on answer
        while(s <= e){

            int mid = s + (e - s) / 2;

            if(ispossible(diff, mid)){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }

        return ans;
    }
};