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
    
    // assem basic c++
    int a,b,c; cin>>a>>b>>c;
    int ans = INF;
    // choose how many groups we will place A, then the remain will be C
    for(int i = 1; i <= 2; i++) {
        vector<int> now(3, 0);
        if(i == 1) {
            now[0] += a;

            now[1] += c / 2;
            now[2] += c - c / 2;
        } else {
            now[0] += a / 2;
            now[1] += a - a / 2;
            
            now[2] += c;
        }
        for(int j = 1; j <= b; j++) {
            int mn = INF, cur = -1;
            for(int k = 0; k < 3; k++) {
                if(now[k] < mn) {
                    mn = now[k];
                    cur = k;
                }
            }
            now[cur]++;
        }
        ans = min(ans, max({now[0],now[1],now[2]}));
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

