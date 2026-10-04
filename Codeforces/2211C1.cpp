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
    
    int n,k; cin>>n>>k;
    vector<int> a(n+1), b(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
    }
    vector<bool> vis(n+1);
    bool ok = true;
    for(int i = 1; i <= n; i++) {
        cin>>b[i];
        if(b[i] == -1) continue;
        if(vis[b[i]]) {
            ok = false;
        } else {
            vis[b[i]] = true;
        }
    }

    if(!ok) {
        cout << "NO\n";
        return;
    }

    queue<int> now;
    for(int i = 1; i <= n; i++) {
        if(!vis[a[i]]) {
            now.push(a[i]);
        }
    }

    for(int i = 1; i <= n; i++) {
        if(b[i] != -1) continue;
        if(now.empty()) assert(false);
        b[i] = now.front();
        now.pop();
    }
    vector<int> x(n+1), y(n+1);
    for(int i = 1; i <= k; i++) {
        x[a[i]]++;
        y[b[i]]++;
    }

    for(int i = 1; i <= n; i++) {
        if(x[i] != y[i]) {
            cout << "NO\n";
            return;
        }
    }

    for(int i = k+1; i <= n; i++) {
        x[a[i-k]]--;
        x[a[i]]++;
        y[b[i-k]]--;
        y[b[i]]++;
        if(x[b[i-k]] != y[b[i-k]] || x[a[i]] != y[a[i]] || x[a[i-k]] != y[a[i-k]] || x[b[i]] != y[b[i]]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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

