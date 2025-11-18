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
    
    int n,a,b;
    cin>>n>>a>>b;
    if(a + b > n - 2 || abs(a - b) > 1) {
        cout << -1 << nl;
        return;
    }

    vector<int> ans(n,-1);
    
    if(a > b){
        // diff 1 
        // max first then min
        int now = n - 1;
        for(int i = 1, cur = 0; i < n && cur < a; i += 2, cur++) {
            ans[i] = now--;
        }
        now = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(ans[i] != -1) continue;
            ans[i] = now++;
        }
    } else if(a < b){
        // diff 1
        // min first then max
        ans.clear();
        ans.resize(n, -1);
        int now = 0;
        for(int i = 1, cur = 0; i < n && cur < b; i += 2, cur++) {
            ans[i] = now++;
        }
        now = n - 1;
        for(int i = n - 1; i >= 0; i--) {
            if(ans[i] != -1) continue;
            ans[i] = now--;
        }
    } else {
        ans.clear();
        ans.resize(n, -1);
        int now = n - 1;
        for(int i = 1, cur = 0; i < n && cur < a; i += 2, cur++) {
            ans[i] = now--;
        }
        now = 0;
        for(int i = 0; i < n; i++) {
            if(ans[i] != -1) continue;
            ans[i] = now++;
        }
    }

    for(auto &x : ans) {
        cout << x + 1 << " ";
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

