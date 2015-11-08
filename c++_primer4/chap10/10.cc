/*
 * c++ primer 4nd ed; chapter10 associate container
 * pair, map, set, multimap, multiset
 * 10.1, 10.2, 10.12
 */

// 10.5 map<string,list<int> >

#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(int argc,char*argv[]) {
  
  /* 10.1 and 10.2
  string s;  int i;
  pair<string,int> p;
  vector< pair<string,int> > vec;

  while(cin >>s >>i) {
    // Note: no 'new'
    // method 1
    //p = pair<string,int>(s,i);

    // method 2
    //p = make_pair(s,i);

    // method 3
    p.first = s;
    p.second = i;
    
    vec.push_back(p);
    break;
    }*/

  // 10.9
  cout << "10.9" << endl;
  map<string,int> word_count;
  string word;
  typedef map<string,int>::value_type valType;

  cout<< word_count["foobar"] << endl;
  
  // method one
  //while(cin>>word) ++word_count[word];

  // method two
  while(cin >> word) {
    pair<map<string,int>::iterator, bool> ret =
        word_count.insert(make_pair(word, 1));
    if(!ret.second) ++ret.first->second;
  }
  word_count.insert(make_pair("Anna",1));
  word_count.insert(map<string,int>::value_type("Bob",1));
  word_count.insert(valType("Mike",1));
  
  // take note of the print logs
  map<string,int>::const_iterator it = word_count.begin();
  
  while(it != word_count.end()) {
    cout<< "word: " << it->first << ", times: "
        << it->second << endl;

    /* use the erase(k) version is more safe */
    word = it->first;
    if(word_count.erase(word))
      cout << "ok, "<< word << " removed" << endl;
    else cout << "oops: "<< word << " not found!" << endl;
    
    ++it;
  }

  map<string,int>::const_iterator its = word_count.find("foobar");
  if(its != word_count.end())
    cout << its->second << endl;

  cout << word_count.size() << endl;

  // error: can be the end()
  // word_count.erase(word_count.end());
  word_count.insert(make_pair("foobar",1));
  word_count.erase(word_count.begin(),word_count.end());
  
  cout << word_count.size() << endl;
  return 0;
}
