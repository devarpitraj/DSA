#include<iostream>
#include<list>
#include<unordered_map>


template <typename T>
class Graph {
    public:
        std::unordered_map<T, std::list<T>> adjList;

        void insert(T lhs, T rhs) {
            adjList[lhs].push_back(rhs);
            adjList[rhs].push_back(lhs);
        }

        void print() {
            for(auto i : adjList) {
                std::cout << i.first << "-> ";
                for(auto j : i.second)
                    std::cout << j << " ";
                std::cout << std::endl;
            }
        }
};

int main() {
    int nodes, edges;

    std::cout << "Enter no. of nodes";
    std::cin >> nodes;

    std::cout << "Enter no. of edges";
    std::cin >> edges;

    Graph<int> g;

    std::cout << "Enter edges : ";
    for(int i = 0; i < edges; i++) {
        int n1, n2;
        std::cin >> n1 >> n2;

        g.insert(n1, n2);
    }

    g.print();

    return 0;
}