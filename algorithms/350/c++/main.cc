#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> ret;
        std::unordered_map<int, int> table;
        for (auto i : nums1) {
            auto it = table.find(i);
            if (it == table.end())
                table.insert({ i, 1 });
            else {
                ++it->second;
            }
        }

        for (auto i : nums2) {
            auto it = table.find(i);
            if (it != table.end() && it->second != 0) {
                ret.push_back(i);
                --it->second;
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