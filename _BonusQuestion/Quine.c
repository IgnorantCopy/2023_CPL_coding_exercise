//
// Created by Ignorant on 2023/10/24.
//


#include <stdio.h>

int main() {
    char *string = "#include <stdio.h>%c%cint main() {%c    char *string = %c%s%c;%c    printf(string, 10, 10, 10, 34, string, 34, 10, 10, 10);%c    return 0;%c}";
    printf(string, 10, 10, 10, 34, string, 34, 10, 10, 10);
    return 0;
}
