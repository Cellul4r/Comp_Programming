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
    
    // #1 and #-1 sum is odd -> answer = -1
    int n; cin>>n;
    vector<int> a(n+1);
    int p = 0, nn = 0;
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        if(a[i] == -1) nn++;
        else if(a[i] == 1) p++;
    }
    if((p+nn) % 2 == 1) {
        cout << -1 << nl;
        return;
    }
    vector<array<int,2>> ans;
    for(int i = 1; i <= n; i++) {
        if(p == nn) {
            ans.push_back({i,i});
            continue;
        }
        assert(i != n);
        if(p > nn && a[i+1] == 1) {
            ans.push_back({i,i+1});
            p--;
            nn++;
            i++;
        } else if(p < nn && a[i+1] == -1) {
            ans.push_back({i,i+1});
            p++;
            nn--;
            i++;
        } else {
            ans.push_back({i,i});
        }
    }
    cout << ans.size() << nl;
    for(auto &x : ans) {
        cout << x[0] << " " << x[1] << nl;
    }
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

