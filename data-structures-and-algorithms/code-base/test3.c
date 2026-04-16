#include <stdio.h>
#define COUNT_EL 6

int old_list[] = {10, 9, 8, 14, 12, 2}; // 6 elements

/* 

Some sorting algorithms I learn
Like this morning from the DSA class

*/

void printArr (int list[], int count);
void resetValues (int list[]);
void bubble_sort (int list[], int count);
void insertion_sort (int list[], int count);

int main ()
{
    int ct = 6;
    int list_[6] = {10, 9, 8, 14, 12, 2}; // 6 elements
    
    printf("Before sorted:\n");
    printArr(list_, ct);

    // Bubble sort
    printf("\nBubble sort:\n");
    bubble_sort(list_, ct);
    printArr(list_, ct);
    resetValues(list_);
    
    // Insertion sort
    printf("\nInsertion sort:\n");
    insertion_sort(list_, ct);
    printArr(list_, ct);

    return 0;
}

void printArr (int list[], int count)
{
    printf("{ ");
    for (int i = 0; i < count; ++i) {
        if (i >= count - 1) printf("%d ", list[i]);
        else printf("%d, ", list[i]);
    }
    printf("}\n");
}

void resetValues (int list[])
{
    for (int i = 0; i < COUNT_EL; ++i) list[i] = old_list[i];
}

// Sorts
void bubble_sort (int list[], int count)
{
    for (int step = 0; step < count; ++step)
    {
        int didSwap = 0;

        for (int i = 0; i < count-1; ++i) {
            if (list[i+1] < list[i]) {
                int temp = list[i+1];
                list[i+1] = list[i];
                list[i] = temp;
                didSwap = 1;
            }
        }

        if (!didSwap) break;
    }
}

void insertion_sort (int list[], int count)
{
    for (int i = 1; i < count; ++i)
    {
        int key = list[i];
        int b = i - 1;

        while (b >= 0 && key < list[b]) {
            list[b + 1] = list[b];
            b--;
        }
        list[b + 1] = key;
    }
}

