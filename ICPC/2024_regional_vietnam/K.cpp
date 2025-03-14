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

    for(int i = 0; i < n; i++) {
        cin>> a[i];
    }

    sort(all(a));
    int ans = 2 * n - 1;
    for(int i = 0; i < n; i++) {
        int j = i;
        while(j < n && a[j] == a[i]) {
            j++;
        }
        
        //cerr << i << " " << j << " " << a[i] << nl ;
        // remove delay
        int k = 2*n - (j - i);
        for(int l = j; l < n; l++) {
            k += a[l] / a[i] + (a[l] % a[i] ? 2 : 0) - 2ll;
            if(k >= ans) break;
        }
        //cerr << k << nl;
        ans = min(ans,k);
        i = j - 1;
    }

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

