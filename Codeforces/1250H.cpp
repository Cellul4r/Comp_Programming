/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    vector<ll> a(11, 0);
    cin>>a[10];
    for(int i = 1; i <= 9; i++) {
        cin>>a[i];
    }
    int mn = INF, cur = -1;
    for(int i = 1; i <= 10; i++) {
        if(a[i] < mn) {
            mn = a[i];
            cur = i;
        }
    }
    if(cur < 10) {
        for(int i = 1;i <= a[cur]+1; i++) {
            cout << cur;
        }
    } else {
        cout << 1;
        for(int i = 1;i <= a[cur]+1; i++) {
            cout << 0;
        }
    }
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

