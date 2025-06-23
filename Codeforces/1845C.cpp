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

void solve(){
    
    string s,l,r;
    int m;
    cin>>s>>m>>l>>r;
    int n = s.length();

    int mx = 0;
    for(int i = 0; i < m; i++) {
        int mx2 = mx;
        for(int j = l[i]; j <= r[i]; j++) {
            int cur = mx;
            while(cur < n && s[cur] != j) {
                cur++;
            }
            mx2 = max(mx2,cur);
        }
        if(mx2 == n) {
            cout << "YES" << nl;
            return;
        }
        mx = mx2 + 1;
    }

    cout << "NO" << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>t;
    while(t--)solve();

    return 0;
}

