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
    
    int n,q; cin>>n>>q;
    vector<int> a(n+1, 0);
    vector<array<int,2>> save(q);
    for(int i = 0; i < q; i++) {
        int type; cin>>type;
        if(type == 1) {
            int x; cin>>x;
            save[i] = {1,x};
            a[x] = !a[x];
        } else {
            char c; cin>>c;
            save[i] = {2,c};
        }
    }
    vector<bool> vis(n+1, false);
    vector<char> ans(n+1, 'a');
    set<int> cur;
    for(int i = 1; i <= n; i++) {
        if(a[i] == 0) {
            cur.insert(i);
        }
    }
    for(int i = q-1; i >= 0; i--) {
        int type = save[i][0];
        if(type == 1) {
            int idx = save[i][1];
            if(vis[idx]) continue;

            if(a[idx] == 0) {
                a[idx] = 1;
                if(cur.count(idx)) {
                    cur.erase(idx);
                }
            } else {
                a[idx] = 0;
                cur.insert(idx);
            }
        } else {
            // color all in cur
            for(auto &x : cur) {
                vis[x] = true;
                ans[x] = (char)save[i][1];
            }
            cur.clear();
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i];
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

