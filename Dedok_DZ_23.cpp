#include <iostream>
using namespace std;
const int ARRAY_SIZE = 20;

void fillRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 41 - 20; 
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int main()
{
    setlocale(LC_ALL, "RUS");
    int arr[ARRAY_SIZE];
    fillRandomArray(arr, ARRAY_SIZE);

    cout << "Исходный массив:" << "\n";
    printArray(arr, ARRAY_SIZE);

    int firstNegativeIndex = -1;
    int lastNegativeIndex = -1;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (arr[i] < 0) {
            if (firstNegativeIndex == -1) {
                firstNegativeIndex = i;
            }
            lastNegativeIndex = i;
        }
    }

    if (firstNegativeIndex != -1 && lastNegativeIndex != -1) {
        for (int i = firstNegativeIndex + 1; i < lastNegativeIndex; i++) {
            for (int j = i; j > firstNegativeIndex && arr[j] < arr[j - 1]; j--) {
                swap(arr[j], arr[j - 1]);
            }
        }

        cout << "Отсортированный массив между крайними отрицательными элементами:" << "\n";
        printArray(arr, ARRAY_SIZE);
    }
    else {
        cout << "В массиве нет отрицательных элементов." << "\n";
    }
}
