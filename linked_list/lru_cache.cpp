// Problem: LRU Cache (LeetCode 146)
// Link: https://leetcode.com/problems/lru-cache/
// Approach: Doubly Linked List + Hash Map
// Time Complexity:
//   get()  -> O(1)
//   put()  -> O(1)
// Space Complexity: O(capacity)

/*
Explanation:
- Use a doubly linked list to maintain usage order
  (most recently used near head, least near tail).
- Use an unordered_map to get node access in O(1).
- On access/update, move node to the front.
- On capacity overflow, remove least recently used node.
*/

#include <unordered_map>
using namespace std;

struct Node {
    int key, value;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), value(v), prev(NULL), next(NULL) {}
};

class LRUCache {
public:
    unordered_map<int, Node*> mpp;
    int cap;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);   // dummy head
        tail = new Node(-1, -1);   // dummy tail
        head->next = tail;
        tail->prev = head;
    }

    // Remove a node from the doubly linked list
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Insert node right after head (most recently used)
    void addAfterHead(Node* node) {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }

    int get(int key) {
        if (!mpp.count(key)) return -1;

        Node* node = mpp[key];
        removeNode(node);
        addAfterHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cap == 0) return;

        if (mpp.count(key)) {
            Node* node = mpp[key];
            node->value = value;
            removeNode(node);
            addAfterHead(node);
        } else {
            if (mpp.size() == cap) {
                Node* lru = tail->prev;
                removeNode(lru);
                mpp.erase(lru->key);
                delete lru;
            }
            Node* node = new Node(key, value);
            mpp[key] = node;
            addAfterHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key, value);
 */
