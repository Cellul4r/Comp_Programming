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
map<pi,int> save;
void solve(){
    
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
    }

    auto f = [&](int l, int r, int d) {
        return save[make_pair(l,r)] <= d;
    };

    for(int i = 0; i < q; i++) {
        ll ans = 0;
        int L,R,d;
        cin>>L>>R>>d;
        L--,R--;
        for(int l = L; l <= R; l++) {
            int lo = l, hi = R;
            while(lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if(f(l,mid,d)) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            if(f(l,lo,d)) {
                ans += 1ll * (R - lo + 1);
            }
        }
        cout << ans << nl;
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

