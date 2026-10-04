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
    
    int q;
    string s,t;
    cin>>q>>s>>t;
    int n = s.size(), m = t.size();
    s = "$" + s;
    t = "$" + t;
    vector<int> idx;
    for(int i = 1; i <= n - m + 1; i++) {
        bool eq = true;
        assert(i+m-1 <= n);
        for(int j = 1; j <= m; j++) {
            if(s[i+j-1] != t[j]) {
                eq = false;
                break;
            }
        }
        if(eq) {
            idx.push_back(i);
            //cout << i << nl;
        }
    }

    int x = idx.size();
    for(int i = 1; i <= q; i++) {
        int L,R; cin>>L>>R;
        auto k = lower_bound(all(idx), L) - idx.begin();
        if(k != x && idx[k] + m - 1 <= R) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

