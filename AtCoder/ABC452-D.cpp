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
    
    string s,t;
    cin>>s>>t;

    ll n = s.size(), m = t.size();
    ll ans = 0;
    vector<vector<int>> save(26);
    for(int i = 0; i < n; i++) {
        save[s[i]-'a'].push_back(i);
    }
    for(int i = 0; i < n; i++) {
        int l = i;
        bool ok = true;
        for(int k = 0; k < m; k++) {
            auto it = lower_bound(all(save[t[k]-'a']), l);
            if(it == save[t[k] - 'a'].end()) {
                ok = false;
                break;
            }
            l = *it + 1;
        }
        l--;
        if(ok) ans += n - l;
    }
    ans = n * (n + 1) / 2ll - ans; 
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

