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
    
    int n,m;
    cin>>n>>m;
    vector<string> a(n);
    int ans = 0;
    for(auto &x : a) {
        cin>>x;
    }
    for(int i = 0; i < m; i++) {
        int now = INF;
        for(int k = 0; k < 26; k++) {
            int op = 0; 
            for(int j = 0; j < n; j++) {
                if(a[j][i] != k + 'a') {
                    op++;
                }
            }
            now = min(now,op);
        }
        ans += now;
    }
    cout << ans;
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

