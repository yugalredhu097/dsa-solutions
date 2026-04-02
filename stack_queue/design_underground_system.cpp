// Problem: Design Underground System
// Link: https://leetcode.com/problems/design-underground-system/
// Approach: Hash Maps for Tracking Check-in and Travel Stats
// Time Complexity:
//   checkIn      → O(1)
//   checkOut     → O(1)
//   getAverage   → O(1)
// Space Complexity: O(n)

/*
Explanation:

We need to design a system that supports:

1. checkIn(id, stationName, t)
2. checkOut(id, stationName, t)
3. getAverageTime(startStation, endStation)

------------------------------------------------

Key Idea:

Use two hash maps:

1. in:
   id → {stationName, time}
   → Tracks ongoing journeys

2. out:
   "start#end" → {count, totalTime}
   → Tracks completed journeys

------------------------------------------------

Operations:

1. checkIn:
   Store station and time for the user

2. checkOut:
   - Retrieve check-in info
   - Compute travel time
   - Update count and total time
   - Remove from active map

3. getAverageTime:
   - Return totalTime / count

------------------------------------------------

Why "start#end"?

To uniquely identify a route.

Example:
"A#B", "B#C"
*/

class UndergroundSystem {
public:

    unordered_map<int, pair<string, int>> in;
    unordered_map<string, pair<int, int>> out;

    UndergroundSystem() {
        in.clear();
        out.clear();
    }

    void checkIn(int id, string stationName, int t) {
        in[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {

        int startTime = in[id].second;
        string startStation = in[id].first;

        int travelTime = t - startTime;

        string route = startStation + "#" + stationName;

        out[route].first++;            // count
        out[route].second += travelTime; // total time

        in.erase(id);
    }

    double getAverageTime(string startStation, string endStation) {

        string route = startStation + "#" + endStation;

        return (1.0 * out[route].second) / out[route].first;
    }
};

/*
Usage:

UndergroundSystem* obj = new UndergroundSystem();
obj->checkIn(id, stationName, t);
obj->checkOut(id, stationName, t);
double ans = obj->getAverageTime(startStation, endStation);
*/