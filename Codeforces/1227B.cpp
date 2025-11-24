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
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    for(int i = 1; i < n; i++) {
        if(a[i] < a[i-1] || (a[i] == a[i-1] && a[i] == 1)) {
            cout << -1 << nl;
            return;
        }
    }
    // non-decreasing order
    vector<int> ans(n);
    ans[0] = a[0];
    set<int> now; 
    for(int i = 1; i <= n; i++) now.insert(i);
    now.erase(ans[0]);
    bool ok = true;
    for(int i = 1; i < n; i++) {
        if(a[i] > a[i-1]) {
            if(!now.count(a[i])) {
                ok = false;
                break;
            }
            now.erase(a[i]);
            ans[i] = a[i];
        } else {
            // a[i] == a[i-1]
            // ans[i] < a[i]
            auto it = now.lower_bound(a[i]);
            if(now.empty() || it == now.begin()) {
                ok = false;
                break;
            }
            it--;
            ans[i] = *it;
            now.erase(it);
        }
    }

    if(!ok) {
        cout << -1 << nl;
        return;
    }

    for(auto &x : ans) {
        cout << x << " ";
    }
    cout << nl;
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

