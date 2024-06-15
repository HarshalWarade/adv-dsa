#include<bits/stdc++.h>
using namespace std;

class graph {
    public:
    map<int, set<int> > adj;

    void addEdge(int u, int v, bool direction) {
        adj[u].insert(v);
        if(!direction) {
            adj[v].insert(u);
        }
    }

    void printGraph() {
        for(auto i:adj) {
            cout << i.first << " -> ";
            for(auto j:i.second) {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main() {

    int nodes, edges;
    bool direction = false;

    cout << "Enter the number of nodes: ";
    cin >> nodes;
    cout << "Enter the number of edges for " << nodes << " nodes: ";
    cin >> edges;

    graph g;

    cout << "Enter edges below" << endl;
    for(int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        g.addEdge(u, v, direction);

    }

    g.printGraph();


    return 0;
}