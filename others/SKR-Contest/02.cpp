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
typedef unsigned long long ull;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void solve(){
    
    int n,m,k;
    cin>>n>>m>>k;
    int now = min(n,m);
    vector<int> a(n);
    for(auto &x : a) cin>>x;
    sort(all(a));
    ull l = 0, r = ULLONG_MAX - 1;
    ull ans = 0;
    while(l <= r) {
        ull mid = l + (r - l) / 2ull;
        ull check = 0;
        for(int i = 0; i < now; i++) {
            check += mid / (1ull * a[i]);
        }
        if(check >= 1ull * k) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

