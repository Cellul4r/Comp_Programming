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
    
    set<pi, greater<pi>> a;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        a.insert(make_pair(x,i));
    }
    int l,r;
    l = r = -1;
    while(!a.empty()) {
        auto u = *a.begin(); 
        a.erase(a.begin());
        if(l == -1) {
            l = r = u.second;
            continue;
        }

        if(u.second + 1 != l && u.second - 1 != r) {
            cout << "NO\n";
            return;
        }
        l = min(l,u.second);
        r = max(r,u.second);
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

