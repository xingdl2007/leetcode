class Solution {
    public:
        string convert(string s, int numRows) {
            int mod = 2*numRows-2;
            string *rows[numRows];
            string ret;

            if(numRows == 1) return s;

            for(int i=0; i<numRows; ++i) {
                rows[i] = new string();
            }

            for(int i=0; i<s.size(); ++i) {
                int reminder = i%mod;
                if(reminder >= numRows) {
                    rows[mod - reminder]->append(s,i,1);
                } else {
                    rows[reminder]->append(s,i,1);
                }
            }

            for(int i=0; i<numRows; ++i) {
                //cout << *rows[i] << endl;
                ret += *rows[i];
            }
            return ret;
        }
};