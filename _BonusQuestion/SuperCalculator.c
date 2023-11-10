//
// Created by Ignorant on 2023/10/16.
//


#include <stdio.h>
#include <string.h>

char nums1[1000][10002] = {0};
char nums2[1000][10002] = {0};
char operator[1000] = {0};
char out[1000][10005] = {0};

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
        int num = num1 + num2 + out[i][bit];
        out[i][bit] = num % 10 + 48;
        if (j == -1 && k == -1) {
            if (num >= 10) {
                out[i][bit + 1] = num / 10 + 48;
            }
            break;
        } else if (num >= 10) {
            out[i][bit + 1] = num / 10;
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
        int num = num1 - num2 - out[i][bit];
        if (num >= 0) {
            out[i][bit] = num + 48;
        } else {
            out[i][bit] = num + 58;
            out[i][bit + 1] += 1;
        }
        if (j == -1 && k == -1) {
            break;
        }
        bit++;
    }
}

void multiply(int i) {
    int bit;
    int len1 = strlen(nums1[i]) - 1;
    int len2 = strlen(nums2[i]) - 1;
    int isFirst[10005] = {0};
    if ((len1 == 0 && nums1[i][0] == '0') || (len2 == 0 && nums2[i][0] == '0')) {
        out[i][0] += 48;
    } else {
        for (int j = len1; j >= 0; j--) {
            for (int k = len2; k >= 0; k--) {
                bit = len1 - j + len2 - k;
                int num = (nums1[i][j] - 48) * (nums2[i][k] - 48);
                if (!isFirst[bit]) {
                    out[i][bit] += 48;
                    isFirst[bit] = 1;
                }
                out[i][bit] += num % 10;
                if (!isFirst[bit + 1]) {
                    out[i][bit + 1] += 48;
                    isFirst[bit + 1] = 1;
                }
                out[i][bit + 1] += num / 10;
                for (int l = 0; out[i][bit + l] - 48 >= 10; l++) {
                    if (!isFirst[bit + l + 1]) {
                        out[i][bit + l + 1] += 48;
                        isFirst[bit + l + 1] = 1;
                    }
                    out[i][bit + l + 1] += (out[i][bit + l] - 48) / 10;
                    out[i][bit + l] = (out[i][bit + l] - 48) % 10 + 48;
                }
            }
        }
    }
}

void divide(int i) {
    int bit = 0;
    int len1 = strlen(nums1[i]);
    int len2 = strlen(nums2[i]);
    int isSmall = 0;
    if (len1 < len2) {
        isSmall = 1;
    } else if (len1 == len2) {
        for (int j = 0; j < len1; j++) {
            if (nums1[i][j] < nums2[i][j]) {
                isSmall = 1;
                break;
            } else if (nums1[i][j] > nums2[i][j]) {
                break;
            }
        }
    }
    if (len2 == 1 && nums2[i][0] == '0') {
        printf("Error");
    } else if (isSmall) {
        out[i][0] += 48;
    } else {
        for (int j = 0; j <= len1 - len2; j++) {
            int mul = 0;
            isSmall = 0;
            while (!isSmall) {
                for (int k = j; k < len2 + j; k++) {
                    if ((j > 0 && nums1[i][j - 1] != '0') || (nums2[i][k - j] < nums1[i][k])) {
                        break;
                    } else if (nums2[i][k - j] > nums1[i][k]) {
                        isSmall = 1;
                        break;
                    }
                }
                if (isSmall) {
                    out[i][bit++] = mul + 48;
                } else {
                    int num = 0;
                    int temp = 0;
                    for (int k = len2 + j - 1; k >= j; k--) {
                        num = nums1[i][k] - nums2[i][k - j] + temp;
                        if (num >= 0) {
                            nums1[i][k] = num + 48;
                            temp = 0;
                        } else {
                            nums1[i][k] = num + 58;
                            if (k == j) {
                                nums1[i][k - 1] -= 1;
                            } else {
                                temp = -1;
                            }
                        }
                    }
                    mul++;
                }
            }
        }
    }
}

void PrintAdd(int i, int t) {
    int resultLength = strlen(out[i]) - 1;
    if (out[i][resultLength] == '0' && resultLength != 0) {
        resultLength--;
    }
    for (; resultLength >= 0; resultLength--) {
        printf("%c", out[i][resultLength]);
    }
    if (i != t - 1) {
        printf("\n");
    }
}

void PrintMinus(int i, int t) {
    int isExtra = 0;
    int resultLength = strlen(out[i]) - 1;
    if (out[i][resultLength] == '0' && resultLength != 0) {
        isExtra = 1;
    }
    for (int j = resultLength; j >= 0; j--) {
        if (out[i][j] != '0' && j != resultLength) {
            isExtra = 0;
        }
        if (isExtra && out[i][j] == '0') {
            continue;
        }
        printf("%c", out[i][j]);
    }
    if (i != t - 1) {
        printf("\n");
    }
}

void PrintMultiply(int i, int t) {
    int resultLength = strlen(out[i]) - 1;
    for (int j = resultLength; j >= 0; j--) {
        if (j == resultLength && out[i][j] == '0') {
            continue;
        } else {
            printf("%c", out[i][j]);
        }
    }
    if (i != t - 1) {
        printf("\n");
    }
}

void PrintDivide(int i, int t) {
    int start = 0;
    int resultLength = strlen(out[i]);
    if (resultLength != 1) {
        for (int j = 0; j < resultLength; j++) {
            if (out[i][j] == '0') {
                start++;
            } else {
                break;
            }
        }
    }
    for (int j = start; j < resultLength; j++) {
        printf("%c", out[i][j]);
    }
    if (i != t - 1) {
        printf("\n");
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
        switch (operator[i]) {
            case '+':
                add(i);
                PrintAdd(i, t);
                break;
            case '-':
                minus(i);
                PrintMinus(i, t);
                break;
            case '*':
                multiply(i);
                PrintMultiply(i, t);
                break;
            case '/':
                divide(i);
                PrintDivide(i, t);
                break;
        }
    }
    return 0;
}
