#include <iostream>
using namespace std;

/*
    int sum(int a, int b, int c) {
        return a + b + c;
    }

    int sum(int a, int b) {
        return a + b;
    }

    int main() {
        cout << sum(1,2,3) << " " << sum(1,2);
    }

    Instead of having two overloaded functions, we can have a single function with default arguments.
    If we want to have default argument in a function, then, from the right end of the function,
    that particular default argument should be assigned.
    i.e.,   int sum(int a = 0, int b, int c) // This is illegal
            int sum(int a, int b = 2, int c = 0)    // This is legal
            int sum(int a, int b = 0, int c) // This is illegal (all the default arguments should start from the right end)
*/


int sum(int a, int b, int c = 0) {
    return a + b + c;
}

int main() {
    cout << sum(1,2,3) << "\n";
    cout << sum(12,30); // Here, value of the third argument is not given, it's automatically taken to be 0.
    return 0;
}