// Problem: Fighting Tournament
// Platform: Codeforces
// Problem ID: 1719C
// Link: https://codeforces.com/problemset/problem/1719/C
// Approach: Next Greater Element + Prefix Maximum + Simulation Logic
// Time Complexity: O(n + q)
// Space Complexity: O(n)

/*
Explanation:

We are given:
- Strength of players
- Queries (i, k)

Each round:
- Current winner fights next player
- Stronger player stays

Goal:
Find how many victories player i gets
within first k rounds.

------------------------------------------------

Key Observations:

1. A player can only start winning after:
   reaching the front.

2. If there exists a stronger player later,
   wins stop before that index.

------------------------------------------------

Preprocessing:

1. Prefix Maximum:
   prefmax[i] = strongest player till i

A player can only become champion if:
prefmax[i] == player strength

------------------------------------------------

2. Next Greater Element (NGE):

nge[i] = next index having stronger player

After reaching nge[i],
player i stops winning.

------------------------------------------------

Cases:

Case 1:
i == 1

Player starts immediately.

Wins until:
- stronger player appears
OR
- rounds exhausted

------------------------------------------------

Case 2:
i > 1

Player first needs:
(i - 1) rounds to reach front.

Then can start winning.

------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

// Next Greater Element
void ngefunc(vector<int> &nge, vector<int> &p){

    stack<int> st;

    int n = p.size() - 1;

    for(int i = n; i >= 1; i--){

        while(!st.empty() && p[i] > p[st.top()])
            st.pop();

        if(st.empty()) nge[i] = -1;
        else nge[i] = st.top();

        st.push(i);
    }
}

// Prefix maximum
void prefmaxFunc(vector<int> &pref, vector<int> &p){

    int maxi = INT_MIN;

    for(int i = 1; i < p.size(); i++){

        maxi = max(maxi, p[i]);

        pref[i] = maxi;
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){

        int n, q;
        cin >> n >> q;

        vector<int> players(n + 1, 0);
        unordered_map<int,int> initial;

        for(int i = 1; i <= n; i++){
            cin >> players[i];
            initial[i] = players[i];
        }

        vector<pair<int,long long>> query(q);

        for(int i = 0; i < q; i++){
            cin >> query[i].first >> query[i].second;
        }

        // Preprocessing
        vector<int> nge(n + 1, 0);
        ngefunc(nge, players);

        vector<int> prefmax(n + 1, 0);
        prefmaxFunc(prefmax, players);

        // Answer queries
        for(int l = 0; l < q; l++){

            int i = query[l].first;
            long long k = query[l].second;

            int p = initial[i];

            long long victory = 0;

            // Player can become winner
            if(i >= 2 && prefmax[i] == p && k >= i - 1){

                victory++;

                if(nge[i] != -1){
                    victory += min(
                        k - (i - 1),
                        1LL * (nge[i] - i - 1)
                    );
                }
                else{
                    victory += k - (i - 1);
                }
            }

            // First player starts immediately
            else if(i == 1){

                if(nge[i] != -1){
                    victory += min(
                        k,
                        1LL * (nge[i] - i - 1)
                    );
                }
                else{
                    victory += k;
                }
            }

            cout << victory << endl;
        }
    }

    return 0;
}