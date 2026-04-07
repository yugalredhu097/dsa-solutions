// Problem: Walking Robot Simulation II
// Link: https://leetcode.com/problems/walking-robot-simulation-ii/
// Approach: Simulation + Boundary Traversal
// Time Complexity: O(num) per step call (optimized using modulo)
// Space Complexity: O(1)

/*
Explanation:

We simulate a robot moving along the boundary of a grid.

Grid size:
width × height

------------------------------------------------

Key Idea:

1. The robot moves along the perimeter in a cycle.

2. Total perimeter:
   perimeter = 2 * (width + height - 2)

3. We reduce steps using modulo:
   num %= perimeter

4. Handle special case:
   If num == 0 and robot at (0,0),
   direction should be "South"

------------------------------------------------

Directions:

0 → North
1 → East
2 → South
3 → West

------------------------------------------------

Movement Rules:

- Move in current direction until boundary
- Then turn accordingly:
   East  → North
   North → West
   West  → South
   South → East

------------------------------------------------

We simulate movement step-by-step while updating:
- position (x, y)
- direction (dir)
*/

class Robot {
public:

    int x, y, xmax, ymax, dir;
    unordered_map<int, string> mpp;

    Robot(int width, int height) {

        x = 0;
        y = 0;
        dir = 1; // East

        xmax = width - 1;
        ymax = height - 1;

        mpp[0] = "North";
        mpp[1] = "East";
        mpp[2] = "South";
        mpp[3] = "West";
    }

    void step(int num) {

        int perimeter = 2 * (xmax + ymax);

        num %= perimeter;

        // Special case
        if (num == 0) {
            if (x == 0 && y == 0) {
                dir = 2; // South
            }
            return;
        }

        while (num > 0) {

            if (dir == 0) { // North

                int steps = ymax - y;

                if (steps == 0) {
                    dir = 3;
                    continue;
                }

                if (steps >= num) {
                    y += num;
                    num = 0;
                } else {
                    y = ymax;
                    num -= steps;
                    dir = 3;
                }
            }

            else if (dir == 1) { // East

                int steps = xmax - x;

                if (steps == 0) {
                    dir = 0;
                    continue;
                }

                if (steps >= num) {
                    x += num;
                    num = 0;
                } else {
                    x = xmax;
                    num -= steps;
                    dir = 0;
                }
            }

            else if (dir == 2) { // South

                int steps = y;

                if (steps == 0) {
                    dir = 1;
                    continue;
                }

                if (steps >= num) {
                    y -= num;
                    num = 0;
                } else {
                    y = 0;
                    num -= steps;
                    dir = 1;
                }
            }

            else { // West

                int steps = x;

                if (steps == 0) {
                    dir = 2;
                    continue;
                }

                if (steps >= num) {
                    x -= num;
                    num = 0;
                } else {
                    x = 0;
                    num -= steps;
                    dir = 2;
                }
            }
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        return mpp[dir];
    }
};

/*
Usage:

Robot* obj = new Robot(width, height);
obj->step(num);
vector<int> pos = obj->getPos();
string dir = obj->getDir();
*/