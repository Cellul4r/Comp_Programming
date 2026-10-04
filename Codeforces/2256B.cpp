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
const ll LINF = 998244353;

void setIO(string);
void solve(){
    
    // max weight sum is in range [0,2]
    // (0,0), (0,1), (1,0), (1,1)
    int n; cin>>n;
    string s; cin>>s;
    // max length of string that match these format is n <= 7
    // thus the format in string must be SUM: 0,1,2
    //                                        0,2,1
    //                                        1,0,2
    //                                        1,2,0
    //                                        2,0,1
    //                                        2,1,0
    //

    // (s[0]+s[1]) != (s[1]+s[2])
    // (s[1]+s[2]) != (s[2]+s[3])
    // (s[2] + s[3]) != (s[3] + s[4])
    // s[0] != s[2] wow!
    // s[1] != s[3]
    // s[2] != s[4]
    // s[3] != s[5]
    // suppose s[1] != s[5] then s[1] = s[3] which is contradiction
    // even index is alternate string 0 1 0 1 0 1 0
    // odd index is alternate string  1 0 1 0 1 0 1
    ll a = 0, b = 0;
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] != '?') continue;
        if(i % 2 == 0) cnt1++;
        else cnt2++;
    }
    if(cnt1 == 0) {
        bool ok = true;
        for(int i = 0; i < n; i += 2) {
            if(i + 2 < n) {
                if(s[i] == s[i+2]) {
                    ok = false;
                    break;
                }
            }
        }
        if(ok) a = 1;
    } else {
        for(int i = 0; i <= 1; i++) {
            bool ok = true;
            for(int k = 0; k < n; k += 2) {
                if(k / 2 % 2 == i) {
                    // must be 0
                    if(s[k] != '?' && s[k] != '0') {
                        ok = false;
                        break;
                    }
                } else {
                    if(s[k] != '?' && s[k] != '1') {
                        ok = false;
                        break;
                    }
                }
            }
            if(ok) a++;
        }
    }
    if(cnt2 == 0) {
        bool ok = true;
        for(int i = 1; i < n; i += 2) {
            if(i + 2 < n) {
                if(s[i] == s[i+2]) {
                    ok = false;
                    break;
                }
            }
        }
        if(ok) b = 1;
    } else {
        for(int i = 0; i <= 1; i++) {
            bool ok = true;
            for(int k = 1; k < n; k += 2) {
                if(k / 2 % 2 == i) {
                    // must be 0
                    if(s[k] != '?' && s[k] != '0') {
                        ok = false;
                        break;
                    }
                } else {
                    if(s[k] != '?' && s[k] != '1') {
                        ok = false;
                        break;
                    }
                }
            }
            if(ok) b++;
        }
    }
    cout << a * b << nl;
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

