//
// Created by Ignorant on 2023/10/22.
//


#include <stdio.h>

char step[5] = {'U', 'D', 'L', 'R'};
char result[500000] = {0};

int main() {
    int xA = 0;
    int xB = 0;
    int xC = 0;
    int yA = 0;
    int yB = 0;
    int yC = 0;
    scanf("%d%d%d%d%d%d", &xA, &yA, &xB, &yB, &xC, &yC);
    int n = 0;
    if (yB > yA && xB > xA) {
        if (yB == yC) {
            while (xA != xB) {
                result[n++] = 'R';
                xA++;
            }
            while (yA != yB) {
                result[n++] = 'U';
                yA++;
            }
        } else {
            while (yA != yB) {
                if (yA == yC - 1 && xA == xC) {
                    result[n++] = 'R';
                    xA++;
                }
                result[n++] = 'U';
                yA++;
            }
            while (xA != xB) {
                result[n++] = 'R';
                xA++;
            }
        }
    } else if (yB > yA && xB == xA) {
        while (yA != yB) {
            if (xA == xC && yA == yC - 1) {
                result[n++] = 'R';
                result[n++] = 'U';
                result[n++] = 'U';
                result[n++] = 'L';
                yA += 2;
            } else {
                result[n++] = 'U';
                yA++;
            }
        }
    } else if (yB > yA && xB < xA) {
        if (yB == yC) {
            while (xA != xB) {
                result[n++] = 'L';
                xA--;
            }
            while (yA != yB) {
                result[n++] = 'U';
                yA++;
            }
        } else {
            while (yA != yB) {
                if (yA == yC - 1 && xA == xC) {
                    result[n++] = 'L';
                    xA--;
                }
                result[n++] = 'U';
                yA++;
            }
            while (xA != xB) {
                result[n++] = 'L';
                xA--;
            }
        }
    } else if (yB == yA && xB > xA) {
        while (xA != xB) {
            if (yA == yC && xA == xC - 1) {
                result[n++] = 'U';
                result[n++] = 'R';
                result[n++] = 'R';
                result[n++] = 'D';
                xA += 2;
            } else {
                result[n++] = 'R';
                xA++;
            }
        }
    } else if (yB == yA && xB < xA) {
        while (xA != xB) {
            if (yA == yC && xA == xC + 1) {
                result[n++] = 'U';
                result[n++] = 'L';
                result[n++] = 'L';
                result[n++] = 'D';
                xA -= 2;
            } else {
                result[n++] = 'L';
                xA--;
            }
        }
    } else if (yB < yA && xB > xA) {
        if (xB == xC) {
            while (yA != yB) {
                result[n++] = 'D';
                yA--;
            }
            while (xA != xB) {
                result[n++] = 'R';
                xA++;
            }
        } else {
            while (xA != xB) {
                if (yA == yC && xA == xC - 1) {
                    result[n++] = 'D';
                    yA--;
                }
                result[n++] = 'R';
                xA++;
            }
            while (yA != yB) {
                result[n++] = 'D';
                yA--;
            }
        }
    } else if (yB < yA && xB == xA) {
        while (yA != yB) {
            if (xA == xC && yA == yC + 1) {
                result[n++] = 'R';
                result[n++] = 'D';
                result[n++] = 'D';
                result[n++] = 'L';
                yA -= 2;
            } else {
                result[n++] = 'D';
                yA--;
            }
        }
    } else if (yB < yA && xB < xA) {
        if (xB == xC) {
            while (yA != yB) {
                result[n++] = 'D';
                yA--;
            }
            while (xA != xB) {
                result[n++] = 'L';
                xA--;
            }
        } else {
            while (xA != xB) {
                if (yA == yC && xA == xC + 1) {
                    result[n++] = 'D';
                    yA--;
                }
                result[n++] = 'L';
                xA--;
            }
            while (yA != yB) {
                result[n++] = 'D';
                yA--;
            }
        }
    }
    printf("%d\n", n);
    printf("%s", result);
    return 0;
}
