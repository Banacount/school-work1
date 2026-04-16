#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define VERTICES 6

struct Node {
    char id;
    int index;
    int weight;
    bool reached;
    struct Node * next;
};

void addEdge (struct Node *vertex, int edge_weight, char id, int index_);
void clearVertex (struct Node *vertex);
struct Node* initVertex (char id_in, bool reached_in, int weight, int index_);
void displayVertex (struct Node* vertex);
void displayAdjList (struct Node** graph_list);

// Algotimstims
void bellman_ford_func(struct Node ** graph_list, bool debugMode);

int main () {
    struct Node ** graph_list = (struct Node**)malloc(VERTICES * sizeof(struct Node*));

    // Initialize Vertices
    graph_list[0] = initVertex('S', true, 0, 0);
    graph_list[1] = initVertex('A', false, 0, 1);
    graph_list[2] = initVertex('B', false, 0, 2);
    graph_list[3] = initVertex('C', false, 0, 3);
    graph_list[4] = initVertex('D', false, 0, 4);
    graph_list[5] = initVertex('E', false, 0, 5);

    // Connecting edges
    // S
    addEdge(graph_list[0], 10, 'A', 1);
    addEdge(graph_list[0], 8, 'E', 5);
    // A
    addEdge(graph_list[1], 2, 'C', 3);
    // B
    addEdge(graph_list[2], 1, 'A', 1);
    // C
    addEdge(graph_list[3], -2, 'B', 2);
    // D
    addEdge(graph_list[4], -4, 'A', 1);
    addEdge(graph_list[4], -1, 'C', 3);
    // E
    addEdge(graph_list[5], 1, 'D', 4);

    //test
    // Before
    printf("-- Initialization --\n");
    displayAdjList(graph_list);

    // After
    printf("\n-- Bellman-Ford Algorithm Recreation --\n");
    bellman_ford_func(graph_list, true);
    displayAdjList(graph_list);

    // Free the vertices
    clearVertex(graph_list[0]);
    clearVertex(graph_list[1]);
    clearVertex(graph_list[2]);
    clearVertex(graph_list[3]);
    clearVertex(graph_list[4]);
    clearVertex(graph_list[5]);
    free(graph_list);
    return 0;
}

void addEdge (struct Node *vertex, int edge_weight, char id, int index_) 
{
    struct Node *temp = vertex;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    struct Node *edge = (struct Node*)malloc(sizeof(struct Node));
    edge->weight = edge_weight;
    edge->id = id;
    edge->index = index_;
    edge->next = NULL;
    temp->next = edge;
}

void clearVertex (struct Node *vertex) 
{
    struct Node *temp;

    while (vertex != NULL) {
        temp = vertex;
        vertex = vertex->next;
        free(temp);
    }
}

struct Node* initVertex (char id_in, bool reached_in, int weight, int index_)
{
    struct Node* vertex = (struct Node*)malloc(sizeof(struct Node));
    vertex->id = id_in;
    vertex->reached = reached_in;
    vertex->weight = weight;
    vertex->index = index_;
    vertex->next = NULL;
    return vertex;
}

void displayVertex (struct Node* vertex)
{
    struct Node* temp = vertex;
    while (temp->next != NULL) {
        printf("%c->", temp->id);
        temp = temp->next;
    }
    printf("%c", temp->id);
    printf("\n");
}

void displayAdjList (struct Node** graph_list)
{
    for (int i = 0; i < VERTICES; ++i) {
        displayVertex(graph_list[i]);
    }
    printf("\n");

    for (int i = 0; i < VERTICES; ++i) {
        printf("%c: %d | ", graph_list[i]->id, graph_list[i]->weight);
    }
    printf("\n");
}

void bellman_ford_func(struct Node ** graph_list, bool debugMode)
{
    if (debugMode) printf("Under the hood proces (For Debugging)-->\n");
    for (int round = 0; round < VERTICES-1; ++round) {
        int hasChanged = 0;

        for (int i = 0; i < VERTICES; ++i) {
            struct Node * so = graph_list[i];
            if (!so->reached) continue;
            struct Node * edge = so->next;

            // Look at all the edges
            while (edge != NULL) {
                struct Node *vertex = graph_list[edge->index];
                int total_edge = so->weight + edge->weight;

                if (!vertex->reached || total_edge < vertex->weight) {
                    vertex->weight = total_edge;
                    vertex->reached = true;
                    hasChanged = 1;
                }
                edge = edge->next;
            }
        }

        // End if it's the same weight for all vertex from the past loop
        if (!hasChanged) return;

        // For debugging
        if (debugMode) {
            printf("%d iteration: ", round);
            for (int i = 0; i < VERTICES; ++i) {
                printf("%c: %d | ", graph_list[i]->id, graph_list[i]->weight);
            }
            printf("\n");
        }
    }
    if (debugMode) printf("\n");

    //return values;
}
