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
    string a,b;
    cin>>a>>b;
    int ans = 0;
    int i = 0, cnt = 0;
    while(i < n) {
        if(a[i] != b[i]) {
            cnt++;
        } else if(cnt != 0) {
            ans++;
            cnt = 0;
        }
        i++;
    }
    if(cnt != 0) ans++;
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

