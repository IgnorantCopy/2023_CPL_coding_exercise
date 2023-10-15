//
// Created by Ignorant on 2023/10/15.
//

#include <stdio.h>

int numbers[1000000] = {0};

int main() {
    int n = 0;
    int k = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    int left = 0;
    int right = n - 1;
    int pivot = numbers[k - 1];
    int index = k - 1;
    while (1) {
        while (numbers[left] < pivot && left != right) {
            left++;
        }
        while (numbers[right] >= pivot && left != right) {
            right--;
        }
        if (left >= right) {
            break;
        }
        numbers[left] = numbers[left] ^ numbers[right];
        numbers[right] = numbers[left] ^ numbers[right];
        numbers[left] = numbers[left] ^ numbers[right];
        if (right == index) {
            index = left;
        } else if (left == index) {
            index = right;
        }
    }
    for (int i = 0; i < n; i++) {
        if ((i < index && numbers[i] > pivot) || (i > index && numbers[i] < pivot)) {
            numbers[i] = numbers[i] ^ numbers[index];
            numbers[index] = numbers[i] ^ numbers[index];
            numbers[i] = numbers[i] ^ numbers[index];
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    return 0;
}
