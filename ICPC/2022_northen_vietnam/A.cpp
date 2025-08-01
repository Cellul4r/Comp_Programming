#include<bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef pair<int,int> pi;

struct p {
    int s,idx,u,v;

    bool operator<(const p& a) const {
        if(s != a.s) {
            return s < a.s;
        }
        return idx < a.idx;
    }
};

const int N = 2e5+1;
int rnk[N], par[N];
int findPar(int u) {
    if(u == par[u]) return u;

    return par[u] = findPar(par[u]);
}
void merge(int u, int v) {
    u = findPar(u);
    v = findPar(v);
    
    if(u == v) return;
    if(rnk[u] < rnk[v]) {
        rnk[v] += rnk[u];
        par[u] = v;
    } else {
        rnk[u] += rnk[v];
        par[v] = u;
    }
}

bool same(int u, int v) {
    u = findPar(u), v = findPar(v);
    return u == v;
}

void solve() {
    
    int n,q;
    cin>>n>>q;
    for(int i = 1; i <= n; i++) {
        rnk[i] = 1;
        par[i] = i;
    }
    vector<char> ans(q);
    vector<p> add;

    int commit = 1;
    vector<p> query;
    for(int i = 0; i < q; i++) {
        char op;
        cin>>op;
        if(op == 'A') {
            int u,v;
            cin>>u>>v;
            add.push_back({commit,i,u,v});
            merge(u,v);
        } else if(op == '?') {
            int u,v;
            cin>>u>>v;
            ans[i] = (same(u,v) ? 'Y' : 'N');
        } else if(op == 'C') {
            commit++;
        } else {
            int s,u,v;
            cin>>s>>u>>v;
            query.push_back({s,i,u,v});
        }
    }
    
    sort(all(add));
    sort(all(query));
    for(int i = 1; i <= n; i++) {
        rnk[i] = 1;
        par[i] = i;
    }
    int i = 0;
    for(auto &x : query) {
        while(i < add.size() && add[i].s <= x.s) {
            merge(add[i].u, add[i].v);
            i++;
        }

        ans[x.idx] = (same(x.u,x.v) ? 'Y' : 'N');
    }
    for(int i = 0; i < q; i++) {
        if(ans[i] != 'Y' && ans[i] != 'N') continue;
        cout << ans[i];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
