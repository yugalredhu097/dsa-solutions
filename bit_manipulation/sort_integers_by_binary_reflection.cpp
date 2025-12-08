// Problem: Sort Integers by Binary Reflection
// Link: https://leetcode.com/problems/sort-integers-by-binary-reflection/
// Approach: Bit manipulation + sorting based on reversed binary value
// Time Complexity: O(n log n)
// Space Complexity: O(n)

/*
Explanation:
We sort integers by their "binary reflection" value.

Binary reflection means:
Reverse the binary representation of a number (only up to its highest set bit).

Example:
n = 6  → binary: 110
Reflection = 011  → decimal = 3

Algorithm:
1. Sort nums initially to maintain stability for equal reflection values.
2. For each number:
   - Compute its reflection using bit operations.
   - Store (reflection, original_index) in a vector.
3. Sort by reflection values.
4. Use original indices to reconstruct answer.

This guarantees:
- Correct sorted order based on reflection
- Stable ordering for equal reflections
*/

class Solution {
public:

    // Helper: reverse bits until highest set bit
    int reflection(int n) {
        int result = 0;

        while (n > 0) {
            int bit = n & 1;                // extract last bit
            result = (result << 1) | bit;   // append reversed bit
            n >>= 1;                        // next bit
        }

        return result;
    }

    vector<int> sortByReflection(vector<int>& nums) {
        // 1. Sort original array
        sort(nums.begin(), nums.end());

        vector<pair<int,int>> temp;

        // 2. Store (reflection_value, original_index)
        for (int i = 0; i < nums.size(); i++) {
            int ref = reflection(nums[i]);
            temp.push_back({ref, i});
        }

        // 3. Sort by reflected values
        sort(temp.begin(), temp.end());

        // 4. Construct answer based on sorted reflection
        vector<int> ans;
        for (int i = 0; i < temp.size(); i++) {
            ans.push_back(nums[temp[i].second]);
        }

        return ans;
    }
};
