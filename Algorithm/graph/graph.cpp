//
// Created by BranY on 2016/8/6.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <climits>
#include <sstream>
#include <queue>
#include <cstring>

using namespace std;

const bool UNDIGRAPH = false;
struct Graph {
    string *vertexLabel;//the number of the labels is equal to vertexes
    int vertexes;
    int edges;
    int **AdjMat;
    bool *visited;//only for DFS,BFS,Dijkstra
    int *distance; //only for Dijkstra
    int *path;//only for Dijkstra
};

void BuildGraph(Graph *&graph, int n) {
    if (graph == NULL) {
        graph = new Graph;
        graph->vertexes = n;
        graph->edges = 0;
        graph->AdjMat = new int *[n];
        graph->vertexLabel = new string[n];
        graph->visited = new bool[n];
        graph->distance = new int[n];
        graph->path = new int[n];
        for (int i = 0; i < graph->vertexes; i++) {
            stringstream ss;
            ss<<"v" << i+1;
            ss >> graph->vertexLabel[i];
            graph->visited[i] = false;
            graph->distance[i] = INT_MAX;
            graph->path[i] = -1;
            graph->AdjMat[i] = new int[n];

            if(UNDIGRAPH)
                memset(graph->AdjMat[i],0, n * sizeof(int));
            else
                for (int j = 0; j < graph->vertexes; j++)
                {
                    if(i == j)
                        graph->AdjMat[i][j] = 0;
                    else
                        graph->AdjMat[i][j] = INT_MAX;
                }
        }
    }
}

void MakeEmpty(Graph *&graph) {
    if(graph == NULL)
        return;

    delete []graph->vertexLabel;
    delete []graph->visited;
    delete []graph->distance;
    delete []graph->path;
    for (int i = 0; i < graph->vertexes; i++)
    {
        delete []graph->AdjMat[i];
    }
    delete []graph->AdjMat;
    delete graph;
}

void AddEdge(Graph *graph,int v1, int v2, int weight) {
    if (graph == NULL) return;
    if (v1 < 0 || v1 > graph->vertexes-1) return;
    if (v2 < 0 || v2 > graph->vertexes-1) return;
    if (v1 == v2) return; //no loop is allowed

    if(UNDIGRAPH) {
        if (graph->AdjMat[v1][v2] == 0)//not exist,edges plus 1
            graph->edges++;
        graph->AdjMat[v1][v2] = graph->AdjMat[v2][v1] = weight;
    }

    else {
        if (graph->AdjMat[v1][v2] == 0 || graph->AdjMat[v1][v2] == INT_MAX)//not exist,edges plus 1
            graph->edges++;
        graph->AdjMat[v1][v2] = weight;
    }
}

void RemoveEdge(Graph *graph, int v1, int v2) {
    if (graph == NULL) return;
    if (v1 < 0 || v1 > graph->vertexes-1) return;
    if (v2 < 0 || v2 > graph->vertexes-1) return;
    if (v1 == v2) return; //no loop is allowed

    if (UNDIGRAPH) {
        if (graph->AdjMat[v1][v2] == 0)//not exists,return
            return;
        graph->AdjMat[v1][v2] = graph->AdjMat[v2][v1] = 0;
        graph->edges--;
    }

    else {
        if (graph->AdjMat[v1][v2] == 0 || graph->AdjMat[v1][v2] == INT_MAX)//not exists,return
            return;
        graph->AdjMat[v1][v2] = INT_MAX;
        graph->edges--;
    }
}

/**
 * 获取入度
 */
int GetIndegree(Graph *graph, int v) {
    if(graph == NULL) return -1;
    if(v < 0 || v > graph->vertexes -1) return -2;
    if(UNDIGRAPH) return -3;
    int degree = 0;
    for (int i = 0; i < graph->vertexes; i++) {
        if(graph->AdjMat[i][v] != 0 && graph->AdjMat[i][v] != INT_MAX)
            degree++;
    }
    return degree;
}

int GetOutdegree(Graph *graph, int v) {
    if(graph == NULL) return -1;
    if(v < 0 || v > graph->vertexes -1) return -2;
    if(UNDIGRAPH) return -3;
    int degree = 0;
    for (int i = 0; i < graph->vertexes; i++) {
        if(graph->AdjMat[v][i] != 0 && graph->AdjMat[v][i] != INT_MAX)
            degree++;
    }
    return degree;
}

