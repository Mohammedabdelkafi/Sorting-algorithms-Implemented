#include <stdio.h>

int arr[] = {5, 8, 7, 4, 6, 2, 3, 1};
int sorted_arr[100];
int ln = sizeof(arr) / sizeof(arr[0]);

int find_min(int array[], int size) {
    int min = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

int remove_value(int array[], int size, int value) {
    int i, j;
    for (i = 0; i < size; i++) {
        if (array[i] == value) {
            for (j = i; j < size - 1; j++) {
                array[j] = array[j + 1];
            }
            break;
        }
    }
    return size - 1;
}

void sort() {
    int temp_arr[100];
    int size = ln;
    for (int i = 0; i < ln; i++) {
        int mn = find_min(arr, size);
        sorted_arr[i] = mn;
        size = remove_value(arr, size, mn);
    }
}

int main() {
    sort();
    for (int i = 0; i < ln; i++) {
        printf("%d ", sorted_arr[i]);
    }
    return 0;
}
