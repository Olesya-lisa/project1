#include "Graf1.h"
#include <iostream>

Graf::Graf(int v) : V(v) {
    dist.resize(V, vector<int>(V, INF));
    for (int i = 0; i < V; ++i)
        dist[i][i] = 0;
}

void Graf::addEdge(int u, int v, int weight) {
    dist[u][v] = weight;
}

void Graf::removeEdge(int u, int v) {
    dist[u][v] = INF;
}

void Graf::changeWeight(int u, int v, int weight) {
    dist[u][v] = weight;
}

void Graf::BFS(int start) {
    vector<bool> visited(V, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    cout << "BFS: ";
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << (u + 1) << " ";

        for (int v = 0; v < V; ++v) {
            if (dist[u][v] != INF && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
}

void Graf::DFSUtil(int v, vector<bool>& visited) {
    visited[v] = true;
    cout << (v + 1) << " ";
    for (int u = 0; u < V; ++u) {
        if (dist[v][u] != INF && !visited[u])
            DFSUtil(u, visited);
    }
}

void Graf::DFS(int start) {
    vector<bool> visited(V, false);
    cout << "DFS: ";
    DFSUtil(start, visited);
    cout << endl;
}

void Graf::dey(int src) {
    vector<int> distance(V, INF);
    set<pair<int, int>> s;
    distance[src] = 0;
    s.insert({ 0, src });

    while (!s.empty()) {
        int u = s.begin()->second;
        s.erase(s.begin());

        for (int v = 0; v < V; ++v) {
            if (dist[u][v] != INF) {
                if (distance[u] + dist[u][v] < distance[v]) {
                    s.erase({ distance[v], v });
                    distance[v] = distance[u] + dist[u][v];
                    s.insert({ distance[v], v });
                }
            }
        }
    }
    setlocale(LC_ALL, "rus");
    cout << "Dey для вершин " << src + 1 << ":\n";
    for (int i = 0; i < V; ++i)
        cout << "  До " << (i + 1) << ": " << (distance[i] == INF ? -1 : distance[i]) << endl;
}

void Graf::floydWarshall() {
    vector<vector<int>> fw = dist;
    for (int k = 0; k < V; ++k)
        for (int i = 0; i < V; ++i)
            for (int j = 0; j < V; ++j)
                if (fw[i][k] + fw[k][j] < fw[i][j])
                    fw[i][j] = fw[i][k] + fw[k][j];
    setlocale(LC_ALL, "rus");
    cout << "Самая короткая матрица:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (fw[i][j] == INF) cout << "INF ";
            else cout << fw[i][j] << " ";
        }
        cout << endl;
    }
}

void Graf::printDistanceMatrix() {
    setlocale(LC_ALL, "rus");
    cout << "Дистанция матрицы:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

void Graf::printAdjacencyMatrix() {
    setlocale(LC_ALL, "rus");
    cout << "Матрица:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cout << (dist[i][j] != INF ? 1 : 0) << " ";
        }
        cout << endl;
    }
}

void Graf::addVertex() {
    setlocale(LC_ALL, "rus");
    ++V;
    for (auto& row : dist) {
        row.push_back(INF);
    }
    dist.push_back(vector<int>(V, INF));
    dist[V - 1][V - 1] = 0;
    cout << "Вершина добавлена. Новая " << V << " вершина\n";
}

void Graf::removeVertex(int vertex) {
    setlocale(LC_ALL, "rus");
    if (vertex < 0 || vertex >= V) {
        cout << "Неправильная вершина\n";
        return;
    }
    dist.erase(dist.begin() + vertex);
    for (auto& row : dist)
        row.erase(row.begin() + vertex);
    --V;
    cout << "Вершина удалена.Новая " << V << " вершина\n";
}