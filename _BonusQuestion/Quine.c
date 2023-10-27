//
// Created by Ignorant on 2023/10/24.
//


#include <stdio.h>

int main() {
    FILE *file = fopen("CMakeLists.txt", "r");
    char out;
    while ((out = fgetc(file) != EOF)) {
        putchar(out);
    }
    fclose(file);
    return 0;
}
