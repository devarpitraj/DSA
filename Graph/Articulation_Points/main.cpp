#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>

class Graph {
    public:
        int nodes, vertices;
        std::unordered_map<int, std::list<int>> adjList;

        Graph(int nodes, int vertices)
            : nodes{nodes}, vertices{vertices} {}

        void insert(int u, int v) {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        void findAP(std::vector<int>& ans);
};

void dfs(int node, int parent, std::vector<int>& disc,
            std::vector<int>& low, std::unordered_map<int, bool>& visited, 
            std::vector<int>& ans, std::unordered_map<int, std::list<int>>& adjList, 
            int& timer) {

    visited[node] = true;
    disc[node] = low[node] = timer++;
    int child{};

    for(auto nbr : adjList[node]) {
        if(nbr == parent) continue;

        if(!visited[nbr]) {
            child++;

            dfs(nbr, node, disc, low, visited, ans, adjList, timer);

            // update low[node]
            low[node] = std::min(low[node], low[nbr]);

            // check for AP
            if(low[nbr] >= disc[node] && parent != -1) {
                ans.push_back(node);
            }
        }

        else { // back edge
            low[node] = std::min(low[node], disc[nbr]);
        }
    }

    if(parent == -1 && child > 1) {
        ans.push_back(node);
    }
}

void Graph::findAP(std::vector<int>& ans) {
    std::vector<int> disc(vertices, -1);
    std::vector<int> low(vertices, -1);
    int timer{};
    int parent{-1};

    std::unordered_map<int, bool> visited;

    for(int i = 0; i < vertices; i++) {
        if(!visited[i]) {
            dfs(i, parent, disc, low, visited, ans, adjList, timer);
        }
    }
}

int main() {
    int vertices{}, edges{};

    std::cout << "Enter vertices and edges : ";
    std::cin >> vertices >> edges;

    Graph* g = new Graph(vertices, edges);

    for(int i = 0; i < edges; i++) {
        int u, v;

        std::cout << "Enter edge : ";
        std::cin >> u >> v;

        g -> insert(u, v);
    }

    std::vector<int> ans;
    g -> findAP(ans);

    std::cout << "Articulation Points : ";
    for(int i : ans) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}