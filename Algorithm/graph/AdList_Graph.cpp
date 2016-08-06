//
// Created by BranY on 2016/8/6.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <climits>
#include <sstream>
#include <queue>
using namespace std;

//const bool UNDIGRAPH = 1;

struct EdgeNode { //edge,the node of linked list
    int vtxNO;
    int weight;
    EdgeNode *next;
};

struct VNode { //vertex, the head of the linked list
    string vertexLabel;
    EdgeNode *first;
    bool visited;//only for DFS,BFS,Dijkstra
    int distance; //only for Dijkstra
    int path;//only for Dijkstra
    int indegree; //only for topological sort
};

struct Graph {
    VNode *vertexList;//the size of this array is equal to vertexes
    int vertexes;
    int edges;
};

void BuildGraph(Graph *&graph, int n) {
    if (graph == NULL) {
        graph = new Graph;
        graph->vertexList = new VNode[n];
        graph->vertexes = n;
        graph->edges = 0;
        for (int i = 0; i < n; i++) {
            stringstream ss;
            ss<<"v" << i+1;
            ss >> graph->vertexList[i].vertexLabel;
            graph->vertexList[i].path = -1;
            graph->vertexList[i].visited = false;
            graph->vertexList[i].first = NULL;
            graph->vertexList[i].indegree = 0;
        }
    }
}

void MakeEmpty(Graph *&graph) {
    if(graph == NULL)
        return;

    for (int i = 0; i < graph->vertexes; i++) {
        EdgeNode *pEdge = graph->vertexList[i].first;
        while (pEdge!=NULL) {
            EdgeNode *tmp = pEdge;
            pEdge = pEdge->next;
            delete tmp;
        }
    }

    delete graph;
}

void AddEdge(Graph *graph,int v1, int v2, int weight) {
    if (graph == NULL) return;
    if (v1 < 0 || v1 > graph->vertexes-1) return;
    if (v2 < 0 || v2 > graph->vertexes-1) return;
    if (v1 == v2) return; //no loop is allowed

    EdgeNode *p = graph->vertexList[v1].first;
    if(p == NULL) {
        //can not be p = new EdgeNode;
        graph->vertexList[v1].first = new EdgeNode;
        graph->vertexList[v1].first->next = NULL;
        graph->vertexList[v1].first->vtxNO = v2;
        graph->vertexList[v1].first->weight = weight;
        graph->edges++;
        graph->vertexList[v2].indegree++;
        return;
    }

    while (p->next != NULL) { //move to the last node
        if(p->vtxNO == v2)//already exits. checking all nodes but the last one
            return;

        p = p->next;
    }

    if(p->vtxNO == v2)//already exits. checking the first or the last node
        return;

    EdgeNode *node = new EdgeNode;
    node->next = NULL;
    node->vtxNO = v2;
    node->weight = weight;
    p->next = node;//last node's next is the new node

    graph->edges++;
    graph->vertexList[v2].indegree++;
}

void RemoveEdge(Graph *graph, int v1, int v2)
{
    if (graph == NULL) return;
    if (v1 < 0 || v1 > graph->vertexes-1) return;
    if (v2 < 0 || v2 > graph->vertexes-1) return;
    if (v1 == v2) return; //no loop is allowed

    EdgeNode *p = graph->vertexList[v1].first;
    if(p == NULL)//not found
        return;

    if(p->vtxNO == v2) {//found,delete the first node
        EdgeNode *tmp = p;//first
        graph->vertexList[v1].first = p->next; //can not be p = p->next
        delete tmp;
        graph->edges--;
        graph->vertexList[v2].indegree--;
        return;
    }

    while(p->next != NULL) {
        if(p->next->vtxNO == v2){//found
            EdgeNode *tmp = p->next;
            p = p->next->next;
            delete tmp;
            graph->edges--;
            graph->vertexList[v2].indegree--;
            return;
        }
        p = p->next;
    }
}

int GetIndegree(Graph *graph, int v) {
    if(graph == NULL) return -1;
    if(v < 0 || v > graph->vertexes -1) return -2;

    int degree = 0;

    for (int i = 0; i < graph->vertexes; i++) {
        EdgeNode *p = graph->vertexList[i].first;
        while (p != NULL) {
            if(p->vtxNO == v) {
                degree++;
                break;
            }
            p = p->next;
        }
    }

    return degree;
}

int GetOutdegree(Graph *graph, int v) {
    if(graph == NULL) return -1;
    if(v < 0 || v > graph->vertexes -1) return -2;
    int degree = 0;

    EdgeNode *p = graph->vertexList[v].first;
    while(p != NULL) {
        p = p->next;
        degree++;
    }

    return degree;
}

