/*
 * sword to offer: problem 21
 * defination a abstract stack with 'min()' find the minest member
 * first need familiar with template
 * for now: lack of 'template' experiences
 * use antoher stack seems a waste of space
 */

#include <iostream>
#include <algorithm>
#include <stack>
#include <assert.h>

#include "gtest/gtest.h"

template<typename T> class stackWithMin {
 public:
  // if not defined C'or and D'or is ok?
  stackWithMin() {}
  virtual ~stackWithMin() {}

  T& top();
  const T& top() const;
  
  void push(const T&);
  void pop();
  const T& min() const;

  bool empty() const;
  size_t size() const;
  
 private:
  std::stack<T> m_data;
  std::stack<T> m_min;
};

template<typename T> T& stackWithMin<T>::top() {
  return m_data.top();
}

template<typename T> const T& stackWithMin<T>::top() const{
  return m_data.top();
}

template<typename T> bool stackWithMin<T>::empty() const {
  return m_data.empty();
}

template<typename T> size_t stackWithMin<T>::size() const {
  return m_data.size();
}

template<typename T> void stackWithMin<T>::push(const T& v) {
  m_data.push(v);

  if(m_min.size() == 0 || v < m_min.top())
    m_min.push(v);
  else
    m_min.push(m_min.top());
}

template<typename T> void stackWithMin<T>::pop() {
  assert(m_data.size() > 0 && m_min.size() > 0);
  m_data.pop();
  m_min.pop();
}

template<typename T> const T& stackWithMin<T>::min() const {
  assert(m_data.size() >0 && m_min.size() > 0);
  
  return m_min.top();
}

TEST(STACK,BASIC) {
  stackWithMin<int> stk;
  stk.push(3);
  stk.push(4);
  stk.push(2);
  stk.push(1);
  stk.pop();
  stk.pop();
  stk.push(0);
  ASSERT_EQ(0,stk.min());
}
