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

ll merge(vector<int>& a, int l, int m, int r) {

    vector<int> now(r - l + 1);
    int i = l, j = m+1, k = 0;
    ll ans = 0;
    while(i <= m && j <= r) {
        if(a[i] <= a[j]) {
            now[k++] = a[i++];
        } else {
            now[k++] = a[j++];
            ans += (m - i + 1);
        }
    }

    while(i <= m) {
        now[k++] = a[i++];
    }
    while(j <= r) {
        now[k++] = a[j++];
    }

    for(int i = l, k = 0; i <= r; i++, k++) {
        a[i] = now[k];
    }
    return ans;
}

ll mergeSort(vector<int>& a, int l, int r) {
    ll ans = 0;
    if(l < r) {
        ll m = (l + r) >> 1;
        
        ans += mergeSort(a,l,m);
        ans += mergeSort(a,m+1,r);

        ans += merge(a,l,m,r);
    }

    return ans;
}
void solve(){
    
    int n;
    cin>>n;
    vector<int> a(n+1), p(n+1);
    vector<int> suff(n+1);
    for(int i = 1; i <= n; i++) {
        int x; cin>>x;
        p[i] = x;
        a[x] = i;
    }
    suff[n] = p[n];
    for(int i = n - 1; i >= 1; i--) {
        suff[i] = max(suff[i+1], p[i]);
    }
    bool ok = true;
    if(a[1] == n) ok = false;
    int mn = a[1];
    for(int i = 1; i <= n; i++) {
        if(a[i] >= mn) continue;
        if(suff[mn] < i) {
            ok = false;
        }
        mn = min(mn, a[i]);
    }
    cout << (ok ? "YES" : "NO") << nl;
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

