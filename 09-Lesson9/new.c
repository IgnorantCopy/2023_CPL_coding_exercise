//
// Created by Ignorant on 2023/12/2.
//

#include <stdio.h> //嘈嘈切切错杂弹
#include <string.h>
#include <stdlib.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        char s[2050];
        scanf("%s", s);
        char *s1 = malloc(1000 * sizeof(char));
        char *s2 = malloc(1000 * sizeof(char));
        char *delim = ";";
        s1 = strtok(s, delim);
        s2 = strtok(NULL, delim);
        int d1 = atoi(strtok(NULL, delim));
        int d2 = atoi(strtok(NULL, delim));
        int size = atoi(strtok(NULL, delim));
        char *s3 = malloc(size * sizeof(char));
        int i = 0, j = 0, k = 0, x;
        x = i + j;
        while (x < size - 1) {
            for (i; i < d1 + k * d1 && x < size - 1 && s1[i] != '\0'; i++) {
                s3[x] = s1[i];
                x++;
            }
            for (j; j < d2 + k * d2 && x < size - 1 && s2[j] != '\0'; j++) {
                s3[x] = s2[j];
                x++;
            }
            if (x == size - 1) {
                s3[x] = '\0';
            }
            k++;
        }
        printf("%s\n", s3);
        free(s1);
        free(s2);
    }
    return 0;
}
