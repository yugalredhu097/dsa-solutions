// Problem: Ingenuity-2
// Platform: Codeforces
// Problem ID: 1974D
// Link: https://codeforces.com/contest/1974/problem/D
// Approach: Greedy + Direction Balancing + Case Handling
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:

We are given a string of movements:
N, S, E, W

We need to assign each move either:
'H' or 'R'

Such that final displacement can be balanced
according to constraints.

------------------------------------------------

Key Observations:

1. Compute final displacement:
   x → horizontal (E/W)
   y → vertical (N/S)

2. If x or y is odd → impossible

------------------------------------------------

Case 1: x = 0 and y = 0

- Special handling required
- If both vertical & horizontal moves exist:
  Assign all N/S as 'H'
- If only horizontal:
  Balance E and W equally
- If only vertical:
  Balance N and S equally

------------------------------------------------

Case 2: x ≠ 0 or y ≠ 0

- Greedily assign 'H' to reduce imbalance
- Reduce x and y step-by-step

------------------------------------------------

Goal:

Ensure valid assignment while maintaining constraints.

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

        string s;
        cin>>s;

        int x = 0, y = 0;
        int vert = 0, hori = 0;

        // Calculate displacement
        for(char c : s){
            if(c=='N'){
                vert = 1;
                y++;
            }
            else if(c=='S') y--;
            else if(c=='E'){
                hori = 1;
                x++;
            }
            else x--;
        } 

        // If odd displacement → impossible
        if(x%2!=0 || y%2!=0){
            cout<<"NO"<<endl;
            continue;
        }

        string ans(n,'R');

        // Case 1: No displacement
        if(x==0 && y==0){

            if(n==2){
                cout<<"NO"<<endl;
                continue; 
            }

            if(vert==1 && hori==1){ 
                for(int i=0;i<n;i++){
                    if(s[i]=='N' || s[i]=='S') 
                        ans[i]='H';
                }
            }
            else if(hori==1 && vert==0){
                int EastH = n/4;
                int WestH = n/4;

                for(int i=0;i<n;i++){
                    if(s[i]=='W'){
                        if(WestH!=0){
                            ans[i]='H';
                            WestH--;
                        }
                    }
                    else{
                        if(EastH!=0){
                            ans[i]='H';
                            EastH--;
                        }
                    }
                }
            }
            else if(vert==1 && hori==0){
                int NorthH = n/4;
                int SouthH = n/4;

                for(int i=0;i<n;i++){
                    if(s[i]=='N'){
                        if(NorthH!=0){
                            ans[i]='H';
                            NorthH--;
                        }
                    }
                    else{
                        if(SouthH!=0){
                            ans[i]='H';
                            SouthH--;
                        }
                    }
                }
            }
        }
        else{
            // Case 2: Greedy balancing
            for(int i=0;i<n;i++){
                if(s[i]=='N' && y>0){
                    y -= 2;
                    ans[i]='H';
                }
                else if(s[i]=='S' && y<0){
                    y += 2;
                    ans[i]='H';
                }
                else if(s[i]=='E' && x>0){
                    x -= 2;
                    ans[i]='H';
                }
                else if(s[i]=='W' && x<0){
                    x += 2;
                    ans[i]='H';
                }
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}