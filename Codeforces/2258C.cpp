/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
int ask(int u, int v, int d) {
    cout << "? " << u << " " << v << " " << d << endl;
    int x; cin>>x;
    return x;
}
void answer(int u, int v, int d) {
    cout << "! " << u << " " << v << " " << d << endl;
}
void solve(){
    
    int n; cin>>n;
    
    // try to find longest depth node u from vertice 1
    int u = 1, d = 0;
    for(int i = 2; i <= n && d != n - 1; i++) {
        if(!ask(1,i,d+1)) continue;
        u = i;
        d++;
        while(d != n - 1 && ask(1,u,d+1)) d++;
    }
    // 2n-2 queries so far
    // then try to find longest depth node from vertice u
    int v = 1;
    for(int i = 1; i <= n && d != n - 1; i++) {
        if(i == u) continue;
        if(!ask(u,i,d+1)) continue;
        v = i;
        d++;
        while(d != n - 1 && ask(u,v,d+1)) d++;
    }
    // that is the answer
    answer(u,v,d);
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    int t = 1;

    //setIO("");
    cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

