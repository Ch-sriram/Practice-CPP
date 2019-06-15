/*
    Every class has a lot of member functions. These functions are not defined inside the class. 
    But in turn, they're actually defined outside the class, using a scope resolution (::) operator.
    Only the function prototypes are given inside the class.
    There are different kind of functions and they're:
        1. Accessors - Getters
        2. Mutators - Setters
        3. Constructors
        4. Destructors
        5. Facilitators
        6. Enquirers
*/

class Rectangle {
private:
    int length;
    int breadth;
public:
/*
    In the classes, we generally have the function prototypes, therefore, we don't have their definitions.
    They're defined outside the class using the Scope Resolution Operator (::)
*/
    // Constructors:
    Rectangle();
    Rectangle(int, int);
    Rectangle(Rectangle&);    
    
    // Mutators:
    void set_length(int);
    void set_breadth(int);

    // Accessors:
    int get_length();
    int get_breadth();
    
    // Facilitators:
    int area(void);
    int perimeter(void);

    // Enquirers:
    bool is_square(void);

    // Destructor:
    ~Rectangle();

};
