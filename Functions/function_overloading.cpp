#include <iostream>
using namespace std;

int add (int a, int b) {
    return a + b;
}

int add (int a, int b, int c) {
    return a + b + c;
}

float add (float a, float b) {
    return a + b;
}

/*
    Function Overloading:   Function with same name, but different signature, overloaded for different functionality
        A Function is in the following form:
            int add(int a, int b)
            --- -----------------
             X         Y
        where, Part X is the Return Type of the Function, & Part Y is the Signature of the Function.
        For Function Overloading, it doesn't matter what Part X (i.e., Return Type) is, but it will matter
        what Part Y (i.e., Function Signature) is. That's because, even if the function has the same name, 
        the signature part, that is the number of parameters or the type of parameters should always change in 
        each of the definitions.
        example:
                int add(int a, int b) {}    ----- (i)
                float add(int a, int b) {}  ----- (ii)
            Here, this is illegal, as there has been no function overloading done here, because (i) & (ii)
            don't differ in their signatures.

                int add(int a, int b) {}            ---- (1)
                int add(int a, int b, int c) {}     ---- (2)
                double add(double a, double b) {}   ---- (3)
            Here, (1), (2) & (3), all are different, as their Function Signatures are totally different. 
*/

int main() {
    int x = add(10, 5);
    int y = add(10, 5, 2);
    float f = add(15.5f, 23.043f);
    cout << x << " " << y << " " << f;

    return 0;
}


/*
    Output:
        15 17 38.543
*/