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
const int N =1e6+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    int k;
    while(cin>>k) {
        int p = 0;
        vector<bool> vis(k+1);
        ll cnt = 0;
        // find all primitive triplets
        // how? m,n such that gcd(m,n) = 1 and m n is not both odd.
        for(ll n = 1; n * n < k; n++) {
            for(ll m = n + 1; m*m < k; m += 2) {
                if(__gcd(n,m) != 1) continue;
                ll a = m * m - n * n;
                ll b = 2ll * m * n;
                ll c = m * m + n * n;

                if(c > k) break;
                cnt++;
                ll aa = a, bb = b, cc = c;
                while(cc <= k) {
                    vis[aa] = true;
                    vis[bb] = true;
                    vis[cc] = true;
                    aa += a;
                    bb += b;
                    cc += c;
                }
            }
        }
        for(int i = 1; i <= k; i++) if(!vis[i]) p++;
        cout << cnt << " " << p << nl; 
    }
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

