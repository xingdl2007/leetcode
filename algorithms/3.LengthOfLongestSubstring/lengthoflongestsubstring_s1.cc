class Solution{
 public:
  int lengthOfLongestSubstring(string s){
    int pos[item_count];
    std::fill(pos,pos+item_count,-1);
    int i=0, maxlen=0;
    for(int j=0; j<s.size(); ++j){
      if(pos[s[j]]>=i){
        i = pos[s[j]] + 1;
      }
      pos[s[j]] = j;
      maxlen = std::max(j-i+1,maxlen);
    }
    return maxlen;
  }
 private:
  const static int item_count = 256;
};

  
