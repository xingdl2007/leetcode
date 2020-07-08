#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// it's a graph problem, can use DFS to search each path
// you must build a graph first

// how can it be solved by Union-Find?
// https://leetcode.com/problems/evaluate-division/discuss/88170/0ms-C%2B%2B-Union-Find-Solution-EASY-to-UNDERSTAND
// 这个问题主要还是难在对问题的建模上，无论是图还是union-find，首先需要进行建模
// 然后根据模型，对问题求解

// 根据提示容易想到是图的问题，union-find的解法也十分惊艳，不过需要考虑union时的比例问题，需要进行调整
// union-find的解法接近于实际的数学计算，或者在模拟计算的过程；而图的解法则偏计算机算法

class Solution {
public:
    vector<double> calcEquation(
        vector<vector<string>>& equations,
        vector<double>& values,
        vector<vector<string>>& queries)
    {
    }
};

int main(int argc, char* argv[])
{
    Solution so;
    return 0;
}