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
    
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(auto &x : a) cin>>x;
    ll l = 1, r = 2e14+1;
    while(l < r) {
        ll mid = l + (r - l) / 2ll;
        int subarray = 1;   
        ll now = 0;
        for(int i = 0; i < n; i++) {
            if(now + a[i] <= mid) {
                now += a[i];
            } else if(a[i] > mid){
                subarray = k+1;
                break;
            } else {
                subarray++;
                now = a[i];
            }
        }
        if(subarray <= k) {
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

    //setIO("");
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

