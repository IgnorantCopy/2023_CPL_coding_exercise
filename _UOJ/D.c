//
// Created by Ignorant on 2023/12/2.
//

#include <stdio.h>
#include <string.h>
char argv[1000001] = {0};
char output1[1000001] = {0};
char output2[1000001] = {0};

int main() {
    scanf("%s", argv);
    int len = strlen(argv);
    if (argv[0] >= 'A' && argv[0] <= 'Z') {
        strcpy(output1, argv);
        output1[0] += 32;
        int index = 0;
        for (int i = 0; i < len; i++) {
            if (output1[i] >= 'A' && output1[i] <= 'Z') {
                output2[index++] = '_';
                output2[index++] = output1[i] + 32;
            } else {
                output2[index++] = output1[i];
            }
        }
        printf("%s\n%s\n%s", output1, argv, output2);
    } else {
        int flag = 0;
        for (int i = 0; i < len; i++) {
            if (argv[i] == '_') {
                flag = 1;
                break;
            }
        }
        int index = 0;
        switch (flag) {
            case 0:
                strcpy(output1, argv);
                output1[0] -= 32;
                for (int i = 0; i < len; i++) {
                    if (argv[i] >= 'A' && argv[i] <= 'Z') {
                        output2[index++] = '_';
                        output2[index++] = argv[i] + 32;
                    } else {
                        output2[index++] = argv[i];
                    }
                }
                printf("%s\n%s\n%s", argv, output1, output2);
                break;
            case 1:
                for (int i = 0; i < len; i++) {
                    if (argv[i] == '_') {
                        i++;
                        output1[index++] = argv[i] - 32;
                    } else {
                        output1[index++] = argv[i];
                    }
                }
                strcpy(output2, output1);
                output2[0] -= 32;
                printf("%s\n%s\n%s", output1, output2, argv);
                break;
        }
    }
    return 0;
}
