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
    
    string s;
    cin>>s;
    int n = s.length();
    int ans = 0;
    vector<bool> replaced(n);
    for(int i = 1; i < n; i++) {
        if(s[i] == s[i-1] && !replaced[i-1]) {
            replaced[i] = true;
        }

        if(i >= 2 && s[i] == s[i-2] && !replaced[i-2]) {
            replaced[i] = true;
        }

        ans += replaced[i];
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

