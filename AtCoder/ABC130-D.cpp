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
    ll k;
    cin>>n>>k;

    vector<ll> a(n+1);
    vector<ll> pre(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        // prefix sum
        pre[i] = pre[i-1] + a[i];
    }

    // count contigious "subsequence" of A
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        int l = 1, r = i;
        int target = -1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(pre[i] - pre[mid-1] >= k) {
                target = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if(target != -1) {
            // found subsequence a such that sum >= k
            ans += target;
        }
    }
    cout << ans;
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

