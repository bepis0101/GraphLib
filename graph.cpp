#include "graph.hpp"

Graph::Graph(int vertecies, int edges) {
    this->vertecies = vertecies;
    this->edges = edges;     
}

void Graph::add_edge(int parent, int child) {
    if(parent > vertecies or child > vertecies) std::cerr << "Non existing vertecies used\n";
    else {
        this->graph[parent].push_back(child);
        edges++;
    }
}
    
void Graph::delete_edge(int parent, int child){
    for(int vertex = 0; vertex < (int)graph[parent].size(); vertex++) {
        if(graph[parent][vertex] == child) {
            graph[parent].erase(graph[parent].begin()+vertex);
            edges--;
        }
    }
}

void Graph::dfs(int root) {
    visited[root] = true;
    for(int v : graph[root]) {
        if(!visited[v]) {
            dfs(v);
        }
    }
}

    void Graph::bfs(int root) {
        std::queue<int> Q;
        Q.push(root);
        visited[root] = true;
        while(!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for(int v : graph[u]) {
                if(!visited[v]) {
                    Q.push(v);
                    visited[v] = true;
                }
            }
        }
    }

    
std::ostream& operator<<(std::ostream& os, const Graph& G) {
    for(int i = 1; i <= G.vertecies; i++) {
        for(auto vertex : G.graph[i]) {
            os << "[" << i << ", " << vertex << "]\n";
        }
    }
    return os;
}
