/*
 * c++ primer 4nd ed; chapter10 associate container
 * multimap, multiset
 * 10.26 ~ 10.29
 */

#include <iostream>
#include <map>
#include <set>
#include <utility>

using namespace std;

int main(int argc, char*argv[]) {
  multimap<string,string> authors;

  // insert
  authors.insert(make_pair("Barth, John", "Sot-Weed Factor"));
  authors.insert(make_pair("Barth, John", "Lost in the Funhouse"));
  authors.insert(make_pair("Barth, John", "Something interesting"));

  string search_item("Barth, John");
  multimap<string,string>::size_type cnt;
  typedef multimap<string,string>::iterator authors_it;
  authors_it iter;
  
  // find
  // method one: use count and find
  cout << "Method One: use count and find " << endl;
  cnt = authors.count(search_item);
  iter = authors.find(search_item);
  for(int i = 0; i != cnt && iter != authors.end(); ++i, ++iter) {
    cout << iter->second << endl;
  }

  // method two: use lower_bound() and upper_bound()
  cout << "Method two: use lower_bound() and upper_bound() " << endl;
  authors_it beg = authors.lower_bound(search_item);
  authors_it end = authors.upper_bound(search_item);
  while(beg != end) {
    cout << beg->second << endl;
    ++beg;
  }

  // method three: use equal_range()
  cout << "Method three: use equal_range()" << endl;
  pair<authors_it, authors_it> range = authors.equal_range(search_item);
  while(range.first != range.second) {
    cout << range.first->second << endl;
    ++range.first;
  }
  
  // some test data for 10.28
  authors.insert(make_pair("Aarth, John", "Sot-Weed Factor"));
  authors.insert(make_pair("Aarth, John", "Lost in the Funhouse"));
  authors.insert(make_pair("Aarth, John", "Something interesting"));

  authors.insert(make_pair("Carth, John", "Sot-Weed Factor"));
  authors.insert(make_pair("Carth, John", "Lost in the Funhouse"));
  authors.insert(make_pair("Carth, John", "Something interesting"));

  authors.insert(make_pair("Darth, John", "Sot-Weed Factor"));
  authors.insert(make_pair("Darth, John", "Lost in the Funhouse"));
  authors.insert(make_pair("Darth, John", "Something interesting"));

  authors.insert(make_pair("Harth, John", "Sot-Weed Factor"));
  authors.insert(make_pair("Harth, John", "Lost in the Funhouse"));
  authors.insert(make_pair("Harth, John", "Something interesting"));

  // need format printing, skip find
  set<string> char_set;
  string author_name;
  iter = authors.begin();
  while(iter != authors.end()) {
      author_name = iter->first;
      end = authors.upper_bound(author_name);
      author_name.resize(1);
      if(!char_set.count(author_name)) {
        char_set.insert(author_name);
        cout << "Author Names Beginning with '"<< author_name << "'" << endl;
      }
      cout << iter->first;
      while(iter != end) {
        cout << ", " << iter->second;
        ++iter;
      }
      cout << endl;
      iter = end;
  }
  
  // erase
  cnt = authors.erase(search_item);
  cout << cnt << endl;

  return 0;
}
