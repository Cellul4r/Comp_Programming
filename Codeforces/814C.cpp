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
    
    int n,q;
    string s;
    cin>>n>>s>>q;
    for(int i  = 0; i < q; i++) {
        int m;
        char c;
        cin>>m>>c;
        int ans = 0, l = 0, r = 0, paint = m;
        while(l < n) {
            while(r < n && (paint > 0 || s[r] == c)) {
                if(s[r] != c) {
                    paint--;
                }
                r++;
            }
            //cerr << l << " " << r << nl;
            ans = max(ans, r - l);
            if(s[l] != c) {
                paint++;
            }
            l++;
        }
        cout << ans << nl;
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

