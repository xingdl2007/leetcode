/*
 * c++ primer 4nd ed; chapter10 associate container
 * set
 */

#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdexcept>

using namespace std;

// helper function to open input file
ifstream& open_file(ifstream& in, const string& file) {
  in.close();
  in.clear();
  in.open(file.c_str());
  return in;
}

// same name function
string singular(string &word) {
  string singular = word;

  // method 1: index
  /*if(word[word.size()-1] == 's')
    singular = string(word,0,word.size()-1);
  */

  // method 2: iterator, just the same with method 1
  if(*(word.end()-1) == 's')
    singular = string(word.begin(),word.end()-1);

  return singular;
}

void singular(ifstream& exclude_file) {
  set<string> excluded;
  string word;
  while(exclude_file >> word) excluded.insert(word);

  while(cin >> word) {
    if(excluded.count(word)) cout << word << endl;
    else
      cout << singular(word) << endl;
  }
}

void restricted_wc(ifstream& remove_file,
                   map<string,int> &word_count)
{
  set<string> excluded;
  string remove_word;
  while(remove_file>>remove_word)
    excluded.insert(remove_word);
  string word;
  while(cin>>word)
    if(!excluded.count(word)) ++word_count[word];
}

int main(int argc, char*argv[]) {
  vector<int> ivec;
  for(vector<int>::size_type i=0; i<10; ++i) {
    ivec.push_back(i);
    ivec.push_back(i);
  }

  set<int> iset(ivec.begin(),ivec.end());
  cout << iset.size() << endl;
  cout << ivec.size() << endl;

  ifstream input;
  if(!open_file(input,"words.txt"))
    throw runtime_error("no excluded file");

  singular(input);
}
