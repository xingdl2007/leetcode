#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

// interesting: bit operation, and very easy to understand
class Solution {
public:
    int divide(int dividend, int divisor)
    {
        bool f1 = (dividend < 0);
        bool f2 = (divisor < 0);
        long long q = 0;
        long long divid = abs(dividend);
        long long divis = abs(divisor);

        // binary search, may be fast
        for (int i = 31; i >= 0; --i) {
            if ((divis << i) <= divid) {
                divid -= (divis << i);
                q |= (1LL << i);
            }
        }

        if (f1 ^ f2) {
            if (-q < INT_MIN)
                return INT_MIN;
            else
                return -q;
        } else {
            if (q > INT_MAX)
                return INT_MAX;
            else
                return q;
        }
    }
};

int main(int argc, char* argv[])
{
    Solution so;
    return 0;
}