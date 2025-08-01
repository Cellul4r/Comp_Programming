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
    int even = 0, odd = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        if(x & 1) odd++;
        else even++;
    }
    int isEven = 1;
    int ans = 0;
    while(true) {
        if(isEven) {
            if(even == 0) {
                if(odd < 2) break;
                odd -= 2;
                ans++;
            } else {
                even--;
                ans++;
            }
        } else {
            if(odd == 0) break;
            if(even == 0 && odd == 2) break;
            odd--;
            ans++;
        }
        isEven ^= 1;
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

