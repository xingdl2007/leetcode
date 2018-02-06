#include <string>
#include <iostream>
#include <memory>

/*
 * Implement a trie with insert, search, and startsWith methods.
 * Note: You may assume that all inputs are consist of lowercase letters a-z.
 */

using namespace std;

// Runtime: 92 ms, 10%
class Trie {
  struct Node {
    shared_ptr<Node> links[26] = {nullptr};  // a-z, alphabet size, all initialize to nullptr
    ssize_t value = -1;           // -1 means null
  };

public:
  /** Initialize your data structure here. */
  Trie() : root(make_shared<Node>()), size(0) {};

  Trie(const Trie &) = delete;
  Trie &operator=(const Trie &) = delete;

  /** Inserts a word into the trie. */
  void insert(string word) {
    shared_ptr<Node> search = root;
    for (auto c:word) {
      auto idx = c - 'a';
      if (search->links[idx] == nullptr) {
        search->links[idx] = make_shared<Node>();
      }
      search = search->links[idx];
    }
    search->value = size++;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    shared_ptr<Node> search = root;
    for (auto c:word) {
      auto idx = c - 'a';
      if (search->links[idx] == nullptr) {
        return false;
      }
      search = search->links[idx];
    }
    return word.empty() || search->value != -1;
  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix) {
    shared_ptr<Node> search = root;
    for (auto c:prefix) {
      auto idx = c - 'a';
      if (search->links[idx] == nullptr) {
        return false;
      }
      search = search->links[idx];
    }
    return true;
  }
private:
  shared_ptr<Node> root;
  size_t size;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int main(int argc, char *argv[]) {
  Trie trie;
  trie.insert("she");
  trie.insert("sells");
  trie.insert("sea");
  trie.insert("shells");
  trie.insert("by");
  trie.insert("the");
  trie.insert("sea");
  trie.insert("shore");

  cout << (trie.search("") ? "true" : "false") << endl;
  cout << (trie.search("she") ? "true" : "false") << endl;
  cout << (trie.search("sells") ? "true" : "false") << endl;
  cout << (trie.search("sea") ? "true" : "false") << endl;
  cout << (trie.search("shells") ? "true" : "false") << endl;
  cout << (trie.search("by") ? "true" : "false") << endl;
  cout << (trie.search("the") ? "true" : "false") << endl;
  cout << (trie.search("sea") ? "true" : "false") << endl;
  cout << (trie.search("shore") ? "true" : "false") << endl;

  cout << (trie.startsWith("shore") ? "true" : "false") << endl;
  cout << (trie.startsWith("abc") ? "true" : "false") << endl;
  return 0;
}
