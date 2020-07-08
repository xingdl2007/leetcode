#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
private:
    using Distance = std::pair<int, int>;

    class DisComparator {
    public:
        bool operator()(Distance const& left, Distance const& right)
        {
            return left.first < right.first;
        }
    };

    int distance(vector<int>& point)
    {
        return point[0] * point[0] + point[1] * point[1];
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K)
    {
        vector<vector<int>> ret;
        std::priority_queue<Distance, std::vector<Distance>, DisComparator> pq;
        for (int i = 0; i < points.size(); ++i) {
            pq.push({ distance(points[i]), i });
        }

        while (pq.size() > K) {
            pq.pop();
        }

        while (!pq.empty()) {
            int idx = pq.top().second;
            ret.push_back(points[idx]);
            pq.pop();
        }
        return ret;
    }
};

class Solution2 {
    static int distance(vector<int> const& point)
    {
        return point[0] * point[0] + point[1] * point[1];
    }

    static bool DisCompare(vector<int> const& lhs, vector<int> const& rhs)
    {
        return distance(lhs) < distance(rhs);
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K)
    {
        std::sort(points.begin(), points.end(), DisCompare);
        vector<vector<int>> ret(points.begin(), points.begin() + K);
        return ret;
    }
};

int main(int argc, char* argv[])
{
    Solution2 so;
    {
        vector<vector<int>> data{ { 1, 3 }, { -2, 2 } };
        auto ret = so.kClosest(data, 1);

        for (auto& p : ret) {
            std::cout << "[";
            for (auto i : p) {
                std::cout << i << " ";
            }
            std::cout << "]";
        }
        std::cout << std::endl;
    }

    {
        vector<vector<int>> data{ { 3, 3 }, { 5, -1 }, { -2, 4 } };
        auto ret = so.kClosest(data, 2);

        for (auto& p : ret) {
            std::cout << "[";
            for (auto i : p) {
                std::cout << i << " ";
            }
            std::cout << "]";
        }
        std::cout << std::endl;
    }
    return 0;
}