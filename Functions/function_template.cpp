/*

            int max(int &a, int &b) {
                return a > b ? a : b;
            }

            float max(float &a, float &b) {
                return a > b ? a : b;
            }

            int main() {
                cout << "Maximum of 10, 12 is " << max(10, 12) << endl;
                cout << "Maximum of 10.5, 53e-2 is " << max(10.5f, 53e-2f) << endl;
            }

        O/P:
            Maximum of 10, 12 is 12
            Maximum of 10.5, 53e-2 is 10.5
        
        For the above program, we can see that, we wrote two functions for the same logic in the program.
        We wrote those two functions because there was a type difference. To overcome these kind of problems,
        we use Funtion Templates, using which, we can focus on the logic, rather than the type of the data.

        Now, by the following program which uses the Template Function, we need not make two function definitions
        for the same logic, just because there is a type difference.
*/

#include <iostream>
using namespace std;

template <class T>
T max(T &a, T &b) {
    return a > b ? a : b;
}

template <class T>
T min(T &a, T &b) {
    return a < b ? a : b;
}

int main() {
    int a = 5, b = 10;
    /*
        The following lines of code will give an error:
            int a = 5; float b = 10;
            int x = max(a, b);
        Here, we get an error because we are not sending the same types into the max function. max() expects only a single type
        of data type.
    */
    int mx = max(a, b);
    int mn = min(a, b);

    cout << "int version:" << endl;
    cout << "max(" << a << ", " << b << ") = " << mx << endl;
    cout << "min(" << a << ", " << b << ") = " << mn << endl;

    float c = 9.0032f, d = 932443e-5f;
    float mx_f = max(c, d), mn_f = min(c, d);
    cout << endl << "float version:" << endl;
    cout << "max(" << c << ", " << d << ") = " << mx_f << endl;
    cout << "min(" << c << ", " << d << ") = " << mn_f << endl;

    return 0;
}

/*
Output:
------

int version:
max(5, 10) = 10
min(5, 10) = 5

float version:
max(9.0032, 9.32443) = 9.32443
min(9.0032, 9.32443) = 9.0032

*/