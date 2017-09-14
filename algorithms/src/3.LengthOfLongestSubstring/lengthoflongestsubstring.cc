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
        /*Note:should not always clear*/
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
