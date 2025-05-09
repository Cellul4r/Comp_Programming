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
    
    int n;
    cin>>n;

    vector<int> a(n);
    int min_ = INF, max_ = -1;
    for(auto &x : a) {
        cin>>x;
        min_ = min(min_, x);
        max_ = max(max_, x);
    }

    vector<int> ans(n);

    if(min_ == max_) {
        cout << "NO\n";
        return;
    }

    for(int i = 0; i < n; i++) {
        if(a[i] == max_) {
            ans[i] = 2;
            break;
        }
    }
    for(int i = 0; i < n; i++) {
        if(ans[i] == 0) ans[i] = 1;
    }
    cout << "Yes" << nl;
    for(auto &x : ans) {
        cout << x << " ";
    }
    cout << nl;
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

