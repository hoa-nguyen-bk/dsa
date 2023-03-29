//copy chatgpt
#ifndef SORTING_H
#define SORTING_H

#include <iostream>

using namespace std;

template <class T>
class Sorting {
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        long size = end - start + 1;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }
    
    static void merge(T* left, T* middle, T* right){
        int n1 = middle - left + 1;
        int n2 = right - middle;

        // Create temporary arrays
        T L[n1], R[n2];

        // Copy data to temporary arrays
        for (int i = 0; i < n1; i++)
            L[i] = left[i];
        for (int j = 0; j < n2; j++)
            R[j] = middle[j+1];

        // Merge the temporary arrays back into arr[l..r]
        int i = 0; // Initial index of first subarray
        int j = 0; // Initial index of second subarray
        int k = 0; // Initial index of merged subarray
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                left[k] = L[i];
                i++;
            }
            else {
                left[k] = R[j];
                j++;
            }
            k++;
        }

        // Copy the remaining elements of L[], if there are any
        while (i < n1) {
            left[k] = L[i];
            i++;
            k++;
        }

        // Copy the remaining elements of R[], if there are any
        while (j < n2) {
            left[k] = R[j];
            j++;
            k++;
        }

        Sorting::printArray(left, right);
    }
    
    static void mergeSort(T* start, T* end) {
        if (start < end) {
            // Find the middle point to divide the array into two halves
            T* middle = start + (end - start) / 2;

            // Call mergeSort for first half
            mergeSort(start, middle);

            // Call mergeSort for second half
            mergeSort(middle + 1, end);

            // Merge the two halves sorted in step 1 and 2
            merge(start, middle, end);
        }
    }
};

#endif /* SORTING_H */
