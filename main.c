#include <stdio.h>
#include <stdbool.h>

#define SIZE 4
bool visited[SIZE];
int graph[SIZE][SIZE] =
        {
                {0, 1, 0, 0},
                {1, 0, 1, 1},
                {0, 1, 0, 0},
                {0, 1, 0, 0}
        };

void dfs(int v);

int main()
{
    //Подсчёт рёбер графа
    int ribs = 0;
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            if(i != j && graph[i][j] == 1)
                ribs++;
    ribs /= 2;
    for(int i = 0; i < SIZE; i++)
        if(graph[i][i] == 1)
            ribs++;
    //Проверка на связанность
    dfs(0);
    for(int i = 0; i < SIZE; i++)
    {
        if(!visited[i])
        {
            printf("Graph not a tree");
            return 1;
        }
    }
    if(ribs != SIZE - 1)
    {
        printf("Graph not a tree");
        return 1;
    }

    printf("Graph is a tree");
    return 0;
}

void dfs(int v)
{
    if(visited[v])
        return;

    visited[v] = true;

    for(int i = 0; i < SIZE; i++)
        if(graph[v][i])
            dfs(i);
}