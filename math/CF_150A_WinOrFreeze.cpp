// Problem: Win or Freeze
// Platform: Codeforces
// Problem ID: 150A
// Link: https://codeforces.com/problemset/problem/150/A
// Approach: Prime Factorization + Divisor Analysis
// Time Complexity: O(sqrt(n))
// Space Complexity: O(sqrt(n))

/*
Explanation:

We are given a number n.

Goal:
Determine the game result based on
prime/composite factor structure.

------------------------------------------------

Cases:

1. n = 1
   → Output:
     1
     0

2. n is prime
   → Output:
     1
     0

------------------------------------------------

Otherwise:

Find divisors of n.

If every divisor is prime:
→ Output:
  2

Else:
Find smallest composite divisor.

→ Output:
  1
  smallest composite divisor

------------------------------------------------

Key Idea:

- Prime numbers have no useful decomposition
- Composite divisors determine winning move

------------------------------------------------

Functions:

1. isPrime(n)
   Checks primality in O(sqrt(n))

2. divisors(n)
   Stores all divisors excluding 1 and n

------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

// Check if number is prime
bool isPrime(long long n){

    if(n < 2) return false;

    for(long long i = 2; i * i <= n; i++){

        if(n % i == 0)
            return false;
    }

    return true;
}

// Find divisors
void divisors(long long &n, vector<long long> &div){

    for(long long i = 2; i * i <= n; i++){

        if(n % i == 0){

            div.push_back(i);

            if(i != n / i)
                div.push_back(n / i);
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    // Base cases
    if(n == 1 || isPrime(n)){

        cout << "1\n";
        cout << "0\n";

        return 0;
    }

    vector<long long> div;

    divisors(n, div);

    sort(div.begin(), div.end());

    long long mini = -1;

    // Find smallest composite divisor
    for(long long k : div){

        if(!isPrime(k)){
            mini = k;
            break;
        }
    }

    if(mini == -1){
        cout << "2\n";
    }
    else{
        cout << "1\n";
        cout << mini << endl;
    }

    return 0;
}