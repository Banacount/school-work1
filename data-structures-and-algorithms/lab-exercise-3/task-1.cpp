#include <stdio.h>
#include <iostream>
using namespace std;


//  This is task 1 - Make a simple static array insert by index algorithm.
int main ()
{
    // Declare and initialize variables
    int score[10] = {10, 11, 12, 13, 14};
    int new_value = 16, store_in = 2, element_count = 5;

    // Print the old array so we can see some kind of "transformation" frfr
    cout << "# Old array values" << endl << "{ ";
    for (int l = 0; l < element_count; l++) {
        cout << score[l];

        if (l >= (element_count - 1)) cout << " ";
        else cout << ", ";
    }
    cout << "}" << endl;

    // Move the elements to the left
    for (int i = (element_count - 1); i >= store_in; i--) {
        score[i + 1] = score[i];
    }

    // Store the value in the desired index
    score[store_in] = new_value;
    element_count++;
    
    // Print the array in a proper formatted thingy
    cout << endl << "# Current array values" << endl << "{ ";
    for (int l = 0; l < element_count; l++) {
        cout << score[l];

        if (l >= (element_count - 1)) cout << " ";
        else cout << ", ";
    }
    cout << "}" << endl;

    return 0;
}