int GetDegree(Graph *graph, int v) {
    if(graph == NULL) return -1;
    if(v < 0 || v > graph->vertexes -1) return -2;

    return GetIndegree(graph,v) + GetOutdegree(graph,v);
}

void PrintGraph(Graph *graph) {
    if(graph == NULL)
        return;
    cout << "Vertex: " << graph->vertexes <<"\n";
    cout << "Edge: " << graph->edges << "\n";

    for (int i = 0; i < graph->vertexes; i++) {
        cout << i+1 << ": " << graph->vertexList[i].vertexLabel<<"->";
        EdgeNode *p = graph->vertexList[i].first;
        while (p != NULL) {
            cout << graph->vertexList[p->vtxNO].vertexLabel << "(" << p->weight <<")->";
            p = p->next;
        }
        cout << "\n";
    }
    cout << "\n";
}

//depth first search (use stack or recursion)
//DFS is similar to preorder traversal of trees
void DFS(Graph *graph, int i) {
    if (!graph->vertexList[i].visited) {
        cout << graph->vertexList[i].vertexLabel << " ";
        graph->vertexList[i].visited = true;
    }

    EdgeNode *p = graph->vertexList[i].first;
    while (p != NULL) {
        if(!graph->vertexList[p->vtxNO].visited)//notice!
            DFS(graph, p->vtxNO);
        p = p->next;
    }
}

void BeginDFS(Graph *graph) {
    if(graph == NULL) return;
    cout << "DFS\n";
    for (int i = 0; i < graph->vertexes; i++)
        graph->vertexList[i].visited = false;

    for (int i = 0; i < graph->vertexes; i++)
        DFS(graph,i);
}
//breadth first search(use queue)
//BFS is similar to leverorder traversal of trees
//all of the vertexes will be searched once no matter how the digraph is constructed
void BFS(Graph *graph) {
    if(graph == NULL)
        return;
    cout << "BFS\n";

    for (int i = 0; i < graph->vertexes; i++)
        graph->vertexList[i].visited = false;

    queue<int> QVertex;

    for (int i = 0; i < graph->vertexes; i++) {
        if (!graph->vertexList[i].visited) {
            QVertex.push(i);
            cout << graph->vertexList[i].vertexLabel << " ";
            graph->vertexList[i].visited = true;
        }
        while(!QVertex.empty()) {
            int vtxNO = QVertex.front();
            QVertex.pop();
            EdgeNode *p = graph->vertexList[vtxNO].first;

            while(p != NULL) {
                if (!graph->vertexList[p->vtxNO].visited) {
                    cout << graph->vertexList[p->vtxNO].vertexLabel << " ";
                    graph->vertexList[p->vtxNO].visited = true;
                    QVertex.push(p->vtxNO);
                }
                p = p->next;
            }
        }
    }

    cout << "\n";
}


void TopologicalSort(Graph *graph) {
    //if(UNDIGRAPH) return;
    if(graph == NULL) return;
    cout << "TopologicalSort"<<"\n";
    int counter = 0;
    queue <int> qVertex;
    for (int i = 0; i < graph->vertexes; i++) {
        if(GetIndegree(graph,i) == 0)
            qVertex.push(i);
    }
    while (!qVertex.empty()) {
        int vtxNO = qVertex.front();
        counter++;

        cout << graph->vertexList[vtxNO].vertexLabel;
        if(counter != graph->vertexes)
            cout << " > ";
        qVertex.pop();

        EdgeNode *p = graph->vertexList[vtxNO].first;
        while(p != NULL) {
            int vtxNo = p->vtxNO;
            /*EdgeNode *tmp = p;
            p = p->next;
            delete tmp;
            tmp = NULL;*/// although tmp is NULL,but p is not NULL,and the data pointed by p has been deleted
            p = p->next;

            //if (GetIndegree(graph,vtxNo) == 0)//error,in while(p != NULL),so use a variable indegree instead
            if (--graph->vertexList[vtxNo].indegree == 0)
                qVertex.push(vtxNo);
        }
    }

    cout << "\n";
}

