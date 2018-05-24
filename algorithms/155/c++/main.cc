#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

class MinStack {
public:
  /** initialize your data structure here. */
  MinStack() : min(0) {}

  void push(int x) {
    if (data.empty() || x < min) {
      min = x;
    }
    data.push(Node(x, min));
  }

  void pop() {
    data.pop();
    if (!data.empty())
      min = getMin();
  }

  int top() {
    return data.top().value;
  }

  int getMin() {
    return data.top().min;
  }

private:
  struct Node {
    int value;
    int min;
    Node(int v, int m) : value(v), min(m) {}
  };
  std::stack<Node> data;
  int min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main(int argc, char *argv[]) {
  MinStack stack;
  stack.push(-2);
  stack.push(0);
  stack.push(-3);
  cout << stack.getMin() << '\n';
  stack.pop();
  cout << stack.top() << '\n';
  cout << stack.getMin() << '\n';
  return 0;
}