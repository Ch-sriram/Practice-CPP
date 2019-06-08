/*
Constructor: A special type of function, which has the same name as the class, but has no return type.

There are 4 types of Constructors in C++:

1. Default Constructor: When we don't explicitly define this constructor, this constructor is called by the compiler,
                        whenever an object is created. This constructor's code is added when 
                        converting the cpp code into object code (m/c level).

2. Non-Parameterized Constructor: This is a user defined constructor where no parameters passed on to
                        the Constructor.

3. Parameterized Constructor: This is a user defined constructor where the constructors take in parameters
                        when the constructor is called.

4. Copy Constructor: This is a constructor used for copying of the details (data members) of one object of same
                     type, into another object of the same type.

        We'll now see the usage of all these constructors.
*/

#include <iostream>
using namespace std;

class Rectangle {
private:
    int length;
    int breadth;

public: 
    // Non-Parameterized Constructor:
    Rectangle() {
        length = 0;
        breadth = 0;
    }

    // Parameterized Constructor:
    Rectangle(int l, int b) {
        length = l;
        breadth = b;
    }

    /* 
        We can remove the Non-Parameterized constructor, by passing default arguments to Parameterized constructor as follows:
        Rectangle(int l = 0, int b = 0) {
            length = l;
            breadth = b;
        }
        We can see that, now we don't need the Non-Parameterized Constructor, we can simply use the Parameterized Constructor.
    */

    // Copy Constructor:
    Rectangle(Rectangle& r) {
        length = r.length;
        breadth = r.breadth;
    }

    /*
        Note that all the constructors have the same name, therefore, all these constructors are also overloaded
        & this is also known as Contructor Overloading.
    */

    int get_length() {          // Accessor Function
        return length;
    }

    int get_breadth() {         // Accessor Function
        return breadth;
    }

    void set_length(int l) {    // Mutator Function
        length = l;
    }

    void set_breadth(int b) {   // Mutator Function
        breadth = b;
    }

    int area() {                
        return length * breadth;
    }

    int perimeter() {
        return 2 * (length + breadth);
    }
};

// Driver Program:
int main() {
    // Initializing the Non-Parameterized Constructor:
    Rectangle r1;                           // r1 is created in stack.
    // We can also create r1 as:
    // Rectangle r1();                      // in stack.
    // Rectangle *r1 = new Rectangle();     // in heap.
    // Rectangle *r1 = new Rectangle;       // in heap.
    cout << "Rectangle - r1" << "\n";
    cout << "Length: " << r1.get_length() << ", Breadth: " << r1.get_breadth() << "\n";
    r1.set_length(32);  
    r1.set_breadth(23);
    cout << "Length: " << r1.get_length() << ", Breadth: " << r1.get_breadth() << "\n";
    cout << "Area: " << r1.area() << ", Perimeter: " << r1.perimeter() << "\n\n";

    Rectangle *r2 = new Rectangle(10,20);   // r2 created in heap.
    // We can create r2 as follows:
    // Rectangle r2(10,20);                 // in stack.
    cout << "Rectangle - r2. r2's length and breadth are already set, due to Parameterized Constructor\n";
    cout << "Length: " << r2->get_length() << ", Breadth: " << r2->get_breadth() << "\n";
    cout << "Area: " << r2->area() << ", Perimeter: " << r2->perimeter() << "\n\n";
    
    // Now, if we want to copy the exact details (data member values) into another Rectangle object
    // in that case, we use the Copy Constructor as follows:
    // we will use the stack declaration:
    Rectangle r3(r1);   // all details of r1 are now copied onto r3
    cout << "Rectangle - r3 = Rectangle - r1 (Due to Copy Constructor)\n";
    cout << "Length: " << r3.get_length() << ", Breadth: " << r3.get_breadth() << "\n";
    cout << "Area: " << r3.area() << ", Perimeter: " << r3.perimeter() << "\n\n";

    // Rectangle - r4 is instantiated in the heap.
    Rectangle *r4 = new Rectangle(r1);  // address of all details of r1 are now copied into r4, since r4 is a pointer.
    cout << "Rectangle - r4 = Rectangle - r1 (Due to Copy Constructor)\n";
    cout << "Length: " << r4->get_length() << ", Breadth: " << r4->get_breadth() << "\n";
    cout << "Area: " << r4->area() << ", Perimeter: " << r4->area() << "\n\n";

    // Rectangle - r5 is instantiated in the heap.
    Rectangle *r5 = new Rectangle(*r2); // address of all details of r1 are now copied into r5, since r5 is a pointer.
    cout << "Rectangle - r5 = Rectangle - r2 (Due to Copy Constructor)\n";
    cout << "Length: " << r5->get_length() << ", Breadth: " << r5->get_breadth() << "\n";
    cout << "Area: " << r5->area() << ", Perimeter: " << r5->perimeter() << "\n\n";

    return 0;
}

/*

Output:
------

Rectangle - r1
Length: 0, Breadth: 0
Length: 32, Breadth: 23
Area: 736, Perimeter: 110

Rectangle - r2. r2's length and breadth are already set, due to Parameterized Constructor
Length: 10, Breadth: 20
Area: 200, Perimeter: 60

Rectangle - r3 = Rectangle - r1 (Due to Copy Constructor)
Length: 32, Breadth: 23
Area: 736, Perimeter: 110

Rectangle - r4 = Rectangle - r1 (Due to Copy Constructor)
Length: 32, Breadth: 23
Area: 736, Perimeter: 736

Rectangle - r5 = Rectangle - r2 (Due to Copy Constructor)
Length: 10, Breadth: 20
Area: 200, Perimeter: 60

*/