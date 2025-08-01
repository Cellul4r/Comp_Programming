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

void dbg(vector<int>& a) {
    for(int i = 0; i < (int)a.size(); i++) {
        cerr << a[i] << " ";
    }
    cerr << nl;
}
void solve(){
    
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
    }
    
    int ans = n - 1;
    for(int i = n - 2; i >= 0; i--) {
        if(a[i] < a[i+1]) {
            ans = i;
        } else {
            break;
        }
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

