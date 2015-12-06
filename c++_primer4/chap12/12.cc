/*
 * c++ primer 4ed, class
 * chapter 12: all homeworks
 */
#include <iostream>
#include <vector>

using namespace std;

class Person {
 public:
  Person(string n, string a): name_(n), addr_(a) {}
  std::string name() const { return name_; }
  std::string addr() const { return addr_; }
 private:
  std::string name_;
  std::string addr_;
};

class Sales_item {
  friend Sales_item add_two_sales_item(Sales_item &lhs, Sales_item &rhs);
  friend Sales_item get_sales_item_from_cin(istream &is);
 public:
  // operations on Sales_item objects
  inline double avg_price() const;
  bool same_isbn(const Sales_item &rhs) const { return isbn == rhs.isbn; }

  // C'ors
  // default C'or
  //Sales_item():units_sold(0), revenue(0.0) { }
  explicit Sales_item(const std::string &book = "default"):
      isbn(book),units_sold(0),revenue(0.0) { }

  // cant have default value of 'is' or default-C have two definations
  // it has compile error
  explicit Sales_item(std::istream &is);

  void ToString(std::ostream &os=std::cout) const;
 private:
  std::string isbn;
  unsigned units_sold;
  double revenue;
};

// must be in the same file with class defination
inline double Sales_item::avg_price() const {
  if(units_sold) return revenue/units_sold;
  else return 0;
}

Sales_item::Sales_item(std::istream &is) {
  is >> isbn >> units_sold >> revenue;
}

void Sales_item::ToString(std::ostream &os) const {
  os << "isbn: " << isbn << " price: " << avg_price() << std::endl;
}

// a friend function
Sales_item add_two_sales_item(Sales_item &lhs, Sales_item &rhs) {
  Sales_item sum;
  
  if(lhs.same_isbn(rhs)) {
    sum.isbn = lhs.isbn;
    sum.units_sold = lhs.units_sold + rhs.units_sold;
    sum.revenue = lhs.revenue + rhs.revenue;
  }
  return sum;
}

// another friend function
Sales_item get_sales_item_from_cin(istream &is) {
  Sales_item input;
  is >> input.isbn >> input.units_sold >> input.revenue;
  return input;
}

//-------------------------------------------------------------------------

typedef std::string Type;
typedef double Money;

// a so complecated class defination
class Screen {
 public:
  // for test: so you can redefine type !!
  typedef double Type;
  typedef long double Money;
  // interface member functions
  typedef std::string::size_type index;

  // return charcter at the cursor or at a given position
  char get() const { return contents[cursor]; }
  inline char get(index ht, index wd) const;
  // inline 
  index get_cursor() const;
  size_t get_display_num() const { return access_ctr; }
  inline Screen& move(index r, index c);
  inline Screen& set(char);
  inline Screen& set(index, index, char);
  
  // interesting
  Screen& display(std::ostream& os) { do_display(os); return *this;}
  // the return value is const in this const function
  const Screen& display(std::ostream& os) const {do_display(os); return *this;}

  // C'or
  Screen(std::string c ="", index h=0, index w=0)
      :contents(c), cursor(0), height(h), width(w), access_ctr(0) { }
  
 private:
  // single function to do the word of displaying a Screen,
  // will be called by the display operations
  void do_display(std::ostream &os) const {
    os << contents << std::endl;
    ++access_ctr;
  }

  std::string contents;
  index cursor;
  index height, width;
  // a useful feature
  mutable size_t access_ctr;
};

char Screen::get(index r, index c) const{
  index row = r * width;
  return contents[row + c];
}

// set the cursor's content
Screen& Screen::set(char c) {
  contents[cursor] = c;
  return *this;
}

Screen& Screen::set(index r, index c, char ch) {
  index row = r*width;
  contents[row + c] = ch;
  return *this;
}

// move the cursor
Screen& Screen::move(index r, index c) {
  index row = r* width ;
  cursor = row + c;
  return *this;
}

inline Screen::index Screen::get_cursor() const { return cursor; }

//--------------------------------------------------------------------------
// the declaration is necessary
class Y;
class X {
 private:
  Y *y;
};

