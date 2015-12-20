/*
 * c++ primer 4ed, class
 * chapter 13.5: pointer
 */

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

// method one: pointer semantic
class HasPtrOne{
 public:
  HasPtrOne(int* ip,int i):ptr(ip),val(i) {}
  
  int* get_ptr() const { return ptr; }
  int get_val() const { return val;}

  void set_ptr(int *ip) { ptr = ip; }
  void set_val(int i) { val = i;}

  int get_ptr_val() const { return *ptr;}
  void set_ptr_val(int val) const { *ptr = val;}
 private:
  int *ptr;
  int val;
};

// method two: smart pointer (must be heap-based)
class HasPtrTwo{
  // reference count
  class U_Ptr{
    friend class HasPtrTwo;
    int *ip;
    size_t use;
    U_Ptr(int *p):ip(p),use(1) {}
    ~U_Ptr() { delete ip; }
  };
  
 public:
  HasPtrTwo(int* ip,int i):ptr(new U_Ptr(ip)),val(i) {}
  HasPtrTwo(const HasPtrTwo& rhs):ptr(rhs.ptr),val(rhs.val) {
    ptr->use++;
  }
  HasPtrTwo& operator=(const HasPtrTwo& rhs) {
    if(this != &rhs) {
      rhs.ptr->use++;
      if(--ptr->use == 0) delete ptr;
      ptr = rhs.ptr;
      val = rhs.val;
    }
    return *this;
  }
  ~HasPtrTwo() { if(--ptr->use == 0) delete ptr;}
  
  int* get_ptr() const { return ptr->ip; }
  int get_val() const { return val;}

  void set_ptr(int *ip) { ptr->ip = ip; }
  void set_val(int i) { val = i;}

  int get_ptr_val() const { return *ptr->ip;}
  void set_ptr_val(int val) const { *ptr->ip = val;}
 private:
  U_Ptr *ptr;
  int val;
};


// method three: value semantic
class HasPtrThree{
 public:
  HasPtrThree(int ip,int i):ptr(new int(ip)),val(i) {}

  HasPtrThree(const HasPtrThree& rhs):ptr(new int(*rhs.ptr)),val(rhs.val) {}
  HasPtrThree& operator=(const HasPtrThree& rhs) {
    *ptr = *rhs.ptr;
    val = rhs.val;
    return *this;
  }
  ~HasPtrThree() { delete ptr;}
  
  int* get_ptr() const { return ptr; }
  int get_val() const { return val;}

  void set_ptr(int *ip) { ptr = ip; }
  void set_val(int i) { val = i;}

  int get_ptr_val() const { return *ptr;}
  void set_ptr_val(int val) const { *ptr = val;}
 private:
  int *ptr;
  int val;
};

int main() {
  // pointer semantic
  cout << "Pointer semantic: \n";
  int obj = 100;
  HasPtrOne one(&obj,obj);
  HasPtrOne two(one);
  cout << one.get_ptr_val() << endl;
  one.set_ptr_val(10);
  cout << two.get_ptr_val() << endl;

  // smart pointer
  cout << "Smart Pointer: \n";
  HasPtrTwo three(new int(200),200);
  HasPtrTwo four(three);
  cout << three.get_ptr_val() << endl;
  three.set_ptr_val(-200);
  cout << four.get_ptr_val() << endl;
  four = three;
  cout << four.get_ptr_val() << endl;
  
  // value semantic
  cout << "Value semantic: \n";
  int obj3 = 100;
  HasPtrThree five(obj3,obj3);
  HasPtrThree six(five);
  cout << five.get_ptr_val() << endl;
  five.set_ptr_val(20);
  cout << five.get_ptr_val() << endl;
  cout << six.get_ptr_val() << endl;
  return 0;
}
