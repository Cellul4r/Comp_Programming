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
const int N =2e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
ll n,q;
set<pl> now;
void solve(){
    
    cin>>n>>q; 
    ll cur = n;
    for(int i = 1; i <= q; i++) {
        int l,r; cin>>l>>r;
        auto it = now.lower_bound({l,-1});

        if(it != now.begin()) {
            it--;

            if(it->second < l) {
                it++;
            }
        }

        while(it != now.end()) {
            int ll = it->first, rr = it->second;
            if(ll > r) {
                break;
            }

            l = min(ll, l);
            r = max(rr, r);

            cur += (rr - ll + 1);

            it = now.erase(it);
        }

        cur -= (r - l + 1);
        now.insert({l,r});
        cout << cur << nl;
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

