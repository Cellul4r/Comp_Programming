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

void solve(){
    
    int n;
    cin>>n;
    vector<int> a(n);
    map<int,int> cnt;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        cnt[a[i]]++;
    }

    int t = 0, s = 0;
    for(auto &[x,y] : cnt) {
        if(y >= 2) {
            t++;
        } else if(y == 1) {
            s++;
        }
    }
    cout << t + (s + 1) / 2 << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    /*
    string s = "";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    */

    cin>>t;
    while(t--)solve();

    return 0;
}

