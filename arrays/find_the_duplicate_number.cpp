// Problem: Find the Duplicate Number
// Link: https://leetcode.com/problems/find-the-duplicate-number/
// Approach: Floyd’s Tortoise and Hare (Cycle Detection)
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
The array contains numbers from 1 to n, and exactly one number is repeated.
We can model the array as a linked list where:
- Each index points to nums[index]
- Due to the duplicate, a cycle must exist

Steps:
1. Use Floyd’s Cycle Detection to find the meeting point of slow and fast pointers.
2. Once they meet, reset one pointer to the start.
3. Move both pointers one step at a time.
4. The point where they meet again is the duplicate number.

This approach does not modify the array and uses constant extra space.
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow = 0;
        int fast = 0;

        // Phase 1: Detect cycle
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
                break;
        }

        // Phase 2: Find entry point of the cycle
        int ptr1 = 0;
        int ptr2 = slow;

        while (ptr1 != ptr2) {
            ptr1 = nums[ptr1];
            ptr2 = nums[ptr2];
        }

        return ptr1;
    }
};
