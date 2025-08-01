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
    
    int ans = 0;
    string s;
    cin>>s;
    s += 'B';
    int n = s.size();
    int a = 0, smallGroup = INF;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'A') {
            a++;
            ans++;
        } else {
            smallGroup = min(smallGroup, a);
            a = 0;
        }
    }

    // smallGroup occurs when AAA.. B AAA. , B can eat just one direction
    // so eat larger group is better!
    // also if we encounter B AAAA.. B AAA.. no need to cut because B can eat all
    if(smallGroup == INF) smallGroup = 0;
    cout << ans - smallGroup << nl;
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

