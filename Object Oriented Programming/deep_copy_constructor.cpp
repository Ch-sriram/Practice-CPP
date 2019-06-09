/* 
Problem with the Copy Constructor is that, if there is any Dynamic Memory Allocation done for some object,
then for the next object of the same type, when the values of one object are copied to the other object using the
copy constructor, and if there's a pointer initialization, then the pointer will again point to the same object's heap
data. We will see the example below to understand it better.
*/


#include <iostream>
using namespace std;

class Test {
private:
    int size;
    int *p;

public:
    // Parameterized Constructor:
    Test(int size) {
        size = size;
        p = new int[size];
    }
    
    // Copy Constructor:
    Test(Test &t) {
        size = t.size;
        p = t.p;    // Here, the pointer p of the new object will point to the array pointed by pointer p of the old object.
    }

    // Deep Copy Constructor:
    Test(Test *t, int s) {      
        size = s;
        p = new int[size];
        for(int i = 0; i < size; ++i)
            p[i] = t->p[i];
    }

    // Accessor Function:
    void get_array_elements(int s) {
        for(int i = 0; i < s; ++i)
            cout << p[i] << " ";
        cout << "\n";
    }

    // Mutator Function:
    void set_array_elements(int s) {
        cout << "Enter " << s << " elements: ";
        for(int i = 0; i < s; ++i) 
            cin >> p[i];
    }

    void get_size() {
        cout << "size is " << size << "\n";
    }

};

int main() {
    // Creating the Test Object t1 in stack
    int s1 = 8;
    Test t1(s1);
    
    // Showing the problem with copy constructor:
    cout << "\nUsing Copy Constructor:\n";
    cout << "----------------------\n";
    cout << "For Object Test - t1\n";
    t1.set_array_elements(s1);
    cout << "Elements of the array in Object t1 are: ";
    t1.get_array_elements(s1);
    cout << "\n";

    // Now, we will create another object - t2 with the help of the copy constructor, which will be a copy of t1.
    // But t2 will be able to accessthe array allocated to pointer p in t also. i.e.,
    Test t2(t1);

    cout << "For Object Test - t2\n";
    cout << "The Array Elements of Object t2 are (same as that of t1's): ";
    t2.get_array_elements(s1);

    // We will clearly see that both the arrays of t1 and t2 have the same values throughout the array.
    // Because, there are no 2 arrays, there's just a single array, pointed by 2 pointer of 2 objects.
    // Now if we make changes to the array pointed by pointer p of object t2, those changes will also reflect 
    // in the array pointed by p at object t1. i.e.,
    t2.set_array_elements(s1);
    cout << "\nComparing Array Elements of Object t1 & t2 (they'll be the same!): \n";
    cout << "The Array Elements of Object t2 are: ";
    t2.get_array_elements(s1);
    cout << "The Array Elements of Object t1 are: ";
    t1.get_array_elements(s1);
    cout << "\n\n";

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    // Now resolving the problem with Copy Constructor using Deep Copy Constructor:
    cout << "Using Deep Copy Constructor:\n";
    cout << "---------------------------\n";
    cout << "For Object Test - t3\n";
    int s2 = 5;
    Test t3(s2);
    t3.set_array_elements(s2);
    cout << "The Array Elements of Object t3 are: ";
    t3.get_array_elements(s2);
    cout << "\n";

    // Now we will create another Test Object using the Deep Copy Constructor as follows, so that, all the 
    // details of t3 are copied onto object t4, with each of them having their separate copies of thier own arrays.
    cout << "For Test Object - t4:\n";
    Test t4(&t3, s2);     // s2 is used for sending the size to t4
    cout << "The Array Elements of t4 are (same as that of t4): ";
    t4.get_array_elements(s2);
    t4.set_array_elements(s2);
    
    cout << "\nComparing the Elements of t3 & t4 after setting new elements for t4:\n";
    cout << "The Array Elements of t3 are: ";
    t3.get_array_elements(s2);
    cout << "The Array Elements of t4 are: ";
    t4.get_array_elements(s2);

    cout << "We can see that they're not the same! This is why we use Deep Copy Constructor.\n\n";
    
    return 0;
}

/* 
Output:

Using Copy Constructor:
----------------------
For Object Test - t1
Enter 8 elements: 1 2 3 4 5 6 7 8
Elements of the array in Object t1 are: 1 2 3 4 5 6 7 8

For Object Test - t2
The Array Elements of Object t2 are (same as that of t1's): 1 2 3 4 5 6 7 8
Enter 8 elements: 100 200 300 400 500 600 700 800

Comparing Array Elements of Object t1 & t2 (they'll be the same!):
The Array Elements of Object t2 are: 100 200 300 400 500 600 700 800
The Array Elements of Object t1 are: 100 200 300 400 500 600 700 800


Using Deep Copy Constructor:
---------------------------
For Object Test - t3
Enter 5 elements: 1 2 3 4 5
The Array Elements of Object t3 are: 1 2 3 4 5

For Test Object - t4:
The Array Elements of t4 are (same as that of t4): 1 2 3 4 5
Enter 5 elements: 100 200 300 400 500

Comparing the Elements of t3 & t4 after setting new elements for t4:
The Array Elements of t3 are: 1 2 3 4 5
The Array Elements of t4 are: 100 200 300 400 500
We can see that they're not the same! This is why we use Deep Copy Constructor.

*/