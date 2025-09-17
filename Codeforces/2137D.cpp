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
    
    int n; cin>>n;
    vector<int> a(n);
    for(auto &x : a) cin>>x;
    vector<vector<int>> cnt(n+1);
    for(int i = 0; i < n; i++) {
        cnt[a[i]].push_back(i); 
    }
    for(int i = 1; i <= n; i++) {
        if(!cnt[i].empty() && (int)cnt[i].size() % i != 0) {
            cout << -1 << nl;
            return;
        }
    }

    int now = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < (int)cnt[i].size(); j++) {
            assert(now <= n);
            a[cnt[i][j]] = now;
            if((j+1) % i == 0) {
                now++;
            }
        }
    }

    for(auto &x : a) cout << x << " ";
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

