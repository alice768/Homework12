//Абрамова Алиса Григорьевна
//Задание 1. Написать следующие функции для работы с динамическим массивом:
//■ Функция добавления элемента в конец массива.
//■ Функция вставки элемента по указанному индексу.
//■ Функция удаления элемента по указанному индексу.
#include <iostream>

using namespace std;
void CreateRandomArray (int* arr, int size, int start, int end) {
    for (int i = 0; i < size; i++) {
        *(arr + i) = start + rand() % (end - start + 1);
    }
    cout << endl;
}
void PrintArray (int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void AddElement (int* arr, int size, int value) {
    int* new_arr = new int[size + 1];
    for (int i = 0; i < size; i++) {
        new_arr[i] = arr[i];
        cout << new_arr[i] << " ";
    }
    new_arr[size + 1] = value;
    cout << new_arr[size + 1] << endl;
}
void AddIndexElement (int* arr, int size, int value, int index) {
    int* new_arr = new int[size + 1];
    for (int i = 0; i < index; i++) {
        new_arr[i] = arr[i];
        cout << new_arr[i] << " ";
    }
    new_arr[index] = value;
    cout << new_arr[index] << " ";
    for (int i = index, j = index + 1; i < size, j < size + 1; i++, j++) {
        new_arr[j] = arr[i];
        cout << new_arr[j] << " ";
    }
    cout << endl;
}
void DeleteIndexElement (int* arr, int size, int index) {
    int* new_arr = new int[size - 1];
    for (int i = 0; i < index; i++) {
            new_arr[i] = arr[i];
            cout << new_arr[i] << " ";
    }
    for (int i = index + 1, j = index; i < size, j < size - 1; i++, j++) {
        new_arr[j] = arr[i];
        cout << new_arr[j] << " ";
    }
    cout << endl;
}
int main() {
    int size = 7;
    int arr[size];
    CreateRandomArray(arr,size,1,10);
    PrintArray(arr,size);
    AddElement(arr,size,11);
    AddIndexElement(arr, size, 11, 3);
    DeleteIndexElement(arr, size, 3);
    return 0;
}
