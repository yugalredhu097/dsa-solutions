// Problem: Robot Collisions
// Link: https://leetcode.com/problems/robot-collisions/
// Approach: Sorting + Stack Simulation
// Time Complexity: O(n log n)
// Space Complexity: O(n)

/*
Explanation:

We are given:
- positions → initial positions of robots
- healths   → health of each robot
- directions → 'L' or 'R'

Goal:
Simulate collisions and return health of surviving robots.

------------------------------------------------

Key Idea:

1. Sort robots by position so collisions happen in order.

2. Use a stack to simulate:
   - Store robots moving to the right ('R')
   - When a left-moving robot ('L') comes,
     it may collide with robots in the stack.

------------------------------------------------

Collision Rules:

1. If R robot health < L robot health:
   - R robot dies
   - L robot loses 1 health

2. If R robot health == L robot health:
   - Both die

3. If R robot health > L robot health:
   - L robot dies
   - R robot loses 1 health

------------------------------------------------

Steps:

1. Pair position, health, direction
2. Sort by position
3. Traverse:
   - Push 'R' robots into stack
   - Resolve collisions for 'L' robots

4. Track updated healths
5. Return remaining robots in original order

------------------------------------------------

This ensures correct simulation of collisions.
*/

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {

        vector<pair<int, pair<int, char>>> corr;
        vector<int> temp = healths;

        unordered_map<int, int> mpp;

        // Store position mapping
        for (int i = 0; i < positions.size(); i++) {
            corr.push_back({positions[i], {healths[i], directions[i]}});
            mpp[positions[i]] = i;
        }

        // Sort by position
        sort(corr.begin(), corr.end());

        stack<pair<int, pair<int, char>>> st;

        for (int i = 0; i < corr.size(); i++) {

            int skip = 0;

            while (!st.empty() &&
                   st.top().second.second == 'R' &&
                   corr[i].second.second == 'L') {

                // If stack robot weaker
                if (st.top().second.first < corr[i].second.first) {

                    temp[mpp[st.top().first]] = 0;
                    st.pop();

                    temp[mpp[corr[i].first]]--;
                    corr[i].second.first--;
                }

                // Equal health
                else if (st.top().second.first == corr[i].second.first) {

                    temp[mpp[st.top().first]] = 0;
                    st.pop();

                    temp[mpp[corr[i].first]] = 0;

                    skip = 1;
                    break;
                }

                // Stack robot stronger
                else {

                    temp[mpp[st.top().first]]--;
                    st.top().second.first--;

                    temp[mpp[corr[i].first]] = 0;

                    skip = 1;
                    break;
                }
            }

            if (skip == 1)
                continue;

            st.push(corr[i]);
        }

        vector<int> ans;

        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] > 0)
                ans.push_back(temp[i]);
        }

        return ans;
    }
};