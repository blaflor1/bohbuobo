#include <vector>
#include <list>
#include <string>
#include <limits.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <deque>
using namespace std;



int INF = 99999, V = 4

void printSolution(int dist[][V])
{
    printf ("Following matrix shows the shortest distances"
            " between every pair of vertices \n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int min(int i, int j) {
    if(i > j) {
        return j;
    }
    return i;
}


int johnson(vector<vector<int>> &Graph)
{
    vector<vector<int>> cost_graph = Graph;
    int i, j, k, c;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            if (Graph[i][j] == 0 && i != j)
                Graph[i][j] = INF;
        }
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                Graph[i][j] = min(Graph[i][j], Graph[i][k] + Graph[k][j]);
    cout << "Resultant adj matrix\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (Graph[i][j] != INF)
                cout << Graph[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// Solves the all-pairs shortest path problem using Floyd Warshall algorithm
void floydWarshall (int graph[][V])
{
    /* dist[][] will be the output matrix that will finally have the shortest 
      distances between every pair of vertices */
    int dist[V][V], i, j, k;
 
    /* Initialize the solution matrix same as input graph matrix. Or 
       we can say the initial values of shortest distances are based
       on shortest paths considering no intermediate vertex. */
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
 
    /* Add all vertices one by one to the set of intermediate vertices.
      ---> Before start of a iteration, we have shortest distances between all
      pairs of vertices such that the shortest distances consider only the
      vertices in set {0, 1, 2, .. k-1} as intermediate vertices.
      ----> After the end of a iteration, vertex no. k is added to the set of
      intermediate vertices and the set becomes {0, 1, 2, .. k} */
    for (k = 0; k < V; k++)
    {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++)
        {
            // Pick all vertices as destination for the
            // above picked source
            for (j = 0; j < V; j++)
            {
                // If vertex k is on the shortest path from
                // i to j, then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
 
    // Print the shortest distance matrix
    printSolution(dist);
}



int main()
{
    /* Let us create the following weighted graph
            10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3           */
    int graph[4][4] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };


    int graph1[10][10] = {  {0,   8,  1, 10, INF, INF, INF, INF, INF, 3},
                            {0,   0,  2, INF, INF, 1, INF, 2, INF, INF},
                            {INF, 3,  0, 13, INF, INF, 3, 1, INF, INF},
                            {0, INF,  INF, 0, INF, INF, INF, INF, INF, INF},
                            {INF, 14,  9, 12, 0, INF, 5, INF, 2, INF},
                            {4, INF,  8, INF, INF, 0, INF, INF, INF, INF},
                            {INF, 2,  5, INF, INF, INF, 0, INF, INF, INF},
                            {0, INF,  INF, 10, INF, INF, INF, 0, INF, INF},
                            {14, INF,  5, 1, INF, INF, INF, INF, 0, 8},
                            {INF, 3,  INF, INF, 2, INF, INF, 2, INF, 0},
                      };
 
    // Print the solution
    floydWarshall(graph);
    return 0;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}