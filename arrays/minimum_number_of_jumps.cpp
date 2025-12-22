// Problem: Minimum number of jumps to reach end
// Link: https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
// Approach: Greedy selection of optimal next index
// Time Complexity: O(n^2) in worst case
// Space Complexity: O(1)

/*
Explanation:
Each element in the array represents the maximum jump length from that index.

Goal:
Reach the last index using the minimum number of jumps.

Approach:
1. Start from index 0.
2. At each index, check how far we can jump (ability).
3. If ability == 0 → cannot move forward → return -1.
4. If ability is enough to directly reach the end → increment jump and finish.
5. Otherwise:
   - From all reachable indices, choose the one which minimizes
     the remaining distance to the end.
   - This greedy choice helps move closer to the destination optimally.
6. Repeat until the end is reached.

This solution uses a greedy heuristic to choose the best next index.
*/

class Solution {
  public:

    // Choose the next index that minimizes remaining distance
    int maxability(vector<int>& arr, int ability, int a) {

        int mini = INT_MAX;

        // Find minimum remaining distance
        for (int i = a + ability; i >= a + 1; i--) {
            int gap = arr.size() - 1 - (i + arr[i]);
            mini = min(mini, gap);
        }

        // Find index that gives this minimum gap
        int index = 0;
        for (int i = a + ability; i >= a + 1; i--) {
            if (arr.size() - 1 - (i + arr[i]) == mini) {
                index = i;
                break;
            }
        }

        return index;
    }

    int minJumps(vector<int>& arr) {

        int i = 0;
        int jumps = 0;
        int n = arr.size();

        while (i < n) {

            int ability = arr[i];

            // Cannot move forward
            if (ability == 0)
                return -1;

            // Can reach end directly
            if (ability >= n - 1 - i) {
                jumps++;
                break;
            }
            else {
                i = maxability(arr, ability, i);
                jumps++;
            }
        }

        return jumps;
    }
};
