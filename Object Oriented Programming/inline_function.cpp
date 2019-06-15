/*
    An inline function is a function which is defined inside the class. When the Object code is generated,
    wherever the inline function is called, the function's code is simply replaced into the place where
    the inline function is called and therefore, in the object code, no extra subroutine is made for an inline
    function. An inline function should not have a lot of complex code, or else, it will become a non-inline function on its own.

    A function defined using the scope resolution operator is by default non-inline. Therefore, for these kind 
    of functions, the object code is generated as a subroutine, where only the call to to the subroutine's starting address
    is given wherever the function is called.

    Note: It is not a good practice to have more inline functions in a class. It is always recommended to use non-inline functions
    in a class.
*/

#include <iostream>
using namespace std;

class Test {
private:
    int a;
public:
    // Constructors:
    Test();
    Test(int);
    Test(Test*);

    // Member Functions:
    // This function is an inline function, because it is defined inside the class.
    void test() {
        cout << a << "\n";
    }

    // This is a non-inline function, because this function's definition will be defined outside.
    // Whenever display() function is called in the main(), the code of display() is given as the subroutine's address in main(),
    // its code will be generated in the memory, as a separate object code.
    int display(void);

    // This is an inline function, whose definition will be given outside the class. Notice the usage of the "inline" keyword.
    // Whenever display2() function is called in the main(), the code of display2() will be replaced inline in the main() function.
    inline void display2(void);

    // Destructor:
    ~Test() {}
};

// Definition of the Constructors:
Test::Test() {
    a = 0;
}

Test::Test(int x) {
    a = x;
}

Test::Test(Test *t) {
    a = t->a;
}

// Definition of the Member Functions which were not defined inside the class:
int Test::display() {
    return a;
}

void Test::display2() {
    cout << a << "\n";
}


// Driver Program:
int main() {
    Test t1(100);
    t1.test();
    cout << t1.display() << "\n";
    t1.display2();

    Test *t2 = new Test(t1);
    t2->test();
    cout << t2->display() << "\n";
    t2->display2();

    return 0;
}

/*
Output:
------

100
100
100
100
100
100

*/