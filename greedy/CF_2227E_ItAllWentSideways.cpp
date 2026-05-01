// Problem: It All Went Sideways
// Platform: Codeforces
// Problem ID: 2227E
// Link: https://codeforces.com/contest/2227/problem/E
// Approach: Suffix Minimum + Segment Grouping + Greedy
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:

We are given an array and need to compute the minimum
cost based on reducing elements using suffix minimums.

------------------------------------------------

Key Idea:

1. Build suffix minimum array:
   suff[i] = minimum element from i → n-1

2. For each element:
   cost += (arr[i] - suff[i])

   This represents reducing each element to its
   smallest possible suffix value.

------------------------------------------------

Optimization Insight:

There are segments where suffix minimum remains constant.

Example:
If suff[j] == suff[j-1], they belong to same segment.

We find the longest such segment.

------------------------------------------------

Why longest segment matters?

We can optimize one segment, effectively saving operations.

So final answer:
total reduction cost + (max segment length - 1)

------------------------------------------------

Steps:

1. Build suffix minimum array
2. Compute total reduction cost
3. Find longest segment of equal suffix values
4. Add (maxlen - 1) to answer

------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        // Step 1: Build suffix minimum
        vector<int> suff(n);
        suff[n-1] = arr[n-1];

        for(int i=n-2;i>=0;i--){
            suff[i] = min(suff[i+1], arr[i]);
        }

        // Step 2: Find longest segment where suffix min is same
        int maxlen = 0;
        int i = 0;

        while(i < n){
            int j = i + 1;

            while(j < n && suff[j] == suff[j-1]){
                j++;
            }

            maxlen = max(maxlen, j - i);
            i = j;
        }

        // Step 3: Compute cost
        long long ans = 0;

        for(int i=0;i<n;i++){
            ans += (arr[i] - suff[i]);
        }

        // Step 4: Add optimization
        ans += maxlen - 1;

        cout << ans << endl;
    }

    return 0;
}