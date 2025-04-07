#include <iostream>
#include <stdlib.h>
#include <clocale>
#include <stdio.h>
#include <random>
#include <ctime>
#include <fstream>

using namespace std;


void printArray(int* arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void merge(int* arr, int low, int mid, int high) {
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;

   
    int temp[20];

    while (i <= mid && j <= high) {
       
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        }
        else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    
    while (j <= high) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(int* arr, int low, int high) {
    int mid;
    if (low < high) {
        
        mid = (low + high) / 2;

        
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

       
        merge(arr, low, mid, high);
    }
}

int main() {

    
    int arr[] = { 39, 14, 46, 76, 54, 89, 7 };

   
    int length = sizeof(arr) / sizeof(int);

    
    cout << "Array, before calling the mergeSort() : ";
    printArray(arr, length);

   
    mergeSort(arr, 0, length - 1);

    
    cout << "Array, after calling the mergeSort() : ";
    printArray(arr, length);
    return 0;
}



