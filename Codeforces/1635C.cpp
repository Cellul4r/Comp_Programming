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
    vector<ll> a(n);
    for(auto &x : a) {
        cin>>x;
    }

    if(a[n-2] > a[n-1]) {
        cout << -1 << nl << nl;
        return;
    }

    if(a[n-1] < 0) {
        cout << (is_sorted(all(a)) ? 0 : -1) << nl << nl; 
        return;
    }
    ll mn = a[n-2], mx = a[n-1];
    int idx1 = n - 2, idx2 = n-1;
    vector<array<int,3>> ans;
    for(int i = n - 3; i >= 0; i--) {
        if(a[i] > a[i+1]) {
            ans.push_back({i,idx1,idx2});
            a[i] = mn - mx;
        }
        if(mn >= 0) {
            mx = mn;
            idx2 = idx1;
        }
        mn = a[i];
        idx1 = i;
    }

    cout << ans.size() << nl;
    for(auto &[x,y,z] : ans) {
        cout << x + 1 << " " << y + 1 << " " << z + 1 << nl;
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

