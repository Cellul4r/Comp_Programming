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
    
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(auto &x : a) cin>>x;
    int l = 0, r = 0;
    int ans = INF;
    map<int,int> cnt;
    int now = 0;
    int last = a[l];
    sort(all(a));
    while(l < n) {
        while(r < n && now != m) {
            for(int i = 1; i * i <= a[r]; i++) {
                if(a[r] % i != 0) continue;
                if(i <= m) {
                    cnt[i]++;
                    if(cnt[i] == 1) now++;
                }
                if(a[r] == i * i) continue;
                if(a[r] / i <= m) {
                    cnt[a[r]/i]++;
                    if(cnt[a[r]/i] == 1) now++;
                }
            }
            last = a[r];
            r++;
        }
        if(now == m) {
            //cerr << l << " " << r << last << nl;
            ans = min(ans,last - a[l]);
        }
        for(int i = 1; i * i <= a[l]; i++) {
            if(a[l] % i != 0) continue;
            if(i <= m) {
                cnt[i]--;
                if(cnt[i] == 0) now--;
            }
            if(a[l] == i * i) continue;
            if(a[l] / i <= m) {
                cnt[a[l]/i]--;
                if(cnt[a[l]/i] == 0) now--;
            }
        }
        l++;
    }

    cout << (ans == INF ? -1 : ans) << nl;
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

