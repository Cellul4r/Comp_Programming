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
    
    int n,s;
    cin>>n>>s;
    vector<int> suff(n+2), a(n), pre(n+1);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    for(int i = n; i >= 1; i--) {
        suff[i] = suff[i+1] + a[i -1];
    }
    for(int i = 1; i <= n; i++) {
        pre[i] = pre[i-1] + a[i-1];
    }

    int ans = INF;
    for(int i = 1; i <= n; i++) {
        // do operation from the left in range [1,i]
        int l = i, r = n+1, target = -1;
        // pre[n] - pre[i] - s
        int want = (pre[n] - pre[i - 1] - s);
        while(l <= r) {
            int mid = l + (r - l) / 2; 
            if(suff[mid] >= want) {
                target = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        //cerr << i << " " << target << nl;
        if(target == -1 || suff[target] != want) continue;
        ans = min(ans, i + n - target);
    }
    cout << (ans == INF ? -1 : ans) << nl;
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

