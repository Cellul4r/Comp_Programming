/* *   author : cellul4r
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

void setIO(string);
void solve(){
    
    int n,k;
    cin>>n>>k;

    set<int> now;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        now.insert(a[i]);
    }

    vector<int> ans(3);
    if(now.size() == n) {
        // permutation
        ans[0] = a[0];
        ans[1] = a[1];
        ans[2] = a[2];
    } else {
        for(int i = 1; i <= n; i++) {
            if(now.count(i) == 0) {
                ans[0] = i;
                break;
            }
        }
        ans[2] = a[n-1];
        for(int i = 1; i <= n; i++) {
            if(i != ans[0] && i != ans[2]) {
                ans[1] = i;
                break;
            }
        }
    }

    for(int i = 0, j = 0; j < k; j++, i = (i+1)%3) {
        cout << ans[i] << " ";
    }
    cout << nl;
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

