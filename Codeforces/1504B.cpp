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
    string s,t;
    cin>>n>>s>>t;
    
    // each index if it is legal remain legal
    // if illegal then illegal if do some operation i
    vector<int> pref(n+1);
    for(int i = 0; i < n; i++) {
        pref[i+1] = pref[i] + (s[i] == '0' ? -1 : 1);
    }

    bool ok = true;
    int flag = 0;
    for(int i = n - 1; i >= 0; i--) {
        if((s[i] != t[i]) ^ flag) {
            if(pref[i+1] != 0) {
                ok = false;
                break;
            }
            flag ^= 1;
        }
    }

    cout << (ok ? "YES" : "NO") << nl;
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

