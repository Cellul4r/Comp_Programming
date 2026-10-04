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
    
    int n,m,a,c,x0;
    cin>>n>>m>>a>>c>>x0;
    vector<int> b(n+1);
    b[0] = x0;
    for(int i = 0; i < n; i++) {
        b[i+1] = (1ll * a * b[i] + 1ll * c) % m;
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        int l = 1, r = n, ans = -1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(b[mid] == b[i]) {
                ans = mid;
                break;
            }
            if(b[mid] > b[i]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if(ans != -1) {
            cnt++;
        }
    }
    cout << cnt;
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

