//Абрамова Алиса Григорьевна
//Написать функцию, которая получает указатель на статический массив и его размер.
//Функция распределяет положительные, отрицательные и нулевые элементы в отдельные динамические массивы.
#include <iostream>
#include <ctime>

using namespace std;
void CreateRandomArray (int* arr, int size, int start, int end) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        *(arr + i) = start + rand() % (end - start +1);
    }
}
void PrintArray (int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int CountPositive (int* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) count++;
    }
    return count;
}
int CountNegative (int* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) count++;
    }
    return count;
}
int CountNull (int* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == 0) count++;
    }
    return count;
}
int* PositiveArray (int* arr, int size, int& new_size) {
    new_size = CountPositive(arr, size);
    int* temp = new int[new_size];
    for (int i = 0, j = 0; i < size; i++) {
        if (arr[i] > 0) {
            temp[j] = arr[i];
            j++;
        }
    }
    return temp;
}
int* NegativeArray (int* arr, int size, int& new_size) {
    new_size = CountNegative(arr, size);
    int* temp = new int[new_size];
    for (int i = 0, j = 0; i < size; i++) {
        if (arr[i] < 0) {
            temp[j] = arr[i];
            j++;
        }
    }
    return temp;
}
int* NullsArray (int* arr, int size, int& new_size) {
    new_size = CountNull(arr, size);
    int* temp = new int[new_size];
    for (int i = 0, j = 0; i < size; i++) {
        if (arr[i] == 0) {
            temp[j] = arr[i];
            j++;
        }
    }
    return temp;
}
int main() {
    int size = 10;
    int arr[size];
    CreateRandomArray(arr, size,-5,5);
    cout << "Given array:\t";
    PrintArray(arr, size);
    int positive_el, negative_el, null_el;
    int* positives = PositiveArray(arr, size, positive_el);
    cout << "Positive array elements:\t";
    PrintArray(positives, positive_el);
    int* negatives = NegativeArray(arr, size, negative_el);
    cout << "Negative array elements:\t";
    PrintArray(negatives, negative_el);
    int* nulls = NullsArray(arr, size, null_el);
    cout << "Null array elements:\t";
    PrintArray(nulls, null_el);
    return 0;
}
