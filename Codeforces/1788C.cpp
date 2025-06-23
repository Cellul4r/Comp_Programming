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
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    int n;
    cin>>n;
    if(n % 2 == 0) {
        cout << "NO" << nl;
        return;
    }

    cout << "YES" << nl;
    vector<bool> vis(2 * n + 1);
    cout << 1 << " " << 2 * n << nl;
    vis[1] = true, vis[2*n] = true;
    int k = 0;
    for(int i = 0, now = 2 * n - 1, want = 2 * n + 1; k < n / 2; i++, now -= 2) {
        cerr << now << want - now << nl;
        if(vis[now] || vis[want - now]) continue;
        vis[now] = vis[want - now] = true;
        cout << now << " " << want - now << nl;
        k++;
        want++;
    }
    k = 0;
    for(int i = 0, now = 2 * n - 2, want = 2 * n; k < n / 2; i++, now -= 2) {
        if(vis[now] || vis[want - now]) continue;
        vis[now] = vis[want - now] = true;
        cout << now << " " << want - now << nl;
        k++;
        want--;
    }
    cout << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
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

