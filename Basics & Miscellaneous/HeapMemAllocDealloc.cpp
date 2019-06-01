#include <iostream>
using namespace std;

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  // This array is created in Data Section of the PCB
    /* 
     Now we can't change the size of the array - arr
     i.e., we cannot write the following line of code:
     arr[20] -- this will produce an error
     Therefore, to make sure that we can use the same array variable, but a different
     sized array, we use Heap Memory Allocation for the array.
    */

    int *P = new int[10];
    for(int i = 0, i < 10; ++i)
        P[i] = i;
    
    /*
        Now, if we want, we can assign P, to a new array created in the Heap,
        But if we do that, the old array's reference will be lost, and that will
        create a Memory Leak & we don't want that. Therefore, we Deaalocate the memory
        pointed by P, and then, assign the new array to P.

        Note: If we don't want to copy the older array's values to the new array, then we can do so by writing the following code:
                                delete[] P;
                                P = new int[20];
                                for(int i = i < 20; ++i)
                                    cout << P[i] << endl;
    */

    int *Q = new int[20];
    for(int i = 0; i < 10; ++i)
        Q[i] = P[i];
    
    delete[] P; P = Q;  Q = nullptr;
    
    for(int i = 0; i < 20; ++i)
        cout << P[i] << endl;
    // After 10 elements, we might see some garbage values, as only 10 elements are assigned properly.

    return 0;
}