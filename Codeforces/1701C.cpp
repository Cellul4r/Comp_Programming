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

    int n,m;
    cin>>n>>m;
    vector<int> workers(n+1);
    for(int i = 0; i < m; i++) {
        int x;
        cin>>x;
        workers[x]++;
    }

    int ans = 0;
    int l = 1, r = 2 * m;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        ll task = 0;
        for(int i = 1; i <= n; i++) {
            if(mid < workers[i]) {
                task += (workers[i] - mid);    
            } else {
                task -= (mid - workers[i]) / 2;
            }
        }

        if(task <= 0) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    /*
    string s = "";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    */

    cin>>t;
    while(t--)solve();

    return 0;
}

