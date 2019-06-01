#include <iostream>
using namespace std;

int main() {
    int x = 10, a = 20;
    a = x;
    x = 20;
    /*
        For the Statements in Line 6 & 7, we've:
                a = x;  ------ (i)
                x = 10; ------ (ii)
        where, (i) has x as the rvalue, (ii) has x as the lvalue.
        
        What do we mean by lvalue & rvalue? [Note: LHS is Left Hand Side & RHS is Right Hand Side]
            In simple terms, when some variable is the lvalue (LHS of assignment), then we are basically,
            in its purest form, referring to it address first, and assigning the data to that address. 
            Similarly, when some variable is the rvalue (RHS of assignment), then we are basically, referring
            directly to its data, and that data is being assigned to some variable on the LHS of the assignment operator.
        
        Now, we'll see what happens to a Reference Variable
    */

    int &r = x;

    /*
        Here, even though x in the RHS of the assignment operator, the x acts as an lvalue, whereas,
        if the above statement, if it was not having a reference variable, then x should be an rvalue.
        Therefore, x will act as an lvalue, only in the case of a reference variable.

        What is a Reference Variable?
        This is a special variable only available in C++ where, the variable is basically an alias to the variable
        which the reference was assigned. For example, in the above statement (in line 23),
        variable r is an alias name for variable x, it means that, we can get the data at x, by simply 
        referring to x, or r, both of them can access the data at x.
        One thing about reference variables is that, we have to assign the reference variable, some other variable,
        directly at the time of initialization. Therefore, we cannot do this:
                            int &r;                         int &r = x;
                            r = x;                          This is Legal
                            That's illegal
        Also, once the reference variable is assigned as an alias to some other variable, it cannot be re-assigned
        to some other variable again. It means that:
                            int &r = x;
                            &r = p;
                            This is Illegal
        Last but not the least, a reference variable is never assigned any memory, it just is an alias to the variable it is referring to.
    */

    cout << "Value of x (using x): " << x << endl;
    cout << "Value of x (using the ref variable r): " << r << endl;

    return 0;
}


/*
    Output:
        Value of x (using x): 20
        Value of x (using the ref variable r): 20

    Even though we don't see why the reference variable is important in C++ now, it's importance is known when
    we pass the parameters by reference, when we use functions.
*/