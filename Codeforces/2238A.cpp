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
    
    int n, c; cin>>n>>c;
    vector<int> a(n), b(n);
    int mx = 0;
    for(auto &x : a) {
        cin>>x;
        mx = max(mx, x);
    }
    bool flag = true;
    for(auto &x : b) {
        cin>>x;
        if(x > mx) {
            flag = false;
        }
    }
    if(!flag) {
        cout << -1 << nl;
        return;
    }
    int ans1 = 0, ans2 = c;
    for(int i = 0; i < n; i++) {
        if(b[i] > a[i]) {
            ans1 = INF;
            break;
        } else {
            ans1 += a[i] - b[i];
        }
    }
    sort(all(a));
    sort(all(b));
    bool ok = true;
    for(int i = 0; i < n; i++) {
        if(a[i] < b[i]) {
            ok = false;
            ans2 = INF;
            break;
        }
        ans2 += a[i] - b[i];
    }
    if(!ok && ans1 == INF) {
        cout << -1 << nl;
        return;
    }
    cout << min(ans1, ans2) << nl;
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

