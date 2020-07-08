#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// // interesting and hard
// To find the number of components in a graph, we can use either depth-first search or union find. The main difficulty with this problem is in specifying the graph.
// One "brute force" way to specify the graph is to associate each grid square with 4 nodes (north, south, west, and east), representing 4 triangles inside the square if it were to have both slashes. Then, we can connect all 4 nodes if the grid square is " ", and connect two pairs if the grid square is "/" or "". Finally, we can connect all neighboring nodes (for example, the east node of the square at grid[0][0] connects with the west node of the square at grid[0][1]).
// This is the most straightforward approach, but there are other approaches that use less nodes to represent the underlying information.

// 问题的关键在于如何表示图，以及如何表达毗邻区域
// 参见 https://i.loli.net/2018/12/20/5c1b3cfd6c7b9.jpg，将一个grid分成上下左右四个三角，这样就可以用union-find来计算

// quick-union version
class DSU {
public:
    DSU(uint32_t len)
        : parent_(new uint32_t[len])
    {
        for (uint32_t i = 0; i < len; ++i) {
            parent_[i] = i;
        }
    }

    ~DSU()
    {
        delete[] parent_;
    }

    uint32_t Find(uint32_t x)
    {
        if (parent_[x] != x) {
            parent_[x] = Find(parent_[x]);
        }
        return parent_[x];
    }

    void Union(uint32_t x, uint32_t y)
    {
        parent_[Find(x)] = Find(y);
    }

private:
    uint32_t* parent_;
};

class Solution {

public:
    int regionsBySlashes(vector<string>& grid)
    {
        int ret = 0;
        int size = grid.size();
        DSU dsu(4 * size * size);

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                int root = 4 * (i * size + j);
                if (grid[i][j] != '/') {
                    dsu.Union(root + 0, root + 2);
                    dsu.Union(root + 1, root + 3);
                }
                if (grid[i][j] != '\\') {
                    dsu.Union(root + 0, root + 1);
                    dsu.Union(root + 2, root + 3);
                }

                // up
                if (i > 0) {
                    dsu.Union(root + 0, root - 4 * size + 3);
                }

                // down
                if (i < size - 1) {
                    dsu.Union(root + 3, root + 4 * size + 0);
                }

                // left
                if (j > 0) {
                    dsu.Union(root + 1, root - 4 + 2);
                }

                // right
                if (j < size - 1) {
                    dsu.Union(root + 2, root + 4 + 1);
                }
            }
        }

        for (int i = 0; i < 4 * size * size; ++i) {
            if (dsu.Find(i) == i) {
                ++ret;
            }
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    Solution so;
    {
        std::vector<std::string> grid{ " /", "/ " };
        std::cout << so.regionsBySlashes(grid) << std::endl;
    }
    {
        std::vector<std::string> grid{ " /", " " };
        std::cout << so.regionsBySlashes(grid) << std::endl;
    }
    {
        std::vector<std::string> grid{ "\\/", "/\\" };
        std::cout << so.regionsBySlashes(grid) << std::endl;
    }
    {
        std::vector<std::string> grid{ "/\\", "\\/" };
        std::cout << so.regionsBySlashes(grid) << std::endl;
    }
    {
        std::vector<std::string> grid{ "//", "/ " };
        std::cout << so.regionsBySlashes(grid) << std::endl;
    }
    return 0;
}