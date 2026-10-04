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
const int N =1e6+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
bool vis[N], used[3001];
void solve(){

    int n; cin>>n;
    vector<vector<int>> a(n+1);
    for(int i = 1; i <= n; i++) {
        used[i] = false;
        int l; cin>>l;
        a[i].resize(l);
        for(int j = 0; j < l; j++) {
            cin>>a[i][j];
            vis[a[i][j]] = false;
        }
        reverse(all(a[i]));
        vector<int> now;
        for(auto &x : a[i]) {
            if(!vis[x]) {
                now.push_back(x);
                vis[x] = true;
            }
        }
        for(auto &x : now) {
            vis[x] = false;
        }
        a[i] = now;
    }

    for(int i = 1; i <= n; i++) {
        // choose one blog n operation to post
        // with lexi smallest seq that has not used (already cleared used number)
        int use = -1;
        for(int j = 1; j <= n; j++) {
            if(use == -1 && !used[j]) {
                use = j;
                continue;
            }
            if(used[j]) continue;
            if(a[j] < a[use]) {
                use = j;
            }
        }
        used[use] = true;
        for(auto &x : a[use]) {
            cout << x << " ";
            vis[x] = true;
        }

        for(int j = 1; j <= n; j++) {
            if(used[j]) continue;
            vector<int> now;
            for(auto &x : a[j]) {
                if(vis[x]) continue;
                now.push_back(x);
            }
            a[j] = now;
        }
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

