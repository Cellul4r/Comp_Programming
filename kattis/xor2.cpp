/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    ll a,n; cin>>a>>n;
    // we need to minimize the value of a ^ (kn) how?
    // try to assign bit bi from most significant bit to lowest bit.
    ll cur = 0;
    for(int i = 63; i >= 0; i--) {
        // can this bit bi to be 0?
        // then ai ^ (kbi) = ai
        ll ai = (a >> i) & 1ull;
        // if bi = 0 -> then ai ^ (kni) = ai
        ll x = cur;
        if(ai) x |= (1ull << i);

        // can this value x have a multiple k of n (kn) k>=0
        __int128 l = x;
        __int128 r = (__int128)x + ((__int128)1 << i) - 1;
        __int128 k = (l + n - 1) / n * n;

        if(k <= r) {
            cur = x;
        } else {
            if(!ai) {
                cur |= (1ull << i);
            }
        }
    }
    cout << (cur ^ a) << nl;
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

