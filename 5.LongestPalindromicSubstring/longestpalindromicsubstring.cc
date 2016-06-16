class Solution{
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
			// bug: for 'lplooooor'
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
