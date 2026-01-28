/*
Problem: Four Sum
Link: https://leetcode.com/problems/4sum/

Approach:
- Sort the array to handle duplicates and use two-pointer technique.
- Fix the first two numbers using nested loops.
- For the remaining two numbers, use two pointers (k, l) to find pairs
  whose sum completes the target.
- Use a set to avoid duplicate quadruplets.

Time Complexity: O(n^3)
Space Complexity: O(n)  (for set storing unique quadruplets)

Explanation:
We iterate over all possible pairs (i, j) and then apply the two-pointer
approach on the remaining subarray. Whenever the sum matches the target,
we store the quadruplet. Sorting helps efficiently move pointers and
handle duplicates.
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> temp;
        set<vector<int>> st;
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 1; i++) {
            long long sum = 0;
            sum += nums[i];

            for (int j = i + 1; j < n - 2; j++) {
                sum += nums[j];
                int k = j + 1;
                int l = n - 1;

                while (k < l) {
                    sum += nums[k] + nums[l];

                    if (sum == target) {
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        temp.push_back(nums[l]);

                        st.insert(temp);
                        temp.clear();

                        sum -= (nums[k] + nums[l]);
                        k++;
                        l--;
                    }
                    else if (sum < target) {
                        sum -= (nums[k] + nums[l]);
                        k++;
                    }
                    else {
                        sum -= (nums[k] + nums[l]);
                        l--;
                    }
                }
                sum -= nums[j];
            }
            sum -= nums[i];
        }

        for (auto& v : st) {
            ans.push_back(v);
        }
        return ans;
    }
};
