// Problem: Find Minimum in Rotated Sorted Array
// Platform: LeetCode
// Problem ID: 153
// Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Approach: Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(1)

/*
Explanation:

We are given a rotated sorted array
with distinct elements.

Goal:
Find the minimum element.

------------------------------------------------

Key Observation:

In a rotated sorted array:

- One half is always sorted
- Minimum lies in the unsorted half

------------------------------------------------

Binary Search Logic:

If nums[mid] > nums[e]:
→ Minimum lies on right side
→ s = mid + 1

Else:
→ Minimum can be mid or left side
→ e = mid

------------------------------------------------

Loop ends when:
s == e

That index contains minimum element.

------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int findMin(vector<int>& nums) {

        int s = 0;
        int e = nums.size() - 1;

        while(s < e){

            int mid = s + (e - s) / 2;

            if(nums[mid] > nums[e]){
                s = mid + 1;
            }
            else{
                e = mid;
            }
        }

        return nums[s];
    }
};