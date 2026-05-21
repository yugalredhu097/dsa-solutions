// Problem: Arrange the Numbers in a Circle
// Platform: Codeforces
// Problem ID: 2230C
// Link: https://codeforces.com/contest/2230/problem/C
// Approach: Greedy + Frequency Handling
// Time Complexity: O(n log n)
// Space Complexity: O(n)

/*
Explanation:

We are given card values.

Goal:
Maximize contribution based on arrangement rules.

------------------------------------------------

Key Idea:

Cards with value 1 behave differently.

We:
- Count number of ones
- Process larger values greedily

------------------------------------------------

Observations:

1. If all cards are 1:
   answer = 0

2. If only one non-one value exists:
   special handling required

3. Larger values can absorb/use ones efficiently.

------------------------------------------------

Greedy Strategy:

For every card > 1:
- Add its value
- Use available ones to maximize gain

Maximum usable ones:
(cards[i] / 2) - 1

------------------------------------------------

Why?

Each large number can pair with only
limited number of ones effectively.

------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        long long one = 0;

        vector<long long> cards(n + 1, 0);

        for(int i = 1; i <= n; i++){

            cin >> cards[i];

            if(cards[i] == 1)
                one++;
        }

        sort(cards.begin(), cards.end());

        // Edge case
        if((n == 1 && cards[1] < 3) || one == n){
            cout << "0\n";
            continue;
        }

        // Only one non-one value
        if(one == n - 1){

            cout << cards[n] + min(one, cards[n] / 2) << endl;

            continue;
        }

        long long ans = 0;

        for(int i = 1; i <= n; i++){

            if(cards[i] != 1){

                ans += cards[i];

                if(one > 0 && cards[i] > 3){

                    long long take =
                        min(one, (cards[i] / 2) - 1);

                    ans += take;

                    one -= take;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}