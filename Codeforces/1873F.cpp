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

void solve(){
    
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1);
    vector<int> h(n+1);
    vector<int> pre(n+1), pre2(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        pre[i] = pre[i-1] + a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin>>h[i];
        pre2[i] += pre2[i-1];
        if(i != 1) {
            pre2[i] += (h[i-1] % h[i] == 0);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int l = i, r = n, x = i - 1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(pre[mid] - pre[i-1] <= k && pre2[mid] - pre2[i] == mid - i) {
                x = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        ans = max(ans, x - i + 1);
    }
    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>t;
    while(t--)solve();

    return 0;
}

