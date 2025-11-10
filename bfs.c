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
    i
