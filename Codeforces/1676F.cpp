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
    
    int n,k; cin>>n>>k;
    // 2 1 2 2
    map<int,int> cnt;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        cnt[x]++;
    }

    int l = -1, r = -1;
    int cur = -INF, curL = -1, curR=-1;
    int prv = -1;
    for(auto &[x,y] : cnt) {
        if(y >= k && (prv == -1 || prv == x - 1)) {
            if(curL == -1) {
                curL = curR = x;
            } else {
                curR = x;
            }
        } else {
            if(curL != -1 && curR - curL > cur) {
                cur = curR - curL;
                l = curL;
                r = curR;
            }
            curL = curR = (y >= k ? x : -1);
        }
        prv = x;
    }
    if(curL != -1 && curR - curL > cur) {
        cur = curR - curL;
        l = curL;
        r = curR;
    }
    if(l == -1) {
        cout << l << nl;
        return;
    }
    cout << l << " " << r << nl;
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

