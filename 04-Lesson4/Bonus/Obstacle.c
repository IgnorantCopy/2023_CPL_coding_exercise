//
// Created by Ignorant on 2023/10/22.
//


#include <stdio.h>

char step[5] = {'U', 'D', 'L', 'R'};
char out[500000] = {0};

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
                out[n++] = 'R';
                xA++;
            }
            while (yA != yB) {
                out[n++] = 'U';
                yA++;
            }
        } else {
            while (yA != yB) {
                if (yA == yC - 1 && xA == xC) {
                    out[n++] = 'R';
                    xA++;
                }
                out[n++] = 'U';
                yA++;
            }
            while (xA != xB) {
                out[n++] = 'R';
                xA++;
            }
        }
    } else if (yB > yA && xB == xA) {
        while (yA != yB) {
            if (xA == xC && yA == yC - 1) {
                out[n++] = 'R';
                out[n++] = 'U';
                out[n++] = 'U';
                out[n++] = 'L';
                yA += 2;
            } else {
                out[n++] = 'U';
                yA++;
            }
        }
    } else if (yB > yA && xB < xA) {
        if (yB == yC) {
            while (xA != xB) {
                out[n++] = 'L';
                xA--;
            }
            while (yA != yB) {
                out[n++] = 'U';
                yA++;
            }
        } else {
            while (yA != yB) {
                if (yA == yC - 1 && xA == xC) {
                    out[n++] = 'L';
                    xA--;
                }
                out[n++] = 'U';
                yA++;
            }
            while (xA != xB) {
                out[n++] = 'L';
                xA--;
            }
        }
    } else if (yB == yA && xB > xA) {
        while (xA != xB) {
            if (yA == yC && xA == xC - 1) {
                out[n++] = 'U';
                out[n++] = 'R';
                out[n++] = 'R';
                out[n++] = 'D';
                xA += 2;
            } else {
                out[n++] = 'R';
                xA++;
            }
        }
    } else if (yB == yA && xB < xA) {
        while (xA != xB) {
            if (yA == yC && xA == xC + 1) {
                out[n++] = 'U';
                out[n++] = 'L';
                out[n++] = 'L';
                out[n++] = 'D';
                xA -= 2;
            } else {
                out[n++] = 'L';
                xA--;
            }
        }
    } else if (yB < yA && xB > xA) {
        if (xB == xC) {
            while (yA != yB) {
                out[n++] = 'D';
                yA--;
            }
            while (xA != xB) {
                out[n++] = 'R';
                xA++;
            }
        } else {
            while (xA != xB) {
                if (yA == yC && xA == xC - 1) {
                    out[n++] = 'D';
                    yA--;
                }
                out[n++] = 'R';
                xA++;
            }
            while (yA != yB) {
                out[n++] = 'D';
                yA--;
            }
        }
    } else if (yB < yA && xB == xA) {
        while (yA != yB) {
            if (xA == xC && yA == yC + 1) {
                out[n++] = 'R';
                out[n++] = 'D';
                out[n++] = 'D';
                out[n++] = 'L';
                yA -= 2;
            } else {
                out[n++] = 'D';
                yA--;
            }
        }
    } else if (yB < yA && xB < xA) {
        if (xB == xC) {
            while (yA != yB) {
                out[n++] = 'D';
                yA--;
            }
            while (xA != xB) {
                out[n++] = 'L';
                xA--;
            }
        } else {
            while (xA != xB) {
                if (yA == yC && xA == xC + 1) {
                    out[n++] = 'D';
                    yA--;
                }
                out[n++] = 'L';
                xA--;
            }
            while (yA != yB) {
                out[n++] = 'D';
                yA--;
            }
        }
    }
    printf("%d\n", n);
    printf("%s", out);
    return 0;
}
