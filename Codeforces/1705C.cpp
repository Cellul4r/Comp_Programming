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

void solve(){
    
    string s;
    int n,c,q;
    cin>>n>>c>>q>>s;
    vector<ll> left(c), diff(c);

    ll len = n;
    for(int i = 0; i < c; i++) {
        ll l,r;
        cin>>l>>r;
        l--,r--;
        left[i] = len;
        diff[i] = len - l;
        //cerr << left[i] << " " << diff[i] << nl;
        len += (r - l + 1);
    }

    while(q--) {
        ll x;
        cin>>x;
        x--;
        for(int i = c-1; i >= 0; i--) {
            if(x < left[i]) continue; 
            x -= diff[i];
            //cerr << x << nl;
        }
        cout << s[x] << nl;
    }
    cout << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    /*
    string s = "";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    */

    cin>>t;
    while(t--)solve();

    return 0;
}

