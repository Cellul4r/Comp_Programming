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

int n,m;
void solve(){
    
    cin>>n>>m;
    vector<int> a(n), cnt(m+1);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        a[i] = x;
        cnt[x]++;
    }
    
    int j = n - 1;
    while(true) {
        bool ok = true;
        for(int i = 1; i <= m; i++) {
            if(cnt[i] == 0) {
                ok = false;
            }
        }
        if(!ok) {
            break;
        }
        ans++;
        cnt[a[j]]--;
        j--;
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

