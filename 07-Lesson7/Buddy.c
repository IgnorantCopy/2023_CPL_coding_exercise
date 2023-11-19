//
// Created by Ignorant on 2023/11/18.
//


#include <stdio.h>
#include <math.h>
#define LEN 10000


int buddy[LEN][5] = {0};

int main() {
    int n = 0;
    int q = 0;
    int sum = 1;
    int start = 0;
    int isSequence = 1;
    scanf("%d%d", &n, &q);
    buddy[0][0] = n;
    buddy[0][3] = -1;
    buddy[0][4] = -1;
    for (int i = 0; i < q; i++) {
        char key = 0;
        getchar();
        scanf("%c", &key);
        int size = 1;
        int request = 0;
        int id = 0;
        switch (key) {
            case 'A':
                scanf("%d%d", &id, &request);
                while (request > size) {
                    size <<= 1;
                }
                size = log2(size);
                for (int j = start; j != -1;) {
                    if (buddy[j][1] || size > buddy[j][0]) {
                        j = buddy[j][3];
                    } else if (size == buddy[j][0]) {
                        buddy[j][1] = 1;
                        buddy[j][2] = id;
                        break;
                    } else if (size < buddy[j][0]) {
                        buddy[j][0]--;
                        buddy[sum][0] = buddy[j][0];
                        if (j == sum - 1 && isSequence) {
                            start = sum;
                            buddy[sum][3] = j;
                            buddy[sum][4] = -1;
                            buddy[j][4] = sum;
                        } else {
                            isSequence = 0;
                            buddy[sum][3] = j;
                            buddy[sum][4] = buddy[j][4];
                            buddy[buddy[j][4]][3] = sum;
                            buddy[j][4] = sum;
                        }
                        j = sum++;
                    }
                }
                break;
            case 'Q':
                printf("%d\n", sum);
                for (int j = start; j != -1; j = buddy[j][3]) {
                    printf("%d ", buddy[j][2]);
                }
                printf("\n");
                break;
        }
    }
    return 0;
}
