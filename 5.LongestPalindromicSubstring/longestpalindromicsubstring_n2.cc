class Solution{
 public:
  // around the center of Palindrom, extend from either side
  string extend(string s, int left, int right) {
  	int l = left, r = right;
	int length = s.size();

	while(l>=0 && r<=length-1 && s[l] == s[r]) {
		l--;
		r++;
	}
	return s.substr(l+1,r-l-1);
  }

  string longestPalindrome(string s) {
	int size = s.size();
	string ret = s.substr(0,1);

	if(size == 0) return "";

	for(int i=0; i<size; ++i) {
		string find = extend(s,i,i);
		if(find.size() > ret.size()) ret = find;

		find = extend(s,i,i+1);
		if(find.size() > ret.size()) ret = find;
	}

	return ret;
  }
};
