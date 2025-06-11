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
    
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
    }
    bool use = false;
    int now = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == 1) {
            //cerr << now << nl;
            if(!use) {
                use = true;
                now = x;
            } else if(now == 0) {
                cout << "NO" << nl;
                return;
            } 
        }
        if(use) now--;
        now = max(now,0);
    }
    cout << "YES" << nl;
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

