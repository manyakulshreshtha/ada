#include <stdio.h>
#include <stdlib.h>

struct Edge
{
    int src, dest, weight;
};

struct Subset
{
    int parent, rank;
};

int find(struct Subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int compare(const void *a, const void *b)
{
    return ((struct Edge *)a)->weight -
           ((struct Edge *)b)->weight;
}

int main()
{
    int V = 4;
    int E = 5;

    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    qsort(edges, E, sizeof(edges[0]), compare);

    struct Subset subsets[V];

    for (int v = 0; v < V; v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    printf("Edges in MST:\n");

    int e = 0, i = 0, cost = 0;

    while (e < V - 1)
    {
        struct Edge next_edge = edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y)
        {
            printf("%d -- %d == %d\n",
                   next_edge.src,
                   next_edge.dest,
                   next_edge.weight);

            cost += next_edge.weight;
            Union(subsets, x, y);
            e++;
        }
    }

    printf("Total Cost = %d\n", cost);

    return 0;
}