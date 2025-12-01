// Problem: Koko Eating Bananas
// Link: https://leetcode.com/problems/koko-eating-bananas/
// Approach: Binary Search on answer (minimum eating speed K)
// Time Complexity: O(n log m)
//   - n = number of piles
//   - m = max bananas in a pile
// Space Complexity: O(1)

/*
Explanation:
Koko chooses an eating speed K. The time needed to eat each pile is:
   time = ceil(piles[i] / K)

We want the smallest K such that total hours <= h.
This is a classic "binary search on answer" problem:
- Search K between [1, max(piles)]
- If K is enough (hours <= h), try smaller K (move left)
- Otherwise try bigger K (move right)

The first K that satisfies the condition is our answer.
*/

class Solution {
public:
    int timetaken(vector<int>& piles, int k, int h) {
        int hours = 0;
        for (int i = 0; i < piles.size(); i++) {
            hours += (piles[i] + k - 1) / k;  // ceil(piles[i] / k)
            if (hours > h) return hours;     // early exit optimization
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = *max_element(piles.begin(), piles.end());

        while (s <= e) {
            int mid = s + (e - s) / 2;
            int usedh = timetaken(piles, mid, h);

            if (usedh <= h) {
                e = mid - 1;  // try smaller speed
            } else {
                s = mid + 1;  // need faster speed
            }
        }
        return s;
    }
};
