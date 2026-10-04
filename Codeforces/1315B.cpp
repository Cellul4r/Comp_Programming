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
    
    ll a,b,p;
    string s;
    cin>>a>>b>>p>>s;
    int n = s.length();
    
    // AABBBAABB a = 3, b= 2
    // a + b + a + b = 2a+2b = 6 + 4 = 10
    vector<int> aa;
    char cur = s[0];
    ll cost = 0;
    for(int i = 1; i < n; i++) {
        if(s[i] != cur) {
            aa.push_back(i-1);
        }
        cur = s[i];
    }
    aa.push_back(n-1);
    int prv = -1;
    for(auto &x : aa) {
        //cerr << x << nl;
        if(x != n - 1 || x != prv + 1) cost += (s[x] == 'A' ? a : b);
        prv = x;
    }
    int idx = 0;
    for(int i = 0; i < n && idx < (int)aa.size(); i++) {
        if(p >= cost) {
            cout << i + 1 << nl;
            return;
        }
        if(i >= aa[idx]) {
            cost -= (s[aa[idx]] == 'A' ? a : b);
            idx++;
        }
    }
    cout << n << nl;
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

