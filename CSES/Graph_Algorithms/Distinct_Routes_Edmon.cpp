#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 505;

struct Edge {
    int v, capacity, flow;
    size_t rev;
};

vector<Edge> adj[MAXN];
int parent[MAXN], edge_index[MAXN];

void add_edge(int u, int v) {
    adj[u].push_back({v, 1, 0, adj[v].size()});
    adj[v].push_back({u, 0, 0, adj[u].size() - 1});
}

int bfs(int s, int t) {
    fill(parent, parent + MAXN, -1);
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (size_t i = 0; i < adj[u].size(); i++) {
            Edge &e = adj[u][i];
            if (parent[e.v] == -1 && e.capacity > e.flow) {
                parent[e.v] = u;
                edge_index[e.v] = i;
                if (e.v == t) return 1;
                q.push(e.v);
            }
        }
    }
    return 0;
}

int max_flow(int s, int t) {
    int flow = 0;
    while (bfs(s, t)) {
        int v = t;
        while (v != s) {
            int u = parent[v];
            Edge &e = adj[u][edge_index[v]];
            e.flow++;
            adj[v][e.rev].flow--;
            v = u;
        }
        flow++;
    }
    return flow;
}

vector<vector<int>> find_paths(int s, int t, int k) {
    vector<vector<int>> paths;
    for (int i = 0; i < k; i++) {
        vector<int> path;
        int u = s;
        path.push_back(u);
        while (u != t) {
            for (auto &e : adj[u]) {
                if (e.flow > 0) {
                    e.flow--;
                    path.push_back(e.v);
                    u = e.v;
                    break;
                }
            }
        }
        paths.push_back(path);
    }
    return paths;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add_edge(a, b);
    }
    int k = max_flow(1, n);
    cout << k << "\n";
    vector<vector<int>> paths = find_paths(1, n, k);
    for (auto &path : paths) {
        cout << path.size() << " ";
        for (int v : path) cout << v << " ";
        cout << "\n";
    }
}
