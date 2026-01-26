// Problem: Online Stock Span (LeetCode 901)
// Link: https://leetcode.com/problems/online-stock-span/
// Approach: Monotonic Decreasing Stack
// Time Complexity: Amortized O(1) per query
// Space Complexity: O(n)

/*
Explanation:
For each incoming stock price, we need to find the number of consecutive
days (including today) where the price was less than or equal to today's price.

Approach:
- Use a stack that stores pairs {price, dayIndex}.
- Maintain the stack in decreasing order of prices.
- Pop all prices less than or equal to the current price.
- The span is calculated as:
      currentDayIndex - previousGreaterPriceDayIndex
- If no previous greater price exists, span = currentDayIndex.
*/

#include <stack>
#include <utility>
using namespace std;

class StockSpanner {
public:
    stack<pair<int,int>> st;
    int day;

    StockSpanner() {
        while (!st.empty()) st.pop();
        day = 1;
    }

    int next(int price) {
        int lastGreaterDay = 0;

        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }

        if (!st.empty()) {
            lastGreaterDay = st.top().second;
        }

        st.push({price, day});
        int span = day - lastGreaterDay;
        day++;

        return span;
    }
};

/*
Usage:
StockSpanner* obj = new StockSpanner();
int span = obj->next(price);
*/
