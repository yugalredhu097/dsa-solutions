// Problem: Find Kth Rotation
// Link: https://www.geeksforgeeks.org/problems/find-kth-rotation/1
// Approach: Find break point in sorted rotated array
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
Given a sorted array that has been rotated, we need to find
the number of rotations performed.

The number of rotations equals the index of the minimum element.

Approach:
1. Traverse the array to find the point where the order breaks.
2. The position where arr[j-1] > arr[j] indicates the rotation.
3. If no such break is found, the array was not rotated.

This linear scan approach finds the rotation count.
*/

class Solution {
public:
    int findKRotation(vector<int> &arr) {
        int cnt = 0;
        int i = 0;
        int n = arr.size();

        while (i < n) {
            int j = i + 1;
            while (j < n && arr[j - 1] < arr[j]) j++;
            cnt = j - i;
            break;
        }

        return (cnt == n) ? 0 : cnt;
    }
};
