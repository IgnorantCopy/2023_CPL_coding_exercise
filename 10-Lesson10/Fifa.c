//
// Created by Ignorant on 2023/12/15.
//


#include <stdio.h>
#include <stdlib.h>

struct TeamMember {
    char name[21];
    int offense;
    int defense;
    int tactics;
};

struct Team {
    char name[21];
    struct TeamMember members[11];
    int offenseSum;
    int defenseSum;
    int tacticsSum;
};

int main() {
    int n = 0;
    scanf("%d", &n);
    struct Team *teams = malloc(n * sizeof(*teams));
    int sort1[1000] = {0};
    int sort2[1000] = {0};
    int sort3[1000] = {0};
    for (int i = 0; i < n; i++) {
        sort1[i] = i + 1;
        sort2[i] = i + 1;
        sort3[i] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", teams[i].name);
        int offenseSum = 0;
        int defenseSum = 0;
        int tacticsSum = 0;
        for (int j = 0; j < 11; j++) {
            scanf("%s%d%d%d", teams[i].members[j].name, &teams[i].members[j].offense,
                  &teams[i].members[j].defense, &teams[i].members[j].tactics);
            offenseSum += teams[i].members[j].offense;
            defenseSum += teams[i].members[j].defense;
            tacticsSum += teams[i].members[j].tactics;
        }
        teams[i].offenseSum = offenseSum;
        teams[i].defenseSum = defenseSum;
        teams[i].tacticsSum = tacticsSum;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (teams[sort1[j] - 1].offenseSum < teams[sort1[j + 1] - 1].offenseSum) {
                int temp = sort1[j];
                sort1[j] = sort1[j + 1];
                sort1[j + 1] = temp;
            }
            if (teams[sort2[j] - 1].defenseSum < teams[sort2[j + 1] - 1].defenseSum) {
                int temp = sort2[j];
                sort2[j] = sort2[j + 1];
                sort2[j + 1] = temp;
            }
            if (teams[sort3[j] - 1].tacticsSum < teams[sort3[j + 1] - 1].tacticsSum) {
                int temp = sort3[j];
                sort3[j] = sort3[j + 1];
                sort3[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%s ", teams[sort1[i] - 1].name);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", teams[sort2[i] - 1].name);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", teams[sort3[i] - 1].name);
    }
    printf("\n");
    free(teams);
    return 0;
}