void Dijkstra(Graph *graph, int v) {
    if(graph == NULL) return;
    if(v < 0 || v > graph->vertexes-1) return;

    for (int i = 0; i < graph->vertexes; i++) {
        graph->vertexList[i].visited = false;
        graph->vertexList[i].distance = INT_MAX;//can delete this line,as initialized in BuildGraph
        graph->vertexList[i].path = -1;
    }

    graph->vertexList[v].distance = 0;//the rest are all INT_MAX

    while(1) {
        int minDisInx = -1;
        int minDis = INT_MAX;
        for (int i = 0; i < graph->vertexes; i++) {
            if(!graph->vertexList[i].visited)
            {
                if(graph->vertexList[i].distance < minDis)
                {
                    minDis = graph->vertexList[i].distance;
                    minDisInx = i;
                }
            }
        }
        if(minDisInx == -1)//all visited
            break;

        graph->vertexList[minDisInx].visited = true;

        EdgeNode *p = graph->vertexList[minDisInx].first;
        while(p != NULL) {
            int vtxNO = p->vtxNO;
            if(!graph->vertexList[vtxNO].visited) {
                if (graph->vertexList[minDisInx].distance + p->weight < graph->vertexList[vtxNO].distance) {
                    graph->vertexList[vtxNO].distance = graph->vertexList[minDisInx].distance + p->weight;
                    graph->vertexList[vtxNO].path = minDisInx;
                    cout << graph->vertexList[vtxNO].vertexLabel << " Updated to " << graph->vertexList[vtxNO].distance << "\n";
                }
            }
            p = p->next;
        }
    }

    cout << "Vertex  Visited  Distance  Path\n";
    for (int i = 0; i < graph->vertexes; i++) {
        cout << graph->vertexList[i].vertexLabel<< "	";
        cout << graph->vertexList[i].visited<< "	";
        cout << graph->vertexList[i].distance<< "	";
        if(graph->vertexList[i].path == -1)
            cout << "NONE\n";
        else
            cout << graph->vertexList[graph->vertexList[i].path].vertexLabel << "\n";
    }
}

//almost for undigraph
void Prim(Graph *graph, int v) {
    if(graph == NULL) return;
    if(v < 0 || v > graph->vertexes-1) return;

    for (int i = 0; i < graph->vertexes; i++) {
        graph->vertexList[i].visited = false;
        graph->vertexList[i].distance = INT_MAX;//can delete this line,as initialized in BuildGraph
        graph->vertexList[i].path = -1;
    }

    graph->vertexList[v].distance = 0;//the rest are all INT_MAX

    while(1) {
        int minDisInx = -1;
        int minDis = INT_MAX;
        for (int i = 0; i < graph->vertexes; i++) {
            if(!graph->vertexList[i].visited) {
                if(graph->vertexList[i].distance < minDis) {
                    minDis = graph->vertexList[i].distance;
                    minDisInx = i;
                }
            }
        }
        if(minDisInx == -1)//all visited
            break;

        graph->vertexList[minDisInx].visited = true;

        EdgeNode *p = graph->vertexList[minDisInx].first;
        while(p != NULL) {
            int vtxNO = p->vtxNO;
            if(!graph->vertexList[vtxNO].visited) {
                if (p->weight < graph->vertexList[vtxNO].distance) {
                    graph->vertexList[vtxNO].distance = p->weight;
                    graph->vertexList[vtxNO].path = minDisInx;
                    cout << graph->vertexList[vtxNO].vertexLabel << " Updated to " << graph->vertexList[vtxNO].distance << "\n";
                }
            }
            p = p->next;
        }
    }

    cout << "Vertex  Visited  Distance  Path\n";
    for (int i = 0; i < graph->vertexes; i++) {
        cout << graph->vertexList[i].vertexLabel<< "	";
        cout << graph->vertexList[i].visited<< "	";
        cout << graph->vertexList[i].distance<< "	";
        if(graph->vertexList[i].path == -1)
            cout << "NONE\n";
        else
            cout << graph->vertexList[graph->vertexList[i].path].vertexLabel << "\n";
    }

}
int main() {
    Graph *graph = NULL;
    BuildGraph(graph,7);

    PrintGraph(graph);

    //for simple test, 0 indexed
    /*AddEdge(graph,0,1,1);
    AddEdge(graph,0,2,1);
    AddEdge(graph,1,3,1);*/

    //for TopologicalSort
    //0 indexed
    AddEdge(graph,0,1,1);
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
    AddEdge(graph,6,5,1);
    PrintGraph(graph);

    RemoveEdge(graph,6,5);
    AddEdge(graph,6,5,1);

    //for Dijkstra(shortest path),Prim(minimum spanning tree)
    //0 indexed
    /*AddEdge(graph,0,1,2);
    AddEdge(graph,0,3,1);
    AddEdge(graph,1,3,3);
    AddEdge(graph,1,4,10);
    AddEdge(graph,2,0,4);
    AddEdge(graph,2,5,5);
    AddEdge(graph,3,2,2);
    AddEdge(graph,3,4,2);
    AddEdge(graph,3,5,8);
    AddEdge(graph,3,6,4);
    AddEdge(graph,4,6,6);
    AddEdge(graph,6,5,1);*/

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