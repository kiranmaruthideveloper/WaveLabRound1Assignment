#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int makeConnected(int n, vector<vector<int>>& connections) {
    if (connections.size() < n - 1) {
        return -1; // Not enough connections to connect all workstations
    }
    vector<vector<int>> adj_list(n);
    for (auto& conn : connections) {
        adj_list[conn[0]].push_back(conn[1]);
        adj_list[conn[1]].push_back(conn[0]);
    }
    vector<bool> visited(n, false);
    int num_components = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            num_components++;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int neighbor : adj_list[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }
    }
    return num_components - 1; // Number of cables to add
}

int main() {
    int n, m;
    
    cin >> n;
    
    cin >> m;
    vector<vector<int>> connections(m, vector<int>(2));
    
    for (int i = 0; i < m; i++) {
        cin >> connections[i][0] >> connections[i][1];
    }
    int min_cables = makeConnected(n, connections);
   cout << min_cables << endl;
    
    return 0;
}