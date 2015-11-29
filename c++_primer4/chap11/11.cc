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

// simple algorithm: just a try
int main(int argc, char*argv[]) {
  int search = 47;
  int ia[6] = {27,210,12,47,109,83};
  // Note: only supported in C++11
  vector<int> vec = {27,210,12,47,109,83};
  list<int> ls(vec.begin(),vec.end());
  
  vector<int>::const_iterator vret = find(vec.begin(), vec.end(), search);
  list<int>::const_iterator lret = find(ls.begin(),ls.end(),search);
  int *aret = find(ia,ia+6,search);

  vector<int>::size_type vsz = count(vec.begin(),vec.end(),search);
  list<int>::size_type lsz = count(ls.begin(),ls.end(),search);
  int asz = count(ia,ia+6,search);

  if(vret != vec.end()) cout << "Vector: " << *vret
                             << " " <<  vsz << " time" << endl;
  if(lret != ls.end()) cout << "List: " << *lret
                            << " " << lsz << " time" << endl;
  if(aret != ia + 6) cout << "Array: " << *aret
                          << " " << asz << " time" << endl;

  // read-only
  int sum = accumulate(vec.begin(),vec.end(),0);
  cout << "Vector's sum: " << sum << endl;

  // cool
  vector<string>svec = {"hello", " world"};
  string s = accumulate(svec.begin(),svec.end(),string(""));
  cout << "sum:" << s << endl;

  // find_fist_of
  // for illustration purpose only, there are much faster ways to
  // solve this problem
  size_t cnt = 0;
  list<string> roster1 = {"john","mark","cristina","mere"};
  list<string> roster2(++roster1.rbegin(), --roster1.rend());
  
  list<string>::iterator it = roster1.begin();
  while((it = find_first_of(it,roster1.end(),
                            roster2.begin(), roster2.end()))
        != roster1.end()) {
    ++cnt;
    ++it;
  }

  cout << cnt << endl;

  vector<double> dvec = {1.1,2.99999,3.0};
  double dsum = accumulate(dvec.begin(),dvec.end(),0.0);
  cout << "Double Vector's sum: " << dsum << endl;

  // write algorithm
  fill(vec.begin(),vec.end(),0);
  sum = accumulate(vec.begin(),vec.end(),0);
  cout << "Vector's sum: " << sum << endl;

  fill(vec.begin(),vec.begin()+vec.size()/2,10);
  sum = accumulate(vec.begin(),vec.end(),0);
  cout << "Vector's sum: " << sum << endl;

  vector<int> ivec ;//= {1,1,1,1,1,1,1,1,1,1};
  //why 'reserve' method does not work? because ivec is stil empty
  //but 'resize()' will work
  ivec.reserve(10);
  ivec.resize(10, 1);
  fill_n(ivec.begin(),10,2);
  sum = accumulate(ivec.begin(),ivec.end(),0);
  cout << "Vector's sum: " << sum << endl;

  // back_inserter
  vector<int> nvec;
  fill_n(back_inserter(nvec),100,1);
  sum = accumulate(nvec.begin(),nvec.end(),0);
  cout << "Vector's sum: " << sum << endl;

  // copy
  vector<int> mvec;
  copy(nvec.begin(),nvec.end(),back_inserter(mvec));
  sum = accumulate(mvec.begin(),mvec.end(),0);
  cout << "Vector's sum: " << sum << endl;

  // replace
  replace(mvec.begin(),mvec.end(),1,2);
  sum = accumulate(mvec.begin(),mvec.end(),0);
  cout << "Vector's sum: " << sum << endl;

  // replace_copy
  vector<int> pvec;
  replace_copy(mvec.begin(),mvec.end(),back_inserter(pvec),2,3);
  sum = accumulate(pvec.begin(), pvec.end(),0);
  cout << "Vector's sum: " << sum << endl;
}
