#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 需要定义节点，来表示集合，通过坐标的关系来决定Union，最后find独立的group个数，
// 总数减去独立的个数就是能够删除的最多的个数
class Solution {
public:
    int removeStones(vector<vector<int>>& stones)
    {
        return 0;
    }
};

int main(int argc, char* argv[])
{
    Solution so;
    {
        vector<vector<int>> stones{ { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 2 }, { 2, 1 }, { 2, 2 } };
        std::cout << so.removeStones(stones) << std::endl;
    }

    {
        vector<vector<int>> stones{ { 0, 0 }, { 0, 2 }, { 1, 1 }, { 2, 0 }, { 2, 2 } };
        std::cout << so.removeStones(stones) << std::endl;
    }

    {
        vector<vector<int>> stones{ { 0, 0 } };
        std::cout << so.removeStones(stones) << std::endl;
    }
    return 0;
}