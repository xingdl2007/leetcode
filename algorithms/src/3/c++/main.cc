#include <string>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int pos[item_count];
    std::fill(pos, pos + item_count, -1);
    int i = 0, maxlen = 0;
    for (int j = 0; j < s.size(); ++j) {
      if (pos[s[j]] >= i) {
        i = pos[s[j]] + 1;
      }
      pos[s[j]] = j;
      maxlen = std::max(j - i + 1, maxlen);
    }
    return maxlen;
  }
private:
  const static int item_count = 256;
};

/*
 * consider the corner case
 */
int main(int argc, char *argv[]) {
  //string s("abcabcbb");
  string s("dvdf");
  //string s("yoyn");
  cout << (new Solution())->lengthOfLongestSubstring(s) << endl;
  return 0;
}

/*
class Solution{
public:
  int lengthOfLongestSubstring(string s){
    int length = 0;
    int index = 0;
    map<char,int> substring;
    string::iterator iter = s.begin();
    map<char,int>::iterator miter,duplicate;
    for(;iter != s.end(); ++iter,++index){
      if((duplicate=substring.find(*iter)) != substring.end()){
        if(length < substring.size()){
          length = substring.size();
        }
        for(miter=substring.begin(); miter!=substring.end();){
          if(miter->second <= duplicate->second){
            substring.erase(miter++);
          }else
            miter++;
        }
      }
      substring.insert(make_pair(*iter,index));
    }

    if(length < substring.size()){
      length = substring.size();
    }

    return length;
  }
};
*/