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
    
    int n,m; cin>>n>>m;
    set<int> cur;
    queue<int> a;
    for(int i = 1; i <= n; i++) {
        int x; cin>>x;
        a.push(x);
    }

    ll ans = 0;
    for(int i = 1; i <= m; i++) {
        int x; cin>>x;
        if(cur.count(x)) {
            cur.erase(x);
            ans++;
            continue;
        }
        while(!a.empty() && a.front() != x) {
            cur.insert(a.front());
            //cout << "::: " << x << nl;
            a.pop();
        }
        /*
        if(i == 3) {
            cout << cur.size() << " " << *cur.begin() << nl;
        }
        */
        ans += cur.size() * 2ll + 1;
        //cout << ans << nl;
        a.pop();
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

