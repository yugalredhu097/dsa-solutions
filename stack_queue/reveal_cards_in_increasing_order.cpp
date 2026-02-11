// Problem: Reveal Cards In Increasing Order
// Link: https://leetcode.com/problems/reveal-cards-in-increasing-order/
// Approach: Simulation using Deque (Reverse Process)
// Time Complexity: O(n log n)
// Space Complexity: O(n)

/*
Explanation:
We are given a deck of unique integers.
We need to arrange the deck such that when we:
1. Reveal the top card,
2. Move the next top card to the bottom,
3. Repeat...

The revealed sequence is in increasing order.

Approach:
1. Sort the deck.
2. Simulate the process in reverse using a deque.
3. Iterate from largest to smallest element:
   - If deque is not empty:
       • Move last element to front.
   - Insert current index at front.
4. Finally, build the answer using computed order.

This reverse simulation ensures correct arrangement.
*/

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());

        int n = deck.size();
        deque<int> dq;

        // Reverse simulation
        for (int i = n - 1; i >= 0; i--) {
            if (!dq.empty()) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            dq.push_front(i);
        }

        vector<int> ans;
        while (!dq.empty()) {
            ans.push_back(deck[dq.front()]);
            dq.pop_front();
        }

        return ans;
    }
};
