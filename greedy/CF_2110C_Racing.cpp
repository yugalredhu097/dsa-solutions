// Problem: Racing
// Platform: Codeforces
// Problem ID: 2110C
// Link: https://codeforces.com/contest/2110/problem/C
// Approach: Range DP (Greedy Feasibility) + Backtracking Construction
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:

We are given:

- Array d (values: 0, 1, or -1)
- Range constraints [l, r] for each position

Goal:
Replace -1 values with 0 or 1 such that all constraints hold.

------------------------------------------------

Key Idea:

We maintain a valid range [l, r] representing possible values
of cumulative sum at each index.

------------------------------------------------

Forward Pass (Feasibility):

- If d[i] == 1 → l++, r++
- If d[i] == -1 → r++ (can choose 1)

Then intersect with given range:
    l = max(l, rng[i].first)
    r = min(r, rng[i].second)

If l > r → impossible

Store valid ranges for backtracking.

------------------------------------------------

Backward Pass (Construction):

Start from last index with maximum valid value.

Traverse backward:
- If value is fixed → take it
- If -1:
    decide 0 or 1 based on feasibility:
    - prefer 0 if possible
    - otherwise take 1

------------------------------------------------

Finally construct the answer.

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

        vector<int> d(n);
        for(int i = 0; i < n; i++){
            cin >> d[i];
        }

        vector<pair<int,int>> rng(n), valid_rng(n);

        for(int i = 0; i < n; i++){
            cin >> rng[i].first >> rng[i].second;
        }

        bool pos = true;
        int l = 0, r = 0;

        // Forward pass
        for(int i = 0; i < n; i++){
            if(d[i] == 1){
                l++; r++;
            }
            if(d[i] == -1){
                r++;
            }

            int nl = max(l, rng[i].first);
            int nr = min(r, rng[i].second);

            if(nl > nr){
                pos = false;
                break;
            }

            l = nl;
            r = nr;

            valid_rng[i] = {l, r};
        }

        if(!pos){
            cout << "-1\n";
            continue;
        }

        // Backward construction
        deque<int> ans;
        int poss = valid_rng[n-1].second;

        for(int i = n-1; i > 0; i--){
            if(d[i] != -1){
                ans.push_front(d[i]);
                if(d[i]) poss--;
                continue;
            }

            if(poss <= valid_rng[i-1].second){
                ans.push_front(0);
            }
            else{
                ans.push_front(1);
                poss--;
            }
        }

        // Handle first element
        if(d[0] != -1){
            ans.push_front(d[0]);
        }
        else{
            if(poss <= 0) ans.push_front(0);
            else ans.push_front(1);
        }

        for(auto &a : ans){
            cout << a << " ";
        }
        cout << endl;
    }

    return 0;
}