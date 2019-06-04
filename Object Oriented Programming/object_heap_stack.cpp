#include <iostream>
using namespace std;

/*  In Java, an Object for a class can never be created in the Stack Area of the Process. It can only be created at the Heap Area.
 *  But in C++, the Object can be created both in Stack and Heap Memory.
 *  We use the new operator to create the Object in the Heap Area, and therefore, the new returns
 *  the address to the class object created in heap, therefore, we would store the object's address, in 
 *  a class type pointer.
 *  
 *  For further understanding, see the following example:
*/

class Rectangle {
    public:
        // Data Members
        int length;
        int breadth;

        // Member Functions
        int area() {
            return length * breadth;
        }

        int perimeter() {
            return 2 * (length + breadth);
        }
};

// Driver Program:
int main() {
    // Creating the Object of Rectangle class in the Stack Area
    Rectangle r1;
    r1.length = 10; r1.breadth = 324;
    cout << "Rectangle r1(10,324) [In Stack Memory]:\n";
    cout << "Area = " << r1.area() << ", Perimeter = " << r1.perimeter() << "\n\n";

    // Creating the Object of Rectangle class in the Heap Area
    Rectangle *r2 = new Rectangle;
/*  
    Note that here, the Object itself does NOT have any name, but it's referred by the pointer r2, that points to it.
    
    We can also define Rectangle object in Heap as follows:
    Rectangle *r2 = new Rectangle();    // The paranthesis in the end is used for passing the parameters to the Constructor.
*/

    // We use the arrow operator (->) to access the members and functions of class Rectangle, using the pointer to Rectangle class.
    r2->length = 832;   r2->breadth = 342;
    // We can also access the members as follows: (*r2).length ... & (*r2).breadth ...
    cout << "Rectangle r2(832,342) [In Heap Memory]:\n";
    cout << "Area = " << r2->area() << ", Perimeter = " << r2->perimeter() << "\n";

    return 0;
}

/*
Output:
------
Rectangle r1(10,324) [In Stack Memory]:
Area = 3240, Perimeter = 668

Rectangle r2(832,342) [In Heap Memory]:
Area = 284544, Perimeter = 2348
*/