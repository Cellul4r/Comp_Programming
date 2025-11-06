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
    cin>>n;
    map<int,int> cnt;
    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
        cnt[x]++;
    }

    ll ans = 0, sum = 0;
    for(auto &[x,y] : cnt) {
        sum += 1ll * y / 2 * 2 * x;
    }

    // no intersect line at symmetry
    for(auto &[x,y] : cnt) {
        if(y % 2 == 0 && sum > 2ll * x) {
            ans = max(ans, sum);
        }
    }

    // 1 intersect line at symmetry
    for(auto &[x,y] : cnt) {
        if(y % 2 == 1 && sum > x) {
            ans = max(ans, sum + x);
        }
    }

    // 2 intersect line at symmetry
    int v1 = -1, v2 = -1;
    for(auto &[x,y] : cnt) {
        if(y % 2 == 0) continue;
        if(v1 == -1) {
            v1 = x;
            continue;
        }
        if(v2 == -1) {
            v2 = x;
        }
        if(sum > v2 - v1) {
            ans = max(ans, sum + v1 + v2);
        }
        v1 = v2;
        v2 = -1;
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

