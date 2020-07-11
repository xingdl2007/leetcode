#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 6.4 : [2,7,4,1,8,1]
class Solution {
public:
    int lastStoneWeight(vector<int>& stones)
    {
        // construct max-heap
        std::priority_queue<int> queue(stones.begin(), stones.end());

        while (queue.size() > 1) {
            int large = queue.top();
            queue.pop();
            int small = queue.top();
            queue.pop();
            if (large > small) {
                queue.push(large - small);
            }
        }
        return queue.empty() ? 0 : queue.top();
    }
};

int main(int argc, char* argv[])
{
    Solution so;
    vector<int> data({ 2, 7, 4, 1, 8, 1 });
    std::cout << so.lastStoneWeight(data) << std::endl;

    {
        vector<int> data({ 2, 2 });
        std::cout << so.lastStoneWeight(data) << std::endl;
    }

    return 0;
}