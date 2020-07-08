#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 这个问题的难点同样是进行建模，如果用union-find建模，有一个小小的问题
// 如何证明或者保证在一个group中的索引值，可以达到全排列的效果，也就是能够通过交换得到最小值
// 这个看起来不是那么明显，但应该是成立的，求证明
// https : //leetcode.com/problems/smallest-string-with-swaps/discuss/387809/C%2B%2B-simple-solution-using-disjoint-set-(148ms-beat-90)
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs)
    {
        return "";
    }
};

int main(int argc, char* argv[])
{
    Solution so;
    return 0;
}