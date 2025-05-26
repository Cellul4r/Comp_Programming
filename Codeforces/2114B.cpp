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
    
    int n,k;
    string s;
    cin>>n>>k>>s;
    int ones = 0, zeros = 0;
    for(auto &x : s) {
        if(x == '1') ones++;
        else zeros++;
    }

    while(k > 0 && (ones >= 2 || zeros >= 2)) {
        k--;
        if(ones > zeros) {
            ones -= 2;
        } else {
            zeros -= 2;
        }
    }
    cout << (ones == zeros && k == 0 ? "YES" : "NO") << nl;
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

