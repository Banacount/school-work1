#include <iostream>
using namespace std;

//  This is task 2 - Make a simple static array delete by index algorithm.
int main ()
{
    // Declare and initialize variables
    int score[10] = {10, 11, 12, 13, 14};
    int delete_in = 2, element_count = 5;
    
    // Print the old array so we can see some kind of "transformation" frfr
    cout << "# Old array values" << endl << "{ ";
    for (int l = 0; l < element_count; l++) {
        cout << score[l];

        if (l >= (element_count - 1)) cout << " ";
        else cout << ", ";
    }
    cout << "}" << endl;
   
    // Overwrite the delete index by shifting all greater than index to the left
    for (int i = delete_in; i < element_count; i++) {
        score[i] = score[i + 1];
    }
    element_count--;
    
    // Print the new damn array
    cout << endl << "# New array values" << endl << "{ ";
    for (int l = 0; l < element_count; l++) {
        cout << score[l];

        if (l >= (element_count - 1)) cout << " ";
        else cout << ", ";
    }
    cout << "}" << endl;

    return 0;
}
