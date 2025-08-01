/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =201+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

vector<int> adj[N];
int color[N];
int n,m;

void solve(){
    
    cin>>n>>m;
    for(int i = 0; i < m; i++) {
        int x,y;
        cin>>x>>y;
        x--,y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= 4; j++) {
            bool ok = true;
            for(auto &v : adj[i]) {
                if(color[v] == j) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                color[i] = j;
                break;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << color[i];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

