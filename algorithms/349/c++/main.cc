#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> ret;
        std::unordered_map<int, int> table;
        for (auto i : nums1) {
            table.insert({ i, 1 });
        }
        for (auto i : nums2) {
            auto it = table.find(i);
            if (it != table.end() && it->second == 1) {
                ret.push_back(i);
                it->second = 0;
            }
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    Solution so;
    return 0;
}