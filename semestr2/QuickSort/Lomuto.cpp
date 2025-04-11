#include <algorithm>
#include <iostream>
#include <clocale>
#include <stdio.h>

using namespace std;


void partition(int arr[], int low,  int high, int pivot)
{
    int temp[ high- low + 1];
    int index = 0;


    for (int i = low;i <= high;i++)
        if (arr[i] <= arr[pivot])
        {
            temp[index] = arr[i];
            index++;
        }
    for (int i = low;i <= high;i++)
    {
        temp[index] = arr[i];
        index++;
    }
    for (int i = low;i <= high;i++)
        arr[i] = temp[i - low];
}

int main() 
{

    int arr[] = { 32, 80, 64, 12, 10, 74 };

    int n = sizeof(arr) / sizeof(arr[0]);

    partition(arr, 0, n - 1, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
