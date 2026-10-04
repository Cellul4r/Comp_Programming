/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    int n; cin>>n;
    vector<ll> a(26), b(26);
    a[0] = b[0] = 1;

    ll s = 1, t = 1;
    for(int i = 0; i < n; i++) {
        ll d,k; cin>>d>>k;
        string ss; cin>>ss;
        for(auto &x : ss) {
            if(d == 1) {
                s += k;
                a[x-'a'] += k;
            } else {
                t += k;
                b[x-'a'] += k;
            }
        }
        int l = INF, r = -1;
        for(int j = 0; j < 26; j++) {
            if(a[j] > 0) {
                l = min(l,j);
            }
            if(b[j] > 0) {
                r = max(r,j);
            }
        }
        if(l < r) {
            cout << "YES\n";
            continue;
        }
        assert(l == r);
        // l never be greater than r
        bool ok = true;
        for(int j = 0; j < r; j++) {
            if(b[j] != 0) {
                ok = false;
                break;
            }
        }
        for(int j = l + 1; j < 26; j++) {
            if(a[j] != 0) {
                ok = false;
                break;
            }
        }
        cout << (ok && s < t ? "YES\n" : "NO\n");
    }
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

