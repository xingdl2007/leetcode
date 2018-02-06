/*
   Design and implement a data structure for Least Recently Used (LRU) cache.
   It should support the following operations: get and put.

  get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
  put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity,
  it should invalidate the least recently used item before inserting a new item.

  Follow up:
  Could you do both operations in O(1) time complexity?

  Example:

  LRUCache cache = new LRUCache( 2 ); // capacity

  cache.put(1, 1);
  cache.put(2, 2);
  cache.get(1);       // returns 1
  cache.put(3, 3);    // evicts key 2
  cache.get(2);       // returns -1 (not found)
  cache.put(4, 4);    // evicts key 1
  cache.get(1);       // returns -1 (not found)
  cache.get(3);       // returns 3
  cache.get(4);       // returns 4
 */

#include <iostream>
#include <cassert>
#include <unordered_map>

using namespace std;

// Runtime: 85 ms, 78%
class LRUCache {
  struct Node {
    int key, value;
    Node *pre = nullptr, *next = nullptr;
  };
public:
  LRUCache(int capacity)
      : head(nullptr), tail(nullptr), cap(capacity) {
    for (int i = 0; i < capacity; ++i) {
      auto tmp = new Node();
      if (head != nullptr) {
        head->pre = tmp;
      }
      tmp->next = head;
      head = tmp;
      if (tail == nullptr) {
        tail = head;
      }
    }
  }

  int get(int key) {
    auto it = table.find(key);
    if (it == table.end()) {
      return -1;
    }
    auto recent = it->second;
    if (recent != tail) {
      auto pre = recent->pre;
      auto nxt = recent->next;
      if (pre != nullptr) {
        pre->next = recent->next;  // not head
      } else {
        head = recent->next;       // head
      }
      if (nxt != nullptr) {
        nxt->pre = pre;
      }
      recent->next = nullptr;
      recent->pre = tail;
      tail->next = recent;
      tail = recent;
    }
    // check();
    return recent->value;
  }

  void put(int key, int value) {
    if (cap < 1) {
      return;
    }
    auto it = table.find(key);
    if (it != table.end()) {
      it->second->value = value;
      // put to the end
      get(key);
    } else {
      // replace head
      table.erase(head->key);
      auto recent = head;
      if (head == tail) {
        head->key = key;
        head->value = value;
        head->pre = head->next = nullptr;
      } else {
        head = head->next;
        head->pre = nullptr;
        recent->key = key;
        recent->value = value;
        recent->next = nullptr;
        recent->pre = tail;
        tail->next = recent;
        tail = recent;
      }
      table[key] = recent;
    }
    // check();
  }

  // very useful function
  void check() {
    assert(head->pre == nullptr);
    assert(tail->next == nullptr);
    auto it = head;
    while (head != tail && it != tail) {
      assert(it->next->pre == it);
      it = it->next;
    }
  }

  void debug() {
    auto it = head;
    cout << "< ";
    while (it != tail) {
      cout << "[" << it->key << ", " << it->value << "] ";
      it = it->next;
    }
    cout << "[" << it->key << ", " << it->value << "] ";
    cout << "> " << endl;
  }

private:
  Node *head, *tail;
  int cap;
  unordered_map<int, Node *> table;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main() {
  LRUCache *cache = new LRUCache(10);

//  cache->put(1, 1);
//  cache->put(2, 2);
//  cout << cache->get(1) << endl;
//  cache->put(3, 3);
//  cout << cache->get(2) << endl;
//  cache->put(4, 4);
//  cout << cache->get(1) << endl;
//  cout << cache->get(3) << endl;
//  cout << cache->get(4) << endl;

//  cout << cache->get(2) << endl;
//  cache->put(2, 6);
//  cout << cache->get(1) << endl;
//  cache->put(1, 5);
//  cache->put(1, 2);
//  cout << cache->get(1) << endl;
//  cout << cache->get(2) << endl;

  // debug
  cache->put(10, 13);
  cache->put(3, 17);
  cache->put(6, 11);
  cache->debug();
  cache->put(10, 5);
  cache->put(9, 10);
  cache->debug();
  cout << cache->get(13) << endl; // -1
  cache->put(2, 19);
  cache->debug();
  cout << cache->get(2) << endl;  // 19
  cache->debug();
  cout << cache->get(3) << endl;  // 17
  cache->debug();

  cache->put(5, 25);
  cout << cache->get(8) << endl;  // -1
  cache->put(9, 22);
  cache->put(5, 5);
  cache->put(1, 30);
  cout << cache->get(11) << endl; // -1
  cache->put(9, 12);
  cout << cache->get(7) << endl;  // -1
  cout << cache->get(5) << endl;  // 5
  cout << cache->get(8) << endl;  // -1
  cout << cache->get(9) << endl;  // 12
  cache->put(4, 30);
  cache->put(9, 3);
  cout << cache->get(9) << endl;  // 3
  cout << cache->get(10) << endl; // 5
  cout << cache->get(10) << endl; // 5
  cache->put(6, 14);
  cache->put(3, 1);
  cout << cache->get(3) << endl;  // 1
  cache->put(10, 11);
  cout << cache->get(8) << endl;  // -1
  cache->put(2, 14);
  cout << cache->get(1) << endl;  // 30
  cout << cache->get(5) << endl;  // 5
  cout << cache->get(4) << endl;  // 30
  cache->put(11, 4);
  cache->put(12, 24);
  cache->put(5, 18);
  cout << cache->get(13) << endl; // -1
  cache->put(7, 23);
  cout << cache->get(8) << endl;  // -1
  cout << cache->get(12) << endl; // 24
  cache->put(3, 27);
  cache->put(2, 12);
  cout << cache->get(5) << endl; // 18
  cache->put(2, 9);
  cache->put(13, 4);
  cache->put(8, 18);
  cache->put(1, 7);
  cout << cache->get(6) << endl; // 14 ? expected: -1
  return 0;
}
