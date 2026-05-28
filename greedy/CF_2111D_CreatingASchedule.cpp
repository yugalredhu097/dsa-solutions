// Problem: Creating a Schedule
// Platform: Codeforces
// Problem ID: 2111D
// Link: https://codeforces.com/contest/2111/problem/D
// Approach: Greedy Construction + Alternating Assignment
// Time Complexity: O(m log m + n)
// Space Complexity: O(n)

/*
Explanation:

We are given:
- n participants
- m values

Goal:
Construct a valid schedule matrix.

------------------------------------------------

Key Idea:

Sort all values first.

Then:
- Use smallest values
- Use largest values
- Alternate them strategically

------------------------------------------------

Construction Strategy:

For every pair of rows:

Even columns:
- First row gets small value
- Second row gets large value

Odd columns:
- Swap assignments

This alternating structure ensures
balanced distribution.

------------------------------------------------

Special Case:

If n is odd:
Last row alternates values itself.

------------------------------------------------

Why Greedy Works?

Using smallest and largest values
alternately maximizes spread and
maintains schedule constraints.

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

        int n, m;
        cin >> n >> m;

        vector<long long> a(m);

        for(int i = 0; i < m; i++){
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        vector<vector<long long>> ans(
            n,
            vector<long long>(6, 0)
        );

        for(int i = 0; i < n; i += 2){

            // Odd row count case
            if(i + 1 == n){

                for(int j = 0; j < 6; j++){

                    if(j % 2 == 0){
                        ans[i][j] = a[i / 2];
                    }
                    else{
                        ans[i][j] =
                            a[m - i / 2 - 1];
                    }
                }
            }

            // Pair rows
            else{

                for(int j = 0; j < 6; j++){

                    if(j % 2 == 0){

                        ans[i][j] =
                            a[i / 2];

                        ans[i + 1][j] =
                            a[m - i / 2 - 1];
                    }
                    else{

                        ans[i][j] =
                            a[m - i / 2 - 1];

                        ans[i + 1][j] =
                            a[i / 2];
                    }
                }
            }
        }

        // Print schedule
        for(int i = 0; i < n; i++){

            for(int j = 0; j < 6; j++){

                cout << ans[i][j] << " ";
            }

            cout << endl;
        }
    }

    return 0;
}