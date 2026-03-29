// Problem: Design Event Manager
// Link: https://leetcode.com/problems/design-event-manager/
// Approach: Hash Map + Ordered Map + Set
// Time Complexity:
//   updatePriority → O(log n)
//   pollHighest    → O(log n)
// Space Complexity: O(n)

/*
Explanation:

We need to design a system that supports:

1. Initialization with events:
   Each event has (eventId, priority)

2. updatePriority(eventId, newPriority)
3. pollHighest() → return eventId with highest priority

------------------------------------------------

Key Idea:

We maintain two data structures:

1. Hash Map:
   mpp[eventId] → current priority

2. Ordered Map:
   prio[priority] → set of eventIds

This allows:
- Fast lookup of current priority
- Efficient retrieval of highest priority using map.rbegin()

------------------------------------------------

Operations:

1. updatePriority:
   - Remove eventId from old priority set
   - Insert into new priority set
   - Update hash map

2. pollHighest:
   - Get highest priority using rbegin()
   - Extract smallest eventId from its set
   - Remove it from data structure

------------------------------------------------

Why set?

Because:
- Maintains sorted order
- Allows picking smallest eventId among same priority

------------------------------------------------

This ensures all operations are efficient.
*/

class EventManager {
public:

    unordered_map<int,int> mpp;        // eventId → priority
    map<int, set<int>> prio;           // priority → set of eventIds

    EventManager(vector<vector<int>>& events) {

        mpp.clear();
        prio.clear();

        for (int i = 0; i < events.size(); i++) {

            mpp[events[i][0]] = events[i][1];
            prio[events[i][1]].insert(events[i][0]);
        }
    }

    void updatePriority(int eventId, int newPriority) {

        int oldPriority = mpp[eventId];

        prio[oldPriority].erase(eventId);

        if (prio[oldPriority].empty())
            prio.erase(oldPriority);

        prio[newPriority].insert(eventId);

        mpp[eventId] = newPriority;
    }

    int pollHighest() {

        if (prio.empty())
            return -1;

        auto highest = prio.rbegin();

        int priority = highest->first;
        int id = *highest->second.begin();

        highest->second.erase(id);

        if (prio[priority].empty())
            prio.erase(priority);

        return id;
    }
};

/*
Usage:

EventManager* obj = new EventManager(events);
obj->updatePriority(eventId, newPriority);
int param_2 = obj->pollHighest();
*/