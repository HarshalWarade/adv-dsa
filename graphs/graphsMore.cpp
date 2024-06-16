#include<bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int> > makeAdj(vector<vector<int> > & adjList) {
    unordered_map<int, vector<int> > adj;
    for(int i = 0; i < adjList.size(); i++) {
        int u = adjList[i][0];
        int v = adjList[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    return adj;
}

void printGraph(unordered_map<int, vector<int> >& myAdjList) {
    for(auto i:myAdjList) {
        cout << i.first << " -> ";
        for(auto j:i.second) {
            cout << j << ", ";
        }
        cout << endl;
    }
    return;
}

vector<int> actualBFS(int node, unordered_map<int, bool>& visited, vector<int> &ans, unordered_map<int, vector<int> >& myAdjList) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);
        for(auto i:myAdjList[frontNode]) {
            if(!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }

    return ans;
}

vector<int> bfs(int nodes, unordered_map<int, vector<int> >& myAdjList) {
    unordered_map<int, bool> visited;
    vector<int> ans;
    for(int i = 0; i < nodes; i++) {
        if(!visited[i]) {
            actualBFS(i, visited, ans, myAdjList);
        }
    }
    return ans;
}

int main() {

    bool direction = false;

    int nodes = 5; int edges = 7;
    vector<vector<int> >  edgeConn;

    edgeConn.push_back({0, 1});
    edgeConn.push_back({0, 2});
    edgeConn.push_back({0, 3});
    edgeConn.push_back({1, 3});
    edgeConn.push_back({1, 4});
    edgeConn.push_back({2, 3});
    edgeConn.push_back({3, 4});


    unordered_map<int, vector<int> > myAdjList = makeAdj(edgeConn);

    vector<int> bfsAns = bfs(nodes, myAdjList);

    cout << "BFS: ";
    for(auto i:bfsAns) {
        cout << i << " ";
    }   


    return 0;
}