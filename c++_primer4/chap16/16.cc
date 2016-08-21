/*
 * c++ primer 4nd ed; chapter16 template and GP programming
 */
#include <iostream>
#include <vector>

#include "Queue.h"

using namespace std;

template <typename T>
bool compare(const T& lhs, const T& rhs) {
    if (lhs < rhs) return -1;
    else if (rhs < lhs) return 1;
    return 0;
}

int main(int argc, char*argv[]) {
    cout << compare(1,2) << endl;

    short a[4] = {3,4,5,18};
    int b[4] = {4,5,6,19};

    vector<int> vec(b,b+4);

    // range ctor test
    Queue<int> q(a,a+4);
    cout << "Q:" << q << endl;

    // default ctor and push/pop test
    Queue<int> t;
    t.push(5);
    t.push(6);
    t.push(7);
    t.push(8);
    t.pop();
    t.push(20);
    cout << "T:" << t << endl;

    // assign template function test
    q.assign(vec.begin(),vec.end());
    cout << "Q:" << q << endl;

    // test copy ctor
    Queue<int> temp(q);
    cout << "temp:" << temp << endl;

    // assignemnt operator test
    temp = t;
    cout << "temp:" << temp << endl;    
}