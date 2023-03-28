//Абрамова Алиса Григорьевна
//Написать функцию, которая получает указатель на динамический массив и его размер.
//Функция должна удалить из массива все какие-то числа(отрицательные) и вернуть указатель на новый динамический массив.

#include<iostream>

using namespace std;
void CreateRandomArray (int* arr, int size, int start, int end) {
    for (int i = 0; i < size; i++) {
        *(arr + i) = start + rand() % (end - start + 1);
    }
}
void PrintArray (int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int Count (int* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] >= 0) count++;
    }
    return count;
}
int* DeleteNegative (int* arr, int size, int& new_size) {
    new_size = Count(arr,size);
    int* new_array = new int[new_size];
    for (int i = 0, j = 0; i < size; i++) {
        if (arr[i] < 0) continue;
        new_array[j] = arr[i];
        j++;
    }
    return new_array;
}
int main() {
    int size = 10;
    int array[size];
    CreateRandomArray(array,size,-20,10);
    PrintArray(array,size);
    int different_size;
    int *new_arr = DeleteNegative(array,size,different_size);
    PrintArray(new_arr,different_size);
    return 0;
}
