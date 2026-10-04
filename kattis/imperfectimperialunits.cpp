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
const int N =1e2+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
map<string,int> save;
int cur = 0;
double dist[N][N];
double w[N][N];
int n,q;
double dfs(int u, int p, int t) {
    if(u == t) return 1.00; 
    //cout << u << nl;
    double k = 0.00;
    for(int j = 0; j < cur; j++) {
        if(j == p) continue;
        if(dist[u][j] != 0) {
            k = max(k,dist[u][j] * dfs(j,u,t));
        }
    }
    return k;
}
void solve(){
    
    cin>>n>>q;
    memset(dist, 0, sizeof dist);
    memset(w, 0, sizeof w);
    for(int i = 0; i < n; i++) {
        string a,b,c,d;
        double val;
        cin>>a>>b>>c>>val>>d;
        // a b c val d
        // 1 u = val d
        if(save.find(b) == save.end()) {
            save[b] = cur++;
        }
        if(save.find(d) == save.end()) {
            save[d] = cur++;
        }
        
        dist[save[b]][save[d]] = val;
        dist[save[d]][save[b]] = 1.00 / val;
    }

    for(int i = 0; i < cur; i++) {
        for(int j = i; j < cur; j++) {
            //cerr << i << " CHECK " << j << " " << w[i][j] << nl;
            w[i][j] = dfs(i,i,j);
            if(w[i][j] != 0) w[j][i] = 1.00 / w[i][j];
        }
    }

    for(int i = 0; i < q; i++) {
        double a;
        string b,c,d;
        cin>>a>>b>>c>>d;
        int u = save[b], v = save[d];
        if(w[u][v] == 0) {
            cout << "impossible\n";
            continue;
        }
        cout << scientific << a * w[u][v] << nl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

