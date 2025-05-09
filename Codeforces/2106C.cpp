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

void solve(){
    
    int n,k;
    cin>>n>>k;

    vector<int> a(n),b(n);
    int val = -1;
    for(auto &x : a) {
        cin>>x;
    }
    for(int i = 0; i < n; i++) {
        cin>>b[i];
        if(b[i] != -1) {
            val = a[i] + b[i];
        }
    }

    bool valid = true;
    if(val != -1) {
        
        for(int i = 0; i < n; i++) {
            if(b[i] != -1) {
                if(a[i] + b[i] != val) {
                    valid = false;
                }
            } else if(val < a[i] || val - a[i] > k){
                valid = false;
            }
        }

        cout << (valid ? 1 : 0) << nl;
        return;
    }

    // all array b contains -1
    // a[0] + b[0] = x
    // a[1] + b[1] = x
    // a[2] + b[2] = x
    int min_ = INF, max_ = -1;
    for(int i = 0; i < n; i++) {
        max_ = max(max_, a[i]);
        min_ = min(min_, a[i]);
    }

    int ans = max(0, k - (max_ - min_) + 1);
    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>t;
    while(t--)solve();

    return 0;
}

