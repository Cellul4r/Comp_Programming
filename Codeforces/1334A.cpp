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
    vector<pi> a(n);
    for(auto &x : a) {
        cin>>x.first>>x.second;
    }
    int p = 0, c = 0, maxC = 0;
    bool ok = true;
    for(auto &x : a) {
        if(x.first < p || x.second < c) {
            ok = false;
            break;
        }
        maxC = maxC + (x.first - p);
        if(x.second > maxC) {
            ok = false;
            break;
        }
        maxC = x.second;
        p = x.first;
        c = x.second;
    }
    cout << (ok ? "YES" : "NO") << nl;
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

