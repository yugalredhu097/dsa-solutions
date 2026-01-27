// Problem: Asteroid Collision
// Link: https://leetcode.com/problems/asteroid-collision/
// Approach: Stack simulation using a vector
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
We simulate collisions using a stack-like vector.

Rules:
- Positive numbers move right, negative move left.
- Collision happens only when a positive asteroid is followed by a negative one.
- Smaller asteroid explodes.
- If both have the same size, both explode.

Steps:
1. Iterate through the asteroids.
2. When encountering a negative asteroid, keep removing smaller positive asteroids from the stack.
3. Handle equal size collision.
4. Push the asteroid if it survives.
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;

        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] < 0) {
                if (ans.empty()) {
                    ans.push_back(asteroids[i]);
                } else {
                    while (!ans.empty() && ans.back() > 0 &&
                           ans.back() < abs(asteroids[i])) {
                        ans.pop_back();
                    }

                    if (ans.empty() || ans.back() < 0) {
                        ans.push_back(asteroids[i]);
                    } 
                    else if (ans.back() == abs(asteroids[i])) {
                        ans.pop_back();
                    }
                }
            } else {
                ans.push_back(asteroids[i]);
            }
        }

        return ans;
    }
};
