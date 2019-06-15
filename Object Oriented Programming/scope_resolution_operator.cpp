/*
    We use the scope resolution operator, to do various things. But one of the things we do is,
    we basically define the member functions of the class, outside the class, as follows:
*/

#include <iostream>
#include "types_of_functions.h"
using namespace std;

// Definition of Non-Parameterized Constructor:
Rectangle::Rectangle() {
    length = 0;
    breadth = 0;
}

// Definition of Parameterized Constructor:
Rectangle:: Rectangle(int l, int b) {
    length = l;
    breadth = b;
}

// Definition of Copy Constructor:
Rectangle::Rectangle(Rectangle *r) {
    length = r->length;
    breadth = r->breadth;
}

// Definition of Mutators:
void Rectangle::set_length(int l) {
    length = l;
}

void Rectangle::set_breadth(int b) {
    breadth = b;
}

// Definition of Accessors:
int Rectangle::get_length() {
    return length;
}

int Rectangle::get_breadth() {
    return breadth;
}


// Defintion of Facilitators:
int Rectangle::area() {
    return length * breadth;
}

int Rectangle::perimeter() {
    return 2 * (length + breadth);
}

void Rectangle::to_string() {
    cout << "Length: " << get_length() << ", Breadth: " << get_breadth() << "\n";
    cout << "Area: " << area() << ", Perimeter: " << perimeter() << "\n\n";
}

// Defintion of Enquirers:
bool Rectangle::is_square() {
    bool is_square = (length == breadth) ? true : false;
    return is_square;
}

// Defintion of Destructor:
Rectangle::~Rectangle() {
    cout << "Deleting this Object........" << "\n\n\n";
    delete this;
}


// Driver Program:
int main() {
    Rectangle *r1 = new Rectangle(10,20);
    r1->to_string();

    Rectangle *r2 = new Rectangle(r1);
    r2->to_string();

    Rectangle *r3 = new Rectangle(40,50);
    r3->to_string();

    return 0;
}

/*
Output:
------

Length: 10, Breadth: 20
Area: 200, Perimeter: 60

Length: 10, Breadth: 20
Area: 200, Perimeter: 60

Length: 40, Breadth: 50
Area: 2000, Perimeter: 180

*/