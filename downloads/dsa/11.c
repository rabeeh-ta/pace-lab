#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int source;
void DFS(int a[MAX][MAX], int visited[MAX], int s, int n)
{
    int u, v;
    u = s;
    visited[u] = 1;
    if (u != source)
        printf(" %d ", u);
    for (v = 1; v <= n; v++)
    {
        if (a[u][v] == 1 && visited[v] == 0)
            DFS(a, visited, v, n);
    }
}
void BFS(int a[MAX][MAX], int visited[MAX], int source, int n)
{
    int queue[MAX], f = 0, r = 0, u, v;
    queue[r] = source;
    visited[source] = 1;
    while (f <= r)
    {
        u = queue[f++];
        for (v = 1; v <= n; v++)
        {
            if (a[u][v] == 1 && visited[v] == 0)
            {
                printf("%d ", v);
                visited[v] = 1;
                queue[++r] = v;
            }
        }
    }
}
int main()
{
    int a[MAX][MAX], visited[MAX], n, choice, i, j, x, y;
    printf("Enter the number of vertices in the graph : ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix for the graph\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    printf("Enter the starting node of the graph : ");
    scanf("%d", &source);
    while (1)
    {
        printf("\n\n**********************MENU*****************");
        printf("\n1. DFS\n2. BFS\n3. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Nodes reachable from %d using DFS method\n", source);
            for (x = 1; x <= n; x++)
                visited[x] = 0;
            DFS(a, visited, source, n);
            break;
        case 2:
            printf("Nodes reachable from %d using BFS method\n", source);
            for (y = 1; y <= n; y++)
                visited[y] = 0;
            BFS(a, visited, source, n);
            break;
        case 3:
            exit(0);
            break;
        }
    }
}