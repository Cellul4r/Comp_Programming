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
    
    int n,even = 0, odd = 0;
    cin>>n;
    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
        if(x & 1) odd++;
        else even++;
    }

    if(even > (n+1) / 2 || odd > (n+1) / 2) {
        cout << -1 << nl;
        return;
    }

    vector<int> evens,odds;
    for(int i =0; i < n; i++) {
        if(a[i] & 1) {
            odds.push_back(i);
        } else {
            evens.push_back(i);
        }
    }
    int i = 0, j = 0;
    ll ans = LINF;
    
    if(even >= odd) {
        ll now = 0;
        for(int k = 0; k < n; k += 2) {
            now += abs(evens[i++] - k);
        }
        ans = min(ans,now);
    } 
    if(even <= odd){
        ll now = 0;
        for(int k = 0; k < n; k += 2) {
            now += abs(odds[j++] - k);
        }
        ans = min(ans,now);

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

