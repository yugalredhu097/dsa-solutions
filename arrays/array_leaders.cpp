// Problem: Array Leaders
// Link: https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1
// Approach: Traverse from right and track maximum
// Time Complexity: O(n)
// Space Complexity: O(1) (excluding output)

/*
Explanation:
An element is called a leader if it is greater than or equal to
all elements to its right.

Approach:
1. Traverse the array from right to left.
2. Keep track of the maximum element seen so far (`opposition`).
3. If current element >= opposition, it is a leader.
4. Update opposition and add element to result.
5. Reverse the result since leaders are collected from right to left.

This greedy approach finds all leaders in a single pass.
*/

class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {

        vector<int> leaders;
        int opposition = -1;
        int i = arr.size() - 1;

        // Traverse from right
        while (i >= 0) {
            if (arr[i] >= opposition) {
                leaders.push_back(arr[i]);
                opposition = arr[i];
            }
            i--;
        }

        // Reverse to maintain original order
        reverse(leaders.begin(), leaders.end());
        return leaders;
    }
};
