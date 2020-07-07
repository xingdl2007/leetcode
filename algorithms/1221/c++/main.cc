#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int balancedStringSplit(string s)
    {
        int ret = 0, cnt = 0;
        for (auto c : s) {
            if (c == 'R')
                ++cnt;
            if (c == 'L')
                --cnt;
            if (cnt == 0)
                ++ret;
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    Solution so;
    std::cout << so.balancedStringSplit("RLRRLLRLRL") << std::endl;
    std::cout << so.balancedStringSplit("RLLLLRRRLR") << std::endl;
    std::cout << so.balancedStringSplit("LLLLRRRR") << std::endl;
    std::cout << so.balancedStringSplit("RLRRRLLRLL") << std::endl;

    return 0;
}