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
    
    int n;
    string s;
    cin>>n>>s;
    ll a = 0, b = 0, c = 0;
    ll ans = 0;
    // AB -> BA
    // BC -> CB
    vector<ll> pre(n), suff(n);
    pre[0] = s[0] == 'A';
    for(int i = 1; i < n; i++) {
        if(s[i] == 'C') {
            pre[i] = 0;
        } else if(s[i] == 'A') {
            pre[i] = 1;
            pre[i] += pre[i-1];
        } else {
            pre[i] += pre[i-1];
        }
    }
    suff[n-1] = s[n-1] == 'C';
    for(int i = n - 2; i >= 0; i--) {
        if(s[i] == 'A') {
            suff[i] = 0;
        } else if(s[i] == 'C') {
            suff[i] = 1;
            suff[i] += suff[i+1];
        } else {
            suff[i] += suff[i+1];
        }
    }
    for(int i = 0; i < n; i++) {
        if(s[i] == 'A') {
            a++;
            b = 0;
            c = 0;
        } else if(s[i] == 'C') {
            a = 0;
            b = 0;
        } else {
            // find how many b after a
            int j = i;
            while(j < n && s[j] == 'B') {
                b++;
                j++;
            }
            // find how many c after b
            while(j < n && s[j] == 'C') {
                c++;
                j++;
            }
            ans += b * max(pre[i], suff[i]);
            i = j - 1;
            c = b = 0;
        }
    }
    cout << ans << nl;
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

