#include <iostream>
#include <iomanip>
using namespace std;

void width_without_setw(long &p1, long &p2, long &p3) {
    cout << "LOCATION  " << "POP." << endl
         << "Hyderabad " << p1 << endl
         << "Bengaluru " << p2 << endl
         << "Karnataka " << p3 << endl;
}

void width_with_setw(long &p1, long &p2, long &p3) {
    cout << setw(12) << "LOCATION" << setw(15) << "POPULATION" << endl
         << setw(12) << "Hyderabad" << setw(15) << p1 << endl
         << setw(12) << "Bengaluru" << setw(15) << p2 << endl
         << setw(12) << "Karnataka" << setw(15) << p3 << endl;
}

int main() {
    long pop1 = 3000000, pop2 = 4003214, pop3 = 1588492;
    width_without_setw(pop1, pop2, pop3);
    cout << endl;
    width_with_setw(pop1, pop2, pop3);
}

/*
Output:
------

LOCATION  POP.
Hyderabad 3000000
Bengaluru 4003214
Karnataka 1588492

    LOCATION     POPULATION
   Hyderabad        3000000
   Bengaluru        4003214
   Karnataka        1588492

*/