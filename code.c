#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define MAX 100

typedef struct Edge {
    int dest, weight;
    struct Edge *next;
} Edge;

typedef struct {
    Edge *head[MAX];
    int vertices;
} Graph;

typedef struct {
    int vertex, dist;
} HNode;

typedef struct {
    HNode arr[MAX * MAX];
    int size;
} MinH;

Edge* createEdge(int dest, int weight) {
    Edge *newEdge = (Edge*)malloc(sizeof(Edge));

    newEdge->dest = dest;
    newEdge->weight = weight;
    newEdge->next = NULL;

    return newEdge;
}

void initializeGraph(Graph *g, int vertices) {
    g->vertices = vertices;

    for (int i = 0; i < vertices; i++) 
        g->head[i] = NULL;
}

void addEdge(Graph *g, int src, int dest, int weight) {
    Edge *newEdge = createEdge(dest, weight);

    newEdge->next = g->head[src];
    g->head[src] = newEdge;

    newEdge = createEdge(src, weight);

    newEdge->next = g->head[dest];
    g->head[dest] = newEdge;
}

void swap(HNode *a, HNode *b) {
    HNode temp = *a;
    *a = *b;
    *b = temp;
}

void insertH(MinH *H, int vertex, int dist) {
    int i = H->size++;
    H->arr[i].vertex = vertex;
    H->arr[i].dist = dist;

    while (i > 0 && H->arr[i].dist < H->arr[(i - 1) / 2].dist) {
        swap(&H->arr[i], &H->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

HNode extractMin(MinH *H) {
    HNode minNode = H->arr[0];

    H->arr[0] = H->arr[--H->size];
    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        
        if (left < H->size && H->arr[left].dist < H->arr[smallest].dist)
            smallest = left;
        
        if (right < H->size && H->arr[right].dist < H->arr[smallest].dist) 
            smallest = right;
        
        if (smallest == i) 
            break;

        swap(&H->arr[i], &H->arr[smallest]);
        i = smallest;
    }
    return minNode;
}

int isEmpty(MinH *H) {
    return H->size == 0;
}

void printPath(int parent[], int vertex) {
    if (parent[vertex] == -1) {
        printf("%d", vertex);
        return;
    }
    printPath(parent, parent[vertex]);
    printf(" -> %d", vertex);
}

void dijkstra(Graph *g, int source, int destination) {
    int dist[MAX];
    int parent[MAX];

    MinH H;
    H.size = 0;

    for (int i = 0; i < g->vertices; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }

    dist[source] = 0;
    insertH(&H, source, 0);

    while (!isEmpty(&H)) {

        HNode current = extractMin(&H);
        int u = current.vertex;

        if (current.dist != dist[u]) continue;
        if (u == destination) break;
        Edge *temp = g->head[u];

        while (temp != NULL) {

            int v = temp->dest;
            int weight = temp->weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                insertH(&H, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    if (dist[destination] == INT_MAX) printf("\nNo route exists between %d and %d.\n", source, destination);
    else {
        printf("\nShortest dist: %d\n", dist[destination]);
        printf("Shortest Path: ");
        printPath(parent, destination);
        printf("\n");
    }
}

int main() {
    Graph g;

    int vertices, edges, src, dest, weight, source, destination;

    printf("Enter number of locations: ");
    scanf("%d", &vertices);

    initializeGraph(&g, vertices);

    printf("Enter number of routes: ");
    scanf("%d", &edges);

    printf("\nEnter routes (source destination dist):\n");

    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(&g, src, dest, weight);
    }

    printf("\nEnter starting location: ");
    scanf("%d", &source);

    printf("Enter destination location: ");
    scanf("%d", &destination);

    dijkstra(&g, source, destination);

    return 0;
}