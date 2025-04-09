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
    vector<ll> a(n-1);
    for(auto &x : a) cin>>x;
    multiset<ll> diff;
    set<int> save;
    for(int i = 1; i <= n; i++) save.insert(i);
    for(int i = 1; i < n - 1; i++) {
        diff.insert(a[i] - a[i-1]);
        if(a[i] - a[i-1] >= 2ll * n) {
            cout << "NO" << nl;
            return;
        }
        if(save.count(a[i] - a[i-1])) save.erase(a[i] - a[i-1]);
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        cnt += (save.count(i) >= 2);
    }
    for(int i = 0; i < n - 2; i++) {
        // missing prefix element is at i+1
        int tmp = cnt;
        ll k = a[i+1] - a[i];
        diff.erase(diff.find(k));
        if(diff.count(k) == 1) tmp--;
        for(auto &x : save) {
            ll y = a[i] + x;
            if(y >= a[i+1]) continue;
            if(diff.count(x) == 1)
        }
        if(tmp == 0 && *save.rbegin() <= n) {
            cout << "YES" << nl;
            return;
        }
        diff.insert(k);
    }
    cout << "NO" << nl;
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

