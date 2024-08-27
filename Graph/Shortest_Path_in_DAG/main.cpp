#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<limits.h>

class Graph {
    public:
        int nodes, edges;
        std::unordered_map<int, std::list<std::pair<int, int>>> adjList;

        Graph(int n, int e) {
            nodes = n;
            edges = e;
        }

        void insert(int u, int v, int weight) {
            adjList[u].push_back({v, weight});
        }

        std::stack<int> topologicalSort();
        void shortest_path(int src, std::stack<int>& st, std::vector<int>& ans);
};

void Graph::shortest_path(int src, std::stack<int>& st, std::vector<int>& ans) {
    while(st.top() != src) {
        st.pop();
    }

    int dist{};
    while(!st.empty()) {
        int top = st.top();
        st.pop();

        dist = ans[top];

        for(auto p : adjList[top]) {
            ans[p.first] = std::min(ans[p.first], dist + p.second);
        }
    }
}

void solve(int node, std::unordered_map<int, bool>& visited,
    std::unordered_map<int, std::list<std::pair<int, int>>>& adjList,
    std::stack<int>& st) {

        visited[node] = 1;

        for(auto v : adjList[node]) {
            if(!visited[v.first])
                solve(v.first, visited, adjList, st);
        }

        st.push(node);
}

std::stack<int> Graph::topologicalSort() {

    std::stack<int> st;
    std::unordered_map<int, bool> visited;

    for(int i = 0; i < nodes; i++) {
        if(!visited[i])
            solve(i, visited, adjList, st);
    }

    return st;
}

int main() {
    int nodes, edges;

    std::cout << "Enter no. of nodes and edges : ";
    std::cin >> nodes >> edges;

    Graph* g = new Graph(nodes, edges);

    std::cout << "Enter edges (u -> <v, weight>) :- " << std::endl;
    for(int i = 0; i  < edges; i++) {
        int u, v, weight;

        std::cout << "Enter edge (with weight) : ";
        std::cin >> u >> v >> weight;

        g -> insert(u, v, weight);
    }

    std::stack<int> topoS = g -> topologicalSort();

    int src{};
    do {
        std::cout << "Enter source node : ";
        std::cin >> src;
        if(src >= nodes) std::cout << "Enter a valid node"
                            << "(0 - " << nodes - 1 << ")" << std::endl;
    } while(src >= nodes);

    std::vector<int> ans(nodes, INT_MAX);
    ans[src] = 0;
    g -> shortest_path(src, topoS, ans);

    for(auto i : ans) {
        if(i == INT_MAX) std::cout << "INF" << " ";
        else std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}

// test case
// 6 9
// 0 1 5 0 2 3 1 2 2 1 3 6 2 3 7 2 4 4 2 5 2 3 4 -1 4 5 -2