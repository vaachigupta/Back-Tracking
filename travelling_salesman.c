#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 20

int n;                          
int graph[MAX][MAX];            
int min_cost = INT_MAX;         
int final_path[MAX + 1];        
bool visited[MAX];              

void copyPath(int path[]) {
    for (int i = 0; i < n; i++) {
        final_path[i] = path[i];
    }
    final_path[n] = path[0];
}

int calculateBound(int current_cost, int level) {
    int bound = current_cost;
    for (int i = level; i < n; i++) {
        int min_cost = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && graph[i][j] < min_cost && i != j) {
                min_cost = graph[i][j];
            }
        }
        if (min_cost != INT_MAX) {
            bound += min_cost;
        }
    }
    return bound;
}

void tsp(int path[], int level, int current_cost) {
    if (level == n) {
        if (graph[path[level - 1]][path[0]] != 0) {
            int total_cost = current_cost + graph[path[level - 1]][path[0]];
            if (total_cost < min_cost) {
                copyPath(path);
                min_cost = total_cost;
            }
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[path[level - 1]][i] != 0) {
            int temp_cost = current_cost + graph[path[level - 1]][i];
            if (temp_cost < min_cost) {
                path[level] = i;
                visited[i] = true;
                tsp(path, level + 1, temp_cost);
                visited[i] = false;
            }
        }
    }
}

int main() {
    n = 4;
    int predefined_graph[MAX][MAX] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = predefined_graph[i][j];
        }
    }

    int path[MAX];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    path[0] = 0;
    visited[0] = true;

    tsp(path, 1, 0);

    printf("Minimum cost: %d\n", min_cost);
    printf("Path: ");
    for (int i = 0; i <= n; i++) {
        printf("%d ", final_path[i]);
    }
    printf("\n");

    return 0;
}
