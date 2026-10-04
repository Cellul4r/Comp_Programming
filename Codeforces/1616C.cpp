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
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
    }
    if(n == 1) {
        cout << 0 << nl;
        return;
    }
    // length r-l+1 = 3 -> a[l+1] = 1/2(a[l] + a[r])
    // 2a[l+1] = a[l] + a[r]
    // a[r] = 2a[l+1] - a[l]
    // length r-l+1 = 4 -> a[l+1] - a[l] = a[r] - a[r-1]
    // a[l+1] - a[l] = 2a[l+1] - a[l] - a[r-1]
    // a[r-1] = a[l+1]
    int ans = INF;
    // upperbound for the answer is n - 2
    // and the formula given in the problem statement is arithmethic series fuck it!!!!
    // 
    // how can we shoose the d in the arithmethic series???
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            int d = a[j] - a[i];
            int cur = 0;
            // d must be equal to (a[j] - a[i]) / (j-i)
            // thus we check for each seq which one we need to change
            for(int k = 1; k <= n; k++) {
                if(k == i || k == j) continue;
                if((a[k] - a[i]) * (j - i) != d * (k - i)) {
                    cur++;
                }
            }
            ans = min(ans, cur);
        }
    }
    cout << ans << nl;
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

