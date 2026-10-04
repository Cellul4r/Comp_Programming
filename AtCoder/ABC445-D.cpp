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
const int N =2e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
int h,w,n;
array<int,2> a[N];
map<int, set<int>> ch, cw;
array<int,2> ans[N];
void solve(){
    
    cin>>h>>w>>n;
    for(int i = 0; i < n; i++) {
        cin>>a[i][0]>>a[i][1];
        ch[a[i][0]].insert(i);
        cw[a[i][1]].insert(i);
    }

    int now = 0;
    int curw = 0, curh = 0;
    int diffH = h, diffW = w;
    while(now != n) {
        now++;
        int k = -1;
        if(!ch[diffH].empty()) {
            k = *ch[diffH].begin(); 
            for(auto &x : ch[diffH]) {
                if(a[x][1] <= diffW) {
                    k = x;
                    break;
                }
            }
        }
        if(k == -1) {
            for(auto &x : cw[diffW]) {
                if(a[x][0] <= diffH) {
                    k = x;
                    break;
                }
            }
        }
        //assert(k != -1);
        ch[a[k][0]].erase(k);
        cw[a[k][1]].erase(k);
        ans[k] = {curh, curw};
        if(a[k][0] == diffH) {
            curw += a[k][1];
            diffW -= a[k][1];
        } else {
            curh += a[k][0];
            diffH -= a[k][0];
        }
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i][0] + 1 << " " << ans[i][1] + 1 << nl;
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

