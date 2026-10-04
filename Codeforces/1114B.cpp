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
    
    // m = 2, k = 3
    // n = 9
    // 5 2 5 2 4 1 1 3 2
    // 1 1 2 2 2 3 4 5 5
    //       * * * * * *
    // subarray 0 -> 4
    // subarray 1 -> 6
    // subarray 2 -> 8
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n);  
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    vector<int> idx(n);
    iota(all(idx), 0);
    sort(all(idx), [&](int i, int j) {
                if(a[i] == a[j]) {
                    return i < j;
                }
                return a[i] > a[j];
            });
    // we want to split sub array with maximum sum maximum sum is
    // the sum of sorted array from max -> min k*m elements
    // (5 2) (5 2 4 1 1) (3 2) 
    // (5 2 5 2
    // m m m m ... n - m*k
    ll sum = 0;
    for(int i = 0; i < k * m; i++) {
        sum += 1ll * a[idx[i]];
    }
    cout << sum << nl;
    sort(idx.begin(), idx.begin() + k * m);
    for(int i = 0; i < (k-1) * m; i += m) {
        cout << idx[i+m-1] + 1 << " "; 
    }
    cout << nl;
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

