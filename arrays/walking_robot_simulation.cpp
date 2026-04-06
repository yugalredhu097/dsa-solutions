// Problem: Walking Robot Simulation
// Link: https://leetcode.com/problems/walking-robot-simulation/
// Approach: Simulation + Hashing (Obstacle Set)
// Time Complexity: O(n * k) where k is max steps per command
// Space Complexity: O(m) for storing obstacles

/*
Explanation:

We simulate a robot moving on a 2D grid.

Commands:
- -2 → turn left
- -1 → turn right
- 1 to 9 → move forward

------------------------------------------------

Key Idea:

1. Store obstacles in a hash set for O(1) lookup.
   Encode (x, y) as a single number using:
      key = (x << 32) | y

2. Maintain direction using dx, dy arrays:
   North → (0,1)
   East  → (1,0)
   South → (0,-1)
   West  → (-1,0)

3. For each command:
   - Update direction OR
   - Move step-by-step (important for obstacle checking)

4. Stop movement if obstacle encountered.

5. Track maximum distance from origin:
   x² + y²

------------------------------------------------

Why step-by-step?

Because obstacle might be in between the path,
not just at the final position.
*/

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        // Store obstacles using hashing
        unordered_set<long long> st;

        for (auto &obs : obstacles) {
            long long key = ((long long)obs[0] << 32) | (unsigned int)obs[1];
            st.insert(key);
        }

        // Directions: North, East, South, West
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};

        int dir = 0; // start facing North
        int x = 0, y = 0;

        int maxDist = 0;

        for (int cmd : commands) {

            // Turn right
            if (cmd == -1) {
                dir = (dir + 1) % 4;
            }
            // Turn left
            else if (cmd == -2) {
                dir = (dir + 3) % 4;
            }
            // Move forward
            else {

                for (int step = 0; step < cmd; step++) {

                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    long long key = ((long long)nx << 32) | (unsigned int)ny;

                    // Stop if obstacle ahead
                    if (st.count(key)) break;

                    // Move
                    x = nx;
                    y = ny;

                    // Update max distance
                    maxDist = max(maxDist, x * x + y * y);
                }
            }
        }

        return maxDist;
    }
};