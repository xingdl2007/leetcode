/*
 * c++ primer 4nd ed; chapter10 associate container
 * chapter 10.6 : text search program, container
 */

#include <map>
#include <set>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
//#include <assert.h> // for assert
#include <stdexcept>

using namespace std;

class TextQuery {
 public:
  // typedef to make declaration easier
  typedef vector<string>::size_type line_no;

  /* interface:
   * read_file builds internal data structure for the given file
   * run_query finds the given word and returns set of lines on which it apperas
   * text_line returns a requested line from the input file
   */
  void read_file(ifstream& is) { store_file(is); build_map();  }
  // a const version
  set<line_no> run_query(string&) const;
  
  // a non-const version
  set<line_no> run_query(string&);
  string text_line(line_no) const;
 private:
  // utility function used by read_file
  void store_file(ifstream&); // store input file
  void build_map(); // associated each word with a set of line numbers
  // remember the whole input file
  vector<string> lines_of_texts;
  map<string, set<line_no> > word_map;
};

// if map does not contain the s, return a empty set
set<TextQuery::line_no> TextQuery::run_query(string& s) {
  if(word_map.count(s)) return word_map[s];
  return set<line_no>();
}

set<TextQuery::line_no> TextQuery::run_query(string& s) const{
  map<string, set<line_no> >::const_iterator it = word_map.find(s);
  if(it == word_map.end())
    return set<line_no>();
  else
    return it->second;
}

string TextQuery::text_line(line_no ln) const{
  // method from leveldb
  //assert(ln < lines_of_texts.size());
  if(ln < lines_of_texts.size())
    return lines_of_texts[ln];
  else
    // or another method: more c++
    throw std::out_of_range("line number out of range");
}

void TextQuery::store_file(ifstream& infile) {
  string line;
  while(getline(infile,line)) lines_of_texts.push_back(line);
}

void TextQuery::build_map() {
  string line,word;
  line_no ln = 1, size = lines_of_texts.size();
  while(ln++ < size) {
    line = lines_of_texts[ln-1];
    stringstream word_line(line);
    while(word_line >> word)  word_map[word].insert(ln);
  }
}

// a useful helper function
ifstream& open_file(ifstream& in, const string& file) {
  in.close();
  in.clear();
  in.open(file.c_str());
  return in;
}

// pretty print
void print_result(const set<TextQuery::line_no>& locs,
                  const string& sought, const TextQuery& file) { 
  typedef set<TextQuery::line_no> line_nums;
  line_nums::size_type size = locs.size();
  cout << "\n" << sought << " occurs "
       << size << " time(s)" << endl;

  line_nums::const_iterator it = locs.begin();
  for(; it!=locs.end();++it) {
    cout << "\t(line "
         << (*it) + 1 << ") "
         << file.text_line(*it) << endl;
  }
}

// the driver part
int main(int argc,char*argv[]) {
  // open the file from which user will query words
  ifstream infile;
  if(argc<2 || !open_file(infile,argv[1])) {
    cerr<< "No input file!" << endl;
    return -1;
  }

  TextQuery tq;
  tq.read_file(infile);
  while(true) {
    cout << "enter word to look for, or q to quit: ";
    string s;
    cin >> s;
    if( !cin || s == "q") break;
    set<TextQuery::line_no> locs = tq.run_query(s);
    print_result(locs,s,tq);
  }
  
  return 0;
}
