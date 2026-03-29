// Problem: Sum of Sortable Integers
// Link: https://leetcode.com/problems/sum-of-sortable-integers/
// Approach: Divisors + Segment Validation
// Time Complexity: O(n * sqrt(n))
// Space Complexity: O(sqrt(n))

/*
Explanation:

We are given an array nums of size n.

Goal:
Find all integers k such that the array can be divided into
segments of size k and each segment satisfies sorting conditions.

Then return the sum of all such valid k.

------------------------------------------------

Approach:

1. Find all divisors of n.

2. For each divisor k:
   - Divide the array into segments of size k
   - Check if each segment is "sortable"

3. Conditions for each segment:
   - At most one inversion (cyclic allowed)
   - Maintain global order across segments

------------------------------------------------

Helper Function: issortable(k)

1. Traverse array in chunks of size k.
2. For each chunk:
   - Count inversions
   - Track min and max values
3. Ensure:
   - Inversions ≤ 1
   - Previous max ≤ current min

------------------------------------------------

Special Case:
If k == 1 → simply check if array is sorted.

------------------------------------------------

Return the sum of all valid k.
*/

class Solution {
public:

    bool issortable(int k, vector<int> &nums) {

        int i = 0;
        int maxi = INT_MIN;

        if (k == 1)
            return is_sorted(nums.begin(), nums.end());

        while (i < nums.size()) {

            int j = i;
            int cnt = 0;

            int currmax = INT_MIN;
            int currmin = INT_MAX;

            while (j < i + k) {

                currmin = min(currmin, nums[j]);
                currmax = max(currmax, nums[j]);

                if (j + 1 < i + k) {
                    if (nums[j] > nums[j + 1])
                        cnt++;
                }
                else {
                    if (nums[j] > nums[i])
                        cnt++;
                }

                j++;
            }

            if (cnt > 1)
                return false;

            if (maxi > currmin)
                return false;

            maxi = currmax;

            i = j;
        }

        return true;
    }

    int sortableIntegers(vector<int>& nums) {

        int n = nums.size();

        vector<int> div;

        // Find all divisors of n
        for (int i = 1; i * i <= n; i++) {

            if (n % i == 0) {

                div.push_back(i);

                if (i != n / i)
                    div.push_back(n / i);
            }
        }

        int ans = 0;

        // Check each divisor
        for (int k : div) {

            if (issortable(k, nums))
                ans += k;
        }

        return ans;
    }
};