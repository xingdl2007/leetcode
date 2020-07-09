#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    // union two friend cycle
    void unionCircle(vector<int>& circle, int lhs, int rhs)
    {
        for (auto& c : circle) {
            if (c == lhs) {
                c = rhs;
            }
        }
    }

    int findCircleNum(vector<vector<int>>& M)
    {
        int ret = M.size();
        vector<int> circle; // first, each person is a single friend circle
        for (int i = 0; i < M.size(); ++i) {
            circle.push_back(i);
        }

        for (int i = 0; i < M.size(); ++i) {
            for (int j = i + 1; j < M.size(); ++j) {
                if (M[i][j] && circle[i] != circle[j]) {
                    --ret;
                    unionCircle(circle, circle[j], circle[i]);
                }
            }
        }
        return ret;
    }
};

int main()
{
    Solution so;
    return 0;
}