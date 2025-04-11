#include <iostream>
#include <stdlib.h>
#include <clocale>
#include <stdio.h>

using namespace std;

void shellSort(int array[], int n) {
    for (int interval = n / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < n; i += 1) {
            int temp = array[i];
            int j;
            for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
                array[j] = array[j - interval];
            }
            array[j] = temp;
        }
    }
}

void printArray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int main() {

    setlocale(LC_ALL, "rus");
    int data[] = { 91, 28, 34, 27, 55, 68, 42, 11 };
    int size = sizeof(data) / sizeof(data[0]);
    shellSort(data, size);
    cout << "Отсортированный массив: ";
    printArray(data, size);
    return 0;
}