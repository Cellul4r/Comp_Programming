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
    
    ll n,k,q; cin>>n>>k>>q;
    vector<ll> mn(n+1,1e9);
    vector<bool> check(n+1,false);

    vector<array<int,2>> a;
    for(int i = 1; i <= q; i++) {
        int c,l,r;
        cin>>c>>l>>r;
        if(c == 1) {
            for(int j = l; j <= r; j++) {
                mn[j] = min(mn[j], k);
            }
        } else {
            for(int j = l; j <= r; j++) {
                check[j] = true;
            }
            a.push_back({l,r}); 
        }
    }
    vector<ll> ans(n+1,-1);
    sort(all(a));
    for(auto &x : a) {
        int l = x[0] ,r = x[1];
        ll mex = 0;
        vector<bool> vis(n+1);
        for(int i = l; i <= r; i++) {
            if(ans[i] >= 0 && ans[i] <= n) {
                vis[ans[i]] = true;
            }
        }
        
        for(int i = 0; i <= n; i++) {
            if(!vis[i]) {
                mex = i;
                break;
            }
        }

        ll cur = k - 1;
        while(cur >= 0 && vis[cur]) {
            cur--;
        }
        priority_queue<array<ll,2>> pq;
        for(int i = l; i <= r && mex <= cur; i++) {
            if(ans[i] != -1) continue;
            if(mn[i] == (ll)1e9) {
                // ok
                ans[i] = mex;
                vis[mex] = true;
                while(mex <= n && vis[mex]) {
                    mex++;
                }
            } else {
                pq.push({mn[i],i});
            }
        }
        // try to put [l,r] such that mn[i] is so much such that mn[i] != 1e9 and ans[i] != -1
        while(!pq.empty() && mex <= cur) {
            ll v = pq.top()[0], idx = pq.top()[1];
            pq.pop();
            if(cur >= v) {
                ans[idx] = cur;
                vis[cur] = true;
                while(cur >= 0 && vis[cur]) {
                    cur--;
                }
            }
        }
        //assert(mex > cur);
    }

    for(int i = 1; i <= n; i++) {
        if(ans[i] == -1) {
            if(check[i] && mn[i] == k) {
                ans[i] = (ll)1e9;
            } else {
                ans[i] = mn[i];
            }
        }
        cout << ans[i] << " ";
    }
    cout << nl;
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

