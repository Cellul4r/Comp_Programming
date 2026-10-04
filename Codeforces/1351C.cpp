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
void solve(){
    
    string s; cin>>s; 
    set<array<int,4>> save;
    array<int,2> p = {0,0};
    ll ans = 0;
    for(auto &x : s) {
        auto q = p; 
        if(x == 'N') {
            q[1] += 1;
        } else if(x == 'E') {
            q[0] += 1;
        } else if(x == 'S') {
            q[1] -= 1;
        } else {
            q[0] -= 1;
        }
        if(save.count({p[0],p[1],q[0],q[1]}) || save.count({q[0],q[1],p[0],p[1]})) {
            ans++;
        } else {
            ans += 5;
        }
        save.insert({p[0],p[1],q[0],q[1]});
        p = q;
    }
    cout << ans << nl;
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

