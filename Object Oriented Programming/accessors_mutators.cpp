/*
We hide data using Accessors & Mutators;
We do that because, we want to give control to the user, only the functionality of the system,
not the control to data. Giving public access to the data (data members) is rather dangerous,
because it malfuntion the ouput by a system. Example:

class Rectangle {
    public:
        \\ Data Members
        int length;
        int breadth;

        \\ Member Functions 
        int area() {
            return length * breadth;
        }
        int perimeter() {
            return 2 * (length + breadth);
        }
};

int main() {
    Rectangle r1;
    r1.length = -93;    // Here, length is negative. Length should never be a negative quantity
    r1.breadth = 9;
    cout << r1.area();  // We'll get a negative area because we gave the control of data to the user. We should never let user control the data.
    return 0;
}

Therefore, we avoid giving data (data member) control to the user. We would basically access it using something called
as Accessors (Getter Functions), & set the data member values using Mutators (Setter Functions)
*/

#include <iostream>
using namespace std;

class Rectangle {
// By default, everything defined inside a class is private
    int length;
    int breadth;

public:
    // Mutators - for Write Permission
    void set_length(int l) {
        if(l > 0)
            length = l;
        else {
            cout << "given length is negative. setting length to 1 (default)" << endl;
            length = 1;
        } 
    }
    void set_breadth(int b) {
        if(b > 0)
            breadth = b;
        else {
            cout << "given length is negative. setting length to 1 (default)" << endl;
            breadth = 1;
        }
    }

    // Accessors - for Read Permission
    int get_length() {
        return length;
    }
    int get_breadth() {
        return breadth;
    }

    // Member Functions
    int area() {
        return length * breadth;
    }
    int perimeter() {
        return 2 * (length + breadth);
    }
};

// Driver Program
int main() {
    Rectangle r1;       // this object is in Stack
    r1.set_length(20);
    r1.set_breadth(-93);
    cout << "Rectangle r1(" << r1.get_length() << "," << r1.get_breadth() << "):\n";
    cout << "Area = " << r1.area() << ", Perimeter = " << r1.perimeter() << "\n\n";

    Rectangle *r2 = new Rectangle();    // this object is in Heap, pointed by r2.
    r2->set_length(83); 
    r2->set_breadth(72);
    cout << "Rectangle r2(" << r2->get_length() << "," << r2->get_breadth() << "):\n";
    cout << "Area = " << r2->area() << ", Perimeter = " << r2->perimeter() << "\n";

    return 0;
}