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
    string s;
    cin>>n>>s;
    map<int,int> save;
    int ans = n;
    int now = 0;
    for(auto &x : s) {
        if(x == 'a') {
            now++;
        } else {
            now--;
        }
    }
    int cur = 0;
    if(now == 0) ans = 0;
    save[0] = -1;
    for(int i = 0; i < n; i++) {
        cur += (s[i] == 'a' ? 1 : -1); 
        if(save.find(cur - now) != save.end()) {
            ans = min(ans, i - save[cur-now]);
        }
        save[cur] = i;
    }
    cout << (ans == n ? -1 : ans) << nl;
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

