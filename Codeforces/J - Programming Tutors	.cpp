#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define L long
#define sLL signed long long
#define uLL unsigned long long
#define f first 
#define s second
#define pf printf
#define sf scanf
#define A(a) (a).begin(),(a).end()
using pii = pair<int,int>;
using piL = pair<int,long>;
using pip = pair<int,pair<int,int>>;
const int INF = 1e9;
const int N = 205;

bool bfs(int s, int t, int rGraph[N][N], int parent[N]) {

    bool visited[N];
    memset(visited, false, sizeof(visited));

    queue<int> Q;
    Q.push(s);
    parent[s] = -1;
    visited[s] = true;
    
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for(int v=0;v<N;++v) {
            if(!visited[v] && rGraph[u][v] > 0) {

                if(v == t) {
                    parent[v] = u;
                    return true;
                }
                visited[v] = true;
                parent[v] = u;
                Q.push(v);
            }
        }
    }
    return false;
}

int fordFulkerson(int s, int t, int graph[N][N]) {

    int u,v;
    int rGraph[N][N];
    int parent[N];
    for(u = 0;u<N; ++u) {
        parent[u] = u;
        for(v = 0; v<N; ++v) {
            rGraph[u][v] = graph[u][v];
        }
    }
    int maxFlow = 0;
    while(bfs(s,t, rGraph, parent)) {
        int pathFlow = INF;
        
        for(v = t; v != s; v = parent[v]) {
            u = parent[v];
            pathFlow = min(pathFlow,rGraph[u][v]);
        }

        for(v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }
    
    return maxFlow;
}

int man(int x1,int y1, int x2, int y2) {
    return abs(x1-x2) + abs(y1-y2);
}
void init(int graph[N][N], int dist, int n,vector<pii>& student, vector<pii>& tutor) {

    for(int i=1;i<=n;++i) {
        graph[0][i] = 1;
    }
    for(int i=1;i<=n;++i) {
        graph[n+i][2*n+1] = 1;
    }

    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j) {
            if(man(student[i].f, student[i].s, tutor[j].f, tutor[j].s) <= dist) {
                graph[i][n+j] = 1;
            }
        }
    }
}
void solve() {
    
    int n;
    cin>>n;
    int graph[N][N];
    vector<pii> student(n+1),tutor(n+1);
    for(int i=1;i<=n;++i) {
        cin>>student[i].f >> student[i].s;
    }
    for(int i=1;i<=n;++i) {
        cin>>tutor[i].f >> tutor[i].s;
    }
    
    int low = 0, high = INF, ans = INF;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        memset(graph,0,sizeof(graph));
        init(graph, mid, n, student, tutor);
        if(fordFulkerson(0, 2*n+1, graph) == n) {
            high = mid-1;
            ans = mid;
        } else {
            low = mid+1;
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin>>t;

    while(t--) {
        solve();
    }
    return 0;
}

