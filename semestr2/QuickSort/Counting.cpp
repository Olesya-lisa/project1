#include <iostream>
#include <stdlib.h>
#include <clocale>
#include <stdio.h>

using namespace std;

void countSort(int arr[], int n) {

    int arr1[100];
    int count_arr[100];
    int x = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > x)
            x = arr[i];
    }

    for (int i = 0; i <= x; ++i) {
        count_arr[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count_arr[arr[i]]++;
    }

    for (int i = 1; i <= x; i++) {
        count_arr[i] += count_arr[i - 1];
    }


    for (int i = n - 1; i >= 0; i--) {
        arr1[count_arr[arr[i]] - 1] = arr[i];
        count_arr[arr[i]] --;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = arr1[i];
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() 
{
    setlocale(LC_ALL, "rus");
    int arr[] = { 56, 22, 47, 98, 38, 22, 13 };
    int n = sizeof(arr) / sizeof(arr[0]);
    countSort(arr, n);
    print(arr, n);
    return 0;
}