/*
Problem: LFU Cache
Link: https://leetcode.com/problems/lfu-cache/

Approach:
- Use two hash maps:
  1) keyNode: maps key -> Node*
  2) freqListMap: maps frequency -> Doubly Linked List
- Each Node stores: key, value, frequency count.
- Each frequency has its own doubly linked list to maintain LRU order
  among nodes with the same frequency.
- minFreq tracks the minimum frequency currently present in the cache.

Operations:
- get(key):
  - If key exists, update its frequency and return value.
  - Else return -1.
- put(key, value):
  - If cache is full, evict the Least Frequently Used node.
    If multiple nodes have same frequency, evict the Least Recently Used one.
  - Insert new node with frequency = 1.

Time Complexity:
- get(): O(1)
- put(): O(1)

Space Complexity:
- O(capacity)
*/

struct Node {
    int key, value, cnt;
    Node* next;
    Node* prev;

    Node(int _key, int _value) {
        key = _key;
        value = _value;
        cnt = 1;
        next = prev = nullptr;
    }
};

struct List {
    int size;
    Node* head;
    Node* tail;

    List() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }

    void addAfterHead(Node* node) {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
        size++;
    }
};

class LFUCache {
    map<int, Node*> keynode;
    map<int, List*> freqlistmap;
    int maxsize;
    int minfreq;
    int currsize;

public:
    LFUCache(int capacity) {
        maxsize = capacity;
        minfreq = 0;
        currsize = 0;
    }

    void updatefreqlist(Node* node) {
        keynode.erase(node->key);
        freqlistmap[node->cnt]->removeNode(node);

        if (node->cnt == minfreq && freqlistmap[node->cnt]->size == 0) {
            minfreq++;
        }

        List* nextList = new List();
        if (freqlistmap.find(node->cnt + 1) != freqlistmap.end()) {
            nextList = freqlistmap[node->cnt + 1];
        }

        node->cnt++;
        nextList->addAfterHead(node);
        freqlistmap[node->cnt] = nextList;
        keynode[node->key] = node;
    }

    int get(int key) {
        if (keynode.find(key) != keynode.end()) {
            Node* node = keynode[key];
            int val = node->value;
            updatefreqlist(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (maxsize == 0) return;

        if (keynode.find(key) != keynode.end()) {
            Node* node = keynode[key];
            node->value = value;
            updatefreqlist(node);
        } else {
            if (currsize == maxsize) {
                List* list = freqlistmap[minfreq];
                keynode.erase(list->tail->prev->key);
                list->removeNode(list->tail->prev);
                currsize--;
            }

            currsize++;
            minfreq = 1;

            List* listfreq = new List();
            if (freqlistmap.find(minfreq) != freqlistmap.end()) {
                listfreq = freqlistmap[minfreq];
            }

            Node* node = new Node(key, value);
            listfreq->addAfterHead(node);
            keynode[key] = node;
            freqlistmap[minfreq] = listfreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key, value);
 */
