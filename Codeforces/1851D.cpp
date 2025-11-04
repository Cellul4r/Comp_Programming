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
    vector<ll> a(n+1);
    map<ll,int> cnt;
    for(int i = 1; i < n; i++) {
        cin>>a[i];
        cnt[a[i] - a[i-1]]++;
    }

    ll sum = 1ll * n * (n+1) / 2ll;
    if(a[n-1] != sum) {
        a[n] = sum;
        set<ll> check;
        bool ok = true;
        for(int i = 1; i <= n; i++) {
            ll k = a[i] - a[i-1];
            if(k <= 0 || k > n) ok = false;
            check.insert(k);
        }
        if(check.size() != n) ok = false;
        cout << (ok ? "YES" : "NO") << nl;
        return;
    }

    ll val = -1;
    for(auto &[x,y] : cnt) {
        if(y >= 2) {
            if(val != -1) {
                // has different number that has occurence value of differences >= 2
                cout << "NO\n";
                return;
            }
            val = x;
        }
    }
    
    if(cnt[val] > 2) {
        cout << "NO\n";
        return;
    }

    int now = 0;
    for(int i = 1; i <= n; i++) {
        if(cnt[i] == 0) now++;
    }

    cout << (now == 2 ? "YES" : "NO") << nl;
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

