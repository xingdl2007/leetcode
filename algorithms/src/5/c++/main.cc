#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  // around the center of Palindrom, extend from either side
  string extend(string s, int left, int right) {
    int l = left, r = right;
    int length = s.size();

    while (l >= 0 && r <= length - 1 && s[l] == s[r]) {
      l--;
      r++;
    }
    return s.substr(l + 1, r - l - 1);
  }

  string longestPalindrome(string s) {
    int size = s.size();
    string ret = s.substr(0, 1);

    if (size == 0)
      return "";

    for (int i = 0; i < size; ++i) {
      string find = extend(s, i, i);
      if (find.size() > ret.size())
        ret = find;

      find = extend(s, i, i + 1);
      if (find.size() > ret.size())
        ret = find;
    }

    return ret;
  }
};

int main() {
  string s1 = (new Solution())->longestPalindrome("hello");
  cout << s1 << endl;

  string s2 = (new Solution())->longestPalindrome("helleh");
  cout << s2 << endl;

  string s3 = (new Solution())->longestPalindrome("abcdefg");
  cout << s3 << endl;

  string s4 = (new Solution())->longestPalindrome("heliloabccbaefg");
  cout << s4 << endl;

  string s5 = (new Solution())->longestPalindrome(
      "cwziydanrqvsdtvnnqgjnbrvvwxwqojeqgxhwxdoktjktulemwpbeqscbbtbfvkxsrjetfdrovcrdwzfmnnihtgxybuairswfewvpuscocqifuwylhssldpjrawqdrbvkykpaggspbfrulcktpbofchzikhzxhpocgvdbwpewpywsgqbczmamprklaoovcfecwchhmsaqkhvuvvzjblmgvqpqtnlipgqsanvovylpmxlmxvymppdykphhaamtxjnnlsqfwjwhyywgurteaummwhvavxbcpgrfffxrowluqmqjaugryxdmwvyokdcfcvcytxpixbvwrdgzctejdoaavgtezexmvxgrkpnayvfarkyoruofqmpnsqdzojxqrjsnfwsbzjmaoigytygukqlrcqaxazvmytgfghdczvzphfdbnxtklaiqqsotavdmhiaermluafheowcobjqmrkmlzyas");
  cout << s5 << endl;

  string s6 = (new Solution())->longestPalindrome("ccc");
  cout << s6 << endl;

  string s7 = (new Solution())->longestPalindrome("aaaa");
  cout << s7 << endl;

  string s8 = (new Solution())->longestPalindrome("bbbbb");
  cout << s8 << endl;

  string s9 = (new Solution())->longestPalindrome(
      "lqlvciwekzxapmjxyddlaoqhfhwphamsyfwjinkfvciucjhdgwodvmnpkibumexvlsxxumvrznuuyqfavmgwfnsvfbrvqhlvhpxaqehsiwxzlvvtxsnmlilbnmvnxyxitxwoahjricdjdncvartepfpdfndxqoozkfpdmlpvshzzffsspdjzlhmamqooooor");
  cout << s9 << endl;

  string s10 = (new Solution())->longestPalindrome("lplooooor");
  cout << s10 << endl;

  string s11 = (new Solution())->longestPalindrome(
      "jhgtrclvzumufurdemsogfkpzcwgyepdwucnxrsubrxadnenhvjyglxnhowncsubvdtftccomjufwhjupcuuvelblcdnuchuppqpcujernplvmombpdttfjowcujvxknzbwmdedjydxvwykbbamfnsyzcozlixdgoliddoejurusnrcdbqkfdxsoxxzlhgyiprujvvwgqlzredkwahexewlnvqcwfyahjpeiucnhsdhnxtgizgpqphunlgikogmsffexaeftzhblpdxrxgsmeascmqngmwbotycbjmwrngemxpfakrwcdndanouyhnnrygvntrhcuxgvpgjafijlrewfhqrguwhdepwlxvrakyqgstoyruyzohlvvdhvqmzdsnbtlwctetwyrhhktkhhobsojiyuydknvtxmjewvssegrtmshxuvzcbrabntjqulxkjazrsgbpqnrsxqflvbvzywzetrmoydodrrhnhdzlajzvnkrcylkfmsdode");
  cout << s11 << endl;

  return 0;
}


/*
 *
 * class Solution{
 public:
  string longestPalindrome(string s) {
  	string ret;
	string::iterator start = s.begin(), end;

	for(start = s.begin(); start < s.end()-ret.size(); ++start) {
		string::iterator last = start + ret.size() - 1;
		string::iterator pre = s.end();
		string::size_type half = 0;

		for(end = last+1; end < s.end(); ++end) {
			// find the turn, first check pre then check last
			// corner case, cover all the same char
			// bug: for 'lplooooor', seems not enough
			if(*start == *end && *start == *last) {
				half = 0;
			}
			else if(pre != s.end() && *end == *pre ) {
				half = end-start-2;
			} else if(*end == *last) {
				half = end-start-1;
			}

			if(end + half < s.end()) 	end += half;

			string sub = s.substr(start-s.begin(),end-start+1);
			//cout << sub << endl;
			if(isPalindrome(sub) && (sub.size() > ret.size())) {
				ret = sub;
			}

			pre = last;
			last = end;
		}
	}
	return ret;
  }

  bool isPalindrome(string s) {
  	if(s.size() == 0) return false;
	string::iterator lo = s.begin(), hi = s.end()-1;
	while(lo < hi) {
		if(*lo != *hi) return false;
		lo++;
		hi--;
	}
	return true;
  }
};

 */