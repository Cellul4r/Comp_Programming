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
    
    string s; cin>>s;
    set<int> a,b,c;
    int n = s.length();
    for(int i = 0; i < n; i++) {
        if(s[i] == 'A') {
            a.insert(i);
        } else if(s[i] == 'B') {
            b.insert(i);
        } else {
            c.insert(i);
        }
    }
    int ans = 0;
    while(!a.empty()) {
        int x = *a.begin();
        auto it = b.upper_bound(x);
        if(it == b.end()) break;
        x = *it;
        auto it2 = c.upper_bound(x);
        if(it2 == c.end()) break;
        ans++;
        a.erase(a.begin());
        b.erase(it);
        c.erase(it2);
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

