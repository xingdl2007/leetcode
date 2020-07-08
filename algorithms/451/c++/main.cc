#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// Given a string, sort it in decreasing order based on the frequency of characters.
class Solution {
    using Frequence = std::pair<char, int>;
    struct Comparator {
        bool operator()(Frequence const& lhs, Frequence const& rhs)
        {
            return lhs.second < rhs.second;
        }
    };

public:
    string frequencySort(string s)
    {
        std::unordered_map<char, int> map;
        for (auto c : s) {
            ++map[c];
        }

        std::priority_queue<Frequence, std::vector<Frequence>, Comparator> pq;
        for (auto& p : map) {
            pq.push(p);
        }

        std::string ret;
        while (!pq.empty()) {
            auto f = pq.top();
            ret.append(std::string(f.second, f.first));
            pq.pop();
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    Solution so;
    std::cout << so.frequencySort("tree") << std::endl; // eert
    std::cout << so.frequencySort("cccaaa") << std::endl; // cccaaa
    std::cout << so.frequencySort("Aabb") << std::endl; // "Aabb"

    return 0;
}