// Problem: Phone Numbers
// Platform: Codeforces
// Problem ID: 898C
// Link: https://codeforces.com/contest/898/problem/C
// Approach: Hash Map + Suffix Elimination
// Time Complexity: O(k² · L)
// Space Complexity: O(total phone numbers)

/*
Explanation:

We are given:

- Names
- Multiple phone numbers for each name

Goal:
Remove redundant phone numbers.

------------------------------------------------

Redundant Number:

A number is redundant if it is a suffix
of another number belonging to the same person.

Example:

911
1911

→ 911 is redundant because it is a suffix of 1911

------------------------------------------------

Key Idea:

For every person:

Compare every pair of phone numbers.

If:
longer_number ends with shorter_number

Then:
remove shorter_number

------------------------------------------------

Implementation:

Store all phone numbers in:

unordered_map<
    string,
    unordered_set<string>
>

This automatically removes duplicates.

------------------------------------------------

After processing:

Print:
- Number of people
- Remaining phone numbers for each person

------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<string, unordered_set<string>> mpp;

    for(int i = 1; i <= n; i++){

        string s;
        cin >> s;

        int a;
        cin >> a;

        for(int j = 1; j <= a; j++){

            string num;
            cin >> num;

            mpp[s].insert(num);
        }
    }

    // Remove redundant suffix numbers
    for(auto &it : mpp){

        auto &nums = it.second;

        vector<string> to_remove;

        for(const string &num : nums){

            for(const string &other_num : nums){

                if(num.size() > other_num.size() &&
                   num.substr(
                       num.size() - other_num.size()
                   ) == other_num){

                    to_remove.push_back(other_num);
                }
            }
        }

        for(const string &remove_item : to_remove){

            if(nums.count(remove_item))
                nums.erase(remove_item);
        }
    }

    cout << mpp.size() << endl;

    for(auto &it : mpp){

        cout << it.first
             << " "
             << it.second.size()
             << " ";

        for(auto &num : it.second){
            cout << num << " ";
        }

        cout << endl;
    }

    return 0;
}