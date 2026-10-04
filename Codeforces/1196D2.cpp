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
    // RGBRGB... -> 012 012 012 (type 0)
    // GBRGBRGBR... -> 120 120 120 (type 1)
    // BRGBRGBRG... -> 201 201 201 (type 2)
    string pat = "RGB";
    // R:0
    // G:1
    // B:2
    int ans = INF;
    int rr = 0, gg = 0, bb = 0;
    for(int l = 0, r = 0; l < n - k + 1; l++) {
        // [l,r)
        while(r - l < k) {
            char &c = s[r];  
            if(c != pat[(r-l)%3]) {
                rr++;
            }
            if(c != pat[(r-l+1)%3]) {
                gg++;
            }
            if(c != pat[(r-l+2)%3]) {
                bb++;
            }
            r++;
        }
        //cout << l << " " << r << " : " << rr << " " << gg << " " << bb << nl;
        ans = min({ans, rr, gg, bb});
        char &c = s[l];
        if(c != pat[0]) {
            rr--;
        }
        if(c != pat[1]) {
            gg--;
        }
        if(c != pat[2]) {
            bb--;
        }
        //cout << rr << " " << gg << " " << bb << nl;
        swap(gg,bb);
        swap(rr,gg);
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

