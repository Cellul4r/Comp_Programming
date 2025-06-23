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
    
    int n,k;
    string s;
    cin>>n>>k>>s;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cnt += s[i] == 'B';
    }
    if(cnt == k) {
        cout << 0 << nl;
        return;
    }
    cout << 1 << nl;
    if(cnt > k) {
        int i = 0;
        for(; cnt > k; i++) {
            if(s[i] == 'B') cnt--;
        }
        cout << i << " " << 'A' << nl;
        return;
    }

    int i = 0;
    for(; cnt < k; i++) {
        if(s[i] == 'A') cnt++;
    }
    cout << i << " " << 'B' << nl;
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

