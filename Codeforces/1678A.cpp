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
    
    int n; cin>>n;
    int zero = 0;
    bool dup = false;
    vector<int> cnt(101);
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        if(x == 0) {
            zero++;
        } else {
            cnt[x]++;
            if(cnt[x] == 2) {
                dup = true;
            }
        }
    }
    if(zero != 0) {
        cout << n - zero << nl;
        return;
    }
    if(dup) {
        cout << n;
    } else {
        cout << n + 1;
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

