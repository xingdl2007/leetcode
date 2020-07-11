#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    // binary search
    vector<int> sortedSquares(vector<int>& A)
    {
        for (auto& i : A) {
            i = i * i;
        }
        std::sort(A.begin(), A.end());
        return A;
    }
};

int main(int argc, char* argv[])
{
    Solution so;
    return 0;
}