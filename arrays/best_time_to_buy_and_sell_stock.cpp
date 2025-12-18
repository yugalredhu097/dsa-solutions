// Problem: Best Time to Buy and Sell Stock
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Approach: Two pointers (tracking minimum price)
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
We need to maximize profit by choosing one day to buy and one later day to sell.

Approach:
1. Maintain two pointers:
   - i → day to buy (minimum price so far)
   - j → day to sell
2. If prices[j] > prices[i], compute profit and update maxProfit.
3. If prices[j] < prices[i], update i = j (new minimum).
4. Continue until the end of the array.

This ensures we always sell after we buy and get the maximum profit.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int i = 0;   // buy index
        int j = 0;   // sell index
        int n = prices.size();
        int maxprofit = 0;

        while (j < n) {
            if (prices[j] > prices[i]) {
                int profit = prices[j] - prices[i];
                maxprofit = max(maxprofit, profit);
            }

            // Update buy day if lower price found
            if (prices[j] < prices[i]) {
                i = j;
            }

            j++;
        }

        return maxprofit;
    }
};
