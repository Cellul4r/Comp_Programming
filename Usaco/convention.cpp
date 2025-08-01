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
    
    int n,m,c;
    cin>>n>>m>>c;
    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
    }
    sort(all(a));
    auto f = [&](int x) {
        // no cows wait more than x
        int bus = 1;
        int nowCow = 1;
        int firstCow = a[0];
        for(int i = 1; i < n; i++) {
            if(a[i] - firstCow > x) {
                bus++;
                nowCow = 1;
                firstCow = a[i];
            } else if(nowCow + 1 > c) {
                bus++;
                nowCow = 1;
                firstCow = a[i];
            } else {
                nowCow++;
            }
        }
        return bus <= m;
    };
    int l = 0, r = 1e9;
    while(l < r) {
        int mid = l + (r - l) / 2;
        if(f(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    setIO("convention");
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

