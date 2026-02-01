// Problem: Ride Sharing System
// LeetCode ID: 3829
// Link: https://leetcode.com/problems/ride-sharing-system/
// Approach: Queue + Deque
// Time Complexity:
//   addRider            -> O(1)
//   addDriver           -> O(1)
//   matchDriverWithRider-> O(1)
//   cancelRider         -> O(n)
// Space Complexity: O(n)

/*
Explanation:
This problem simulates a ride-sharing platform where riders and drivers
arrive independently and are matched in FIFO order.

Approach:
1. Use a deque to maintain riders so that:
   - Front rider can be matched quickly.
   - Any rider can be removed in case of cancellation.
2. Use a queue to maintain drivers in arrival order.
3. When matching:
   - If either riders or drivers are empty, return {-1, -1}.
   - Otherwise, match the earliest driver with the earliest rider.
4. For rider cancellation:
   - Traverse the deque and remove the rider if found.

This design efficiently supports all required operations.
*/

class RideSharingSystem {
public:
    deque<int> riders;
    queue<int> drivers;

    RideSharingSystem() {}

    void addRider(int riderId) {
        riders.push_back(riderId);
    }

    void addDriver(int driverId) {
        drivers.push(driverId);
    }

    vector<int> matchDriverWithRider() {
        if (riders.empty() || drivers.empty()) {
            return {-1, -1};
        }

        vector<int> match;
        match.push_back(drivers.front());
        drivers.pop();

        match.push_back(riders.front());
        riders.pop_front();

        return match;
    }

    void cancelRider(int riderId) {
        for (auto it = riders.begin(); it != riders.end(); ++it) {
            if (*it == riderId) {
                riders.erase(it);
                break;
            }
        }
    }
};
