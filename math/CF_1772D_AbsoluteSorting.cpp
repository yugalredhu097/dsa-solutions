// Problem: Absolute Sorting
// Platform: Codeforces
// Problem ID: 1772D
// Link: https://codeforces.com/contest/1772/problem/D
// Approach: Math + Range Constraints
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:

We need to find an integer x such that:

|a[i] - x| <= |a[i+1] - x|

for every adjacent pair.

------------------------------------------------

Key Observation:

For two adjacent values:

Case 1:
a[i] < a[i+1]

To maintain order:
x <= (a[i] + a[i+1]) / 2

This gives an upper bound.

------------------------------------------------

Case 2:
a[i] > a[i+1]

To flip correctly:
x >= (a[i] + a[i+1] + 1) / 2

This gives a lower bound.

------------------------------------------------

Case 3:
a[i] == a[i+1]

No restriction added.

------------------------------------------------

Maintain:

low  = maximum lower bound
high = minimum upper bound

If low <= high:
answer exists

Else:
impossible

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

        vector<long long> v(n);

        for(int i = 0; i < n; i++){
            cin >> v[i];
        }

        long long low = 0;
        long long high = 1e9;

        for(int i = 0; i < n - 1; i++){

            long long a = v[i];
            long long b = v[i + 1];

            if(a < b){
                // Upper bound
                high = min(high, (a + b) / 2);
            }
            else if(a > b){
                // Lower bound
                low = max(low, (a + b + 1) / 2);
            }
        }

        if(low <= high){
            cout << low << endl;
        }
        else{
            cout << -1 << endl;
        }
    }

    return 0;
}