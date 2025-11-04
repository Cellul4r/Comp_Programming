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
    
    int n,k,l,r;
    cin>>n>>k>>l>>r;
    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
    }

    ll ans = 0;
    map<int,ll> cnt1,cnt2;
    ll j = -1, p = -1;
    ll cur = 0;
    for(int i = 0; i < n; i++) {
        while(j + 1 < n && cur < k) {
            cur += (cnt1[a[j+1]] == 0);
            cnt1[a[j+1]]++;
            j++;
            if(p < j) {
                cnt2[a[++p]]++;
            }
        }

        while(p + 1 < n && cnt2[a[p+1]] != 0) {
            cnt2[a[p+1]]++;
            p++;
        }
        if(cur == k) {
            ll mn = i + l - 1, mx = i + r - 1;
            ans += max(0ll,min(p,mx) - max(mn,j) + 1);
        }
        //cerr << i << " " << j << " " << p << " CHECK: " << cur << nl;
        if(cnt1[a[i]] == 1) cur--;
        cnt1[a[i]]--;
        cnt2[a[i]]--;
    }
    cout << ans << nl;
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

