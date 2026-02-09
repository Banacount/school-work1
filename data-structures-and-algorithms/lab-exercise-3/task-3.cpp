#include <iostream>
using namespace std;

int main ()
{
    // Declare and initialize variables
    int score[10] = {10, 11, 12, 13, 14};
    int where_is = 13, element_count = 5, founded = 0;

    // Print the array
    cout << "# Array values" << endl << "{ ";
    for (int l = 0; l < element_count; l++) {
        cout << score[l];

        if (l >= (element_count - 1)) cout << " ";
        else cout << ", ";
    }
    cout << "}" << endl;

    // Search for the value
    cout << endl << "Value goal is " << where_is << "." << endl;
    for (int i = 0; i < element_count; i++) {
        if (score[i] == where_is) {
            cout << "Found one at index "<< i << "." << endl;
            founded = 1;
            break;
        }
    }

    // Display not found if the search found absolutely nothing
    if (founded == 0) cout << "Not found." << endl;
    return 0;
}
