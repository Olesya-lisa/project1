#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

const int INF = 5000;

class Graf {
    int V;
    vector<vector<int>> dist;

public:
    Graf(int v);
    void addEdge(int u, int v, int weight);
    void removeEdge(int u, int v);
    void changeWeight(int u, int v, int weight);
    void BFS(int start);
    void DFS(int start);
    void DFSUtil(int v, vector<bool>& visited);
    void dey(int src);
    void floydWarshall();
    void printDistanceMatrix();
    void printAdjacencyMatrix();
    void addVertex();
    void removeVertex(int vertex);
};

#endif