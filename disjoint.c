#include <stdio.h>
#include <stdlib.h>

#define MAX 50

struct node {
    struct node *rep;
    struct node *next;
    int data;
};

struct node *head[MAX], *tail[MAX];
int countRoot = 0;

void makeSet(int x) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->rep = newNode;
    newNode->next = NULL;
    newNode->data = x;
    head[countRoot] = newNode;
    tail[countRoot] = newNode;
    countRoot++;
}

struct node *find(int a) {
    for (int i = 0; i < countRoot; i++) {
        struct node *temp = head[i];
        while (temp != NULL) {
            if (temp->data == a)
                return temp->rep;
            temp = temp->next;
        }
    }
    return NULL;
}

void unionSets(int a, int b) {
    int pos = -1;
    struct node *rep1 = find(a);
    struct node *rep2 = find(b);
    if (rep1 == NULL || rep2 == NULL) {
        printf("\nElement not present in the DS\n");
        return;
    }
    if (rep1 != rep2) {
        struct node *tail2 = NULL;
        // find position of rep2's set
        for (int j = 0; j < countRoot; j++) {
            if (head[j] == rep2) {
                pos = j;
                tail2 = tail[j];
                break;
            }
        }
        if (pos == -1) return;

        // remove rep2's set from arrays
        for (int i = pos; i < countRoot - 1; i++) {
            head[i] = head[i + 1];
            tail[i] = tail[i + 1];
        }
        countRoot--;

        // find rep1's set
        for (int j = 0; j < countRoot; j++) {
            if (head[j] == rep1) {
                tail[j]->next = rep2;
                tail[j] = tail2;
                break;
            }
        }

        // update representative
        struct node *temp = rep2;
        while (temp != NULL) {
            temp->rep = rep1;
            temp = temp->next;
        }
    }
}

int search(int x) {
    for (int i = 0; i < countRoot; i++) {
        struct node *temp = head[i];
        while (temp != NULL) {
            if (temp->data == x)
                return 1;
            temp = temp->next;
        }
    }
    return 0;
}

int main() {
    int choice, x, y;
    struct node *rep;

    do {
        printf("\n....MENU.....\n");
        printf("1. Make Set\n");
        printf("2. Display Set Representatives\n");
        printf("3. Union\n");
        printf("4. Find Set\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter new element: ");
            scanf("%d", &x);
            if (search(x))
                printf("\nElement already present in the disjoint set\n");
            else
                makeSet(x);
            break;

        case 2:
            printf("\nSet representatives: ");
            for (int i = 0; i < countRoot; i++)
                printf("%d ", head[i]->data);
            printf("\n");
            break;

        case 3:
            printf("\nEnter the first element: ");
            scanf("%d", &x);
            printf("Enter the second element: ");
            scanf("%d", &y);
            unionSets(x, y);
            break;

        case 4:
            printf("\nEnter the element: ");
            scanf("%d", &x);
            rep = find(x);
            if (rep == NULL)
                printf("\nElement not present in the DS\n");
            else
                printf("\nThe representative of %d is %d\n", x, rep->data);
            break;

        case 5:
            exit(0);

        default:
            printf("\nWrong choice\n");
        }
    } while (1);
    return 0;
}
