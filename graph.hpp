#pragma once
#include <bits/stdc++.h>
const int N = 1e3+2;

class Graph {
private:
    int vertecies;
    int edges;
    std::vector<int> graph[N];
    bool visited[N];

public:
    Graph(int vertecies, int edges);
    inline Graph(int vertecies) : Graph(vertecies, 0) {}
    inline Graph() : Graph(0, 0) {}
    void add_edge(int parent, int child);
    void delete_edge(int parent, int child);
    void dfs(int root);
    void bfs(int root);
    friend std::ostream& operator<<(std::ostream& os, const Graph& G);
};