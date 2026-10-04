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
    
    int n,m,k;
    cin>>n>>m>>k;
    // trivial answer if k = 1 -> always YES
    // if k = n -> each i, a[i] must be equal to 1
    // 1 color? a[1] = n -> valid only if k <= 1
    // 2 color? a[1] + a[2] = n
    //          (1, n - 1) a[2] a[1] a[2] -> valid only if k = 1 or k = 2 and n <= 3
    //          (2, n - 2) a[2] a[1] a[2] a[1]
    // k <= m
    vector<int> a(m);
    for(int i = 0; i < m; i++) {
        cin>>a[i];
    }
    // split n to ceil(n / k) segments each segment has length k, except the last one has n mod k in length.
    // each segments we want and will fill the element with distinct colors.
    // this a[i] <= ceil(n / k)
    // count how many it is for a[i] == ceil(n / k) -> the last used color will last in last segment count should be <= n mod k
    int seg = (n + k - 1) / k;
    int cnt = 0;
    for(auto &x : a) {
        if(x > seg) {
            cout << "NO\n";
            return;
        }
        if(x == seg) cnt++;
    }
    int lt = n - (n / k * k);
    if(lt == 0) lt = k;
    cout << (cnt <= lt ? "YES" : "NO") << nl;
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

