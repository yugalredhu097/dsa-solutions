// Problem: Longest Common Suffix Queries
// Platform: LeetCode
// Problem ID: 3093
// Link: https://leetcode.com/problems/longest-common-suffix-queries/
// Approach: Reverse Strings + Sorting + Binary Search + Longest Common Prefix Matching
// Time Complexity: O(n log n + q * k)
// Space Complexity: O(n)

/*
Explanation:

We are given:

- wordsContainer
- wordsQuery

Goal:

For each query string, find the index of the string
in wordsContainer having:

1. Longest common suffix
2. If tie -> shortest length
3. If still tie -> smallest index

------------------------------------------------

Key Observation:

Suffix matching becomes prefix matching
after reversing strings.

Example:

container = "testing"
query     = "ing"

Reverse:

"gnitset"
"gni"

Now we need longest common prefix.

------------------------------------------------

Algorithm:

1. Reverse all container strings
2. Store:
   {reversed_string, original_index}

3. Sort container strings lexicographically

4. Reverse every query

5. For each query:
   - Binary search first string having same
     starting character
   - Compare all candidate strings
   - Track:
       longest common prefix length
       shortest string length
       smallest index

------------------------------------------------

Fallback:

If no suffix matches,
return index of shortest string in container.

------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> stringIndices(
        vector<string>& wordsContainer,
        vector<string>& wordsQuery
    ) {

        int idx = -1;
        int n = wordsContainer.size();
        int m = wordsQuery.size();

        int mini = INT_MAX;

        vector<pair<string,int>> Container;

        // Reverse container strings
        for(int i = 0; i < n; i++) {

            reverse(
                wordsContainer[i].begin(),
                wordsContainer[i].end()
            );

            if(wordsContainer[i].size() < mini) {
                mini = wordsContainer[i].size();
                idx = i;
            }

            Container.push_back({
                wordsContainer[i],
                i
            });
        }

        sort(Container.begin(), Container.end());

        // Reverse query strings
        for(string &s : wordsQuery) {
            reverse(s.begin(), s.end());
        }

        vector<int> ans(m, idx);

        for(int i = 0; i < m; i++) {

            int s = 0;
            int e = n - 1;

            int pin = -1;

            char c = wordsQuery[i][0];

            // Find first candidate
            while(s <= e) {

                int mid = s + (e - s) / 2;

                if(Container[mid].first[0] == c) {
                    pin = mid;
                    e = mid - 1;
                }
                else if(Container[mid].first[0] > c) {
                    e = mid - 1;
                }
                else {
                    s = mid + 1;
                }
            }

            if(pin == -1) continue;

            int maxlen = INT_MIN;

            pair<int,int> prev = {
                INT_MAX,
                -1
            };

            int j = pin;

            while(
                j < n &&
                Container[j].first[0] == c
            ) {

                int k = 0;

                while(
                    k < Container[j].first.size() &&
                    k < wordsQuery[i].size() &&
                    Container[j].first[k] ==
                    wordsQuery[i][k]
                ) {
                    k++;
                }

                if(k > maxlen) {

                    prev = {
                        (int)Container[j].first.size(),
                        Container[j].second
                    };

                    maxlen = k;

                    ans[i] = Container[j].second;
                }

                else if(k == maxlen) {

                    if(
                        Container[j].first.size() < prev.first
                        ||
                        (
                            Container[j].first.size()
                            == prev.first
                            &&
                            Container[j].second
                            < prev.second
                        )
                    ) {

                        ans[i] =
                            Container[j].second;

                        prev = {
                            (int)Container[j].first.size(),
                            Container[j].second
                        };
                    }
                }

                j++;
            }
        }

        return ans;
    }
};