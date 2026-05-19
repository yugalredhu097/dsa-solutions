// Problem: Number Game
// Platform: Codeforces
// Problem ID: 1370C
// Link: https://codeforces.com/contest/1370/problem/C
// Approach: Game Theory + Number Theory
// Time Complexity: O(sqrt(n))
// Space Complexity: O(1)

/*
Explanation:

Two players:
- Ashishgup
- FastestFinger

Players alternate moves based on divisibility rules.

Goal:
Determine winner assuming optimal play.

------------------------------------------------

Key Observations:

1. n = 1
→ No moves possible
→ FastestFinger wins

------------------------------------------------

2. n is odd OR n == 2
→ Ashishgup wins immediately

Why?

- Odd numbers have odd divisors
- n = 2 has direct winning move

------------------------------------------------

3. n is power of 2
→ FastestFinger wins

Reason:
Only divisors are powers of 2,
eventually forcing losing state.

Check using:
(n & (n - 1)) == 0

------------------------------------------------

4. n = 2 * odd_prime
→ FastestFinger wins

Reason:
Only one useful move exists,
leading opponent to winning state.

Condition:
- n % 4 != 0
- n/2 is prime

------------------------------------------------

5. All other cases
→ Ashishgup wins

------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

// Prime check
bool isPrime(long long n) {

    if(n < 2) return false;

    for(long long i = 2; i * i <= n; i++) {

        if(n % i == 0)
            return false;
    }

    return true;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){

        long long n;
        cin >> n;

        // Case 1
        if(n == 1){
            cout << "FastestFinger\n";
        }

        // Case 2
        else if(n % 2 != 0 || n == 2){
            cout << "Ashishgup\n";
        }

        // Case 3: Power of 2
        else if((n & (n - 1)) == 0){
            cout << "FastestFinger\n";
        }

        // Case 4: n = 2 * odd prime
        else if(n % 4 != 0 && isPrime(n / 2)){
            cout << "FastestFinger\n";
        }

        // Case 5
        else{
            cout << "Ashishgup\n";
        }
    }

    return 0;
}