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
    
    int x;
    cin>>x;
    vector<int> ans;
    ans.push_back(x);
    // change X to 2^k
    for(int i = 0; i < 32; i++) {
        if((x >> i) & 1) {
            if(x == (1 << i)) {
                break;
            }
            x -= (1 << i);
            ans.push_back(x);
        }
    }
    while(x > 1) {
        x >>= 1;
        ans.push_back(x);
    }
    cout << ans.size() << nl;
    for(auto &x : ans) cout << x << " ";
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

