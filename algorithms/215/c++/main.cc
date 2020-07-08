#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        std::priority_queue<int,
            std::vector<int>,
            std::greater<int>>
            queue(nums.begin(), nums.end());
        while (queue.size() > k) {
            queue.pop();
        }
        return queue.top();
    }
};

// bottom up construction of heap
// void heapit(std::vector<int>& queue_)
// {
//     // bottom-up construction
//     // leaf: 2*i+1, 2*i+2;
//     for (int i = (queue_.size() + 1) / 2 - 1; i >= 0; i--) {
//         int v = queue_[i], j, k = i;
//
//         bool done = false;
//         // still have leaf?
//         while (!done && (2 * k + 1) < queue_.size()) {
//             j = 2 * k + 1; // leaf
//             if (j < queue_.size() - 1) {
//                 if (queue_[j] < queue_[j + 1]) {
//                     j = j + 1;
//                 }
//             }
//             if (v < queue_[j]) {
//                 queue_[k] = queue_[j]; // swap, but only assin is enough
//                 k = j;
//             } else {
//                 done = true;
//             }
//         }
//         queue_[k] = v;
//     }
// }

int main(int argc, char* argv[])
{
    Solution so;
    {
        vector<int> nums{ 3, 2, 1, 5, 6, 4 };
        std::cout << so.findKthLargest(nums, 2) << std::endl;
    }
    {
        vector<int> nums{ 3, 2, 3, 1, 2, 4, 5, 5, 6 };
        std::cout << so.findKthLargest(nums, 4) << std::endl;
    }
    return 0;
}