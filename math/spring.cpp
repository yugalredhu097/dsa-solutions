// Problem: Spring
// Link: https://codeforces.com/problemset/problem/2204/C
// Approach: Inclusion-Exclusion Principle + LCM
// Time Complexity: O(log(min(a,b,c))) per test case
// Space Complexity: O(1)

/*
Explanation:

We are given:
- a, b, c → intervals for Alice, Bob, and Carol
- m → total number of days

Each person waters plants on multiples of their number.

Goal:
Calculate total water contributed by Alice, Bob, and Carol.

------------------------------------------------

Key Idea: Inclusion-Exclusion

We count:
- Multiples of a → m / a
- Multiples of b → m / b
- Multiples of c → m / c

Then subtract overlaps:

- AB → m / lcm(a, b)
- AC → m / lcm(a, c)
- BC → m / lcm(b, c)

Add back triple overlap:

- ABC → m / lcm(a, b, c)

------------------------------------------------

Then we compute:

- Only A = total A - overlaps
- Only B = total B - overlaps
- Only C = total C - overlaps

------------------------------------------------

Water contribution:

- Only person → 6 units
- Two people → 3 units each
- Three people → 2 units each

Finally compute total contribution for each.

------------------------------------------------

Important:
We use LCM to find overlapping multiples efficiently.
*/

#include <bits/stdc++.h>
using namespace std;

// Compute GCD
long long __gcd(long long a, long long b){
    if (b == 0) return a;
    return __gcd(b, a % b);
}

// Compute LCM
long long lcm(long long a, long long b){
    return (a / __gcd(a, b)) * b;
}

int main(){

    long long t;
    cin >> t;

    while(t--){

        long long a, b, c, m;
        cin >> a >> b >> c >> m;

        long long AB = m / lcm(a, b);
        long long AC = m / lcm(a, c);
        long long BC = m / lcm(b, c);
        long long ABC = m / lcm(lcm(a, b), c);

        long long ABonly = AB - ABC;
        long long AConly = AC - ABC;
        long long BConly = BC - ABC;

        long long Aonly = m / a - ABonly - AConly - ABC;
        long long Bonly = m / b - ABonly - BConly - ABC;
        long long Conly = m / c - AConly - BConly - ABC;

        long long alice_water = Aonly * 6 + ABonly * 3 + AConly * 3 + ABC * 2;
        long long bob_water   = Bonly * 6 + ABonly * 3 + BConly * 3 + ABC * 2;
        long long carol_water = Conly * 6 + AConly * 3 + BConly * 3 + ABC * 2;

        cout << alice_water << " " << bob_water << " " << carol_water << endl;
    }

    return 0;
}