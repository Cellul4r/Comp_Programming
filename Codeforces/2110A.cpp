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
    vector<int> a;
    int lOdd = INF, rOdd = -1, lEven = INF, rEven = -1;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        a.push_back(x);
    }
    sort(all(a));
    for(int i = 0; i < n; i++) {
        int x = a[i];
        if(x & 1) {
            lOdd = min(i,lOdd);
            rOdd = max(i,rOdd);
        } else {
            lEven = min(i,lEven);
            rEven = max(i,rEven);
        }
    } 
    cout << min(lOdd+n-rOdd-1,lEven+n-rEven-1) << nl;
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

