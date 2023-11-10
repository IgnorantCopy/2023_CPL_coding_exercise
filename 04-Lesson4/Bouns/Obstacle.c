//
// Created by Ignorant on 2023/10/22.
//


#include <stdio.h>
#include <math.h>

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
        while (yA != yB - 1) {
            if (yA == yC - 1 && xA == xC) {
                while (xA != xB) {
                    result[n++] = 'R';
                    xA++;
                }
            }
            result[n++] = 'U';
            yA++;
        }
        if () {
            
        }
        while (xA != xB) {
            if (xA == xC - 1) {
                while () {

                }
            }
        }
    }else if (yB > yA && xB == xA) {

    }else if (yB > yA && xB < xA) {

    } else if (yB == yA && xB > xA) {

    } else if (yB == yA && xB == xA) {

    } else if (yB == yA && xB < xA) {

    } else if (yB < yA && xB > xA) {

    } else if (yB < yA && xB == xA) {

    } else if (yB < yA && xB < xA) {

    }
    return 0;
}
