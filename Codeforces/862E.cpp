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
    
    int n,m,q;
    cin>>n>>m>>q;
    vector<ll> a(n), b(m);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;
    ll sumA = 0;
    ll now = 0;
    for(int i = 0; i < n; i++) {
        if(i & 1) {
            sumA -= a[i];
            now += b[i];
        }
        else {
            sumA += a[i];
            now -= b[i];
        }
    }
    vector<ll> sumB{now};
    //cerr << now << nl;
    for(int i = 1, l = 0, r = n; i <= m - n; i++, l++,r++) {
        now = -(now + b[l]) + b[r] * (n & 1 ? -1 : 1);
        sumB.push_back(now);
        //cerr << now << nl;
    }
    sort(all(sumB));
    auto query = [&](ll x) {
        //cerr << "CHECK: " << x << nl;
        int idx = lower_bound(all(sumB), -x) - sumB.begin();
        if(idx == (int)sumB.size()) idx--;
        ll ans = llabs(sumB[idx] + x);
        if(idx > 0) {
            if(ans > llabs(x + sumB[idx-1])) {
                ans = llabs(x + sumB[idx-1]);
            }
        }
        return ans;
    };
    cout << query(sumA) << nl;
    for(int i = 0; i < q; i++) {
        int l,r;
        ll x;
        cin>>l>>r>>x;
        l--,r--;
        int sz = r - l + 1;
        if(sz & 1) {
            if(l & 1) sumA -= x;
            else sumA += x;
        }
        cout << query(sumA) << nl;
    }
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

