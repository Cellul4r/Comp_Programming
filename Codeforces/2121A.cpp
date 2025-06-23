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
    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
    }

    if(n == 1) {
        cout << abs(s - a[0]) << nl;
        return;
    }
    int left = a[0], right = a[n-1];
    int ans = INF;
    if(left <= s && s <= right) {
        ans = min(2 * (s - left) + (right - s), 2 * (right - s) + (s - left));    
    } else if(s < left) {
        ans = right - s;
    } else {
        ans = s - left;
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

