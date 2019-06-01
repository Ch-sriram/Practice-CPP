#include <iostream>
using namespace std;

int main() {
    int *p = new int[10];
    for(int i = 0; i < 10; ++i)
        cout << p[i] << " ";

    int *q = p;
    delete []q;
    q = nullptr;
    // p is now pointing to a freed memory area, and this is the dangling pointer problem.
    for(int i = 0; i < 10; ++i)
        cout << p[i];
    // The output of the for loop in line 13 can be weird
    return 0;
}

// The Output of the Program was: 7828600 7798976 0 0 0 0 0 0 0 0 7828600779897600000000
// The output contained a lot of Garbage values, because p is actually not pointing to anything.