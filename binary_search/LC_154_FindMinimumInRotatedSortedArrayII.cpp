// Problem: Find Minimum in Rotated Sorted Array II
// Platform: LeetCode
// Problem ID: 154
// Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
// Approach: Binary Search with Duplicates Handling
// Time Complexity: O(log n) average, O(n) worst case
// Space Complexity: O(1)

/*
Explanation:

We are given a rotated sorted array
that may contain duplicates.

Goal:
Find the minimum element.

------------------------------------------------

Key Difference from Problem 153:

Duplicates can break the usual
binary search ordering logic.

Example:
[2,2,2,0,1]

------------------------------------------------

Observation:

If nums[s] == nums[e],
binary search cannot determine
which side contains minimum safely.

So:
fallback to linear scan.

------------------------------------------------

Binary Search Logic:

If:
nums[s] <= nums[mid]
AND
nums[mid] >= nums[e]
AND
nums[s] >= nums[e]

→ Minimum lies on right side
→ s = mid + 1

Else:
→ Minimum may lie on left side
→ e = mid

------------------------------------------------

Worst Case:

When many duplicates exist:
example [1,1,1,1,1]

Time complexity becomes O(n).

------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int findMin(vector<int>& nums) {

        int s = 0;
        int e = nums.size() - 1;

        // Handle duplicate ambiguity
        if(nums[s] != nums[e]){

            while(s < e){

                int mid = s + (e - s) / 2;

                if(nums[s] <= nums[mid] &&
                   nums[mid] >= nums[e] &&
                   nums[s] >= nums[e]){

                    s = mid + 1;
                }
                else{
                    e = mid;
                }
            }
        }
        else{
            return *min_element(nums.begin(), nums.end());
        }

        return nums[s];
    }
};