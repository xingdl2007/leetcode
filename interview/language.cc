/*
 * some C++ language test
 */

#include <iostream>

using namespace std;

class Empty1{
};

class Empty2{
 public:
  Empty2(){};
  ~Empty2(){};
};

class Empty3{
 public:
  Empty3(){};
  virtual ~Empty3(){};
};

class CopyConstructorError{
 public:
  CopyConstructorError(){};
  
  // compile error
  //CopyConstructorError(CopyConstructorError other) {};
  CopyConstructorError(const CopyConstructorError& other) {};
};

int main() {
  Empty1 emp1;
  Empty2 emp2;
  Empty3 emp3;
  
  cout << sizeof(emp1) << " "
       << sizeof(emp2) << " "
       << sizeof(emp3)
       << endl;
}
