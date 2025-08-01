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

int n,k;
int a,b,c,d;
void solve(){

    cin>>n>>k>>a>>b>>c>>d;
    vector<int> aa(n+1);
    for(int i = 1; i <= n; i++) {
        aa[i] = i;
    }

    int L = max(a,c), R = min(b,d);
    if(L > R) {
        if(k & 1) {
            reverse(aa.begin() + a, aa.begin() + (b + 1));
            reverse(aa.begin() + c, aa.begin() + (d + 1));
        }
    } else {
        set<vector<int>> save{aa};
        int loop = 1;
        while(true) {
            reverse(aa.begin() + a, aa.begin() + (b + 1));
            reverse(aa.begin() + c, aa.begin() + (d + 1));
            if(save.count(aa)) {
                break;
            }
            loop++;
            save.insert(aa);
        }
        k %= loop;
        for(int i = 0; i < k; i++) {
            reverse(aa.begin() + a, aa.begin() + (b + 1));
            reverse(aa.begin() + c, aa.begin() + (d + 1));
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << aa[i] << nl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

