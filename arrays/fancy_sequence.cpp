// Problem: Fancy Sequence
// Link: https://leetcode.com/problems/fancy-sequence/
// Approach: Lazy Updates with Modular Arithmetic
// Time Complexity: 
//   append  -> O(log MOD) (due to modular inverse)
//   addAll  -> O(1)
//   multAll -> O(1)
//   getIndex -> O(1)
// Space Complexity: O(n)

/*
Explanation:

We need to design a data structure that supports:

1. append(val)
2. addAll(inc)
3. multAll(m)
4. getIndex(idx)

Naive Approach:
If we actually update every element for addAll and multAll,
the complexity becomes O(n) per operation which is too slow.

------------------------------------------------

Optimized Idea: Lazy Transformation

Every value in the sequence follows a transformation:

value = original * mult + sum

Where:
mult → cumulative multiplication
sum  → cumulative addition

Instead of updating every element, we keep track of these
two variables globally.

------------------------------------------------

Handling append:

When we insert a new value, we store its "reverse transformed"
value so that future transformations still work.

Given:

current_value = stored_value * mult + sum

We solve for stored_value:

stored_value = (val - sum) / mult

Since we are working in modulo arithmetic, division becomes
multiplication with modular inverse.

------------------------------------------------

Modular Inverse:

Using Fermat's Little Theorem:

a^(-1) ≡ a^(mod-2)  (mod mod)

We compute modular inverse using fast exponentiation.

------------------------------------------------

getIndex(idx):

We simply apply the transformation:

value = stored_value * mult + sum
*/

class Fancy {
public:

    long long mod = 1e9 + 7;

    long long sum;
    long long mult;

    vector<long long> seq;

    Fancy() {
        sum = 0;
        mult = 1;
    }

    // Fast exponentiation
    long long modPow(long long a, long long b) {

        long long res = 1;

        while (b) {

            if (b & 1)
                res = (res * a) % mod;

            a = (a * a) % mod;

            b >>= 1;
        }

        return res;
    }

    // Modular inverse using Fermat's theorem
    long long modInv(long long x) {
        return modPow(x, mod - 2);
    }

    void append(int val) {

        long long rev = ((val - sum) % mod + mod) % mod;

        rev = (rev * modInv(mult)) % mod;

        seq.push_back(rev);
    }

    void addAll(int inc) {
        sum = (sum + inc) % mod;
    }

    void multAll(int m) {
        mult = (mult * m) % mod;
        sum = (sum * m) % mod;
    }

    int getIndex(int idx) {

        if (idx >= seq.size())
            return -1;

        return (seq[idx] * mult + sum) % mod;
    }
};

/*
Usage:

Fancy* obj = new Fancy();
obj->append(val);
obj->addAll(inc);
obj->multAll(m);
int param_4 = obj->getIndex(idx);
*/