void PrintGraph(Graph *graph) {
    if(graph == NULL)
        return;
    cout << "Vertex: " << graph->vertexes <<"\n";
    cout << "Edge: " << graph->edges << "\n";

    for (int i = 0; i < graph->vertexes; i++) {
        cout << "  "<< graph->vertexLabel[i];
    }
    cout << "\n";

    for (int i = 0; i < graph->vertexes; i++) {
        for (int j = 0; j < graph->vertexes; j++) {
            if(j == 0)
                cout << graph->vertexLabel[i] << " ";

            if(graph->AdjMat[i][j] == INT_MAX)
                cout << "-" << "   ";
            else
                cout << graph->AdjMat[i][j] << "   ";
        }
        cout << "\n";
    }
    cout << "\n";
}
int GetDegree(Graph *graph, int v) {
    if(graph == NULL) return -1;
    if(v < 0 || v > graph->vertexes -1) return -2;

    if(UNDIGRAPH) {
        int degree = 0;
        for (int i = 0; i < graph->vertexes; i++)
        {
            if(graph->AdjMat[v][i] != 0)
                degree++;
        }
        return degree;
    }
    else
        return GetIndegree(graph,v) + GetOutdegree(graph,v);
}


//depth first search (use stack or recursion)
//DFS is similar to preorder traversal of trees
void DFS(Graph *graph, int i) {
    if (!graph->visited[i]) {
        cout << graph->vertexLabel[i] << " ";
        graph->visited[i] = true;
    }

    for (int j = 0; j < graph->vertexes; j++) {
        if (UNDIGRAPH) {
            if (graph->AdjMat[i][j] != 0 && !graph->visited[j])
                DFS(graph,j);
        }
        else {
            if (graph->AdjMat[i][j] != INT_MAX && !graph->visited[j])
                DFS(graph, j);
        }
    }
}

void BeginDFS(Graph *graph) {
    if(graph == NULL) return;
    cout << "DFS\n";
    for (int i = 0; i < graph->vertexes; i++)
        graph->visited[i] = false;

    for (int i = 0; i < graph->vertexes; i++)
        DFS(graph, i);
}
//breadth first search(use queue)
//BFS is similar to leverorder traversal of trees
//all of the vertexes will be searched once no matter how the digraph is constructed
void BFS(Graph *graph) {
    if(graph == NULL)
        return;
    cout << "BFS\n";

    memset(graph->visited, false, graph->vertexes * sizeof(bool));
    queue<int> QVertex;

    for (int i = 0; i < graph->vertexes; i++) {
        if (!graph->visited[i]) {
            QVertex.push(i);
            cout << graph->vertexLabel[i] << " ";
            graph->visited[i] = true;
            while(!QVertex.empty()) {
                int vtxNO = QVertex.front();
                QVertex.pop();
                for (int j = 0; j < graph->vertexes; j++) {
                    if (UNDIGRAPH) {
                        if(!graph->visited[j] && graph->AdjMat[vtxNO][j]!=0)
                        {
                            cout << graph->vertexLabel[j] << " ";
                            graph->visited[j] = true;
                            QVertex.push(j);
                        }
                    }
                    else {
                        if(!graph->visited[j] && graph->AdjMat[vtxNO][j]!=INT_MAX) {
                            cout << graph->vertexLabel[j] << " ";
                            graph->visited[j] = true;
                            QVertex.push(j);
                        }
                    }

                }
            }
        }
    }

    cout << "\n";
}

//after executing this function,the value of AdjMat changed
void TopologicalSort(Graph *graph) {
    if(UNDIGRAPH) return;
    if(graph == NULL) return;
    cout << "TopologicalSort\n";
    int counter = 0;
    queue <int> qVertex;
    for (int i = 0; i < graph->vertexes; i++) {
        if(GetIndegree(graph, i) == 0)
            qVertex.push(i);
    }
    while (!qVertex.empty()) {
        int vertexNO = qVertex.front();
        counter++;

        cout << graph->vertexLabel[vertexNO];
        if(counter != graph->vertexes)
            cout << " -> ";
        qVertex.pop();
        for (int i = 0; i < graph->vertexes; i++) {
            if(i == vertexNO)
                continue;

            if (GetIndegree(graph,i) != 0) {
                graph->AdjMat[vertexNO][i] = INT_MAX;//indegree--
                if(GetIndegree(graph,i) == 0)
                    qVertex.push(i);
            }
        }
    }
    cout << "\n";
}

