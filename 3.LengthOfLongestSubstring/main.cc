#include <string>
#include <iostream>
#include <map>
using namespace std;

#include "lengthoflongestsubstring.cc"

/*
 * consider the corner case
 */
int main(int argc, char*argv[])
{
  //string s("abcabcbb");
  string s("dvdf");
  //string s("yoyn");
  cout << (new Solution())->lengthOfLongestSubstring(s) << endl;
  return 0;
}
