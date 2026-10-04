/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    // how can we count efficiently?
    // sqrt(S) <= 1e6 is the hint
    ll s,q; cin>>s>>q;
    // offline queries? maintain inceasing x queries with y increasing if x is equal
    // easy solution in navie solution O(S*q) but can we do it better?
    //
    // Observation that is good forward!
    // S <= 1e12
    // for each x such that 1 <= x <= S it height y maximal is S / x.
    vector<pair<ll,ll>> a;
    for(ll x = 1; x * x <= s; x++) {
        if(s % x != 0) continue;
        a.push_back({x, s / x});
        if(s / x != x) {
            a.push_back({s / x, x});
        }
    }
    sort(all(a));
    int m = a.size();
    vector<ll> cur(m);
    vector<pair<ll,ll>> sum(m+1);
    for(int i = 0; i < m; i++) {
        cur[i] = a[i].first;
        ll k = (a[i].second - (i + 1 < m ? a[i+1].second : 0ll));
        sum[i+1] = {sum[i].first + k * a[i].first, sum[i].second + k};
    }
    ll cnt = sum[m].first;
    for(int i = 1; i <= q; i++) {
        ll x,y; cin>>x>>y;        
        ll ans = cnt;
        int idx = upper_bound(all(cur), y) - cur.begin();
        if(idx != m) {
            ans -= sum[m].first - sum[idx].first - y * (sum[m].second - sum[idx].second);
        }
        idx = upper_bound(all(cur), x) - cur.begin();
        if(idx != m) {
            ans -= sum[m].first - sum[idx].first - x * (sum[m].second - sum[idx].second);
        }
        
        int l =
            upper_bound(all(cur), x) - cur.begin();

        /*
         * Find last corner whose height > y.
         *
         * a[i].second is decreasing.
         */
        int lo = 0, hi = m - 1;
        int p = -1;

        while(lo <= hi) {

            int mid = (lo + hi) / 2;

            if(a[mid].second > y) {
                p = mid;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }

        if(p >= l) {

            /*
             * complete horizontal strips:
             *
             * indices [l, p)
             */
            ans +=
                (sum[p].first - sum[l].first)
                - x * (
                    sum[p].second -
                    sum[l].second
                );

            /*
             * partial strip p:
             *
             * height from y to a[p].second
             * width  from x to a[p].first
             */
            ans +=
                (a[p].second - y)
                * (a[p].first - x);
        }
        cout << ans << nl;
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

