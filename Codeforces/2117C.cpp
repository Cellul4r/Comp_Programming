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
    vector<int> a(n);
    vector<int> cnt(n);
    vector<vector<int>> save(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        a[i]--;
        cnt[a[i]]++;
        save[a[i]].push_back(i);
    }

    int ans = 1;
    int idx = -1, prev_ = n, nxt = INF;
    for(int i = 0; i < n; i++) {
       cnt[a[i]]--; 
       if(cnt[a[i]] == 0) {
           idx = i;
           break;
       }
    }
    assert(idx != -1);
    while(idx > 0) {
        nxt = INF;
        for(int i = idx; i < prev_; i++) {
            save[a[i]].pop_back(); 
            if(!save[a[i]].empty()) nxt = min(nxt, save[a[i]].back());
        }
        prev_ = idx;
        idx = nxt;
        ans++;
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

