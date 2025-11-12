#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

// Structure to represent a vertex
struct vertex {
    char data;
    bool visited;
};

struct vertex *graph[MAX];
int adj_matrix[MAX][MAX];
int vertex_count = 0;

// Stack for DFS
int stack[MAX];
int top = -1;

// ---------------- Stack Operations ----------------
void push(int data) {
    if (top == MAX - 1) {
        printf("\nStack Overflow!\n");
        return;
    }
    stack[++top] = data;
}

int pop() {
    if (top == -1) {
        printf("\nStack Underflow!\n");
        return -1;
    }
    return stack[top--];
}

bool is_stack_empty() {
    return top == -1;
}

// ---------------- Graph Operations ----------------
void add_vertex(char data) {
    if (vertex_count >= MAX) {
        printf("\nCannot add more vertices!\n");
        return;
    }
    struct vertex *newv = (struct vertex *)malloc(sizeof(struct vertex));
    newv->data = data;
    newv->visited = false;
    graph[vertex_count++] = newv;
}

void add_edge(int start, int end) {
    if (start >= vertex_count || end >= vertex_count) {
        printf("\nInvalid vertex index!\n");
        return;
    }
    adj_matrix[start][end] = 1;
    adj_matrix[end][start] = 1; // Undirected graph
}

int adj_unvisited_vertex(int vertex_index) {
    for (int i = 0; i < vertex_count; i++) {
        if (adj_matrix[vertex_index][i] == 1 && graph[i]->visited == false) {
            return i;
        }
    }
    return -1;
}

void display_vertex(int pos) {
    printf("%c ", graph[pos]->data);
}

// ---------------- DFS Traversal ----------------
void dfs(int start) {
    // Step 2: Mark start vertex as visited and push it
    graph[start]->visited = true;
    display_vertex(start);
    push(start);

    while (!is_stack_empty()) {
        int peek_vertex = stack[top];
        int unvisited = adj_unvisited_vertex(peek_vertex);

        if (unvisited == -1) {
            // If no unvisited adjacent vertices, pop from stack
            pop();
        } else {
            // Visit the adjacent vertex
            graph[unvisited]->visited = true;
            printf("->");
            display_vertex(unvisited);
            push(unvisited);
        }
    }

    // Reset visited flags for next traversal
    for (int i = 0; i < vertex_count; i++) {
        graph[i]->visited = false;
    }
}

void show_vertices() {
    printf("\nVertices and their positions:\n");
    for (int i = 0; i < vertex_count; i++) {
        printf("Position %d → %c\n", i, graph[i]->data);
    }
}

// ---------------- Main Function ----------------
int main() {
    int opt;
    char data;
    int edge_1, edge_2, start;

    // Initialize adjacency matrix
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            adj_matrix[i][j] = 0;

    do {
        printf("\n==== MENU ====\n");
        printf("1) Add vertex\n");
        printf("2) Create edge\n");
        printf("3) DFS Traversal\n");
        printf("0) Exit\n");
        printf("Choose option: ");
        scanf("%d", &opt);

        switch (opt) {
        case 1:
            printf("\nEnter data to be added to vertex: ");
            scanf(" %c", &data);
            add_vertex(data);
            break;

        case 2:
            show_vertices();
            printf("\nEnter edge starting position: ");
            scanf("%d", &edge_1);
            printf("Enter edge ending position: ");
            scanf("%d", &edge_2);
            add_edge(edge_1, edge_2);
            break;

        case 3:
            if (vertex_count == 0) {
                printf("\nNo vertices to traverse.\n");
                break;
            }
            show_vertices();
            printf("\nEnter starting vertex position: ");
            scanf("%d", &start);
            if (start < 0 || start >= vertex_count) {
                printf("\nInvalid start position!\n");
            } else {
                printf("\nDFS Traversal: ");
                dfs(start);
                printf("\n");
            }
            break;

        case 0:
            printf("\nExiting...\n");
            break;

        default:
            printf("\nInvalid option!\n");
        }
    } while (opt != 0);

    return 0;
}
