#include "Graf1.h"
#include <clocale>
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <limits>


using namespace std;

class Graf{
private:
    int V; //количество вершин
    vector<list<pair<int, int>>> adj;

public:

    Graf(int vertices) : V(vertices) {
        adj.resize(V);
    }

    //добавление ребра
    void addEdge(int u, int v, int w) {
        adj[u].push_back(make_pair(v, w));
    }

    //обход в ширину
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);
        setlocale(LC_ALL, "rus");
        cout << "BFS начало обхода вершин " << start + 1 << ": ";

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current + 1 << " ";

            for (auto it = adj[current].begin(); it != adj[current].end(); ++it) {
                int neighbor = it->first;
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    //вывод матрицы смежности
    void printAdjacencyMatrix() {
        setlocale(LC_ALL, "rus");
        cout << "Матрица:\n";
        for (int i = 0; i < V; ++i) {
            vector<int> row(V, 0);
            for (auto it = adj[i].begin(); it != adj[i].end(); ++it) {
                row[it->first] = it->second;
            }
            for (int j = 0; j < V; ++j) {
                cout << row[j] << "\t";
            }
            cout << endl;
        }
    }
};

int main() {
    Graf g(6);

    //добавляем ребра 
    g.addEdge(0, 2, 13); // 1 -> 3
    g.addEdge(0, 3, 15); // 1 -> 4
    g.addEdge(0, 5, 18); // 1 -> 6
    g.addEdge(1, 3, 20); // 2 -> 4
    g.addEdge(1, 4, 21); // 2 -> 5
    g.addEdge(2, 3, 39); // 3 -> 4
    g.addEdge(2, 4, 30); // 3 -> 5
    g.addEdge(3, 5, 31); // 4 -> 6
    g.addEdge(4, 3, 28); // 5 -> 4

    //выполняется BFS начиная с вершины 4 
    g.BFS(3);

    //вывод матрицы смежности для проверки
    g.printAdjacencyMatrix();

    return 0;
}