// Problem: Minimize Max Distance to Gas Station
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1
// Approach: Binary Search on Answer
// Time Complexity: O(n * log(range))
// Space Complexity: O(1)

/*
Explanation:
We want to minimize the maximum distance between adjacent gas stations
after adding at most K new stations.

We binary search on the answer (maximum allowed distance `d`).
For a given `d`, we calculate how many new stations are needed so that
no gap exceeds `d`. If required stations ≤ K, the distance is feasible.

Using binary search with precision (1e-6), we find the minimum possible
maximum distance.
*/

class Solution {
  public:
  bool ispossible(vector<int> &stations, double d, int K) {
      int stations_needed = 0;
      for (int i = 1; i < stations.size(); i++) {
          double D = stations[i] - stations[i - 1];
          stations_needed += (int)ceil(D / d) - 1;
          if (stations_needed > K) return false;
      }
      return true;
  }

  double minMaxDist(vector<int> &stations, int K) {
      double s = 0;
      double e = 0;

      for (int i = 1; i < stations.size(); i++) {
          e = max(e, (double)(stations[i] - stations[i - 1]));
      }

      while (e - s >= 1e-6) {
          double mid = s + (e - s) / 2;
          if (ispossible(stations, mid, K)) {
              e = mid;
          } else {
              s = mid;
          }
      }
      return e;
  }
};
