//
// Created by Ignorant on 2023/10/16.
//


#include <stdio.h>
#include <string.h>

char nums1[1000][10002] = {0};
char nums2[1000][10002] = {0};
char operator[1000] = {0};
char result[1000][10005] = {0};

void add(int i) {
    int num1;
    int num2;
    int bit = 0;
    int j = strlen(nums1[i]) - 1;
    int k = strlen(nums2[i]) - 1;
    while (1) {
        num1 = 0;
        num2 = 0;
        if (j >= 0) {
            num1 = nums1[i][j] - 48;
            j--;
        }
        if (k >= 0) {
            num2 = nums2[i][k] - 48;
            k--;
        }
        int num = num1 + num2 + result[i][bit];
        result[i][bit] = num % 10 + 48;
        if (j == -1 && k == -1) {
            if (num >= 10) {
                result[i][bit + 1] = num / 10 + 48;
            }
            break;
        } else if (num >= 10) {
            result[i][bit + 1] = num / 10;
        }
        bit++;
    }
}

void minus(int i) {
    int num1;
    int num2;
    int bit = 0;
    int j = strlen(nums1[i]) - 1;
    int k = strlen(nums2[i]) - 1;
    while (1) {
        num1 = 0;
        num2 = 0;
        if (j >= 0) {
            num1 = nums1[i][j] - 48;
            j--;
        }
        if (k >= 0) {
            num2 = nums2[i][k] - 48;
            k--;
        }
        int num = num1 - num2 - result[i][bit];
        if (num >= 0) {
            result[i][bit] = num + 48;
        } else {
            result[i][bit] = num + 58;
            result[i][bit + 1] += 1;
        }
        if (j == -1 && k == -1) {
            break;
        }
        bit++;
    }
}

void multiply(int i) {
    int bit = 0;
    int len1 = strlen(nums1[i]) - 1;
    int len2 = strlen(nums2[i]) - 1;
    if ((len1 == 0 && nums1[i][0] == '0') || (len2 == 0 && nums2[i][0] == '0')) {
        result[i][0] += 48;
    } else {
        for (int j = len1; j >= 0; j--) {
            for (int k = len2; k >= 0; k--) {
                bit = len1 - j + len2 - k;
                int num = (nums1[i][j] - 48) * (nums2[i][k] - 48);
                result[i][bit] += num % 10;
                result[i][bit + 1] += num / 10;
            }
        }
        for (int j = 0; j < strlen(result[i]); j++) {
            if (result[i][j] < 10) {
                result[i][j] += 48;
            } else {
                if (j != strlen(result[i]) - 1) {
                    result[i][j + 1] += result[i][j] / 10;
                } else {
                    result[i][j + 1] += result[i][j] / 10 + 48;
                }
                result[i][j] = result[i][j] % 10 + 48;
            }
        }
    }
}

void divide(int i) {
    int bit = 0;
    int len1 = strlen(nums1[i]) - 1;
    int len2 = strlen(nums2[i]) - 1;
    int isSmall = 0;
    if (len1 < len2) {
        isSmall = 1;
    } else if (len1 == len2) {
        for (int j = 0; j < len1; j++) {
            if (nums1[i][j] < nums2[i][j]) {
                isSmall = 1;
                break;
            }
        }
    }
    if (len2 == 0 && nums2[0] == '0') {
        printf("Error");
    } else if (isSmall) {
        result[i][0] += 48;
    } else {
        for (int j = 0; j < len2; j++) {
            
        }
    }
}

int main() {
    int t = 0;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%s", nums1[i]);
        getchar();
        scanf("%c", &operator[i]);
        getchar();
        scanf("%s", nums2[i]);
    }
    for (int i = 0; i < t; i++) {
        int resultLength;
        int isExtra = 0;
        switch (operator[i]) {
            case '+':
                add(i);
                resultLength = strlen(result[i]) - 1;
                if (result[i][resultLength] == '0' && resultLength != 0) {
                    resultLength--;
                }
                for (; resultLength >= 0; resultLength--) {
                    printf("%c", result[i][resultLength]);
                }
                if (i != t - 1) {
                    printf("\n");
                }
                break;
            case '-':
                minus(i);
                resultLength = strlen(result[i]) - 1;
                if (result[i][resultLength] == '0' && resultLength != 0) {
                    isExtra = 1;
                }
                for (int j = resultLength; j >= 0; j--) {
                    if (result[i][j] != '0' && j != resultLength) {
                        isExtra = 0;
                    }
                    if (isExtra && result[i][j] == '0') {
                        continue;
                    }
                    printf("%c", result[i][j]);
                }
                if (i != t - 1) {
                    printf("\n");
                }
                break;
            case '*':
                multiply(i);
                resultLength = strlen(result[i]) - 1;
                for (int j = resultLength; j >= 0; j--) {
                    printf("%c", result[i][j]);
                }
                if (i != t - 1) {
                    printf("\n");
                }
                break;
            case '/':
                divide(i);

                break;
        }
    }
    return 0;
}
