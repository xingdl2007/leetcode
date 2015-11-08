/*
 * c++ primer 4nd ed; chapter10 associate container
 * pair, map, set, multimap, multiset
 * 10.17 ~ 10.20
 */
/*
 * A program to transform words.
 * Take tow arguments: The first is the name of the word transformating file
 *                     The second is name of the input to transform
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <utility>
#include <stdexcept> // for runtime_error()

using namespace std;

// helper function to open input file
ifstream& open_file(ifstream& in, const string& file) {
  in.close();
  in.clear();
  in.open(file.c_str());
  return in;
}

int main(int argc, char*argv[]) {
  // map to hold the word transformation pairs:
  // key is the word to look for in the input; vlaue is word to use in the output
  map<string,string> trans_map;
  string key, value;

  if(argc != 3)
    throw runtime_error("worong number of arguments");

  // open transformation file and check that open successed
  ifstream map_file;
  if(!open_file(map_file,argv[1]))
    throw runtime_error("no transformation file");
  
  // read the transformation map and build the map
  while(map_file >> key >> value)
    trans_map.insert(make_pair(key,value));
  
  // ok, now we're ready to do the transformations
  // open the input file and check that the open succeeded
  ifstream input;
  if(!open_file(input,argv[2]))
    throw runtime_error("no input file");
  
  string line; // hold each line of the input
  while(getline(input,line)) {
    istringstream stream(line);
    string word;
    bool firstword = true; // controls whether a space is printed
    while(stream>>word) {
      map<string,string>::iterator it =
          trans_map.find(word);
        if(it != trans_map.end())
          word = it->second;
        
        if(firstword) firstword = false;
        else cout << " ";
        cout << word;
    }
    cout << endl;
  }
  
  return 0;
}

