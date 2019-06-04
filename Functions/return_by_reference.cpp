#include <iostream>
using namespace std;

/*
Normal Function returns to the main(), and it's always the rvalue (data), i.e.,
int disp(int a) {
    cout << a;
    return a;
}

int main() {
    int x = 10;
    int y = disp(x);    // Here, the disp() is on the RHS of the assignment, therefore, that makes disp() as the rvalue.
    cout << y;  // y = 10;
}

But, a function that returns a reference, can be the lvalue, i.e., the function itself will act as a 
reference to a variable, and that function (i.e., the reference variable) can be assigned a value.
The surprising thing is, the function acting as a reference is on the LHS of the assignment, and being assigned
a value to it. Let's see the example:
*/

int& display(int& a) {   // The function should only return a reference, therefore, int& is the return type
    cout << a << "\n";
    return a;
}

int main() {
    int x = 10;
    display(x) = 100;
    /* 
        display(x) returns the reference of x, therefore, if we assign some value to display(x), 
        it's the same as assigning to x.
    */
    cout << "Value of display(x) = " << display(x) << "\n";
    cout << "Value of x = " << x << "\n";
    return 0;
}