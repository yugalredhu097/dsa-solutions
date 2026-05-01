// Problem: PalindromeX
// Platform: Codeforces
// Problem ID: 2227D
// Link: https://codeforces.com/contest/2227/problem/D
// Approach: Expand Around Center + MEX Computation using Set
// Time Complexity: O(n^2 log n)
// Space Complexity: O(n)

/*
Explanation:

We are given an array of size 2n.

We need to determine the maximum possible MEX value
that can be obtained by choosing a palindromic segment
centered at specific indices.

------------------------------------------------

Key Idea:

We simulate expanding around centers similar to
palindrome expansion:

1. Start from a center (i, j)
2. Expand outward while elements match
3. Track all elements included in this segment

------------------------------------------------

MEX Calculation:

- Maintain a set containing numbers from 0 to n
- Remove elements as we include them in palindrome
- The smallest remaining element is the MEX

------------------------------------------------

Centers to check:

- First occurrence of 0 → (x, x)
- Last occurrence of 0 → (y, y)
- Middle segment → ((x+y)/2, (x+y+1)/2)

Take maximum MEX among all.

------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

int solve(int i,int j){
   set<int> s;

   for(int k=0;k<=n;k++) 
        s.insert(k);

    while(i>=0 && j<2*n){
        if(v[i]!=v[j]){
            break;
        }
        s.erase(v[i]);
        i--;
        j++;
    }

    return *s.begin();
}

int main(){
    int t;
    cin>>t;

    while(t--){
        cin>>n;

        v = vector<int>(2*n);

        for(int i=0;i<2*n;i++){
            cin>>v[i];
        }

        int x = -1, y = -1;

        for(int i=0;i<2*n;i++){
            if(v[i]==0){
                x = i;
                break;
            }
        }

        for(int i=2*n-1;i>=0;i--){
            if(v[i]==0){
                y = i;
                break;
            }
        }

        cout << max({
            solve(x,x),
            solve(y,y),
            solve((x+y)/2,(x+y+1)/2)
        }) << endl;
    }

    return 0;
}