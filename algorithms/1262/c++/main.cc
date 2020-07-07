#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// interesting
// Represent the state as DP[pos][mod]: maximum possible sum starting in the position "pos"
// in the array where the current sum modulo 3 is equal to mod.

//         | 3 | 6 | 5  |  1 |  8 |
//  mod 0  | 3 | 9 | 9  | 15 | 18 |
//  mod 1  | 0 | 0 | 0  | 10 | 22 |
//  mod 2  | 0 | 0 | 14 | 14 | 23 |
//
//  if nums[pos] % 3  == 0
//  status[pos][0] = status[pos-1][0] + nums[pos]
//  status[pos][1] = status[pos-1][0] == 0 ? 0 : status[pos-1][0] + nums[pos]
//  status[pos][2] = status[pos-1][0] == 0 ? 0 : status[pos-1][0] + nums[pos
//
//  if nums[pos] % 3  == 1
//  status[pos][0] = max((status[pos-1][2] == 0 ? 0 : status[pos-1][2] + nums[pos]), status[pos-1][0])
//  status[pos][1] = max(status[pos-1][0] + nums[pos]), status[pos-1][1])
//  status[pos][2] = max((status[pos-1][1] == 0 ? 0 : status[pos-1][1] + nums[pos]), status[pos-1][2])
//
//  if nums[pos] % 3  == 2
//  status[pos][0] = max((status[pos-1][1] == 0 ? 0 : status[pos-1][1] + nums[pos]), status[pos-1][0])
//  status[pos][1] = max((status[pos-1][2] == 0 ? 0 : status[pos-1][2] + nums[pos]), status[pos-1][1])
//  status[pos][2] = max(status[pos-1][0] + nums[pos], status[pos-1][2])
//
// should have to induct to compact form
//
// class Solution(object):
//     def maxSumDivThree(self, nums):
//         """
//         :type nums: List[int]
//         :rtype: int
//         """
//         dp = [0,0,0]
//         for i in nums:
//             v0 = dp[0]+i
//             v1 = dp[1]+i
//             v2 = dp[2]+i
//             dp[v0%3] = max(dp[v0%3],v0)
//             dp[v1%3] = max(dp[v1%3],v1)
//             dp[v2%3] = max(dp[v2%3],v2)
//         return dp[0]
// 		```
class Solution {
public:
    int maxSumDivThree(vector<int>& nums)
    {
        vector<int> dp{ 0, 0, 0 };
        for (auto n : nums) {
            auto m0 = dp[0] + n;
            auto m1 = dp[1] + n;
            auto m2 = dp[2] + n;

            // subtle
            dp[m0 % 3] = max(dp[m0 % 3], m0);
            dp[m1 % 3] = max(dp[m1 % 3], m1);
            dp[m2 % 3] = max(dp[m2 % 3], m2);
        }
        return dp[0];
    }
};

int main(int argc, char* argv[])
{
    Solution so;

    return 0;
}