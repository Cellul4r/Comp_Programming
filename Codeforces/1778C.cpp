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
    
    // insert into Q with at most different "k" chars
    // 0/1 knapsack? has n diff char choose a way to insert atmost diff k chars to make substring a equal to b at most 


    // abcd
    // axcb
    //  b d
    //  x b
    int n,k; cin>>n>>k;
    string s,t; cin>>s>>t;
    vector<int> save;
    for(auto &x : s) {
        save.push_back(x-'a');
    }
    sort(all(save));
    save.erase(unique(all(save)), save.end());
    int m = save.size();
    ll ans = 0;
    vector<array<ll,2>> a;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == t[i]) {
            cnt++;
        } else {
            int idx = -1;
            for(int j = 0; j < m; j++) {
                if(save[j] == (s[i] - 'a')) {
                    idx = j;
                    break;
                }
            }
            a.push_back({cnt,idx});
            cnt = 0;
        }
    }
    if(a.empty()) {
        cout << 1ll * n * (n+1ll) / 2ll << nl;
        return;
    }
    if(cnt > 0) {
        a.push_back({cnt,-1});
    }
    for(int mask = 0; mask < (1 << m); mask++) {
        cnt = __builtin_popcount(mask);
        if(cnt > k) continue;
        ll mx = 0;
        ll now = 0; 
        for(auto &x : a) {
            int c = x[1];
            if(c == -1) {
                now += x[0];
            }
            else if(mask & (1<<c)) {
                now += 1 + x[0];
            } else {
                now += x[0];
                mx += now * (now + 1) / 2ll;
                now = 0;
            }
        }
        mx += now * (now + 1) / 2ll;
        ans = max(ans, mx);
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

