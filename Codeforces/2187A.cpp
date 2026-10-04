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
    
    int n; cin>>n;
    vector<int> a(n);
    int mx = 0, mn = INF;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }

    vector<int> b = a;
    sort(all(b));
    if(a == b) {
        cout << -1 << nl;
        return;
    }

    int l = 0, r = mx - mn;
    while(l < r) {
        int mid = l + (r - l + 1) / 2;
        bool ok = true;
        for(int i = 0; i < n; i++) {
            if(a[i] == b[i]) continue;
            if(a[i] - mn < mid && mx - a[i] < mid) {
                ok = false;
            }
        }
        if(ok) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    cout << l << nl;
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

