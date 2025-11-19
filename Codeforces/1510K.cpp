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
int n;
int recur(vector<int> a, int op, int prv) {
    if(op == 2*n) {
        bool flag = is_sorted(all(a));
        return (flag ? 0 : 1e7);
    }

    if(is_sorted(all(a))) {
        return 0;
    }
    int ans = INF;
    vector<int> b = a;
    for(int i = 0; i < 2 * n; i += 2) {
        swap(b[i],b[i+1]);
    }
    if(prv != 0) ans = min(ans, 1 + recur(b, op+1,0));
    b = a;
    for(int i = 0; i < n; i++) {
        swap(b[i], b[i+n]);
    }
    if(prv != 1) ans = min(ans, 1 + recur(b, op+1,1));
    return ans;
}
void solve(){
    
    cin>>n;
    vector<int> a(2*n);
    for(int i = 0; i < 2*n; i++) {
        cin>>a[i];
    }

    int ans = recur(a,0,-1);
    cout << (ans >= 1e7 ? -1 : ans);
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

