#include <iostream>
using namespace std;

/*
Class is a Blueprint, Object is the instance of the Class.
Class doesn't take any memory, but the Object does.
Class has Data Members (variables & objects) & Member Functions (functions).
If there no Access Modifier mentioned (like public, private or protected), the members & functions
are by default, private.
*/

class Rectangle {
public:     // If we don't mention this access modifier, everything by default, is public, and hence, cannot be accessed by any other function(s).
    // Data Members:
    int length;
    int breadth;

    // Member Functions: We can define simple functions in the class, but for complex functions, it is better to do it outside, using the scope resolution operator(::).
    int area() {
        return (length * breadth);
    }

    int perimeter() {
        return (2 * (length + breadth));
    }

    // Since the area() & perimeter() are smaller functions, we can define them right inside the class.
};

// Driver Program
int main() {
    Rectangle r1, r2;   // r1 & r2 are variables of type Rectangle, or we can say, r1 & r2 are objects of Rectangle.
    r1.length = 10; r1.breadth = 5; // if the length and breadth data members were private, this line would raise an error.
    r2.length = 5;  r2.breadth = 32;
    cout << "Rectangle r1(10,5): \n";
    cout << "Area = " << r1.area() << ", Perimeter = " << r1.perimeter() << "\n\n";
    cout << "Rectangle r2(5,32): \n";
    cout << "Area = " << r2.area() << ", Perimeter = " << r2.perimeter();
    return 0;
}

/*
Output:
------

Rectangle r1(10,5): 
Area = 50, Perimeter = 30

Rectangle r2(5,32): 
Area = 160, Perimeter = 74
*/