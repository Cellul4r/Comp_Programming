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
    
    ll n;
    int m;
    cin>>n>>m;

    vector<pl> a(m);
    for(auto &x : a) {
        cin>>x.first>>x.second;
    }

    sort(all(a), [](pl& a, pl& b) {
                if(a.second - a.first != b.second - b.first) {
                    return a.second - a.first > b.second - b.first;
                }
                if(a.second - a.first < b.second - b.first) {
                    return false;
                }
                return a.first < b.first;
            }
        );

    
    ll ans = 0;
    for(int i = 0; i < m; i++) {
        if(n >= a[i].first) {
            ll k = (n - a[i].first) * 1ll / (a[i].first - a[i].second);
            ans += k; 
            n = n - k * (a[i].first - a[i].second);

            n = n - (a[i].first - a[i].second);
            ans++;
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

