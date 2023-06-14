#include <stdio.h>
#include <string.h>

#define MAX_PEOPLE 10

typedef struct {
    char name[50];
    char parent[50];
} Person;

int countDescendants(Person people[], int n, char name[]) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(people[i].parent, name) == 0) {
            count += 1 + countDescendants(people, n, people[i].name);
        }
    }
    return count;
}

int countGenerations(Person people[], int n, char name[]) {
    int maxGeneration = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(people[i].parent, name) == 0) {
            int generation = 1 + countGenerations(people, n, people[i].name);
            if (generation > maxGeneration) {
                maxGeneration = generation;
            }
        }
    }
    return maxGeneration;
}

int main() {
    Person people[MAX_PEOPLE];
    int numPeople = 0;

    // Read child-parent relations
    while (1) {
        char child[50];
        char parent[50];
        scanf("%s", child);
        if (strcmp(child, "***") == 0) break;
        scanf("%s", parent);
        strcpy(people[numPeople].name, child);
        strcpy(people[numPeople].parent, parent);
        numPeople++;
    }

    // Perform queries
    while (1) {
        char cmd[50];
        char param[50];
        scanf("%s", cmd);
        if (strcmp(cmd, "***") == 0) break;
        scanf("%s", param);
        if (strcmp(cmd, "descendants") == 0) {
            int numDescendants = countDescendants(people, numPeople, param);
            printf("%d\n", numDescendants);
        } else if (strcmp(cmd, "generation") == 0) {
            int numGenerations = countGenerations(people, numPeople, param);
            printf("%d\n", numGenerations);
        }
    }

    return 0;
}