class Y {
 private:
  X *x;
};

class XX {
  friend class YY;
  friend void f() {}
};

// different with c++primer 4ed: must declare
class YY;
void f();

class ZZ {
  YY *ymem;
  void g() { return ::f(); }
};

class NoDefault {
 public:
  NoDefault(int c_) { c = c_; }
 private:
  int c;
};

class C {
 public:
  C():no(0) {};
 private:
  NoDefault no;
};

void f(const vector<int>&);

// if no C'or is defined, can use initialization same with array!
struct Data { int ival; char *ptr;
  //Data():ival(0),ptr(0) {}
};

//--------------------------------------------------------------------------
class Account {
 public:
  // interface function here
  void applyint() { amount += amount * interestRate;}
  static double rate() { return interestRate;}
  static int period() {return period_;}
  static void rate(double r) { interestRate = r; }
 private:
  std::string owner;
  double amount;
  static const int period_ = 30;
  static double interestRate;
  static double initRate() { return 0.97; };
};

// must be first define and must do this in global scope
double Account::interestRate = initRate();
//int Account::period_ = 30;

// interesting
class Bar2 {
  static Bar2 mem1;
  Bar2 *mem2;
  //Bar2 mem3;  // error
};

// static const member can be the default parameter
class Sc {
 public:
  Sc(char c = bkground) {}
 private:
  static const char bkground = '#';
};

// FooBar class: a little tricky
class Foo {
 public:
  Foo(int f_=0xf):f(f_),time(0) {}
  int getfoo() {return f;}
  Foo FooVal();
  int callsFooVal() {return time;}
 private:
  int f;
  int time;
};

class Bar {
  friend Foo Foo::FooVal();
 public:
  static int getbar() { return b;}
  static Foo getf() { return f;}
 private:
  static int b;
  static Foo f;
};

// defination and initialization
int Bar::b(20);
Foo Bar::f(0);

Foo Foo::FooVal() {
  ++time;
  return Bar::f;
}

//--------------------------------------------------------------------------

int main() {
  int a(100);
  
  Person p("Jackson","USA");
  cout << p.name() << ": " << p.addr() << endl;

  // simple test of screen
  Screen myscreen("0123456789abcdefghijklmnopqrstuvwxyz",6,6);
  cout << "cursor: " << myscreen.get() << endl;
  myscreen.move(4, 0).set('#').display(std::cout).
      move(0,0).set('!').display(cout)
      .set(3, 4, '(').set(4,5,')').display(cout)
      .set(0,0,'{').set(5,5,'}').display(cout).move(0,0);

  // a mutable type can be modified by even const function
  cout << myscreen.get_display_num() << endl;
  
  // will call const display version
  const Screen blank("111111111",3,3);
  blank.display(cout);

  //Sales_item first(cin);
  string null_book = "99-99-99-99";
  Sales_item first(null_book);
  Sales_item next;
  Sales_item last("9-999-9999-9");
  Sales_item sum = add_two_sales_item(first, last);
  //Sales_item input = get_sales_item_from_cin(cin);

  first.ToString(cout);
  next.ToString(cout);
  last.ToString(cout);
  
  sum.ToString(cout);
  //input.ToString(cout);

  cout << "same_isbn 1: " << first.same_isbn(Sales_item(null_book)) << endl;
  //cout << "same_isbn 2: " << first.same_isbn(Sales_item(cin)) << endl;
  Data val1 = {0,0};
  char c[] = "Anna Livia Plurabelle";
  Data val2 = {1024, c};

  // static
  Account ac1;
  Account *ac2 = &ac1;
  double rate;
  int period;
  rate = ac1.rate();
  rate = ac2->rate();
  rate = Account::rate();
  period = Account::period();
  cout << rate << endl;

  Foo foo;
  Bar bar;

  cout << foo.getfoo() << endl;
  cout << foo.FooVal().getfoo() << endl;
  cout << foo.callsFooVal() << endl;
  cout << bar.getbar() << endl;
  cout << bar.getf().FooVal().getfoo() << endl;
  
  return 0;
}
