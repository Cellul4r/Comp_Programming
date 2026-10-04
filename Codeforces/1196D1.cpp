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
    
    int n,k; cin>>n>>k;
    string s; cin>>s;
    // some substring of length k in s must not have same adjacent characters
    // RGBRGB...
    // GBRGBRGBR...
    // BRGBRGBRG...
    string pat = "RGB";
    int ans = INF;
    for(int i = 0; i < n; i++) {
        for(int t = 0; t < 3; t++) {
            int cur = t % 3;
            int cnt = 0;
            for(int j = i; j < i + k; j++) {
                if(s[j] != pat[cur]) {
                    cnt++;
                }
                cur = (cur + 1) % 3;
            }
            ans = min(ans, cnt);
        }
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

