/*
 * sword to offer: problem 7
 * Use two stacks to build a queue: interesting
 * C++ template
 */

#include <stack>
#include <stdexcept>

#include "gtest/gtest.h"

template<typename T> class CQueue {
 public:
  CQueue(void) {};
  ~CQueue(void) {};

  void appendTail(const T& node);
  T deleteHead();
  
 private:
  std::stack<T> stack1;
  std::stack<T> stack2;
};

template<typename T> void CQueue<T>::appendTail(const T& node) {
  stack1.push(node);
}

template<typename T> T CQueue<T>::deleteHead() {
  if(stack2.empty()) {
    while(!stack1.empty()) {
      T& data = stack1.top();
      stack1.pop();
      stack2.push(data);
    }
  }
  if(stack2.empty()) throw std::runtime_error("queue is empty");
  T& data = stack2.top();
  stack2.pop();
  return data;
}

TEST(QUEUE,BASIC) {
  CQueue<int> queue;
  queue.appendTail(0);
  queue.appendTail(1);
  queue.appendTail(2);
  queue.appendTail(3);
  queue.appendTail(4);
  ASSERT_EQ(0,queue.deleteHead());
  ASSERT_EQ(1,queue.deleteHead());
  ASSERT_EQ(2,queue.deleteHead());
  queue.appendTail(5);
  queue.appendTail(6);
  queue.appendTail(7);
  ASSERT_EQ(3,queue.deleteHead());
  ASSERT_EQ(4,queue.deleteHead());
  queue.appendTail(8);
  ASSERT_EQ(5,queue.deleteHead());
  ASSERT_EQ(6,queue.deleteHead());
  ASSERT_EQ(7,queue.deleteHead());
  ASSERT_EQ(8,queue.deleteHead());
}
