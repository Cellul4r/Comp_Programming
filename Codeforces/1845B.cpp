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
    
    auto f = [&](pi a, pi b) {
        return abs(a.first - b.first) + abs(a.second - b.second);
    };

    vector<pi> a(3); 
    for(int i = 0; i < 3; i++) {
        cin>>a[i].first>>a[i].second;
    }

    // d(A,B) + d(A,C) = 2 * d(A,X) + d(X,B) + d(X,C)
    // d(A,x) = d(A,B) + d(A,C) - d(B,C) / 2
    cout << 1 + (f(a[0],a[1]) + f(a[0],a[2]) - f(a[1],a[2])) / 2; 
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

