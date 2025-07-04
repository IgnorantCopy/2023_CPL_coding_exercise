//
// Created by Ignorant on 2023/12/28.
//


#include <stdio.h>
#include <string.h>

char line[1001] = {0};
char lineCopy[1001] = {0};

int main() {
    int n = 0;
    scanf("%d%s", &n, line);
    size_t len = strlen(line);
    strcpy(lineCopy, line);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < len; j++) {
            if (line[j] == 'A' && j != 0 && j != len - 1) {
                if (line[j - 1] == 'I' && line[j + 1] == 'I') {
                    lineCopy[j] = '#';
                } else {
                    lineCopy[j - 1] = lineCopy[j - 1] == 'I' ? 'I' : 'A';
                    lineCopy[j + 1] = lineCopy[j + 1] == 'I' ? 'I' : 'A';
                }
            } else if (line[0] == 'A' && line[1] != 'I') {
                lineCopy[1] = 'A';
            } else if (line[len - 1] == 'A' && line[len - 2] != 'I') {
                lineCopy[len - 2] = 'A';
            }
        }
        strcpy(line, lineCopy);
    }
    printf("%s\n", line);
    return 0;
}
