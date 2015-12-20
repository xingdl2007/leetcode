/*
 * c++ primer 4ed, class
 * chapter 13: all homeworks
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// just for print int
void print(int& i) {
  cout << i << " ";
}

// a pair of function
struct NoName {
  NoName():pstring(new std::string()), i(0), d(0) {}
  NoName(const NoName& rhs):pstring(new std::string(*rhs.pstring)),
                            i(rhs.i), d(rhs.d) {}
  NoName& operator= (const NoName& rhs) {
    pstring = new string();
    *pstring = *rhs.pstring;
    i = rhs.i;
    d = rhs.d;
    return *this;
  }
  // delete the resources when allocated in C'or
  ~NoName() { delete pstring; }
  
 private:
  std::string *pstring;
  int i;
  double d;
};

class Employee {
 public:
  Employee() {}
  Employee(string n) { name = n; id = getid();}
  //copy
  Employee(const Employee& rhs):name(rhs.name),id(getid()) {}
  Employee& operator=(const Employee& rhs) {
    if(this != &rhs) {
      name = rhs.name;
      id = getid();
    }
    return *this;
  }
  // return a reasonable initial value
  static int init() { return 0; }
  // for print
  void toString(ostream& out) {
    out << "Name: " << name << ", ID: " << id << "\n";
  }
 private:
  string name;
  int id;
  static int counter;
  int getid() {return counter++;}
};

int Employee::counter = init();

struct Exmpl{
  Exmpl() {std::cout << "Exmpl(): " << this << std::endl;}
  Exmpl(const Exmpl&) {std::cout << "Exmpl(const Exmpl&): " << this << std::endl;}
  Exmpl& operator=(const Exmpl&)
  {std::cout << "Exmpl& operator=(const Exmpl&)" << std::endl;}
  ~Exmpl() {std::cout << "~Exmpl(): " << this << std::endl;}
};

int main() {
  vector<int> vec = {0,1,2,3,4,5,6,7,8,9};
  vector<int> vec2 = vec;
  for_each(vec2.begin(),vec2.end(),print);
  std::cout << std::endl;
  
  // NoName
  NoName noname;

  // Employee
  Employee john("John");
  john.toString(std::cout);
  Employee john2(john);
  john2.toString(std::cout);

  john2 = john = john = john = john2 = john2;
  john2.toString(std::cout);

  // Exmpl
  Exmpl e;
  Exmpl e2(e);
  Exmpl *e3 = new Exmpl();
  e2 = e;
  delete e3;
  
  return 0;
}
