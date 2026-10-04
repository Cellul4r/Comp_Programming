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
    
    int n,q; cin>>n;
    vector<ll> a(n+1), p1(n+2), p2(n+2);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        p1[i] = p1[i-1];
        p2[i] = p2[i-1];
        if(i & 1) {
            p1[i] += a[i];
        } else {
            p2[i] += a[i];
        }
    }

    cin>>q;
    for(int i = 1; i <= q; i++) {
        ll l,r; cin>>l>>r;
        if(l == r) {
            cout << a[l] << nl;
            continue;
        }
        ll sum = (p1[r] - p1[l-1]) - (p2[r] - p2[l-1]); 
        if(l % 2 == 0) {
            sum *= -1;
        }
        cout << sum << nl;
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

