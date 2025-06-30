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
    vector<int> b(n);
    for(auto &x : b) {
        cin>>x;
    }

    set<int> now; 
    for(int i = 1; i <= 2 * n; i++) {
        now.insert(i);
    }

    vector<int> ans(2*n);
    for(int i = 0; i < 2 * n; i += 2) {
        if(now.count(b[i / 2]) == 0) {
            cout << -1 << nl;
            return;
        }
        now.erase(b[i/2]);
        ans[i] = b[i/2];
    }
    
    for(int i = 1; i < 2 * n; i += 2) {
        auto it = now.lower_bound(b[(i-1)/2]);
        if(it == now.end()) {
            cout << -1 << nl;
            return;
        }
        ans[i] = *it;
        now.erase(it);
    }
    for(auto &x : ans) {
        cout << x << " ";
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

