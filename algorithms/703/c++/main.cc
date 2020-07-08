#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// int k = 3;
// int[] arr = [4,5,8,2];
// KthLargest kthLargest = new KthLargest(3, arr); // [8,5,4,2]
// kthLargest.add(3);   // [8,5,4,3,2], returns 4
// kthLargest.add(5);   // [8,5,5,4,3,2], returns 5
// kthLargest.add(10);  // [10,8,5,5,4,3,2], returns 5
// kthLargest.add(9);   // [10,9,8,5,5,4,3,2], returns 8
// kthLargest.add(4);   // [10,9,8,5,5,4,4,3,2], returns 8

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums)
        : k_(k)
        , queue_(nums.begin(), nums.end())
    {
    }

    int add(int val)
    {
        queue_.push(val);
        while (queue_.size() > k_) {
            queue_.pop();
        }
        return queue_.top(); // smallest, top of heap
    }

private:
    const int k_;
    // compare return true, will output later
    std::priority_queue<int, std::vector<int>, std::greater<int>> queue_;
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

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main(int argc, char* argv[])
{
    vector<int> nums{ 4, 5, 8, 2 };
    KthLargest obj(3, nums);
    std::cout << obj.add(3) << std::endl;
    std::cout << obj.add(5) << std::endl;
    std::cout << obj.add(10) << std::endl;
    std::cout << obj.add(9) << std::endl;
    std::cout << obj.add(4) << std::endl;
    return 0;
}