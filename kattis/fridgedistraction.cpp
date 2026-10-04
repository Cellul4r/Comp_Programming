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
int n,w;
void solve(){

    cin>>n>>w;
    int k = w / n;
    int cur = n - 1;
    vector<int> ans;
    for(int i = 0; i < k; i++) {
        ans.push_back(cur);
        cur--;
        if(cur < 0) cur = n - 1;
    }

    k = w % n;
    // 0 <= k < n
    for(int i = 0; i < k; i++) {
        cur++;
        cur %= n;
    }
    if(k > 0) {
        ans.push_back(cur);
    }
    cout << ans.size() << nl;
    for(auto &x : ans) {
        cout << (char)(x + 'a') << " ";
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

