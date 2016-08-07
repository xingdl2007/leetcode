#include <string>
#include <iostream>

using namespace std;

#include "zigzagconversion.cc"

/* ZigZag examples

    2 line example:
    0   2   4
    1   3   5

    3 line example:
    0       4       8
    1   3   5   7   9
    2       6       10

    4 line example:
    0           6           12
    1       5   7       11  13
    2   4       8   10      14
    3           9           15
*/

int main(int argc, char* argv[]) {
    cout << (new Solution())->convert("PAYPALISHIRING",3) << endl;
    cout << (new Solution())->convert("ABC",2) << endl;
    return 0;
}