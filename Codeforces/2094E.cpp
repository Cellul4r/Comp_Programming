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

void solve(){
    
    int n;
    cin>>n;

    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
    }
    sort(all(a));

    vector<int> bits(30);
    vector<ll> cnt(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 30; j++) {
            if((1 << j) & a[i]) {
                bits[j]++;
            }
        }
    }

    for(int i = 0; i < 30; i++) {
        if(2 * bits[i] != n) {
            for(int j = 0; j < n; j++) {
                if((1 << i) & a[j]) {
                    cnt[j] += (1ll * n - bits[i]) * (1ll << i);
                } else {
                    cnt[j] += 1ll * bits[i] * (1ll << i);
                }
            }
        }
    }

    int id = 0;
    ll max_ = 0;
    for(int i = 0; i < n; i++) {
        if(cnt[i] > max_) {
            max_ = cnt[i];
            id = i;
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += (a[id] ^ a[i]);
    }
    //cerr << id << nl;
    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>t;
    while(t--)solve();

    return 0;
}

