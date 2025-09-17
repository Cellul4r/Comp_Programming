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
bool overlap(int l1, int r1, int l2, int r2) {
    int l = max(l1,l2);
    int r = min(r1,r2);
    return l <= r;
}
void solve(){
    
    // edge case n = 2
    // Ali try to select indices(i,j) that make Bahamin unchanged the array
    int n,k; cin>>n>>k; 
    vector<pi> a(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i].first;
    }
    for(int i = 0; i < n; i++) {
        cin>>a[i].second;
    }

    ll cost = 0;
    for(int i = 0; i < n; i++) {
        if(a[i].first > a[i].second) swap(a[i].first,a[i].second);
        cost += abs(a[i].first - a[i].second);
    }


    sort(all(a));
    // find pair that is already optimal (no increase of cost)
    bool found = false;
    for(int i = 0; i < n - 1; i++) {
        if(overlap(a[i].first,a[i].second,a[i+1].first,a[i+1].second)) {
            found = true;
        }
    }
    if(!found) {
        ll mn = LINF;
        for(int i = 0; i < n - 1; i++) {
            vector<int> b{a[i].first,a[i].second,a[i+1].first,a[i+1].second};
            sort(all(b));
            ll now = 0;
            now += b[3] - b[0];
            now += b[2] - b[1];
            mn = min(mn,now - (a[i].second - a[i].first) - (a[i+1].second - a[i+1].first));
        }
        cout << cost + mn << nl;
    } else {
        cout << cost << nl;
    }
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

