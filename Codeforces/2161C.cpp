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
    ll x;
    cin>>n>>x;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }

    sort(all(a));
    ll mx = 0;
    vector<int> ans;
    int cur = -1;
    ll now = 0;
    for(int i = n - 1; i > cur; i--) {
        now += a[i];
        while(now < x && cur + 1 < i) {
            now += a[cur+1];
            ans.push_back(a[cur+1]);
            cur++;
        }

        if(now >= x) {
            mx += a[i];
            now -= x;
        }
        ans.push_back(a[i]);
    }

    cout << mx << nl;
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

