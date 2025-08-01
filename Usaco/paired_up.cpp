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
int n;
pi a[N];
void solve(){
    cin>>n;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        cin>>a[i].second>>a[i].first;
    }
    sort(a,a+n);
    int l = 0, r = n-1;
    while(l < r) {
        if(a[l].second == 0) {
            l++;
            continue;
        }
        if(a[r].second == 0) {
            r--;
            continue;
        }
        int k = min(a[l].second, a[r].second);
        a[l].second -= k;
        a[r].second -= k;
        ans = max(ans, a[l].first + a[r].first);
    }
    if(l == r && a[l].first != 0) {
        ans = max(ans, a[l].first * 2); 
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    setIO("pairup");
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

