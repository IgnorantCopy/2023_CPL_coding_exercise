//
// Created by Ignorant on 2023/10/29.
//


#include <stdio.h>
int nums[10] = {52, 10, 9, 36, 745, 321, 56, 8, 99, 10};

void BubbleSort(int arr[], int length);

void SelectionSort(int arr[], int length);

void InsertionSort(int arr[], int length);

void QuickSort(int arr[], int left, int right);

void MergeSort(int arr[], int left, int right);

void Merge(int arr[], int left1, int right1, int right2);

int main() {
//    BubbleSort(nums, 10);
//    SelectionSort(nums, 10);
//    InsertionSort(nums, 10);
//    QuickSort(nums, 0, 9);
//    MergeSort(nums, 0, 9);
    for (int i = 0; i < 10; i++) {
        printf("%d ", nums[i]);
    }
    return 0;
}

void BubbleSort(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                arr[j] ^= arr[j + 1] ^= arr[j] ^= arr[j + 1];
            }
        }
    }
}

void SelectionSort(int arr[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int k = 0; k < 10; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
        int min = arr[i];
        int index = i;
        for (int j = i; j < length; j++) {
            if (arr[j] <= min) {
                min = arr[j];
                index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
}

void InsertionSort(int arr[], int length) {
    for (int i = 1; i < length; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] <= arr[j]) {
                int temp = arr[i];
                for (int k = i; k > j; k--) {
                    arr[k] = arr[k - 1];
                }
                arr[j] = temp;
            }
        }
    }
}

void QuickSort(int arr[], int left, int right) {
    if (left < right) {
        int pivot = arr[left];
        int index = left;
        for (int i = left + 1; i <= right; i++) {
            if (arr[i] < pivot) {
                index++;
                int temp = arr[i];
                arr[i] = arr[index];
                arr[index] = temp;
            }
        }
        arr[left] = arr[index];
        arr[index] = pivot;
        QuickSort(arr, left, index - 1);
        QuickSort(arr, index + 1, right);
    }
}

void MergeSort(int arr[], int left, int right) {
    if (left < right) {
        int index = (left + right) / 2;
        MergeSort(arr, left, index);
        MergeSort(arr, index + 1, right);
        Merge(arr, left, index, right);
    }

}

void Merge(int arr[], int left1, int right1, int right2) {
    int newArr[right2 - left1 + 1];
    int index = 0;
    int i = left1;
    int j = right1 + 1;
    while (i <= right1 && j <= right2) {
        if (arr[i] <= arr[j]) {
            newArr[index++] = arr[i++];
        } else {
            newArr[index++] = arr[j++];
        }
    }
    if (j == right2 + 1) {
        while (i <= right1) {
            newArr[index++] = arr[i++];
        }
    } else {
        while (j <= right2) {
            newArr[index++] = arr[j++];
        }
    }
    index = 0;
    for (int k = left1; k <= right2; k++) {
        arr[k] = newArr[index++];
    }
}
