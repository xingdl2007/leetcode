/*
 * c++ primer 4ed, Standard IO Library
 * 8.3 and 8.4
 * 8.6, 8.7, 8.8, 8.9, 8.10
 */

#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>

using namespace std;

istream& foo(istream& in) {
  string sval;
  while(in >> sval) {
    cout << sval << endl;
  }
  /* a warning to user, may not necessary */
  //cout << "EOF" << endl;
  in.clear();
  return in;
}


// 8.9
vector<string> read_line(const string& file) {
  vector<string> vec;
  ifstream input(file.c_str());
  string line;

  while(getline(input,line)) {
    vec.push_back(line);
  }

  return vec;
}

// 8.10
vector<string> read_word(const string& file) {
  vector<string> vec;
  ifstream input(file.c_str());
  string line,word;
  istringstream words;

  while(getline(input,line)) {
    // set the binding string
    words.str(line);
    while(words>>word) vec.push_back(word);
    // here: clear() is necessary
    words.clear();
  }

  return vec;
}

vector<string> read_word2(const string& file) {
  vector<string> vec;
  ifstream input(file.c_str());
  string line,word;

  while(getline(input,line)) {
    istringstream words(line);
    while(words>>word) vec.push_back(word);
  }

  return vec;
}


void print(vector<string> vec) {
  vector<string>::const_iterator it = vec.begin();
  while(it != vec.end()) {
    cout << *it << endl;
    ++it;
  }
}

// a useful helper function
ifstream& open_file(ifstream& in, const string& file) {
  in.close();
  in.clear();
  in.open(file.c_str());
  return in;
}

// 8.13
ofstream& open_file_o(ofstream& out, const string& file) {
  out.close();
  out.clear();
  out.open(file.c_str());
  return out;
}

int main(int argc, char*argv[]) {
  //8.3 and 8.4
  //foo(cin);

  //8.6
  ifstream infile("namedfile.txt");
  //foo(infile);

  //8.7.1
  string s;
  vector<string> files;
  files.push_back("1.txt");
  files.push_back("2.txt");
  files.push_back("4.txt");
  files.push_back("3.txt");

  cout<< "8.7.1" << endl;
  vector<string>::const_iterator it = files.begin();
  while(it != files.end()) {
    ifstream input(it->c_str());
    if(!input) {
      cerr << "Error: open file " << *it << " failed. " << endl;
      ++it;
      continue;
    }
    while(input >> s)  cout << s;
    cout << endl;
    ++it;
  }


  // 8.7.2
  cout<< "8.7.2" << endl;
  ifstream input;
  it = files.begin();
  while(it != files.end()) {
    input.open(it->c_str());
    if(!input) {
      cerr << "Error: open file " << *it << " failed. " << endl;
    }
    else
    {
      while(input >> s)  cout << s;
      cout << endl;
      input.close();
      /* seems no need to invoke clear(), little different with the book */
      input.clear();
    }
    ++it;
  }

  // 8.9
  cout<< "8.9" << endl;
  vector<string> lines;
  lines = read_line("1.txt");
  print(lines);

  // 8.10
  cout<< "8.10" << endl;
  vector<string> words;
  words = read_word("1.txt");
  //words = read_word2("1.txt");
  print(words);

  // 8.14
  cout << "8.14" << endl;
  // why open_file() will return the 'reference of stream'
  open_file(input,"1.txt");
  foo(input);

  // 8.15
  cout << "8.15" << endl;
  istringstream hello("Hello world.");
  foo(hello);

  // 8.16
  cout << "8.16" << endl;
  vector<string>::const_iterator sit = lines.begin();
  while(sit != lines.end()) {
    istringstream line(*sit);
    while(line >> s) cout << "8.16 "<<s << endl;
    ++sit;
  }
  
  return 0;
}