void Dijkstra(Graph *graph, int v) {
    if(graph == NULL) return;
    if(v < 0 || v > graph->vertexes-1) return;

    for (int i = 0; i < graph->vertexes; i++) {
        graph->visited[i] = false;
        graph->distance[i] = INT_MAX;//can delete this line,as initialized in BuildGraph
        graph->path[i] = -1;
    }

    graph->distance[v] = 0;//the rest are all INT_MAX

    while(1) {
        int minDisInx = -1;
        int minDis = INT_MAX;
        for (int i = 0; i < graph->vertexes; i++) {
            if(!graph->visited[i]) {
                if(graph->distance[i] < minDis) {
                    minDis = graph->distance[i];
                    minDisInx = i;
                }
            }
        }
        if(minDisInx == -1)//all visited
            break;

        graph->visited[minDisInx] = true;

        for (int i = 0; i < graph->vertexes; i++) {
            //unvisited and adjacent to current vertex
            //&& graph->AdjMat[minDisInx][i]!=0 is for undigraph
            if (!graph->visited[i] && graph->AdjMat[minDisInx][i]!=INT_MAX && graph->AdjMat[minDisInx][i]!=0) {
                if (graph->distance[minDisInx] + graph->AdjMat[minDisInx][i] < graph->distance[i]) {
                    graph->distance[i] = graph->distance[minDisInx] + graph->AdjMat[minDisInx][i];
                    graph->path[i] = minDisInx;
                    cout << graph->vertexLabel[i] << " Updated to " << graph->distance[i] <<"\n";
                }
            }

        }
    }

    cout << "Vertex  Visited  Distance  Path\n";
    for (int i = 0; i < graph->vertexes; i++) {
        cout << graph->vertexLabel[i]<< "	";
        cout << graph->visited[i]<< "	";
        cout << graph->distance[i]<< "	";
        if(graph->path[i] == -1)
            cout << "NONE\n";
        else
            cout << graph->vertexLabel[graph->path[i]]<< "\n";
    }
}

//almost for undigraph
void Prim(Graph *graph, int v) {
    if(graph == NULL) return;
    if(v < 0 || v > graph->vertexes-1) return;

    for (int i = 0; i < graph->vertexes; i++) {
        graph->visited[i] = false;
        graph->distance[i] = INT_MAX;//can delete this line,as initialized in BuildGraph
        graph->path[i] = -1;
    }

    graph->distance[v] = 0;//the rest are all INT_MAX

    while(1) {
        int minDisInx = -1;
        int minDis = INT_MAX;
        for (int i = 0; i < graph->vertexes; i++) {
            if(!graph->visited[i]) {
                if(graph->distance[i] < minDis) {
                    minDis = graph->distance[i];
                    minDisInx = i;
                }
            }
        }
        if(minDisInx == -1)//all visited
            break;

        graph->visited[minDisInx] = true;

        for (int i = 0; i < graph->vertexes; i++) {
            //unvisited and adjacent to current vertex
            //&& graph->AdjMat[minDisInx][i]!=0 is for undigraph
            if (!graph->visited[i] && graph->AdjMat[minDisInx][i]!=INT_MAX && graph->AdjMat[minDisInx][i]!=0) {
                if (graph->AdjMat[minDisInx][i] < graph->distance[i]) {
                    graph->distance[i] = graph->AdjMat[minDisInx][i];
                    graph->path[i] = minDisInx;
                    cout << graph->vertexLabel[i] << " Updated to " << graph->distance[i] <<"\n";
                }
            }

        }
    }

    cout << "Vertex  Visited  Distance  Path\n";
    for (int i = 0; i < graph->vertexes; i++) {
        cout << graph->vertexLabel[i]<< "	";
        cout << graph->visited[i]<< "	";
        cout << graph->distance[i]<< "	";
        if(graph->path[i] == -1)
            cout << "NONE\n";
        else
            cout << graph->vertexLabel[graph->path[i]]<< "\n";
    }

}
int main()
{
    Graph *graph = NULL;
    BuildGraph(graph, 7);

    PrintGraph(graph);

    //for simple test, 0 indexed
    /*AddEdge(graph,0,1,1);
    AddEdge(graph,0,2,1);
    AddEdge(graph,1,3,1);*/

    //for TopologicalSort
    //0 indexed
    /*AddEdge(graph,0,1,1);
    AddEdge(graph,0,2,1);
    AddEdge(graph,0,3,1);
    AddEdge(graph,1,3,1);
    AddEdge(graph,1,4,1);
    AddEdge(graph,2,5,1);
    AddEdge(graph,3,2,1);
    AddEdge(graph,3,5,1);
    AddEdge(graph,3,6,1);
    AddEdge(graph,4,3,1);
    AddEdge(graph,4,6,1);
    AddEdge(graph,6,5,1);*/


    //for Dijkstra(shortest path),Prim(minimum spanning tree)
    //0 indexed

    AddEdge(graph,0,1,4);
    AddEdge(graph,0,2,1);
    AddEdge(graph,0,3,5);
    AddEdge(graph,1,3,3);
    AddEdge(graph,1,4,1);
    AddEdge(graph,2,5,7);
    AddEdge(graph,3,2,9);
    AddEdge(graph,3,5,1);
    AddEdge(graph,3,6,11);
    AddEdge(graph,4,3,2);
    AddEdge(graph,4,6,1);
    AddEdge(graph,6,5,6);

    PrintGraph(graph);
    BeginDFS(graph);
    cout << "\n";
    BFS(graph);
    for (int i = 0; i < graph->vertexes; i++) {
        cout << "\n";
        Dijkstra(graph,i);
    }
    Prim(graph,0);

    TopologicalSort(graph);
    MakeEmpty(graph);

    return 0;
}