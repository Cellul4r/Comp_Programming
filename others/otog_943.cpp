#include <bits/stdc++.h>
using namespace std;
#define maxN 10000
#define ll long long
#define f first
#define s second
#define endl "\n"

void solve(){
	int n,m,b,q,k; cin>>n>>m>>b>>k>>q;
	int a[n][m];
	pair<int,int> x[b];
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<b;++i){
		cin >> x[i].first >> x[i].second;
	}
	int v,w;
	while(q--){
		cin>>v>>w;
		int cnt = 0;
		for(int i=0;i<b;++i) {
			if(abs(v - x[i].first) + abs(w - x[i].second) <= k) ++cnt;
		}
		cout << max(0,a[v][w] - cnt) << endl;
	}
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

