// Problem: Hamburgers
// Platform: Codeforces
// Problem ID: 371C
// Link: https://codeforces.com/contest/371/problem/C
// Approach: Binary Search on Answer + Resource Calculation
// Time Complexity: O(log n)
// Space Complexity: O(1)

/*
Explanation:

We are given:

- A recipe string (e.g., "BSC")
- Available ingredients: have[B], have[S], have[C]
- Prices of each ingredient
- Total money (r)

Goal:
Find maximum number of hamburgers we can make.

------------------------------------------------

Key Idea:

Each hamburger requires:
- rb breads
- rs sausages
- rc cheese

Count from recipe string.

------------------------------------------------

For a given number of hamburgers (mid):

Required ingredients:
mid * recipe[i]

If we don’t have enough:
Buy remaining using money.

------------------------------------------------

Cost calculation:

cost =
max(0, mid*rb - have[B]) * price[B] +
max(0, mid*rs - have[S]) * price[S] +
max(0, mid*rc - have[C]) * price[C]

------------------------------------------------

We need:
cost <= r

This condition is monotonic:
→ If mid works, smaller values also work

So we use Binary Search on answer.

------------------------------------------------

Steps:

1. Count ingredients from recipe
2. Binary search on number of hamburgers
3. Check feasibility using cost function
4. Return maximum valid mid

------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int have[3] = {0};
    cin >> have[0] >> have[1] >> have[2];

    int prices[3] = {0};
    cin >> prices[0] >> prices[1] >> prices[2];

    long long r;
    cin >> r;

    int rb = 0, rs = 0, rc = 0;

    for(char c : s){
        if(c == 'B') rb++;
        else if(c == 'S') rs++;
        else rc++;
    }

    int recipe[3] = {rb, rs, rc};

    long long st = 0;
    long long end = 1e13; // safe upper bound
    long long ans = 0;

    while(st <= end){
        long long mid = (st + end) / 2;

        long long cost =
            max(0LL, mid * recipe[0] - have[0]) * prices[0] +
            max(0LL, mid * recipe[1] - have[1]) * prices[1] +
            max(0LL, mid * recipe[2] - have[2]) * prices[2];

        if(cost <= r){
            ans = mid;
            st = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}