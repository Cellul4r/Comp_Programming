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
const int N = 1e5;
const int S = 3005;

struct dinic {
	struct edge {ll b, cap, flow, flip;};
	vector<edge> g[S+2];
	ll ans=0, d[S+2], ptr[S+2];

	void add_edge (ll a, ll b, ll cap) {
		g[a].push_back({b, cap, 0, (ll)g[b].size()});
		g[b].push_back({a, 0, 0, (ll)g[a].size()-1});
	}

	ll dfs (ll u, ll flow=LLONG_MAX) {
		if (u==S+1 || !flow) return flow;
		while (++ptr[u] < (ll)g[u].size()) {
			edge &e = g[u][ptr[u]];
			if (d[e.b] != d[u]+1) continue;
			if (ll pushed = dfs(e.b, min(flow, e.cap-e.flow))) {
				e.flow += pushed;
				g[e.b][e.flip].flow -= pushed;
				return pushed;
			}
		}
		return 0;
	}

	void calc() {
		do {
			vector<ll> q {S};
			memset(d, 0, sizeof d);
			ll i = -(d[S] = 1);
			while (++i<(ll)q.size() && !d[S+1])
				for (auto e: g[q[i]])
					if (!d[e.b] && e.flow<e.cap) {
						q.push_back(e.b);
						d[e.b] = d[q[i]]+1;
					}

			memset(ptr, -1, sizeof ptr);
			while(ll pushed=dfs(S)) ans+=pushed;
		} while (d[S+1]);
	}
};

int n,m;
int board[1002][1002];
int syn[1002];
bool f(int mid) {
    dinic d;
    for(int i=1;i<=m;++i) {
        d.add_edge(S,i,1);
    }
    for(int i=1;i<=n;++i) {
        d.add_edge(i+m,S+1,1);
    }
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            if(board[i][j] >= mid) {
                d.add_edge(j,i+m,1);
            }
        }
    }
    d.calc();
    if(d.ans == n) {
        for(int i=1;i<=m;++i) {
            //cout << i << " ->";
            for(auto x:d.g[i]) {
                if(x.b != S && x.flow == 1) syn[x.b - m] = i;
                //cout << x.b << " : " << x.cap << " " << x.flow << endl;
            }
        }
        return true;
    }
    return false;
}
void solve() {
    
    cin>>n>>m; 
    int l = INF, r = -1;
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            cin>>board[i][j];
            l = min(board[i][j],l);
            r = max(board[i][j],r);
        }
    }
    int ans = -1;
    while(l <= r) {
        int mid = l+(r - l) / 2;
        if(f(mid)) {
            ans = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    cout << ans << endl;
    for(int i=1;i<=n;++i) {
        cout << syn[i] << " ";
    }
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


