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
    cin>>n;
    string s;
    cin>>s;

    int ans = INF;
    
    for(int i = 0; i < 26; i++) {
        int l = 0, r = n-1, cnt = 0;  
        while(l < r) {
            if(s[l] == s[r]) {
                l++;
                r--;
            } else if(s[l] == i + 'a'){
                cnt++;
                l++;
            } else if(s[r] == i + 'a') {
                cnt++;
                r--;
            } else {
                cnt = INF;
                break;
            }
        }
        ans = min(ans,cnt);
    }
    cout << (ans == INF ? -1 : ans) << nl;
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

