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
    vector<pi> ans;
    set<pi> a;
    for(int i = 0; i < n; i++) {
       int x;
       cin>>x;
       if(x == 0) continue;
       a.insert(make_pair(x,i+1));
    }

    while((int)a.size() > 1) {
        pi u = *a.begin();
        pi v = *a.rbegin();
        a.erase(a.begin());
        a.erase(--a.end());
        u.first--;
        v.first--;
        ans.push_back(make_pair(u.second,v.second));
        if(u.first != 0) {
            a.insert(u);
        }
        if(v.first != 0) {
            a.insert(v);
        }
    }
    
    cout << ans.size() << nl;
    for(auto &x : ans) {
        cout << x.first << " " << x.second << nl;
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

