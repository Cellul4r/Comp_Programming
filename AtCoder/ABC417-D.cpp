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

    int n;
    cin>>n;
    vector<int> p(n), a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin>>p[i]>>a[i]>>b[i];
    }

    auto f = [&](int x) {
        for(int i = 0; i < n; i++) {
            if(p[i] >= x) {
                x += a[i];
            } else {
                x -= b[i];
                if(x < 0) x = 0;
            }
        }
        return x;
    };

    int q;
    cin>>q;
    while(q--) {
        int x;
        cin>>x;
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

