#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 7

int vertex_count = 0;

struct vertex {
    char data;
    bool visited;
};

struct vertex *graph[MAX];
int adj_matrix[MAX][MAX];

// Queue variables
int queue[MAX];
int rear = -1;
int front = 0;
int queue_count = 0;

// -------------------- Queue Operations --------------------
void enqueue(int data) {
    if (rear == MAX - 1) {
        printf("\nQueue overflow!\n");
        return;
    }
    queue[++rear] = data;
    queue_count++;
}

int dequeue() {
    if (queue_count == 0) {
        printf("\nQueue underflow!\n");
        return -1;
    }
    queue_count--;
    return queue[front++];
}

bool is_queue_empty() {
    return queue_count == 0;
}

// -------------------- Graph Operations --------------------
void add_vertex(char data) {
    if (vertex_count >= MAX) {
        printf("\nCannot add more vertices (limit reached)\n");
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
    adj_matrix[end][start] = 1; // undirected graph
}

int adj_vertex(int vertex_get) {
    for (int i = 0; i < vertex_count; i++) {
        if (adj_matrix[vertex_get][i] == 1 && !graph[i]->visited) {
            return i;
        }
    }
    return -1;
}

void display_vertex(int pos) {
    printf("%c ", graph[pos]->data);
}

// -------------------- BFS Traversal --------------------
void bfs(struct vertex *start_vertex, int start_index) {
    if (!start_vertex) {
        printf("\nNothing to display (graph empty)\n");
        return;
    }

    printf("\nBFS Traversal: ");
    start_vertex->visited = true;
    display_vertex(start_index);
    enqueue(start_index);

    while (!is_queue_empty()) {
        int current_vertex = dequeue();
        if (current_vertex == -1) break; // safety

        int unvisited;
        while ((unvisited = adj_vertex(current_vertex)) != -1) {
            graph[unvisited]->visited = true;
            display_vertex(unvisited);
            enqueue(unvisited);
        }
    }
    printf("\n");

    // Reset visited flags
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

// -------------------- Main Function --------------------
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
        printf("3) BFS Traversal\n");
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
                bfs(graph[start], start);
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
