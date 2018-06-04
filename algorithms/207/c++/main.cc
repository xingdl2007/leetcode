#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>

using namespace std;

class Solution {
public:
  bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
    unordered_map<int, vector<int>> graph;
    for (auto &p: prerequisites) {
      graph[p.first].push_back(p.second);
    }
    for (int i = 0; !loop && i < numCourses; ++i) {
      if (!seen[i])
        dfs(i, graph);
    }
    return !loop;
  }
private:
  void dfs(int i, unordered_map<int, vector<int>> &graph) {
    seen[i] = true;
    onstack[i] = true;
    for (auto const n: graph[i]) {
      if (!seen[n]) {
        dfs(n, graph);
      } else if (onstack[n]) {
        loop = true;
        break;
      }
    }
    onstack[i] = false;
  }
  unordered_map<int, bool> seen, onstack;
  bool loop = false;
};

int main(int argc, char *argv[]) {
  Solution so;
  return 0;
}