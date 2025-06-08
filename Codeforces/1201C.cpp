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
    sort(all(a));
    int l = 0, r = 2e9;
    // last x such that f(x) is true
    l--;
    while(l < r) {
        int mid = l + (r - l + 1) / 2;
        //cerr << mid << nl;
        bool ok = true;
        int now = k;
        for(int i = n / 2; i < n; i++) {
            if(a[i] < mid) {
                if(mid - a[i] > now) {
                    ok = false;
                    break;
                }
                now -= mid - a[i];
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
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

