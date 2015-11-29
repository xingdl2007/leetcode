/*
 * c++ primer 4ed, generic algorithm
 */

#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <string>
#include <iterator>

using namespace std;

bool isShorter(const string &s1, const string &s2) {
  return s1.size() < s2.size();
} 

bool GT4(const string &s) {
  return s.size() >= 4;
}

// just for print int
void print(int& i) {
  cout << i << " ";
}

int main(int argc, char*argv[]) {
  // intput
  vector<string> words = {"the", "quick", "red", "fox", "jumps",
                          "over", "the", "slow", "red", "turtle"};
  // first sort is used to prepare to invoke unique
  sort(words.begin(), words.end());
  // take care: not const_iterator because of 'erase' function
  vector<string>::iterator it = unique(words.begin(),words.end());
  words.erase(it,words.end());
  
  // second sort: actually no need at all
  stable_sort(words.begin(), words.end(), isShorter);

  vector<string>::size_type wc =
      count_if(words.begin(), words.end(), GT4);

  cout << "wc: " << wc << endl;

  // use the find_if, not the best method, but still can work
  vector<string>::size_type wc2 = 0;
  vector<string>::iterator it2 = words.begin();
  while((it2 = find_if(it2, words.end(), GT4))
        != words.end()) {
    // a good change to do something
    it2++;
    wc2++;
  }
  cout << "wc2: " << wc2 << endl;

  // back_inserter/front_inserter/inserter
  list<int> ilst = {3,3,2,2,1,1,0,0}, ilst2, ilst3;
  cout << "\nilst:" << endl;
  for_each(ilst.begin(),ilst.end(),print);

  vector<int> vec;
  // ilst2 will have {0,1,2,3}
  copy(ilst.begin(),ilst.end(),front_inserter(ilst2));
  cout << "\nilst2:" << endl;
  for_each(ilst2.begin(),ilst2.end(),print);
  
  // ilst3 will have {3,2,1,0}
  // ilst3.begin() just used to point the start point
  copy(ilst.begin(),ilst.end(),inserter(ilst3, ilst3.begin()));
  cout << "\nilst3:" << endl;
  for_each(ilst3.begin(),ilst3.end(),print);
  
  //unique_copy(ilst.begin(), ilst.end(), inserter(vec,vec.begin()));
  unique_copy(ilst.begin(), ilst.end(), back_inserter(vec));
  cout << "\nvec:" << endl;
  for_each(vec.begin(),vec.end(),print);

  cout << endl;
  
  // reverse_iterator
  vector<int> ivec = {0,1,2,3,4,5,6,7,8,9};
  sort(ivec.rbegin(),ivec.rend());
  cout << endl;
  
  for_each(ivec.begin(),ivec.end(),print);
  cout << endl;

  // output 'FIRST'
  string s("FIRST,MIDDLE,LAST");
  string::iterator sit = find(s.begin(),s.end(),',');
  cout << string(s.begin(),sit) << endl;

  // output 'LAST'
  string::reverse_iterator rsit = find(s.rbegin(),s.rend(),',');
  cout << string(s.rbegin(),rsit) << endl; /*Note: this will output TSAL*/
  cout << string(rsit.base(),s.end()) << endl; /*This is the right way*/
  
  // iostream_iterator
  /*istream_iterator<int> cin_it(cin);
    istream_iterator<int> eof;
  
    // method 1: awesome and cool
    vector<int> v1(cin_it,eof);
  
    // method 2
    vector<int> v2;
    while(cin_it != eof) {
    v2.push_back(*cin_it++);
    }
    for_each(v2.begin(),v2.end(),print);
  
    ostream_iterator<int> out_iter(cout, " ");
    istream_iterator<int> in_iter(cin);
    vector<int> v3(in_iter,eof);
    sort(v3.begin(),v3.end());
    unique_copy(v3.begin(), v3.end(), out_iter);
  */

  return 0;
}
